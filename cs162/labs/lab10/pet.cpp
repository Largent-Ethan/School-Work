#include "./pet.h"





#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>


using namespace std;

string Pet::get_name(){
    return name;
}

void Pet::set_name(string new_name){
    name = new_name;
}

int Pet::get_weight(){
    return weight;
}

void Pet::set_weight(int new_weight){
    weight = new_weight;
}

string Pet::getLifespan(){
    return "unknown lifespan";
}