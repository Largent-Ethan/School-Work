#ifndef HAND_H
#define HAND_H


#include "./deck.h"
#include "./card.h"


#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


class Hand {
    private:
        Card* cards;
        int n_cards;
    public:
        Hand(Deck);
        ~Hand();
        Hand(const Hand&);
        Hand& operator= (const Hand&);
        void print();
};





#endif