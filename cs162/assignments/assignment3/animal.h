#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;



class Animal {
    private:

    protected:
        int price;
        int age;
        int hunger;
        int litter_size;
        int revenue;

    public:
    
/*********************************************************************
** Function: get_price
** Description: returns the price of an animal
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: int
*********************************************************************/
        int get_price();
    
/*********************************************************************
** Function: get_age
** Description: returns the age of an animal
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: int
*********************************************************************/
        int get_age();
    
/*********************************************************************
** Function: get_hunger
** Description: returns the hunger of an animal
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: int
*********************************************************************/
        int get_hunger();
    
/*********************************************************************
** Function: get_litter_size
** Description: returns the litter size of an animal
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: int
*********************************************************************/
        int get_litter_size();
    
/*********************************************************************
** Function: get_revenue
** Description: returns the revenue of an animal
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: int
*********************************************************************/
        int get_revenue();
    
/*********************************************************************
** Function: set_price
** Description: changes the price of an animal
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: void
*********************************************************************/
        void set_price(int);
    
/*********************************************************************
** Function: set_age
** Description: changes the age of an animal
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: void
*********************************************************************/
        void set_age(int);
    
/*********************************************************************
** Function: set_hunger
** Description: changes the hunger of an animal
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: void
*********************************************************************/
        void set_hunger(int);
    
/*********************************************************************
** Function: set_litter_size
** Description: changes the litter size of an animal
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: void
*********************************************************************/
        void set_litter_size(int);
    
/*********************************************************************
** Function: set_revenue
** Description: changes the revenue of an animal
** Parameters: int
** Pre-Conditions: int
** Post-Conditions: void
*********************************************************************/
        void set_revenue(int);

} ;

#endif