#include "./dog.h"
#include "./pet.h"




#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>


using namespace std;


string Dog::get_breed(){
    return breed;
}

void Dog::set_breed(string new_breed){
    breed = new_breed;
}

string Dog::getLifespan(){
    if(weight > 100)
        return "Approximately 7 years";
    return "Approximately 13 years";
}