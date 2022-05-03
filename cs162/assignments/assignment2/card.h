#ifndef CARD_H
#define CARD_H








#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


class Card {
    private:

        int rank;
        int suit;

    public:
    
/*********************************************************************
** Function: Card()
** Description: makes an ace of hearts card
** Parameters: void
** Pre-Conditions: card is created
** Post-Conditions: void
*********************************************************************/
        Card();

/*********************************************************************
** Function: Card()
** Description: makes a specified card
** Parameters: int int
** Pre-Conditions: card is created with 2 parameters
** Post-Conditions: void
*********************************************************************/
        Card(int, int);

/*********************************************************************
** Function: Card()
** Description: copies a card to a card
** Parameters: void
** Pre-Conditions: card is created equal to a card
** Post-Conditions: void
*********************************************************************/
        Card(const Card&);

/*********************************************************************
** Function: operator=()
** Description: copies a card to a card (no dynamic memory)
** Parameters: void
** Pre-Conditions: card is set to card
** Post-Conditions: void
*********************************************************************/
        Card& operator= (const Card&);

/*********************************************************************
** Function: set_rank()
** Description: sets the rank of a card
** Parameters: int
** Pre-Conditions: int exists
** Post-Conditions: void
*********************************************************************/
        void set_rank(int);

/*********************************************************************
** Function: set_suit()
** Description: sets the rank of a card
** Parameters: int
** Pre-Conditions: int exists
** Post-Conditions: void
*********************************************************************/
        void set_suit(int);

/*********************************************************************
** Function: get_rank()
** Description: gets the rank of a card
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: int
*********************************************************************/
        int get_rank();

/*********************************************************************
** Function: get_suit()
** Description: gets the suit of a card
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: int
*********************************************************************/
        int get_suit();

/*********************************************************************
** Function: print()
** Description: prints a card representation of a cards data
** Parameters: void
** Pre-Conditions: 
** Post-Conditions: void
*********************************************************************/
        void print();
} ;






#endif