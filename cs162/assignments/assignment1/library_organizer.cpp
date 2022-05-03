/*********************************************************************
** Program Filename: library_organizer.cpp
** Author: Ethan Largent
** Date: 11 April 2021
** Description: Allows you to organize correctly formatted data and
   store the results in the terminal or another file
** Input: string in a file
** Output: a string that can be appended to a file
*********************************************************************/

//Function headers are found in the header file mentioned in the line below
#include "library_organizer_imp.h"


#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char** argv){
    if(argc != 2){
        cout << "\nError | Invalid number of arguments\n" << endl;
        return 0;
    }

    ifstream input_file(argv[1], ios::in);

    if(input_file.fail()){
        cout << "\nError | File does not exist\n" << endl;
        return 0;
    }

    int num_books;
    input_file >> num_books;
    spellbook* library = create_spellbooks(num_books);
    get_spellbook_data(library, num_books, input_file);

    string output;

    while(1){ //If I put this in a function then it would make main() less lines, but it makes sense here to me
        string choice1 = pick_operation();
        if(choice1 == "1"){
            sort_by_pages(library, num_books);
            output = string_of_pages(library, num_books);
        }
        else if(choice1 == "2"){
            output = string_of_effects(library, num_books);
        }
        else if(choice1 == "3"){
            sort_avg_success_rate(library, num_books);
            output = string_of_avg_success_rate(library, num_books);
        }
        else {
            delete_spellbook_data(library, num_books);
            return 0;
        }
        bool valid_file = true;
        string choice2 = pick_ouput();
        if(choice2 == "1")
            output_to_terminal(output);
        if(choice2 == "2")
            valid_file = output_to_file(output);
        if(valid_file == false){
            delete_spellbook_data(library, num_books);
            return 0;
        }
    }
}