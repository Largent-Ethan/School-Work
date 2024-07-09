#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#ifndef METRIC
#define METRIC    true
#endif

#ifndef COYOTES
#define COYOTES   true
#endif

int	NowYear;    // current year (2024- 2029)
int	NowMonth;	// current month (0 - 11)
float	NowPrecip;	// inches of rain per month
float	NowTemp;		// temperature this month
float	NowHeight;	// grain height in inches
int	NowNumDeer;	// number of deer in the current population
int   NowNumCoyotes; // number of coyotes in the current population

unsigned int seed = 0;  // for random number generation

const float GRAIN_GROWS_PER_MONTH =       12.0;
const float ONE_DEER_EATS_PER_MONTH =     1.0;
const float ONE_COYOTE_EATS_PER_MONTH =   0.5; 

const float AVG_PRECIP_PER_MONTH =        7.0;	// average
const float AMP_PRECIP_PER_MONTH =        6.0;	// plus or minus
const float RANDOM_PRECIP =               2.0;	// plus or minus noise

const float AVG_TEMP =                    60.0;	// average
const float AMP_TEMP =                    20.0;	// plus or minus
const float RANDOM_TEMP =                 10.0;	// plus or minus noise

const float MIDTEMP =                     40.0;
const float MIDPRECIP =                   10.0;

omp_lock_t Lock;
volatile int NumInThreadTeam;
volatile int NumAtBarrier;
volatile int NumGone;

void InitBarrier(int n);
void WaitBarrier();
float SQR(float x);
float Ranf(float low, float high);
void SetEnvironment();
void PrintData();
void Grain();
void Deer();
void Coyotes();
void Watcher();

// Initializes barriers for each threads
void
InitBarrier( int n )
{
   NumInThreadTeam = n;
   NumAtBarrier = 0;
   omp_init_lock( &Lock );
}

// Locks a thread and waits until all threads are locked
void
WaitBarrier( )
{
   omp_set_lock( &Lock );
   {
      NumAtBarrier++;
      if( NumAtBarrier == NumInThreadTeam )
      {
         NumGone = 0;
         NumAtBarrier = 0;
         // let all other threads get back to what they were doing
			// before this one unlocks, knowing that they might immediately
			// call WaitBarrier( ) again:
         while( NumGone != NumInThreadTeam-1 );
         omp_unset_lock( &Lock );
         return;
      }
   }
   omp_unset_lock( &Lock );
   while( NumAtBarrier != 0 ); // this waits for the nth thread to arrive
   #pragma omp atomic
   NumGone++; // this flags how many threads have returned
}

// Squares a float
float
SQR( float x )
{
   return x*x;
}

// Generates a random float between two floats
float
Ranf( float low, float high )
{
   float r = (float) rand();
   float t = r / (float) RAND_MAX;
   return low + t * ( high - low );
}

// Sets the temperature and precipitation based off of the current month
void
SetEnvironment( )
{
   float ang = (  30.*(float)NowMonth + 15.  ) * ( M_PI / 180. );	// angle of earth around the sun

   float temp = AVG_TEMP - AMP_TEMP * cos( ang );
   NowTemp = temp + Ranf( -RANDOM_TEMP, RANDOM_TEMP );

   float precip = AVG_PRECIP_PER_MONTH + AMP_PRECIP_PER_MONTH * sin( ang );
   NowPrecip = precip + Ranf( -RANDOM_PRECIP, RANDOM_PRECIP );
   if( NowPrecip < 0. ) NowPrecip = 0.;
}

// Prints all of the relevant data from the simulation
void
PrintData( )
{
   int timePassed = (NowYear - 2024) * 12 + NowMonth;
   fprintf(stderr, "%3d , ", timePassed);
   if (METRIC) fprintf(stderr, "%2.2f , %2.2f , %2.2f, ", (NowTemp - 32) * 5/9, NowPrecip * 2.54, NowHeight * 2.54);
   else fprintf(stderr, "%2.2f , %2.2f , %2.2f, ", NowTemp, NowPrecip, NowHeight);
   if (COYOTES) fprintf(stderr, "%2d, %2d\n", NowNumDeer, NowNumCoyotes);
   else fprintf(stderr, "%2d\n", NowNumDeer);
}

