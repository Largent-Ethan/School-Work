#ifndef PLAYER_H
#define PLAYER_H


#include "./card.h"
#include "./hand.h"




#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


class Player {
    private:

        Hand hand;
        string name;

    public:

/*********************************************************************
** Function: Player()
** Description: makes a player with a hand and a name
** Parameters: void
** Pre-Conditions: player is created
** Post-Conditions: void
*********************************************************************/
        Player();
        
/*********************************************************************
** Function: Player()
** Description: copies a player to player
** Parameters: void
** Pre-Conditions: player is created equal to a player
** Post-Conditions: void
*********************************************************************/
        Player(const Player&);

/*********************************************************************
** Function: operator=()
** Description: copies a player to a player (no dynamic memory)
** Parameters: void
** Pre-Conditions: player is set to player
** Post-Conditions: void
*********************************************************************/
        Player& operator= (const Player&);

/*********************************************************************
** Function: set_hand()
** Description: sets the hand of a player
** Parameters: Hand
** Pre-Conditions: Hand exists
** Post-Conditions: void
*********************************************************************/
        void set_hand(Hand);

/*********************************************************************
** Function: set_name()
** Description: sets the name of a player
** Parameters: string
** Pre-Conditions: string exists
** Post-Conditions: void
*********************************************************************/
        void set_name(string);
        
/*********************************************************************
** Function: get_hand()
** Description: gets the hand of a player
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: Hand
*********************************************************************/
        Hand get_hand();

/*********************************************************************
** Function: get_name()
** Description: gets the name of a player
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: string
*********************************************************************/
        string get_name();

/*********************************************************************
** Function: valid_card()
** Description: checks if two cards match in suit or rank
    if int is 0 then an error message is printed
** Parameters: int, Card, Card
** Pre-Conditions: int and Cards exists
** Post-Conditions: bool
*********************************************************************/
        bool valid_card(int, Card, Card);

/*********************************************************************
** Function: valid_action()
** Description: checks if card is valid, if card exists, or if int is 0
** Parameters: int, Card
** Pre-Conditions: int and Card exists
** Post-Conditions: bool
*********************************************************************/
        bool valid_action(int, Card);

/*********************************************************************
** Function: add_to_hand()
** Description: adds a card to your hand
** Parameters: Card
** Pre-Conditions: Card exists
** Post-Conditions: void
*********************************************************************/
        void add_to_hand(Card);

/*********************************************************************
** Function: remove_from_hand()
** Description: plays a card from your hand
** Parameters: int
** Pre-Conditions: int exists
** Post-Conditions: Card
*********************************************************************/
        Card remove_from_hand(int);

/*********************************************************************
** Function: played_eight()
** Description: prompts user to pick a suit for an eight
** Parameters: int
** Pre-Conditions: int exists
** Post-Conditions: void
*********************************************************************/
        void played_eight(int);

/*********************************************************************
** Function: print_hand()
** Description: prints hand
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void print_hand();
};


#endif