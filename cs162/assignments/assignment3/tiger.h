#ifndef TIGER_H
#define TIGER_H

#include "./animal.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


class Tiger : public Animal {
    private:

    public:

/*********************************************************************
** Function: Tiger
** Description: creates a default tiger object
** Parameters: void
** Pre-Conditions: tiger is made
** Post-Conditions: void
*********************************************************************/
        Tiger();
        
/*********************************************************************
** Function: Tiger
** Description: creates a tiger object of a certain age
** Parameters: int
** Pre-Conditions: tiger is made, int given
** Post-Conditions: void
*********************************************************************/
        Tiger(int);
        
} ;

#endif