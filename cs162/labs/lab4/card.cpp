#include "./card.h"



#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


Card::Card(){
    rank = 0;
    suit = 0;
}

Card::Card(int a, int b){
    set_rank(a);
    set_suit(b);
}

int Card::get_rank(){
    return rank;
}

int Card::get_suit(){
    return suit;
}

void Card::set_rank(int new_rank){
    rank = new_rank;
}

void Card::set_suit(int new_suit){
    suit = new_suit;
}

void Card::print(){
    cout << "c - s:" << suit << "r:" << rank << endl;
}