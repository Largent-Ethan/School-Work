#ifndef SEA_LION_H
#define SEA_LION_H

#include "./animal.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


class Sea_lion : public Animal {
    private:

    public:

/*********************************************************************
** Function: Sea_lion
** Description: creates a default sea lion object
** Parameters: void
** Pre-Conditions: sea lion is made
** Post-Conditions: void
*********************************************************************/
        Sea_lion();
        
/*********************************************************************
** Function: Sea_lion
** Description: creates a sea lion object of a certain age
** Parameters: int
** Pre-Conditions: sea lion is made, int given
** Post-Conditions: void
*********************************************************************/
        Sea_lion(int);

} ;

#endif