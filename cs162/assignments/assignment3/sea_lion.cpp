#include "./sea_lion.h"
#include "./animal.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


Sea_lion::Sea_lion(){
    set_price(800);
    set_age(0);
    set_hunger(1);
    set_litter_size(1);
    set_revenue(160);
}

Sea_lion::Sea_lion(int starting_age){
    set_price(800);
    set_age(starting_age);
    set_hunger(1);
    set_litter_size(1);
    set_revenue(160);
}