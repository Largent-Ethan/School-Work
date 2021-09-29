#ifndef DECK_H
#define DECK_H



#include "./card.h"


#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


class Deck{
    private:
        Card cards[52];
        int n_cards;
        void swap_cards(int, int);
    public:
        Deck();

        Card get_card(int);
        int get_n_cards();

        void set_card(int, Card);
        void set_n_cards(int);

        void print();
        void shuffle();
} ;







#endif