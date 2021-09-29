#include <iostream>
#include "common_functions.h"

using namespace std;

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
