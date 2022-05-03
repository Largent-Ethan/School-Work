#include "./tiger.h"
#include "./animal.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


Tiger::Tiger(){
    set_price(10000);
    set_age(0);
    set_hunger(5);
    set_litter_size(3);
    set_revenue(1000);
}

Tiger::Tiger(int starting_age){
    set_price(10000);
    set_age(starting_age);
    set_hunger(5);
    set_litter_size(3);
    set_revenue(1000);
}