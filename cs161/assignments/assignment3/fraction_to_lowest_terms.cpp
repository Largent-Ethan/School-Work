/*********************************************************************
* ** Project Name: fraction_to_lowest_terms.cpp
** Author: Ethan Largent
** Date: 25 Feb 2021
** Description: Simplifies a fraction into its lowest form
** Input: string numerator, string denominator
** Output: int numerator, int denominator (simplified)
*********************************************************************/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

/*********************************************************************
* ** Function: is_int()
** Description: checks if a string is also an integer
** Parameters: string str
** Pre-conditionals: take a string parameter
** Post-conditionals: return a bool signifying if it is an int or not
*********************************************************************/
bool is_int(string str){
   for(int i = 0; str[i] != '\0'; i++)
      if(int(str[i]) < 48 || int(str[i] > 57)){
	    cout << "Invalid Input, whole numbers only!" << endl;
	    return false;
	    }
   return true;
}

/*********************************************************************
* ** Function: get_int()
** Description: converts a string of numbers to an integer
** Parameters: string prompt
** Pre-conditionals: take a string parameter
** Post-conditionals: return an int equal to the literal value of the string
*********************************************************************/
int get_int(string prompt){
   int num = 0;
   for (int i = 0; prompt[i] != '\0'; i++)
	 num += ((int(prompt[i]) - 48) * pow(10, (prompt.length() - i - 1)));
   return num;
}

/*********************************************************************
* ** Function: g_c_d()
** Description: finds the greatest common factor for a pair of integers
** Parameters: integer num1, integer num2, integer num3
** Pre-conditionals: take a string parameter
** Post-conditionals: return an int representing the number in prompt
*********************************************************************/
int g_c_d(int num1, int num2, int num3 = 1){
   if(num2%num3 != 0 || num1%(num2/num3) != 0 || num2%(num2/num3) != 0)
      return g_c_d(num1, num2, num3 + 1);
   return (num2/num3);
}

/*********************************************************************
* ** Function: to_lowest_terms()
** Description: converts two numbers representing a fraction into
   their simplest form
** Parameters: int& numerator, int& denominator
** Pre-conditionals: takes the address of a int numerator and denominator
** Post-conditionals: return a bool thats false when the denominator is 0
*********************************************************************/
bool to_lowest_terms(int* numerator, int* denominator){
   if(*denominator == 0){
      cout << "Invalid Input, denominator cannot be 0!" << endl;
      return false;
   }
   int divisor = g_c_d(*numerator, *denominator);
   *numerator = *numerator / divisor;
   *denominator = *denominator / divisor;
   return true;
}

int main(){
   string num1, num2;
   int numerator, denominator;
   do{
      cout << "Enter your fraction\'s numerator: ";
      getline(cin, num1);
   }while(is_int(num1) == 0);
   numerator = get_int(num1);
   do{
      do{
         cout << "Enter your fraction\'s denominator: ";
         getline(cin, num2);
      }while(is_int(num2) == 0);
      denominator = get_int(num2);
   }while(to_lowest_terms(&numerator, &denominator) == 0);
   if(denominator == 1)
      cout << numerator << endl;
   else
      cout << numerator << "/" << denominator << endl;
   return 0;
}
