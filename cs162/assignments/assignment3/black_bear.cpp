#include "./black_bear.h"
#include "./animal.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


Black_bear::Black_bear(){
    set_price(5000);
    set_age(0);
    set_hunger(3);
    set_litter_size(2);
    set_revenue(500);
}
        
Black_bear::Black_bear(int starting_age){
    set_price(5000);
    set_age(starting_age);
    set_hunger(3);
    set_litter_size(2);
    set_revenue(500);
}