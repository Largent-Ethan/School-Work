#include <iostream>

using namespace std;

void make_board(int*** board, int rows, int cols){
   *board = new int*[rows];
   for(int i = 0; i < rows; i++){
      (*board)[i] = new int[cols];
      for(int j = 0; j < cols; j++){
	 if(j==0)
	    (*board)[i][j] = i + 1;
	 else
	    (*board)[i][j] = 0;
      }
   }
}

void clear_board(int*** board, int rows, int cols){
   for(int i = 0; i < rows; i++)
      delete [] (*board)[i];
   delete [] *board;
   *board = NULL;
}

void print(int*** board, int rows, int cols) {
   for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++)
	 cout << (*board)[i][j] << '\t';
      cout << '\n';
   }
   for(int k = 0; k < cols; k++)
      cout << "--------";
   cout<<endl;
}

void move(int n, int ***b, int from, int to, int rows){
   for(int i = 0; i < rows; i++)
      if((*b)[i][from] != 0)
	 for(int j = rows - 1; j >= 0; j--)
	    if((*b)[j][to] == 0){
	       (*b)[j][to] = (*b)[i][from];
	       (*b)[i][from] = 0;
	       print(b, rows, 3);
	       return;
      }
}

void towers(int n, int ***b, int from_col, int to_col, int spare, int rows) {
   if(n==1){
      move(n, b, from_col, to_col, rows);
      return;
   }
   towers(n - 1, b, from_col, spare, to_col, rows);
   move(n, b, from_col, to_col, rows);
   towers(n - 1, b, spare, to_col, from_col, rows);
}


int main(int argc, char** argv){
   int number_of_disks = int(argv[1][0]) - 48;
   int columns = 3;
   int** board;
   make_board(&board, number_of_disks, columns);
   print(&board, number_of_disks, columns);
   towers(number_of_disks, &board, 0, 2, 1, number_of_disks);
   clear_board(&board, number_of_disks, columns);
   return 0;
}
