#ifndef PIT_H
#define PIT_H


#include "./event.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


class Pit : public Event{

    private:

    protected:

    public:

        Pit();

/*********************************************************************
** Function: percept
** Description: return the string printed when player is near pit
** Parameters: void
** Pre-Conditions: being printed or assigned to a string
** Post-Conditions: string
*********************************************************************/
        string percept();

/*********************************************************************
** Function: icon_top
** Description: return the string printed for top of pit
** Parameters: void
** Pre-Conditions: being printed or assigned to a string
** Post-Conditions: string
*********************************************************************/
        string icon_top();

/*********************************************************************
** Function: icon_bottom
** Description: return the string printed for bottom of pit
** Parameters: void
** Pre-Conditions: being printed or assigned to a string
** Post-Conditions: string
*********************************************************************/
        string icon_bottom();
        
} ;


#endif