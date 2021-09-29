#ifndef DOG_H
#define DOG_H

#include "./pet.h"


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>


using namespace std;


class Dog : public Pet{
    
    private:
        string breed;

    public:
        string get_breed();
        void set_breed(string);

} ;


#endif