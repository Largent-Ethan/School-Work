/*********************************************************************
* ** Project Name: c_style_strings.cpp
** Author: Ethan Largent
** Date: 26 Feb 2021
** Description: Runs a users choice of three options on a user inputed string
** Input: int operation, string sentence, int rerun, (inputs for operation)
** Output: result of operation
*********************************************************************/

#include <iostream>
#include <math.h>
#include <cstring>
#include <math.h>

using namespace std;



/*********************************************************************
* ** Function: to_int()
** Description: finds the integer representation of a c style string
** Parameters: char* option
** Pre-conditionals: take a c style string
** Post-conditionals: return an integer representation of the string
*********************************************************************/
int to_int(char* option){
   int integer = 0;
   for (int i = 0; i < strlen(option); i++)
      integer = (int(option[i]) - 48) * pow(10,i);
   return integer;
}



/*********************************************************************
* ** Function: in_range()
** Description: checks if input is in between two numbers
** Parameters: char* option, int low, int high
** Pre-conditionals: take a c style string and 2 integers
** Post-conditionals: return a bool whether it is in the range given
*********************************************************************/
bool in_range(char* option, int low, int high){
   int test = to_int(option);
   if(low > test || high < test){
      if(high!=1)
	 cout << "\n\nInvalid input, must be a listed value\n(you may need to press enter to continue)" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
      return false;
   }
   return true;
}


/*********************************************************************
* ** Function: only_lower()
** Description: changes all capital letters in a string to lowercase 
   and deletes all charaters that are not a space or letter
** Parameters: char* sentence
** Pre-conditionals: take a c style string
** Post-conditionals: none
*********************************************************************/
void only_lower(char* sentence){
   int count = 0, j = 0;
   char lower_sentence[strlen(sentence)];
   for (int i = 0; i < strlen(sentence); i++){
      if (((96 < int(sentence[i])) && (int(sentence[i]) < 123)) || ((int(sentence[i]) == 32))){
	 lower_sentence[j++] = sentence[i];
	 count++;
      }
      else if ((64 < int(sentence[i])) && (int(sentence[i]) < 91)){
	 lower_sentence[j++] = char(int(sentence[i]) + 32);
	 count++;
      }
   }
   lower_sentence[count] = '\0';
   strcpy(sentence, lower_sentence);
}


/*********************************************************************
* ** Function: letters_present()
** Description: checks if letters are in a given string
** Parameters: char* sentence
** Pre-conditionals: take a c style string
** Post-conditionals: return a bool whether it has a letter or not
*********************************************************************/
bool letters_present(char* sentence){
   for (int i = 0; i <= strlen(sentence); i++)
      if ((64 < int(sentence[i]) && int(sentence[i]) < 91) || (96 < int(sentence[i]) && int(sentence[i]) < 123)){
	 only_lower(sentence);
	 return true;
      }
   cout << "\n\nInvalid input, must contain letters\n(you may need to press enter to continue)" << endl;
   cin.clear();
   cin.ignore(10000, '\n');
   return false;
}


/*********************************************************************
* ** Function: no_spaces()
** Description: deletes all non-letter characters from a string
** Parameters: char* sentence
** Pre-conditionals: take a c style string
** Post-conditionals: none
*********************************************************************/
void no_spaces(char* sentence){
   int count = 0, j = 0;
   char spaceless_sentence[strlen(sentence)];
   for (int i = 0; i < strlen(sentence); i++)
      if (!(int(sentence[i]) == 32)){
	 spaceless_sentence[j++] = sentence[i];
	 count++;
      }
   spaceless_sentence[count] = '\0';
   strcpy(sentence, spaceless_sentence);
}


/*********************************************************************
* ** Function: contains_sub_string()
** Description: checks if a given string is present inside a given string
** Parameters: char* sub_string, char* sentence
** Pre-conditionals: take a c style string
** Post-conditionals: return a bool to tell if sub_string is within sentence
*********************************************************************/
bool contains_sub_string(char* sub_string, char* sentence){
   for (int i = 0; i < strlen(sentence); i++)
      if (sentence[i] == sub_string[0]){
	 for (int j=1; j < strlen(sub_string); j++){
	    if (sentence[i+j] != sub_string[j])
	       break;
	    if (j == (strlen(sub_string) - 1))
	       return true;
	 }
      }
   return false;
}


