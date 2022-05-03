/*********************************************************************
* ** Project Name: connect_four.cpp
** Author: Ethan Largent
** Date: 12 Mar 2021
** Description: A two player game of connect four
** Input: char* 
** Output: char** game_board, 
*********************************************************************/


/*********************************************************************

****README**README**README**README**README**README**README**README****

In lecture I was told that we can have comments in our code to explain
how it works instead of a seperate document and that seemed simpler to
me. The function headers seem to do that by themselves sometimes, but
with the larger functions I will have comments in them.

All the functions are 15 lines or less if you don't count the exceptions
mentioned on the pdf.
 
There is no single player implementation since it was cut from the
assignment.

****README**README**README**README**README**README**README**README****

*********************************************************************/


#include <iostream>
#include <math.h>
#include <string>
#include <string.h>


using namespace std;


/*********************************************************************
* ** Function: check_range()
** Description: checks if a given integer is within a given range
** Parameters: int test_value, int lower_bound, int upper_bound
** Pre-conditionals: takes integer parameters
** Post-conditionals: return a bool to tell if the test_value is in
   range of lower and upper bound
*********************************************************************/
bool check_range(int test_value, int lower_bound, int upper_bound){
   if(lower_bound > test_value || test_value > upper_bound)
      return false;
   return true;
}

/*********************************************************************
* ** Function: get_int()
** Description: gets the integer value of a string containing only numbers
** Parameters: string prompt
** Pre-conditionals: take a string parameter
** Post-conditionals: return an int representing the number in prompt
*********************************************************************/
int get_int(string prompt){
   int num = 0; 
   for(int i = 0; i < prompt.length(); i++)
      num += ((int(prompt[i]) - 48) * pow(10, (prompt.length() - i - 1)));
   return num;
}

/*********************************************************************
* ** Function: check_ command_line_arguments()
** Description: checks if command line arguments or its runtime 
   equivalents are valid
** Parameters: int argc, char** argv, string* cmdarg
** Pre-conditionals: take an int, char**, and string* parameter
** Post-conditionals: return a bool signifying the validity
*********************************************************************/
bool check_command_line_arguments(int argc, char** argv, string* cmdarg){
   if(cmdarg[0] == "" && cmdarg[1] == "" && argc == 3) //converts char*s to string
      for(int i = 0; i < 2; i++)
	 for(int j = 0; j < strlen(argv[i + 1]); j++)
	    cmdarg[i] += argv[i + 1][j];
   if(cmdarg[0] == "" && cmdarg[1] == "" && argc != 3)
      return false;
   int check1 = get_int(cmdarg[0]), check2 = get_int(cmdarg[1]); //coonverts to int now that its a string
   if(check_range(check1, 1, 20) == 0 || check_range(check2, 1, 20) == 0) //checks range
      return false;
   else
      return true;
}

/*********************************************************************
* ** Function: ask_for_input()
** Description: prompts the user with a given message and returns the
   users input as a string. If the message is printing the inputs range
   then dynamic_range should be a true and integers given
** Parameters: string message_prompt,
   bool dynamic_range = false, int lower = 0, int upper = 0
** Pre-conditionals: take a string parameter
   take a bool and two ints if range will be printed
** Post-conditionals: return a string of the users input
*********************************************************************/
string ask_for_input(string message_prompt, bool dynamic_range = false, int lower = 0, int upper = 0){
   string input;
   if(dynamic_range == false)
      cout << message_prompt << ":\t";
   else //for printing a dynamic range
      cout << message_prompt << "(" << lower << "-" << upper << "):\t";
   getline(cin, input);
   return input;
}

/*********************************************************************
* ** Function: create_2d_array()
** Description: creates a dynamic 2d array with ' ' as each element
** Parameters: char*** array, int rows, int columns
** Pre-conditionals: take an address of a char[][] and two ints
** Post-conditionals: none (changes values with pointers)
*********************************************************************/
void create_2d_array(char***array, int rows, int columns){
   *array = new char*[rows];
   for(int i = 0; i < rows; i++){
      (*array)[i] = new char[columns];
      for(int j = 0; j < columns; j++)
	 (*array)[i][j] = ' ';
   }
}

/*********************************************************************
* ** Function: delete_2d_array()
** Description: clears memory that an array is using in the heap
** Parameters: char*** array, int columns
** Pre-conditionals: take an address of a char[][] and an int
** Post-conditionals: none
*********************************************************************/
void delete_2d_array(char*** array, int columns){
  for(int i = 0; i <= columns; i++)
     delete [] (*array)[i];
  delete [] (*array);
}

