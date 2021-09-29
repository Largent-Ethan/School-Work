#ifndef ROOM_H
#define ROOM_H


#include "./event.h"
#include "./wumpus.h"
#include "./bats.h"
#include "./pit.h"
#include "./gold.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


class Room {

    private:

        bool has_event;
        Event* event;

    protected:

    public:

        Room();
        ~Room();

        void set_has_event(bool);
        
        void set_event(Event*);

        bool get_has_event();
        
        Event* get_event();
    
} ;


#endif