/*********************************************************************
* ** Function: vows_cons()
** Description: prints if the number of vowels and cosonants are equal or not
** Parameters: char* sentence
** Pre-conditionals: take a c style string
** Post-conditionals: none (prints result)
*********************************************************************/
void vows_cons(char* sentence){
   no_spaces(sentence);
   int vow_count = 0;
   int con_count = 0;
   for (int i = 0; i < strlen(sentence); i++){
      if (sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' || sentence[i] =='o' || sentence[i] == 'u')
	 vow_count++;
      else
	 con_count++;
   }
   vow_count == con_count ? cout << "# vowels = # consonants\n" : cout << "# vowels != # consonants\n";
}


/*********************************************************************
* ** Function: is_pal()
** Description: prints if the string is a palindrome or not
** Parameters: char* sentence
** Pre-conditionals: take a c style string
** Post-conditionals: none (prints result)
*********************************************************************/
void is_pal(char* sentence){
   int j = 0;
   no_spaces(sentence);
   for (int i = 0; i < int(strlen(sentence)/2); i++)
      if (sentence[i] != sentence[strlen(sentence)-i-1]){
	    cout << "This is not a palindrome" << endl;
	    return;
      }
   cout << "This is a palindrome" << endl;
}


/*********************************************************************
* ** Function: word_count()
** Description: counts the amount of words in a given string
** Parameters: char* sentence
** Pre-conditionals: take a c style string
** Post-conditionals: return an int representing the number of words in sentence
*********************************************************************/
int word_count(char* sentence){
   int count = 0;
   for (int i = 0; i < (strlen(sentence) - 1); i++)
      if (sentence[i] != ' ' && sentence[i + 1] == ' ')
	 count += 1;
   if (sentence[strlen(sentence) - 1] != ' ')
      count += 1;
   return count;
}


/*********************************************************************
* ** Function: find_words()
** Description: outputs the amount each word occurs in the string
** Parameters: char* sentence, char** words
** Pre-conditionals: take a c style string
** Post-conditionals: none (prints result)
*********************************************************************/
void find_words(char* sentence, char** words, int n){
   for (int i = 0; i < n; i++){
      int count = 0;
      for (int j = 0; j < word_count(sentence); j++)
         if (strstr(sentence, words[i])){
	    count++;
   	    char* update = strstr(sentence, words[i]);
	    for(int k = 0; k < strlen(words[i]); k++)
	       update[k] = ' ';
	    strcat(sentence, update);
      }
      cout << words[i] << " - " << count << endl;
   } 
}


/*********************************************************************
* ** Function: word_arr()
** Description: creates a dynamically allocated array or c style strings
** Parameters: char* sentence
** Pre-conditionals: take a c style string
** Post-conditionals: none (prints result)
*********************************************************************/
void word_arr(char* sentence){
   char n[3];
   do{
      cout << "How many words will you search\nEnter a number 1-9: ";
      cin.getline(n, 3);
   }while(in_range(n,1,9) == 0);
   char** words = new char*[to_int(n)];
   for (int i = 0; i < to_int(n); i++){
      words[i] = new char[46];
      do{
         cout << "Enter word "<< i + 1 << ": ";
	 cin.getline(words[i], 46);
	 no_spaces(words[i]);
      }while(letters_present(words[i]) == 0);
   }
   find_words(sentence, words, to_int(n));
   for(int i = 0; i < to_int(n); i++)
      delete[] words[i];
   delete[] words;
}


int main(){

   char option1[3];
   char option2[3];
   char sentence[1024];

   do{
      do{
         cout << "\n\nWhat you like to test:\n\t1 - Whether the number of vowels and constants is equal\n\t2 - Whether or not it is a palindrome\n\t3 - Count the occurance of specified words within it\nEnter the number of your option: ";
         cin.getline(option1, 3);
      }while(in_range(option1,1,3) == 0);

      do{
         cout << "\n\nEnter the string that you would like to test (Max of 1023 characters): ";
         cin.getline(sentence, 1024);
      }while(letters_present(sentence) == 0);

cout<<sentence<<endl;
      if(option1[0] == '1')
         vows_cons(sentence);
      else if(option1[0] == '2')
         is_pal(sentence);
      else
	 word_arr(sentence);

cout<<sentence<<endl;
      cout << "\n\nWould you like to run another test?\n\t  1   - yes\n\tnot 1 - no\nEnter the number of your option: ";
      cin.getline(option2, 3);
   }while(in_range(option2,1,1) == 1);

   return 0;
}
