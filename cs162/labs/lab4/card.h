#ifndef CARD_H
#define CARD_H


#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


class Card{
    private:
        int rank;  // Should be in the range 0-12.
        int suit;  // Should be in the range 0-3.
    public:
        Card();
        Card(int, int);

        int get_rank();
        int get_suit();

        void set_rank(int);
        void set_suit(int);

        void print();
} ;







#endif