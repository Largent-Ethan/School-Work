#ifndef WUMPUS_H
#define WUMPUS_H


#include "./event.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


class Wumpus : public Event{

    private:

    protected:

    public:

        Wumpus();

/*********************************************************************
** Function: percept
** Description: return the string printed when player is near wumpus
** Parameters: void
** Pre-Conditions: being printed or assigned to a string
** Post-Conditions: string
*********************************************************************/
        string percept();

/*********************************************************************
** Function: icon_top
** Description: return the string printed for top of wumpus
** Parameters: void
** Pre-Conditions: being printed or assigned to a string
** Post-Conditions: string
*********************************************************************/
        string icon_top();

/*********************************************************************
** Function: icon_bottom
** Description: return the string printed for bottom of wumpus
** Parameters: void
** Pre-Conditions: being printed or assigned to a string
** Post-Conditions: string
*********************************************************************/
        string icon_bottom();
    
} ;


#endif