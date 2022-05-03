#include "./date.h"


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;



int main(){

//Create 2 dates with different constructors
    Date default_date;
    Date todays_date(4, 27, 2021);


//Print both dates in a numerical format
    cout << "\n\nDefault date in regular print:\n";
    default_date.print();
    cout << "\nTodays date in regular print:\n";
    todays_date.print();


//Print both dates in a text format
    cout << "\n\nDefault date in fancier print:\n";
    default_date.fancier_print();
    cout << "\nTodays date in fancier print:\n";
    todays_date.fancier_print();
    cout << "\n" << endl;


    return 0;
}