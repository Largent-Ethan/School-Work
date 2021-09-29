/**********************************************************************
* ** Program: assignment2.cpp
** Author: Ethan Largent
** Date: 2/11/2021
** Description: A library of functions that can be used to test for
   different qualities of a given type of input
** Input: None (test values of functions are given)
** Output: The desired and actual outputs of each function
**********************************************************************/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


/*********************************************************************
* ** Function: check_range()
** Description: checks if a given integer is within a given range
** Parameters: int test_value, int lower_bound, int upper_bound
** Pre-conditionals: takes integer parameters
** Post-conditionals: return a bool to tell if the test_value is in range of lower and upper bound
*********************************************************************/
bool check_range(int lower_bound, int test_value, int upper_bound){
   if (lower_bound <= test_value <= upper_bound)
      return true;
   return false;
}


/*********************************************************************
* ** Function: is_capital()
** Description: checks if a given character is capital
** Parameters: char letter
** Pre-conditionals: takes an character parameter
** Post-conditionals: return a bool to tell if letter is capital
*********************************************************************/
bool is_capital(char letter){
   if (64 < int(letter) && int(letter) < 91)
      return true;
   return false;
}


/*********************************************************************
* ** Function: is_even()
** Description: checks if a given integer is even
** Parameters: int num
** Pre-conditionals: takes an int parameter
** Post-conditionals: return a bool to tell if num is even
*********************************************************************/
bool is_even(int num){
   if (num % 2 == 0)
      return true;
   return false;
}


/*********************************************************************
* ** Function: is_odd()
** Description: checks if a given integer is odd
** Parameters: int num
** Pre-conditionals: takes an int parameter
** Post-conditionals: return a bool to tell if num is odd
*********************************************************************/
bool is_odd(int num){
   if (num % 2 == 1)
      return true;
   return false;
}


/*********************************************************************
* ** Function: equality_test()
** Description: checks which of 2 given integers is greater
** Parameters: int num1, int num2
** Pre-conditionals: takes int parameters
** Post-conditionals: return an int to tell if num1 or num2 is greater, or equal
*********************************************************************/
int equality_test(int num1, int num2){
   if (num1 > num2)
      return 1;
   if (num2 > num1)
      return -1;
   return 0;
}


/*********************************************************************
* ** Function: float_is_equal()
** Description: checks if 2 given floats are equal to a cerain precision
** Parameters: float num1, float num2, float precision
** Pre-conditionals: takes float parameters
** Post-conditionals: return a bool to tell if float1 and float2 are equal enough
*********************************************************************/
bool float_is_equal(float num1, float num2, float precision){
   if (((num1 + num2) / 2 <= precision + num2) && ((num1 + num2) / 2 <= precision + num1))
      return true;
   return false;
}


/*********************************************************************
* ** Function: is_int()
** Description: checks if a given string is an integer
** Parameters: string num
** Pre-conditionals: take a string parameter
** Post-conditionals: return a bool to tell if num is an int
*********************************************************************/
bool is_int(string num){
   for (int i = 0; i < num.length(); i++)
      if (!(47 < int(num[i]) && int(num[i]) < 58))
	 return false;
   return true;
}


/*********************************************************************
* ** Function: numbers_present()
** Description: checks if numbers are in a given string
** Parameters: string sentence
** Pre-conditionals: take a string parameter
** Post-conditionals: return a bool to tell if sentence has numbers in it
*********************************************************************/
bool numbers_present(string sentence){
   for (int i = 0; i < sentence.length(); i++)
      if (47 < int(sentence[i]) && int(sentence[i]) < 58)
	 return true;
   return false;
}


/*********************************************************************
* ** Function: letters_present()
** Description: checks if letters are in a given string
** Parameters: string sentence
** Pre-conditionals: take a string parameter
** Post-conditionals: return a bool to tell if sentence has letteres in it
*********************************************************************/
bool letters_present(string sentence){
   for (int i = 0; i < sentence.length(); i++)
      if ((64 < int(sentence[i]) && int(sentence[i]) < 91) || (96 < int(sentence[i]) && int(sentence[i]) < 123))
	 return true;
   return false;
}


/*********************************************************************
* ** Function: contains_sub_string()
** Description: checks if a given string is present inside a given string
** Parameters: string sub_string, string sentence
** Pre-conditionals: take string parameters
** Post-conditionals: return a bool to tell if sub_string is within sentence
*********************************************************************/
bool contains_sub_string(string sub_string, string sentence){
   for (int i = 0; i < sentence.length(); i++)
      if (sentence[i] == sub_string[0]){
	 for (int j=1; j < sub_string.length(); j++){
	    if (sentence[i+j] != sub_string[j])
	       break;
	    if (j == (sub_string.length() - 1))
	       return true;
	 }
      }
   return false;
}


