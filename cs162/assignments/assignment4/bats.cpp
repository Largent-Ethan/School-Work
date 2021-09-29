#include "./event.h"
#include "./bats.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


Bats::Bats(){
    set_name("bats");
}

string Bats::percept(){
    return "You hear wings flapping. ";
}

string Bats::icon_top(){
    return " ^●^ ";
}

string Bats::icon_bottom(){
    return " ^●^ ";
}