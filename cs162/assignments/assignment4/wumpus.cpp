#include "./event.h"
#include "./wumpus.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


Wumpus::Wumpus(){
    set_name("wumpus");
}

string Wumpus::percept(){
    return "You smell a terrible stench. ";
}

string Wumpus::icon_top(){
    return " bФd ";
}

string Wumpus::icon_bottom(){
    return " \\Ж/ ";
}