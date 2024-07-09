#include <stdio.h>
#include <math.h>
#include <mpi.h>

#define THEBOSS 0
#define BIGSIGNALFILEBIN	(char*)"bigsignal.bin"
#define BIGSIGNALFILEASCII	(char*)"bigsignal.txt"
#define CSVPLOTFILE		(char*)"plot.csv"
#define TAG_SCATTER		'S'
#define TAG_GATHER		'G'
#define NUMELEMENTS	(8*1024*1024)
#define MAXSHIFTS	1024
#define MAXPLOT		 400
#define BINARY
//#define ASCII
#define DEBUG		true

float * BigSums;
float *	BigSignal;
int	NumCpus;
float * PPSums;
float *	PPSignal;
int	PPSize;

void	DoOneLocalAutocorrelation( int );

int
main( int argc, char *argv[ ] )
{
	MPI_Status status;

	MPI_Init( &argc, &argv );

	MPI_Comm_size( MPI_COMM_WORLD, &NumCpus );
	int  me;
	MPI_Comm_rank( MPI_COMM_WORLD, &me );

	PPSize    = NUMELEMENTS / NumCpus;

	PPSignal  = new float [PPSize+MAXSHIFTS];
	PPSums    = new float [MAXSHIFTS];

	if( me == THEBOSS )
	{
		BigSignal = new float [NUMELEMENTS+MAXSHIFTS];

#ifdef BINARY
		FILE *fp = fopen( BIGSIGNALFILEBIN, "rb" );
		if( fp == NULL )
		{
			fprintf( stderr, "Cannot open data file '%s'\n", BIGSIGNALFILEBIN );
			return -1;
		}

		fread( BigSignal, sizeof(float), NUMELEMENTS, fp );
#endif

		for( int i = 0; i < MAXSHIFTS; i++ )
		{
			BigSignal[NUMELEMENTS+i] = BigSignal[i];
		}
	}

	if( me == THEBOSS )
	{
		BigSums = new float [MAXSHIFTS];
	}

	double time0 = MPI_Wtime( );

	if( me == THEBOSS )
	{
		for( int i = 0; i < PPSize+MAXSHIFTS; i++ )
		{
			PPSignal[i] = BigSignal[ THEBOSS*PPSize + i ];
		}
	}

	if( me == THEBOSS )
	{
		for( int dst = 0; dst < NumCpus; dst++ )
		{
			if( dst != THEBOSS )
			{
				MPI_Send( &BigSignal[dst*PPSize], PPSize+MAXSHIFTS, MPI_FLOAT, dst, TAG_SCATTER, MPI_COMM_WORLD );
			}
		}
	}
	else
	{
		MPI_Recv( PPSignal, PPSize+MAXSHIFTS, MPI_FLOAT, THEBOSS, TAG_SCATTER, MPI_COMM_WORLD, &status );
	}

	DoOneLocalAutocorrelation( me );

	if( me == THEBOSS )
	{
		for( int s = 0; s < MAXSHIFTS; s++ )
		{
			BigSums[s] = PPSums[s];
		}
	}
	else
	{
		MPI_Send( PPSums, MAXSHIFTS, MPI_FLOAT, THEBOSS, TAG_GATHER, MPI_COMM_WORLD );
	}

	if( me == THEBOSS )
	{
		float tmpSums[MAXSHIFTS];
		for( int src = 0; src < NumCpus; src++ )
		{
			if( src != THEBOSS )
			{
				MPI_Recv( tmpSums, MAXSHIFTS, MPI_FLOAT, src, TAG_GATHER, MPI_COMM_WORLD, &status );
				for( int s = 0; s < MAXSHIFTS; s++ )
					BigSums[s] += tmpSums[s];
			}
		}
	}

	double time1 = MPI_Wtime( );

	if( me == THEBOSS )
	{
		double seconds = time1 - time0;
		double performance = (double)MAXSHIFTS*(double)NUMELEMENTS/seconds/1000000.;
		fprintf( stderr, "%3d processors, %10d elements, %9.2lf mega-autocorrelations computed per second\n",
			NumCpus, NUMELEMENTS, performance );
	}

	if( me == THEBOSS )
	{
		FILE *fp = fopen( CSVPLOTFILE, "w" );
		if( fp == NULL )
		{
			fprintf( stderr, "Cannot write to plot file '%s'\n", CSVPLOTFILE );
		}
		else
		{
			for( int s = 1; s < MAXPLOT; s++ )
			{
				fprintf( fp, "%6d , %10.2f\n", s, BigSums[s] );
			}
			fclose( fp );
		}
	}

	MPI_Finalize( );
	return 0;
}

void
DoOneLocalAutocorrelation( int me )
{
	MPI_Status status;

	if( DEBUG )	fprintf( stderr, "Node %3d entered DoOneLocalAutocorrelation( )\n", me );

	for( int s = 0; s < MAXSHIFTS; s++ )
	{
		float sum = 0.;
		for( int i = 0; i < PPSize; i++ )
		{
			sum += PPSignal[i] * PPSignal[i+s];
		}
		PPSums[s] = sum;
	}
}