/*********************************************************************
* ** Function: print_board()
** Description: prints the game board in an appealing format
** Parameters: char** board, int rows, int columns
** Pre-conditionals: take a char[][] and two ints
** Post-conditionals: none (couts only)
*********************************************************************/
void print_board(char** board, int rows, int columns){
   cout << endl;
   for(int i = 1; i <= columns; i++){
      if(i < 10)
	 cout << "  " << i << "  ";
      else
	 cout << "  " << i << " ";
   }
   cout << endl;

   for(int i = 0; i < rows; i++){
      for(int j = 0; j < columns; j++){
	 if((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))
	    cout << "|\033[30;47m " << board[i][j] << " ";
	 else
	    cout << "|\033[0m " << board[i][j] << " ";
	 cout << "\033[0m ";
      }
      cout << "|" << endl; //very interesting addition, yeah?
   }
   cout << "\n\n\n\n\n" << endl;
}

/*********************************************************************
* ** Function: place_piece()
** Description: places a piece in a given column on the bottom most
   empty space
** Parameters: char piece, char*** gameboard, int choice, int rows,
   int* piece_row, int* piece_column
** Pre-conditionals: take a char, an address to a char[][], 2 ints,
   and 2 address to ints
** Post-conditionals: returns a bool if column was already full or not
*********************************************************************/
bool place_piece(char piece, char*** gameboard, int choice, int rows, int* piece_row, int* piece_column){
   if((*gameboard)[0][choice] != ' ')
      return false;

   for(int i = rows - 1; i >= 0; i--)
      if((*gameboard)[i][choice] == ' '){
	 (*gameboard)[i][choice] = piece;
	 *piece_row = i; //saves the row and column for checking if the piece made them win
	 *piece_column = choice; 
	 return true;
      }
}

/*********************************************************************
* ** Function: player_turn()
** Description: prompts the player to take an action and reprompts them
   if thier input is invalid
** Parameters: char player, char*** gameboard, int rows, int columns,
   int* piece_row, int* piece_column
** Pre-conditionals: take a char, an address to a char[][], 2 ints,
   and 2 address to ints
** Post-conditionals: none (changes board using pointers)
*********************************************************************/
void player_turn(char player, char*** gameboard, int rows, int columns, int* piece_row, int* piece_column){
   string choice;
   bool check1, check2;
   
   print_board(*gameboard, rows, columns); //shows board
 
   choice = ask_for_input("Which column will you place your piece", true, 1, columns);//gets input and checks its validity

   while(1){
      int num_choice = get_int(choice) - 1;

      check1 = check_range(num_choice, 0, columns - 1);
      if(check1 == 0){
	 choice = ask_for_input("Error | Enter a valid option", true, 1, columns);
	 continue;
      }

      check2 = place_piece(player, gameboard, num_choice, rows, piece_row, piece_column); 
      if(check2 == 0){
	 choice = ask_for_input("Error | Enter a column that is not full", true, 1, columns);
	 continue;
      }

      break;
   }
}

/*********************************************************************
* ** Function: print_winner()
** Description: prints a winning or tie screen when the game is over
** Parameters: char winner, char** gameboard, int rows, int columns
** Pre-conditionals: take a char, char[][], and 2 ints
** Post-conditionals: none (couts only)
*********************************************************************/
void print_winner(char winner, char** gameboard, int rows, int columns){
   print_board(gameboard, rows, columns);
   if(winner == 'X')
      cout << "\n----------------------------\n >>> PLAYER 1 (X) WINS! <<< \n----------------------------\n" << endl;
   else if(winner == 'O')
      cout << "\n----------------------------\n >>> PLAYER 2 (O) WINS! <<< \n----------------------------\n" << endl;
   else
      cout << "\n----------------------------\n >>>    IT\'S A TIE!!    <<< \n----------------------------\n" << endl;
}

/*********************************************************************
* ** Function: check_full()
** Description: checks if the board is full
** Parameters: char piece, char** gameboard, int rows, int columns
** Pre-conditionals: take a char, char[][], and 2 ints
** Post-conditionals: returns a bool if board is filled or not
*********************************************************************/
bool check_full(char piece, char** gameboard, int rows, int columns){
   for(int i = 0; i < columns; i++)
      if(gameboard[0][i] == ' ')
	 return false;
   print_winner('T', gameboard, rows, columns);
   return true;
}

