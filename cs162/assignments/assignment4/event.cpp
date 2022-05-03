#include "./event.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


Event::Event(){
    set_name("");
}

Event::Event(const Event& existing_event){
    this -> name = existing_event.name;
}

Event& Event::operator=(const Event& existing_event){
    this -> name = existing_event.name;
    return *this;
}

void Event::set_name(string new_name){
    name = new_name;
}

string Event::get_name(){
    return name;
}