// Maintains the grain height
void
Grain( )
{
   float tempFactor;
   float precipFactor;
   float nextHeight;
   while( NowYear < 2030 )
   {
      tempFactor = exp(   -SQR(  ( NowTemp - MIDTEMP ) / 10.  )   );
      precipFactor = exp(   -SQR(  ( NowPrecip - MIDPRECIP ) / 10.  )   );

      nextHeight = NowHeight;
      nextHeight += tempFactor * precipFactor * GRAIN_GROWS_PER_MONTH;
      nextHeight -= (float)NowNumDeer * ONE_DEER_EATS_PER_MONTH;
      if( nextHeight < 0. ) nextHeight = 0.;

   	WaitBarrier( ); // DoneComputing barrier

      NowHeight = nextHeight;

   	WaitBarrier( ); // DoneAssigning barrier

      // do nothing

   	WaitBarrier( ); // DonePrinting barrier
   }
}

// Maintains the deer population
void
Deer( )
{
   int nextNumDeer;
   int carryingCapacity;
   while( NowYear < 2030 )
   {
      nextNumDeer = NowNumDeer;
      carryingCapacity = (int)( NowHeight );
      if( nextNumDeer < carryingCapacity ) nextNumDeer++;
      else if( nextNumDeer > carryingCapacity ) nextNumDeer--;
      if(COYOTES) nextNumDeer -= (int)(NowNumCoyotes * ONE_COYOTE_EATS_PER_MONTH);
      if( nextNumDeer < 0 ) nextNumDeer = 0;

   	WaitBarrier( ); // DoneComputing barrier

      NowNumDeer = nextNumDeer;

   	WaitBarrier( ); // DoneAssigning barrier

      // do nothing

   	WaitBarrier( ); // DonePrinting barrier
   }
}

// Maintains the coyote population
void
Coyotes( )
{
   int nextNumCoyotes;
   int carryingCapacity;
   while( NowYear < 2030 )
   {
      nextNumCoyotes = NowNumCoyotes;
      carryingCapacity = NowNumDeer;
      if( nextNumCoyotes < carryingCapacity ) nextNumCoyotes++;
      else if( nextNumCoyotes > carryingCapacity ) nextNumCoyotes--;
      if( nextNumCoyotes < 0 ) nextNumCoyotes = 0;

   	WaitBarrier( ); // DoneComputing barrier

      NowNumCoyotes = nextNumCoyotes;

   	WaitBarrier( ); // DoneAssigning barrier

      // do nothing

   	WaitBarrier( ); // DonePrinting barrier
   }
}

// Prints simulation data and maintains the environment
void
Watcher( )
{
   float ang;
   float temp;
   float precip;
   while( NowYear < 2030 )
   {
      //do nothing

   	WaitBarrier( ); // DoneComputing barrier

      // do nothing

   	WaitBarrier( ); // DoneAssigning barrier

      PrintData( );
      NowMonth++;
      if( NowMonth > 11) 
      {
         NowMonth = 0;
         NowYear++;
      }
      SetEnvironment( );

   	WaitBarrier( ); // DonePrinting barrier
   }
}

// Main 
int
main( )
{
   // initial values
   NowMonth = 0;
   NowYear = 2024;
   NowNumDeer = 2;
   NowHeight = 5.;
   NowNumCoyotes = 1;
   SetEnvironment( );
   int numThreads = 3;
   if (COYOTES) numThreads++;

   omp_set_num_threads( numThreads );
   InitBarrier( numThreads );
   #pragma omp parallel sections
   {
   	#pragma omp section
   	{
   		Deer( );
   	}
   	#pragma omp section
   	{
   		Grain( );
   	}
   	#pragma omp section
   	{
   		Watcher( );
   	}
      #pragma omp section
   	{
   		Coyotes( );
   	}
   }  // implied barrier -- all functions must return to get past here
}