/*********************************************************************
* ** Function: check_horizontal()
** Description: checks if the player has won horizontally
** Parameters: char piece, int count, char** gameboard, int rows,
   int columns, int piece_ro
** Pre-conditionals: take a char, char[][], and 4 ints
** Post-conditionals: return a bool if they won horizontally or not
*********************************************************************/
bool check_horizontal(char piece, int count, char** gameboard, int rows, int columns, int piece_ro){
   for(int i = 0; i < columns; i++){
      if(gameboard[piece_ro][i] == piece)
	 count++;
      else
	 count = 0;
      if(count >= 4){
	 print_winner(piece, gameboard, rows, columns);
	 return true;
      }
   }
   return false;
}

/*********************************************************************
* ** Function: check_vertical()
** Description: checks if the player has won vertically
** Parameters: char piece, int count, char** gameboard, int rows,
   int columns, int piece_co
** Pre-conditionals: take a char, char[][], and 4 ints
** Post-conditionals: return a bool if they won vertically or not
*********************************************************************/
bool check_vertical(char piece, int count, char** gameboard, int rows, int columns, int piece_co){
   for(int i = 0; i < rows; i++){
      if(gameboard[i][piece_co] == piece)
	 count++;
      else
	 count = 0;
      if(count >= 4){
	 print_winner(piece, gameboard, rows, columns);
	 return true;
      }
   }
   return false;
}

/*********************************************************************
* ** Function: check_descending_diagonal1()
** Description: checks if the player has won diagonally from top left
   to bottom right starting on the top
** Parameters: char piece, int count, char** gameboard, int rows,
   int columns, int piece_ro, int piece_co
** Pre-conditionals: take a char, char[][], and 5 ints
** Post-conditionals: return a bool if they won diagonally in this way
   or not
*********************************************************************/
bool check_descending_diagonal1(char piece, int count, char** gameboard, int rows, int columns, int piece_ro, int piece_co){
   int i = 0;
 
   while(i < rows && piece_co - piece_ro + i < columns){
      if(gameboard[i][piece_co - piece_ro + i] == piece)
	 count++;
      else
	 count = 0;
      if(count >= 4){
	 print_winner(piece, gameboard, rows, columns);
	 return true;
      }
      i++;
   }
   return false;
}

/*********************************************************************
* ** Function: check_descending_diagonal2()
** Description: checks if the player has won diagonally from top left
   to bottom right starting on the left side
** Parameters: char piece, int count, char** gameboard, int rows,
   int columns, int piece_ro, int piece_co
** Pre-conditionals: take a char, char[][], and 5 ints
** Post-conditionals: return a bool if they won diagonally in this way
   or not
*********************************************************************/
bool check_descending_diagonal2(char piece, int count, char** gameboard, int rows, int columns, int piece_ro, int piece_co){
   int i = 0;
 
   while(piece_ro - piece_co + i < rows && i < columns){
      if(gameboard[piece_ro - piece_co + i][i] == piece)
	 count++;
      else
	 count = 0;
      if(count >= 4){
	 print_winner(piece, gameboard, rows, columns);
	 return true;
      }
      i++;
   }
   return false;
}

/*********************************************************************
* ** Function: check_ascending_diagonal1()
** Description: checks if the player has won diagonally from bottom left
   to top right starting on the bottom
** Parameters: char piece, int count, char** gameboard, int rows,
   int columns, int piece_ro, int piece_co
** Pre-conditionals: take a char, char[][], and 5 ints
** Post-conditionals: return a bool if they won diagonally in this way
   or not
*********************************************************************/
bool check_ascending_diagonal1(char piece, int count, char** gameboard, int rows, int columns, int piece_ro, int piece_co){   
   int i = 0;
 
   while(rows - 1 - i >= 0 && piece_co - rows + 1 + i < columns){
      if(gameboard[rows - 1 - i][piece_co - piece_ro + 1 + i] == piece)
	 count++;
      else
	 count = 0;
      if(count >= 4){
	 print_winner(piece, gameboard, rows, columns);
	 return true;
      }
      i++;
   }
   return false;
}

/*********************************************************************
* ** Function: check_ascending_diagonal2()
** Description: checks if the player has won diagonally from bottom left
   to top right starting on the left side
** Parameters: char piece, int count, char** gameboard, int rows,
   int columns, int piece_ro, int piece_co
** Pre-conditionals: take a char, char[][], and 5 ints
** Post-conditionals: return a bool if they won diagonally in this way
   or not
*********************************************************************/
bool check_ascending_diagonal2(char piece, int count, char** gameboard, int rows, int columns, int piece_ro, int piece_co){   
   int i = 0;
 
   while(piece_ro + piece_co - i >= 0 && i < columns){
      if(gameboard[piece_ro + piece_co - i][i] == piece)
	 count++;
      else
	 count = 0;
      if(count >= 4){
	 print_winner(piece, gameboard, rows, columns);
	 return true;
      }
      i++;
   }
   return false;
}

