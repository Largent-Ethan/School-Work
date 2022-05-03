/******************************************************
** Program: driver.cpp (Linked lists)
** Author: Ethan Largent
** Date: 6 June 2021
** Description: A tested implementation of a linked list data structure
** Input: y or n, a or d, numbers for list
** Output: input prompts, information about list
******************************************************/
#include "./node.h"
#include "./linked_list.h"


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>


using namespace std;


int main(){
    string input = "y";
    while(input == "y"){
        Linked_list l1;
        cout << endl;

        while(input == "y"){
            cout << "Enter a number: ";
            getline(cin, input);
            l1.push_back(atoi(input.c_str()));
            cout << "Do you want to enter another num (y or n): ";
            getline(cin, input);
        }
        cout << endl;

        l1.print();
        cout << endl;

        cout << "Sort ascending or descending (a or d)?: ";
        getline(cin, input);
        if(input == "a")
            l1.sort_ascending(l1.get_head());
        else if(input == "d")
            l1.sort_descending(l1.get_head());
        l1.print();
        cout << endl;

        l1.print_primes();
        cout << endl;

        l1.clear();
        cout << "Do you want to do this again (y or n)?: ";
        getline(cin, input);
        cout << endl;
    }

    return 0;
}