#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct mult_div_values{
   int mult;
   float div;
} ;

void set_mult_values(mult_div_values** table, int n){
   for(int i = 0; i < n; i++){
      table[0][i].mult = i + 1;
      table[i][0].mult = i + 1;
   }
   for(int i = 1; i < n; i++)
      for(int j = 1; j < n; j++)
      table[i][j].mult = table[0][j].mult * table[i][0].mult;
}

void set_div_values(mult_div_values** table, int n){
   for(int i = 0; i < n; i++){
      table[0][i].div = i + 1;
      table[i][0].div = i + 1;
   }
   for(int i = 1; i < n; i++)
      for(int j = 1; j < n; j++)
      table[i][j].div = (floor((table[i][0].div / table[0][j].div) * 100 + 0.5) / float(100.00));
}

mult_div_values** create_table(int num){
   mult_div_values** table;
   table = new mult_div_values*[num];
   for(int i = 0; i < num; i++)
      table[i] = new mult_div_values[num];
   set_mult_values(table, num);
   set_div_values(table, num);
   return table;
}

int digits(int num){
   int count = 0;
   while(num != 0) {
      num = num / 10;
      count++;
   }
   return count;
}

int fdigits(float flt){
   int num = flt * 100;
   int count = 0;
   for(int i = 0; i < 4; i++){
      if((num % 10) != 0){
         if(i == 1){
            count++;
         }
         count++;
      }
      if(i == 2 && num % 10 == 0)
         count++;
      num = num / 10;
   }
   return count;
}

void print_mtable(mult_div_values** table, int num){
   int max_spaces = digits(table[num-1][num-1].mult) + 1;
   cout << "Multiplication Table:" << endl;
   for(int i = 0; i < num; i++){
      for(int j = 0; j < num; j++){
         int spaces = max_spaces - digits(table[i][j].mult);
         cout << table[i][j].mult;
         for(int k = 0; k <= spaces; k++)
            cout << ' ';
      }
      cout << endl;
   }
   cout << endl;
}

void print_dtable(mult_div_values** table, int num){
   int max_spaces = fdigits(table[0][num].div) + 4;
   cout << "Division Table:" << endl;
   for(int i = 0; i < num; i++){
      for(int j = 0; j < num; j++){
         int spaces = max_spaces - fdigits(table[i][j].div);
         cout << table[i][j].div;
         for(int k = 0; k <= spaces; k++)
            cout << ' ';
      }
      cout << endl;
   }
   cout << endl;
}

void delete_table(mult_div_values** table, int num){
   for(int i = 0; i < num; i++)
      delete[] table[i];
   delete[] table;
}

int set_dimensions(int* argc, int value, int again){
   char input[2];
   while(again == 1 || value == 0 || 99 < value){
      if(again == 1 || (*argc) != 2 ){
         cout << "\nEnter a max value for tables: ";
            again = 0;
            (*argc) = 2;
      }
      else if(0 == value || 99 < value)
         cout << "\nError | Must be an integer between 0 and 100\nInput max value for tables: ";
      cin >> input;
      value = atoi(input);
   }
   cout << endl;
   return value;
}

int main(int argc, char* argv[]){
   int again, value = 0;
   if(argc == 2)
      value = atoi(argv[1]);
   do{
      int dimensions = set_dimensions(&argc, value, again);

      mult_div_values** mdtables = create_table(dimensions);
      
      print_mtable(mdtables, dimensions);
      print_dtable(mdtables, dimensions);
      delete_table(mdtables, dimensions);

      cout << "\nAgain? (1 - yes / not 1 - no): ";
      cin >> again;
   }while(again == 1);
   return 0;
}