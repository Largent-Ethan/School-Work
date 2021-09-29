#include "./event.h"
#include "./gold.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


Gold::Gold(){
    set_name("gold");
}

string Gold::percept(){
    return "You see a glimmer nearby. ";
}

string Gold::icon_top(){
    return " $ $ ";
}

string Gold::icon_bottom(){
    return " ῶῶῶ ";
}