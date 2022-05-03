#ifndef DECK_H
#define DECK_H


#include "./deck.h"
#include "./card.h"


#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


class Deck{
    private:
        Card cards[52];
        void swap_cards(int, int);
    public:
        Deck();

        Card get_card(int);

        void set_card(int, Card);

        void print();
        void shuffle();
} ;







#endif