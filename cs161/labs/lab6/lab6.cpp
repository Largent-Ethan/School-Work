//Recurssion Questions:
//Main hasnt seen the factorial function before so it crashes when it gets to the first call
//It never stops its "recursiveness" because there is no base case for it to stop at
//Nah, they are a part of different scopes

#include <iostream>
#include <sys/time.h>
#include <cstdlib>

using std::cout;
using std::endl;

void fib_iter(int n){
   int num1, num2, result;
   for(int i=0; i<=n; i++){
      if(i==0)
	 num1=0, result=0;
      else if(i==1)
	 num2=1, result=1;
      else{
	 result=num1+num2;
	 num1=num2;
	 num2=result;
      }
   }
}

int fib_recurs(int n){
   if(n==0)
      return 0;
   else if(n==1)
      return 1;
   else
      return fib_recurs(n-1) + fib_recurs(n-2);
}

int main(){
   int n;
   typedef struct timeval time;
   time stop, start;

   std::cin >> n;

   gettimeofday(&start, NULL);

   fib_iter(n);

   gettimeofday(&stop, NULL);

   if(stop.tv_sec > start.tv_sec)
      cout << "Seconds: " << stop.tv_sec - start.tv_sec << endl;
   else
      cout << "Micro: " << stop.tv_usec - start.tv_usec << endl;

   gettimeofday(&start, NULL);

   fib_recurs(n);

   gettimeofday(&stop, NULL);

   if(stop.tv_sec > start.tv_sec)
      cout << "Seconds: " << stop.tv_sec - start.tv_sec << endl;
   else
      cout << "Micro: " << stop.tv_usec - start.tv_usec << endl;

   return 0;
}