/*********************************************************************
* ** Function: check__diagonal()
** Description: checks if the player has won diagonally
** Parameters: char piece, int count, char** gameboard, int rows,
   int columns, int piece_ro, int piece_co
** Pre-conditionals: take a char, char[][], and 5 ints
** Post-conditionals: return a bool if they won diagonally or not
*********************************************************************/
bool check_diagonal(char piece, int count, char** gameboard, int rows, int columns, int piece_ro, int piece_co){   
//the function descriptions for these 4 diagonal checks describe how this all works better. this diagonal stuff was the hardest part of the assignment
   if(piece_ro < piece_co)
      if(check_descending_diagonal1(piece, count, gameboard, rows, columns, piece_ro, piece_co) == 1)
         return true;
   if(piece_ro >= piece_co)
      if(check_descending_diagonal2(piece, count, gameboard, rows, columns, piece_ro, piece_co) == 1)
         return true;
   if(rows - piece_ro - 1 < piece_co)
      if(check_ascending_diagonal1(piece, count, gameboard, rows, columns, piece_ro, piece_co) == 1)
         return true;
   if(rows - piece_ro - 1 >= piece_co)
      if(check_ascending_diagonal2(piece, count, gameboard, rows, columns, piece_ro, piece_co) == 1)
	 return true;
   return false;
}

/*********************************************************************
* ** Function: check_winner()
** Description: checks if a player has won or if the game is a tie or not
** Parameters: char piece, char** gameboard, int rows, int columns,
   int* piece_row, int* piece_column
** Pre-conditionals: take a char, char[][], 3 ints, and 2 address of ints
** Post-conditionals: return a bool if the game is over or not
*********************************************************************/
bool check_winner(char piece, char** gameboard, int rows, int columns, int* piece_row, int* piece_column){
   if(check_full(piece, gameboard, rows, columns) == 1) //check for tie game
      return true;

   int count = 0;
   int piece_ro = (*piece_row);
   int piece_co = (*piece_column);

   if(check_horizontal(piece, count, gameboard, rows, columns, piece_ro) == 1) //check horizontal win
      return true;
   if(check_vertical(piece, count, gameboard, rows, columns, piece_co) == 1) //check vertical win
      return true;
   if(check_diagonal(piece, count, gameboard, rows, columns, piece_ro, piece_co) == 1) //check diagonal win
      return true;
   return false;
}

/*********************************************************************
* ** Function: play_game()
** Description: plays a game of connect four using the other functions
** Parameters: char** gameboard, int rows, int columns
** Pre-conditionals: take a char[][] and 2 ints
** Post-conditionals: none
*********************************************************************/
void play_game(char** gameboard, int rows, int columns){
   char player1 = 'X', player2 = 'O';
   int piece_row = 0;
   int piece_column = 0;

   while(1){
      player_turn(player1, &gameboard, rows, columns, &piece_row, &piece_column); //player one turn
   
      if(check_winner(player1, gameboard, rows, columns, &piece_row, &piece_column) == 1) //check if last move won
         break;
   
      player_turn(player2, &gameboard, rows, columns, &piece_row, &piece_column); //player two turn
   
      if(check_winner(player2, gameboard, rows, columns, &piece_row, &piece_column) == 1) //check if last move won
 	 break;
   }
}

int main(int argc, char** argv){
   string cmdarg[2]; //where the string versions of the command line arguments will be strored
   char** gameboard;
   int play_again;

   while(check_command_line_arguments(argc, argv, cmdarg) == 0){ //checks if the command line arguments are valid
      cmdarg[0] = ask_for_input("Error | Enter a valid number of rows(1-20)");
      cmdarg[1] = ask_for_input("        Enter a valid number of columns(1-20)");
   }

   int row = get_int(cmdarg[0]);
   int col = get_int(cmdarg[1]);

   do{
      create_2d_array(&gameboard, row, col); //make new board(need to exit for a new size)

      play_game(gameboard, row, col); //plays game
      play_again = get_int(ask_for_input("Do you want to play again(1-yes | 2-no)")); //asks to play again
      while(check_range(play_again, 1, 2) == 0)
         play_again = get_int(ask_for_input("Error | Enter a valid option(1-yes | 2-no)"));
      delete_2d_array(&gameboard, col); //delete the board
   }while(play_again == 1);

   return 0;
}
