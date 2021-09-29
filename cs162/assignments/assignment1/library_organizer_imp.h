#ifndef LIBRARY_ORGANIZER_IMP_H
#define LIBRARY_ORGANIZER_IMP_H

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

struct spellbook {
  string title;
  string author;
  int num_pages;
  int edition;
  int num_spells;
  float avg_success_rate;
  struct spell* s;
};

struct spell {
  string name;
  float success_rate;
  string effect; 
};

/*********************************************************************
** Function: create_spellbooks
** Description: makes a dynamic array of size equal to the amount of
   books
** Parameters: int
** Pre-Conditions: int exists
** Post-Conditions: spellbook*
*********************************************************************/
spellbook* create_spellbooks(int); 

/*********************************************************************
** Function: get_spellbook_data
** Description: plugs in data from file into a struct and goes to other
   functions to fill in data not found in the file
** Parameters: spellbook*, int, ifstream&
** Pre-Conditions: spellbook*, int, and ifstream& exists
** Post-Conditions: void
*********************************************************************/
void get_spellbook_data(spellbook*, int, ifstream&);

/*********************************************************************
** Function: create_spells
** Description: makes a dynamic array of size equal to the amount of
   spells
** Parameters: int
** Pre-Conditions: int exists
** Post-Conditions: spell*
*********************************************************************/
spell* create_spells(int);

/*********************************************************************
** Function: get_spell_data
** Description: plugs in data from file into a struct
** Parameters: spellbook*, int, ifstream&
** Pre-Conditions: spellbook*, int, and ifstream& exist
** Post-Conditions: void
*********************************************************************/
void get_spell_data(spell*, int, ifstream&);

/*********************************************************************
** Function: get_average
** Description: find the average of an array of floats
** Parameters: spell*, int
** Pre-Conditions: spell* and int exists
** Post-Conditions: float
*********************************************************************/
float get_average(spell*, int);

/*********************************************************************
** Function: pick_operation
** Description: prompts user to pick an operation and reprompts after
   invalid input
** Parameters: void
** Pre-Conditions: none
** Post-Conditions: string
*********************************************************************/
string pick_operation();

/*********************************************************************
** Function: swap_spellbooks
** Description: swaps two items in an array
** Parameters: spellbook*, int, int
** Pre-Conditions: spellbook*, int, and int exists
** Post-Conditions: void
*********************************************************************/
void swap_spellbooks(spellbook*, int, int);

/*********************************************************************
** Function: sort_by_pages
** Description: sorts books by number of pages in decending order
** Parameters: spellbook*, int
** Pre-Conditions: spellbook* and int exists
** Post-Conditions: void
*********************************************************************/
void sort_by_pages(spellbook*, int);

/*********************************************************************
** Function: string_of_pages
** Description: puts each book and its page number into a string
** Parameters: spellbook*, int
** Pre-Conditions: spellbook* and int exists
** Post-Conditions: string
*********************************************************************/
string string_of_pages(spellbook*, int);

/*********************************************************************
** Function: sort_by_effect
** Description: puts the current spell into the string
** Parameters: string*, string, string
** Pre-Conditions: string*, string, and string exists
** Post-Conditions: void
*********************************************************************/
void sort_by_effect(string*, string, string);

/*********************************************************************
** Function: string_of_effects
** Description: puts each spell and its effect into a string 
** Parameters: spellbook*, int
** Pre-Conditions: spellbook* and int exists
** Post-Conditions: string
*********************************************************************/
string string_of_effects(spellbook*, int);

/*********************************************************************
** Function: sort_avg_success_rate
** Description: sorts books by avergae success rate in ascending order
** Parameters: spellbook*, int
** Pre-Conditions: spellbook* and int exists
** Post-Conditions: void
*********************************************************************/
void sort_avg_success_rate(spellbook*, int);

/*********************************************************************
** Function: string_of_avg_success_rate
** Description: puts each book and its average success rate into a string
** Parameters: spellbook*, int
** Pre-Conditions: spellbook* and int exists
** Post-Conditions: string
*********************************************************************/
string string_of_avg_success_rate(spellbook*, int);

/*********************************************************************
** Function: pick_ouput
** Description: prompts the user to pick an output method and reprompts
   after invalid input
** Parameters: void
** Pre-Conditions: none
** Post-Conditions: string
*********************************************************************/
string pick_ouput();

/*********************************************************************
** Function: output_to_terminal
** Description: takes a string and outputs it to the terminal
** Parameters: string
** Pre-Conditions: string exists
** Post-Conditions: void
*********************************************************************/
void output_to_terminal(string);

/*********************************************************************
** Function: output_to_file
** Description: takes a string and outputs it to a file
** Parameters: string
** Pre-Conditions: string exists
** Post-Conditions: bool
*********************************************************************/
bool output_to_file(string);

/*********************************************************************
** Function: delete_spellbook_data
** Description: deletes all dynamic arrays in the array of books
** Parameters: spellbook*, int
** Pre-Conditions: spellbook* and int exist
** Post-Conditions: void
*********************************************************************/
void delete_spellbook_data(spellbook*, int); 

#endif