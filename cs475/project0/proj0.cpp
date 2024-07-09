#include <omp.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// number of threads to use
#ifndef NUMT
#define NUMT	         1
#endif

// array size
#ifndef SIZE
#define SIZE       	16384
#endif

// how many times to run the timing to get reliable timing data
#define NUMTRIES        20

float A[SIZE];
float B[SIZE];
float C[SIZE];

int
main( )
{
	for( int i = 0; i < SIZE; i++ )
	{
		A[i] = 1.;
		B[i] = 2.;
	}

   omp_set_num_threads( NUMT );

   double maxMegaMults = 0.;
   double sumMegaMults = 0.;

   for( int t = 0; t < NUMTRIES; t++ )
   {
      double time0 = omp_get_wtime( );

      #pragma omp parallel for
      for( int i = 0; i < SIZE; i++ )
      {
         C[i] = A[i] * B[i];
      }

      double time1 = omp_get_wtime( );
      double megaMults = (double)SIZE/(time1-time0)/1000000.;
      sumMegaMults += megaMults;
      if( megaMults > maxMegaMults )
         maxMegaMults = megaMults;
   }

   double avgMegaMults = sumMegaMults/(double)NUMTRIES;
   fprintf( stderr, "For %d threads, Peak Performance = %8.2lf MegaMults/Sec\n", NUMT, maxMegaMults );
   fprintf( stderr, "For %d threads, Average Performance = %8.2lf MegaMults/Sec\n", NUMT, avgMegaMults );

   return 0;
}