#include "./event.h"
#include "./pit.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


Pit::Pit(){
    set_name("pit");
}

string Pit::percept(){
    return "You feel a breeze. ";
}

string Pit::icon_top(){
    return "     ";
}

string Pit::icon_bottom(){
    return "  Θ  ";
}