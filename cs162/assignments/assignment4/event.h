#ifndef EVENT_H
#define EVENT_H


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


class Event {

    private:

    protected:
        
        string name;

    public:

        Event();

        Event(const Event&);

        Event& operator=(const Event&);

        virtual void set_name(string) final;

        virtual string get_name() final;

/*********************************************************************
** Function: percept
** Description: return the string printed when player is near event
** Parameters: void
** Pre-Conditions: being printed or assigned to a string
** Post-Conditions: string
*********************************************************************/
        virtual string percept() = 0;

/*********************************************************************
** Function: icon_top
** Description: return the string printed for top of event
** Parameters: void
** Pre-Conditions: being printed or assigned to a string
** Post-Conditions: string
*********************************************************************/
        virtual string icon_top() = 0;

/*********************************************************************
** Function: icon_bottom
** Description: return the string printed for bottom of event
** Parameters: void
** Pre-Conditions: being printed or assigned to a string
** Post-Conditions: string
*********************************************************************/
        virtual string icon_bottom() = 0;

} ;


#endif