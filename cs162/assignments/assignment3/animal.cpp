#include "./animal.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


int Animal::get_price(){
    return price;
}

int Animal::get_age(){
    return age;
}

int Animal::get_hunger(){
    return hunger;
}

int Animal::get_litter_size(){
    return litter_size;
}

int Animal::get_revenue(){
    return revenue;
}

void Animal::set_price(int new_price){
    price = new_price;
}

void Animal::set_age(int new_age){
    age = new_age;
}

void Animal::set_hunger(int new_hunger){
    hunger = new_hunger;
}

void Animal::set_litter_size(int new_litter_size){
    litter_size = new_litter_size;
}

void Animal::set_revenue(int new_revenue){
    revenue = new_revenue;
}