/*********************************************************************
* ** Function: word_count()
** Description: counts the amount of words in a given string
** Parameters: string sentence
** Pre-conditionals: take a string parameter
** Post-conditionals: return an int representing the number of words in sentence
*********************************************************************/
int word_count(string sentence){
   int count = 0;
   for (int i = 0; (i < sentence.length() - 1); i++)
      if (sentence[i] != ' ' && sentence[i + 1] == ' ')
	 count += 1;
   if (sentence[sentence.length() - 1] != ' ')
      count += 1;
   return count;
}


/*********************************************************************
* ** Function: to_upper()
** Description: changes all lowercase letters in a string to capitals
** Parameters: string senetence
** Pre-conditionals: take a string parameter
** Post-conditionals: return a string similar to sentence but all letters are capital
*********************************************************************/
string to_upper(string sentence){
   string upper_sentence;
   for (int i = 0; i < sentence.length(); i++){
      if (96 < int(sentence[i]) && int(sentence[i]) < 123)
	 upper_sentence += char(int(sentence[i])-32);
      else
	 upper_sentence += sentence[i];
   }
   return upper_sentence;
}


/*********************************************************************
* ** Function: to_lower()
** Description: changes all capital letters in a string to lowercase
** Parameters: string sentence
** Pre-conditionals: take a string parameter
** Post-conditionals: return a string similar to sentence but all letteres are lowercase
*********************************************************************/
string to_lower(string sentence){
   string lower_sentence;
   for (int i = 0; i < sentence.length(); i++){
      if (64 < int(sentence[i]) && int(sentence[i]) < 91)
	 lower_sentence += char(int(sentence[i]) + 32);
      else
	 lower_sentence += sentence[i];
   }
   return lower_sentence;
}


/*********************************************************************
* ** Function: get_int()
** Description: gets the integer value of a string containing only numbers
   (if there are other characters, it will return 0)
** Parameters: string prompt
** Pre-conditionals: take a string parameter
** Post-conditionals: return an int representing the number in prompt
*********************************************************************/
int get_int(string prompt){
   int num = 0;
   for (int i = 0;i < prompt.length(); i++){
      if (!(47 < int(prompt[i]) && int(prompt[i]) < 58))
	 return 0;
      else
	 num += ((int(prompt[i]) - 48) * pow(10, (prompt.length() - i - 1)));
   }
   return num;
}


