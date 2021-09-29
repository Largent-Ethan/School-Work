#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;

void assign_values(int ***square){
   srand (time(NULL));
   for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
	 (*square)[i][j] = rand() % 9 + 1;
}

bool fun(int ***square){
   for(int i = 1; i < 3; i++){
      a = (*square)[i-1][0] + (*square)[i-1][1] + (*square)[i-1][2];
      b =(*square)[i][0] + (*square)[i][1] + (*square)[i][2];
      if(a!=b)
	 return false;
   }
   cout<<a;
}

int main(){
   int **square[3][3];
   assign_values(&square);
   fun(&square);
}
