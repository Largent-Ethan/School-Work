#ifndef ZOO_H
#define ZOO_H

#include "./animal.h"
#include "./sea_lion.h"
#include "./tiger.h"
#include "./black_bear.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;



class Zoo {
    private:
        int month;
        int year;
        string zoo_name;
        int food_price;
        int food_mod;
        int bank;
        int num_animals;
        int num_sea_lions;
        int num_tigers;
        int num_black_bears;
        Sea_lion* sea_lion_pen;
        Tiger* tiger_pen;
        Black_bear* black_bear_pen;
        char trash;
    public:

    
/*********************************************************************
** Function: Zoo
** Description: creates a default zoo object
** Parameters: void
** Pre-Conditions: zoo is made
** Post-Conditions: void
*********************************************************************/
        Zoo();
    
/*********************************************************************
** Function: ~Zoo
** Description: deletes a default zoo object
** Parameters: void
** Pre-Conditions: zoo is destroyed
** Post-Conditions: void
*********************************************************************/
        ~Zoo();
    
/*********************************************************************
** Function: get_month
** Description: returns the month of a zoo
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: int
*********************************************************************/
        int get_month();
    
/*********************************************************************
** Function: get_year
** Description: returns the year of a zoo
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: int
*********************************************************************/
        int get_year();
    
/*********************************************************************
** Function: get_zoo_name
** Description: returns the name of a zoo
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: string
*********************************************************************/
        string get_zoo_name();
    
/*********************************************************************
** Function: get_food_price
** Description: returns the food price of a zoo
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: int
*********************************************************************/
        int get_food_price();
    
/*********************************************************************
** Function: get_food_mod
** Description: returns the food mod of a zoo
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: int
*********************************************************************/
        int get_food_mod();
    
/*********************************************************************
** Function: get_bank
** Description: returns the bank of a zoo
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: int
*********************************************************************/
        int get_bank();
    
/*********************************************************************
** Function: get_num_animals
** Description: returns the number of animals in a zoo
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: int
*********************************************************************/
        int get_num_animals();
    
/*********************************************************************
** Function: get_num_sea_lions
** Description: returns the number of sea lions in a zoo
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: int
*********************************************************************/
        int get_num_sea_lions();
    
/*********************************************************************
** Function: get_num_tigers
** Description: returns the number of tigers in a zoo
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: int
*********************************************************************/
        int get_num_tigers();
    
/*********************************************************************
** Function: get_num_black_bears
** Description: returns the number of black bears in a zoo
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: int
*********************************************************************/
        int get_num_black_bears();
    
/*********************************************************************
** Function: set_month
** Description: changes the month of a zoo
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: void
*********************************************************************/
        void set_month(int);
    
/*********************************************************************
** Function: set_year
** Description: changes the year of a zoo
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: void
*********************************************************************/
        void set_year(int);
    
/*********************************************************************
** Function: set_zoo_name
** Description: changes the name of a zoo
** Parameters: string
** Pre-Conditions: string
** Post-Conditions: void
*********************************************************************/
        void set_zoo_name(string);
    
/*********************************************************************
** Function: set_food_price
** Description: changes the food price of a zoo
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: void
*********************************************************************/
        void set_food_price(int);
    
/*********************************************************************
** Function: set_food_mod
** Description: changes the food mod of a zoo
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: void
*********************************************************************/
        void set_food_mod(int);
    
/*********************************************************************
** Function: set_bank
** Description: changes the bank of a zoo
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: void
*********************************************************************/
        void set_bank(int);
    
/*********************************************************************
** Function: set_num_animals
** Description: changes the number of animals in a zoo
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: void
*********************************************************************/
        void set_num_animals(int);
    
/*********************************************************************
** Function: set_num_sea_lions
** Description: changes the number of sea lions in a zoo
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: void
*********************************************************************/
        void set_num_sea_lions(int);
    
/*********************************************************************
** Function: set_num_tigers
** Description: changes the number of tigers in a zoo
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: void
*********************************************************************/
        void set_num_tigers(int);
    
/*********************************************************************
** Function: set_num_black_bears
** Description: changes the number of black bears in a zoo
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: void
*********************************************************************/
        void set_num_black_bears(int);

/*********************************************************************
** Function: add_sea_lion
** Description: adds a number of sea lions of a specific age to a
                dynamic array of sea lions
** Parameters: int int
** Pre-Conditions: two ints
** Post-Conditions: void
*********************************************************************/
        void add_sea_lion(int, int);
    
/*********************************************************************
** Function: add_tiger
** Description: adds a number of tigers of a specific age to a
                dynamic array of tigers
** Parameters: int int
** Pre-Conditions: two ints
** Post-Conditions: void
*********************************************************************/
        void add_tiger(int, int);
    
/*********************************************************************
** Function: add_black_bear
** Description: adds a number of black bears of a specific age to a
                dynamic array of black bears
** Parameters: int int
** Pre-Conditions: two ints
** Post-Conditions: void
*********************************************************************/
        void add_black_bear(int, int);
    
/*********************************************************************
** Function: remove_sea_lion
** Description: removes a specfied sea lion from a dynamic array of sea lions
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: void
*********************************************************************/
        void remove_sea_lion(int);
    
/*********************************************************************
** Function: remove_tiger
** Description: removes a specfied tiger from a dynamic array of tigers
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: void
*********************************************************************/
        void remove_tiger(int);
    
/*********************************************************************
** Function: remove_black_bear
** Description: removes a specfied black_bear from a dynamic array of black_bears
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: void
*********************************************************************/
        void remove_black_bear(int);
    
/*********************************************************************
** Function: one_month_passes
** Description: ages all elements of the zoo by 1 month
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void one_month_passes();
    
/*********************************************************************
** Function: determine_event
** Description: randomizes an event to occur
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void determine_event();
    
/*********************************************************************
** Function: generate_money
** Description: revenue from each animal is added to the zoos bank
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        int generate_money();
    
/*********************************************************************
** Function: buy_animals
** Description: player is prompted to buy 0 to 2 animals of a single species
                the animals are added and are 48 months old
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void buy_animals();
    
/*********************************************************************
** Function: buy_food
** Description: player is prompted to choose what food to buy
                the food chosen affects the chances of a sickness event
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void buy_food();
    
/*********************************************************************
** Function: keep_playing
** Description: player is prompted to continue to the next month or not
                returns true if the player want to keep playing
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: bool
*********************************************************************/
        bool keep_playing();   
 
/*********************************************************************
** Function: sickness
** Description: a random animal from a random species falls ill
                the money required for medicine is deducted from the bank
                if bank is too low the animal is removed from the array(dies)
                money required varies
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void sickness();
    
/*********************************************************************
** Function: birth
** Description: an adult animal from a random species gives birth
                an animal of that species of age 0 is added to array
                single animals can give birth
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void birth();
    
/*********************************************************************
** Function: attendance_boom
** Description: all sea lions produce 150 to 400 more revenue
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void attendance_boom();
    
/*********************************************************************
** Function: reset_boom
** Description: all sea lions get their revenue set to 160
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void reset_boom();
    
/*********************************************************************
** Function: gen_rand_num
** Description: generates a random integer between two given integers
** Parameters: int int
** Pre-Conditions: two ints
** Post-Conditions: int
*********************************************************************/
        int gen_rand_num(int, int);
    
/*********************************************************************
** Function: print_month
** Description: returns a string of spaces needed after a month
                to be 9 characters long
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: string
*********************************************************************/
        string print_month();
    
/*********************************************************************
** Function: print_n_sea_lions
** Description: returns a string of spaces needed before the number of sea lions
                to be 3 characters long
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: string
*********************************************************************/
        string print_n_sea_lions();
    
/*********************************************************************
** Function: print_n_tigers
** Description: returns a string of spaces needed before the number of tigers
                to be 3 characters long
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: string
*********************************************************************/
        string print_n_tigers();
    
/*********************************************************************
** Function: print_n_black_bears
** Description: returns a string of spaces needed before the number of black bears
                to be 3 characters long
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: string
*********************************************************************/
        string print_n_black_bears();
    
/*********************************************************************
** Function: print_bank
** Description: returns a string of spaces needed before the bank
                to be 10 characters long
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: string
*********************************************************************/
        string print_bank();
    
/*********************************************************************
** Function: print_food_price
** Description: returns a string of spaces needed before the food price
                to be 10 characters long
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: string
*********************************************************************/
        string print_food_price();
    
/*********************************************************************
** Function: print_zoo_name
** Description: returns the zoo name with an equal amount of spaces on each side
                so that it is 36 characters long
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: string
*********************************************************************/
        string print_zoo_name();
    
/*********************************************************************
** Function: print_open
** Description: prints a home screen for when the game opens
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void print_open();
    
/*********************************************************************
** Function: print_game
** Description: prints information about the zoo in an appealing format
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void print_game();
    
/*********************************************************************
** Function: print_close
** Description: prints a game over screen for when the game closes
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void print_close();

} ;

#endif