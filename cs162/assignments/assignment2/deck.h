#ifndef DECK_H
#define DECK_H


#include "./card.h"





#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


class Deck {
    private:

        Card cards[52];
        int n_cards;

    public:

/*********************************************************************
** Function: Deck()
** Description: makes a static array deck of 52 cards
** Parameters: void
** Pre-Conditions: deck is created
** Post-Conditions: void
*********************************************************************/
        Deck();

/*********************************************************************
** Function: set_card()
** Description: sets a card of a deck
** Parameters: int, Card
** Pre-Conditions: int and Card exists
** Post-Conditions: void
*********************************************************************/
        void set_card(int, Card);

/*********************************************************************
** Function: set_n_cards()
** Description: sets the n_cards of a deck
** Parameters: int
** Pre-Conditions: int exists
** Post-Conditions: void
*********************************************************************/
        void set_n_cards(int);
        
/*********************************************************************
** Function: get_card()
** Description: gets a card of a deck
** Parameters: int
** Pre-Conditions: int exists
** Post-Conditions: Card
*********************************************************************/
        Card get_card(int);

/*********************************************************************
** Function: get_n_cards()
** Description: gets the n_cards of a deck
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: int
*********************************************************************/
        int get_n_cards();

/*********************************************************************
** Function: shuffle()
** Description: shuffles the cards in a deck
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void shuffle();

/*********************************************************************
** Function: swap_cards()
** Description: swaps 2 cards in a deck
** Parameters: int, int
** Pre-Conditions: ints exists
** Post-Conditions: void
*********************************************************************/
        void swap_cards(int, int);

/*********************************************************************
** Function: draw_card()
** Description: returns the top card of a deck and lowers n_cards
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: Card
*********************************************************************/
        Card draw_card();

/*********************************************************************
** Function: print()
** Description: prints the deck in a minimal format
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void print();
} ;





#endif