#ifndef BLACK_BEAR_H
#define BLACK_BEAR_H

#include "./animal.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


class Black_bear : public Animal {
    private:

    public:

/*********************************************************************
** Function: Black_bear
** Description: creates a default black bear object
** Parameters: void
** Pre-Conditions: black bear is made
** Post-Conditions: void
*********************************************************************/
        Black_bear();

/*********************************************************************
** Function: Black_bear
** Description: creates a black bear object of a certain age
** Parameters: int
** Pre-Conditions: black bear is made, int given
** Post-Conditions: void
*********************************************************************/
        Black_bear(int);
        
} ;

#endif