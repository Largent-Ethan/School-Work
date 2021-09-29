#include "./room.h"
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


Room::Room(){
    set_has_event(false);
    set_event(NULL);
}

Room::~Room(){
    delete event;
}

void Room::set_has_event(bool newhas_event){
    has_event = newhas_event;
}

void Room::set_event(Event* newevent){
    delete event;
    event = newevent;
}

bool Room::get_has_event(){
    return has_event;
}

Event* Room::get_event(){
    return event;
}
