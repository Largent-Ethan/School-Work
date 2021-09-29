#ifndef HAND_H
#define HAND_H


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
    
/*********************************************************************
** Function: Hand()
** Description: makes a dynamic array hand with 0 cards of size 0
** Parameters: void
** Pre-Conditions: hand is created
** Post-Conditions: void
*********************************************************************/
        Hand();

/*********************************************************************
** Function: ~Hand()
** Description: deletes a a dynamic array hand
** Parameters: void
** Pre-Conditions: hand is deleted
** Post-Conditions: void
*********************************************************************/
        ~Hand();

/*********************************************************************
** Function: Hand()
** Description: copies an old hand to a new hand
** Parameters: void
** Pre-Conditions: hand is created equal to a hand
** Post-Conditions: void
*********************************************************************/
        Hand(const Hand&);

/*********************************************************************
** Function: operator=()
** Description: copies an old hand to a old hand
** Parameters: void
** Pre-Conditions: hand is set to hand
** Post-Conditions: void
*********************************************************************/
        Hand& operator= (const Hand&);

/*********************************************************************
** Function: set_card()
** Description: sets a card of a hand
** Parameters: int, Card
** Pre-Conditions: int and Card exists
** Post-Conditions: void
*********************************************************************/
        void set_card(int, Card);

/*********************************************************************
** Function: set_n_cards()
** Description: sets the n_cards of a hand
** Parameters: int
** Pre-Conditions: int exists
** Post-Conditions: void
*********************************************************************/
        void set_n_cards(int);

/*********************************************************************
** Function: get_card()
** Description: gets a card of a hand
** Parameters: int
** Pre-Conditions: int exists
** Post-Conditions: Card
*********************************************************************/
        Card get_card(int);

/*********************************************************************
** Function: get_n_cards()
** Description: gets the n_cards of a hand
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: int
*********************************************************************/
        int get_n_cards();

/*********************************************************************
** Function: add_card()
** Description: makes the dynamic array hand one bigger and adds card
** Parameters: Card
** Pre-Conditions: Card exists
** Post-Conditions: void
*********************************************************************/
        void add_card(Card);

/*********************************************************************
** Function: play_card()
** Description: makes the dynamic array hand one smaller, removes the
    card from the index specified, and returns that card
** Parameters: int
** Pre-Conditions: int exists
** Post-Conditions: Card
*********************************************************************/
        Card play_card(int);

/*********************************************************************
** Function: pick_suit()
** Description: changes the suit of the card from the index specified
** Parameters: int
** Pre-Conditions: int esists
** Post-Conditions: void
*********************************************************************/
        void pick_suit(int);

/*********************************************************************
** Function: print()
** Description: prints a card representation of each card in a hand
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void print();
};





#endif