int main(){
//Testing check_range()
   cout << "\nTesting check_range(1,2,3)...\n";
   cout << "Expected: 1";
   cout << "\tActual: " << check_range(1,2,3);
   (check_range(1,2,3)==1)? cout << "\tPASSED\n" : cout <<"\tFAILED\n";

   cout << "\nTesting check_range(8,2,-4)...\n";
   cout << "Expected: 0";
   cout << "\tActual: " << check_range(8,2,-4);
   (check_range(8,2,-4==0))? cout << "\tPASSED\n" : cout <<"\tFAILED\n";
//Testing is_capital()
   cout << "\nTesting is_capital(\'P\')...\n";
   cout << "Expected: 1";
   cout << "\tActual: " << is_capital('P');
   (is_capital('P')==1)? cout << "\tPASSED\n" : cout <<"\tFAILED\n";

   cout << "\nTesting is_capital(\'f\')...\n";
   cout << "Expected: 0";
   cout << "\tActual: " << is_capital('f');
   (is_capital('f')==0)? cout << "\tPASSED\n" : cout <<"\tFAILED\n";
//Testing is_even()
   cout << "\nTesting is_even(4)...\n";
   cout << "Expected: 1";
   cout << "\tActual: " << is_even(4);
   (is_even(4)==1)? cout << "\tPASSED\n" : cout <<"\tFAILED\n";

   cout << "\nTesting is_even(3)...\n";
   cout << "Expected: 0";
   cout << "\tActual: " << is_even(3);
   (is_even(3)==0)? cout << "\tPASSED\n" : cout <<"\tFAILED\n";
//Testing is odd()
   cout << "\nTesting is_odd(3)...\n";
   cout << "Expected: 1";
   cout << "\tActual: " << is_odd(3);
   (is_odd(3)==1)? cout << "\tPASSED\n" : cout <<"\tFAILED\n";

   cout << "\nTesting is_odd(4)...\n";
   cout << "Expected: 0";
   cout << "\tActual: " << is_odd(4);
   (is_odd(4)==0)? cout << "\tPASSED\n" : cout <<"\tFAILED\n";
//Testing equality_test()
   cout << "\nTesting equality_test(1,2)...\n";
   cout << "Expected: -1";
   cout << "\tActual: " << equality_test(1,2);
   (equality_test(1,2)==-1)? cout << "\tPASSED\n" : cout <<"\tFAILED\n";

   cout << "\nTesting equality_test(2,1)...\n";
   cout << "Expected: 1";
   cout << "\tActual: " << equality_test(2,1);
   (equality_test(2,1)==1)? cout << "\tPASSED\n" : cout <<"\tFAILED\n";

   cout << "\nTesting equality_test(1,1)...\n";
   cout << "Expected: 0";
   cout << "\tActual: " << equality_test(1,1);
   (equality_test(1,1)==0)? cout << "\tPASSED\n" : cout <<"\tFAILED\n";
//Testing float_is_equal()
   cout << "\nTesting float_is_equal(3.14152,3.14155,0.0001)...\n";
   cout << "Expected: 1";
   cout << "\tActual: " << float_is_equal(3.14152,3.14155,0.0001);
   (float_is_equal(3.14152,3.14155,0.0001)==1)? cout << "\tPASSED\n" : cout <<"\tFAILED\n";

   cout << "\nTesting float_is_equal(3.14152,3.14155,0.00001)...\n";
   cout << "Expected: 0";
   cout << "\tActual: " << float_is_equal(3.14152,3.14155,0.00001);
   (float_is_equal(3.13152,3.14155,0.00001)==0)? cout << "\tPASSED\n" : cout <<"\tFAILED\n";
//Testing is_int()
   cout << "\nTesting is_int(\"123\")...\n";
   cout << "Expected: 1";
   cout << "\tActual: " << is_int("123");
   (is_int("123")==1)? cout << "\tPASSED\n" : cout <<"\tFAILED\n";

   cout << "\nTesting is_int(\"1a2b34\")...\n";
   cout << "Expected: 0";
   cout << "\tActual: " << is_int("1a2b34");
   (is_int("1a2b34")==0)? cout << "\tPASSED\n" : cout <<"\tFAILED\n";
//Testing numbers_present()
   cout << "\nTesting numbers_present(\"1 thing\")...\n";
   cout << "Expected: 1";
   cout << "\tActual: " << numbers_present("1 thing");
   (numbers_present("1 thing")==1)? cout << "\tPASSED\n" : cout <<"\tFAILED\n";

   cout << "\nTesting numbers_present(\"one thing\")...\n";
   cout << "Expected: 0";
   cout << "\tActual: " << numbers_present("one thing");
   (numbers_present("one thing")==0)? cout << "\tPASSED\n" : cout <<"\tFAILED\n";
//Testing letters_present()
   cout << "\nTesting letters_present(\"5 dollars\")...\n";
   cout << "Expected: 1";
   cout << "\tActual: " << letters_present("5 dollars");
   (letters_present("5 dollars")==1)? cout << "\tPASSED\n" : cout <<"\tFAILED\n";

   cout << "\nTesting letters_present(\"$5.00\")...\n";
   cout << "Expected: 0";
   cout << "\tActual: " << letters_present("$5.00");
   (letters_present("$5.00")==0)? cout << "\tPASSED\n" : cout <<"\tFAILED\n";
//Testing contains_sub_string()
   cout << "\nTesting contains_sub_string(\"fun\",\"functions\")...\n";
   cout << "Expected: 1";
   cout << "\tActual: " << contains_sub_string("fun","functions");
   (contains_sub_string("fun","functions")==1)? cout << "\tPASSED\n" : cout <<"\tFAILED\n";

   cout << "\nTesting contains_sub_string(\"funny\",\"functions\")...\n";
   cout << "Expected: 0";
   cout << "\tActual: " << contains_sub_string("funny","functions");
   (contains_sub_string("funny","functions")==0)? cout << "\tPASSED\n" : cout <<"\tFAILED\n";
//Testing word_count()
   cout << "\nTesting word_count(\"This sentence is 9 words including symbols & numbers\")...\n";
   cout << "Expected: 9";
   cout << "\tActual: " << word_count("This sentence is 9 words including symbols & numbers");
   (word_count("This sentence is 9 words including symbols & numbers")==9)? cout << "\tPASSED\n" : cout <<"\tFAILED\n";
//Testing to_upper()
   cout << "\nTesting to_upper(\"I am at 100% volume\")...\n";
   cout << "Expected: I AM AT 100% VOLUME";
   cout << "\tActual: " << to_upper("I am at 100% volume");
   (to_upper("I am at 100% volume")=="I AM AT 100% VOLUME")? cout << "\tPASSED\n" : cout <<"\tFAILED\n";
//Testing to_lower()
   cout << "\nTesting to_lower(\"My Volume Is At 0%\")...\n";
   cout << "Expected: my volume is at 0%";
   cout << "\tActual: " << to_lower("My Volume Is At 0%");
   (to_lower("My Volume Is At 0%")=="my volume is at 0%")? cout << "\tPASSED\n" : cout <<"\tFAILED\n";
//Testing get_int()
   cout << "\nTesting get_int(\"123456\")...\n";
   cout << "Expected: 123456";
   cout << "\tActual: " << get_int("123456");
   (get_int("123456")==123456)? cout << "\tPASSED\n" : cout <<"\tFAILED\n";

   cout << "\nTesting get_int(\"1234s6\")...\n";
   cout << "Expected: 0";
   cout << "\tActual: " << get_int("1234s6");
   (get_int("1234s6")==0)? cout << "\tPASSED\n" : cout <<"\tFAILED\n";

}
