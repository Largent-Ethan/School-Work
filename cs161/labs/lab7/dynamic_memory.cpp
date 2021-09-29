#include <iostream>

using namespace std;

//void input(int *heap_var){
//   cin >> heap_var;
//}

int *heap_create1(){
   int *heap_var = new int;
//   input(heap_var);
   return heap_var;
}

void heap_create2(int **heap_var){
   *heap_var = new int;
//   input(heap_var);
}

void heap_create3(int *&heap_var){
   heap_var = new int;
//   input(heap_var);
   cout << *heap_var << '\t';
   delete heap_var;
}

int main(){
   int *heap_var;

   heap_create1();
   cout << heap_var << '\t';
   delete heap_var;

   heap_create2(&heap_var);
   cout << *heap_var << '\t';
   delete heap_var;

   heap_create3(heap_var);

   return 0;
}
