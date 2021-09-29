#ifndef GAME_H
#define GAME_H


#include "./card.h"
#include "./hand.h"
#include "./player.h"
#include "./deck.h"


#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


class Game {
    private:

        Deck cards;
        Player players[2];

    public:
    
/*********************************************************************
** Function: Game()
** Description: makes a game with two players and deck
** Parameters: void
** Pre-Conditions: game is created
** Post-Conditions: void
*********************************************************************/
        Game();

/*********************************************************************
** Function: set_cards()
** Description: sets the cards of a game
** Parameters: Deck
** Pre-Conditions: Deck exists
** Post-Conditions: void
*********************************************************************/
        void set_cards(Deck);

/*********************************************************************
** Function: set_player()
** Description: sets a player of a game
** Parameters: int, Player
** Pre-Conditions: int and Player exists
** Post-Conditions: void
*********************************************************************/
        void set_player(int, Player);

/*********************************************************************
** Function: get_cards()
** Description: gets the cards of a game
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: Deck
*********************************************************************/
        Deck get_cards();

/*********************************************************************
** Function: get_player()
** Description: gets a player of a game
** Parameters: int
** Pre-Conditions: int exists
** Post-Conditions: Player
*********************************************************************/
        Player get_player(int);

/*********************************************************************
** Function: print_rules()
** Description: prints the rules of the game
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void print_rules();

/*********************************************************************
** Function: player_turn()
** Description: prompts the user of if they will play or draw
    takes the top card and returns the valid card played
** Parameters: Card
** Pre-Conditions: Card exists
** Post-Conditions: Card
*********************************************************************/
        Card player_turn(Card);

/*********************************************************************
** Function: computer_turn()
** Description: takes the top card and returns a valid card
    if there is no valid card then it draws until it gets one
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        Card computer_turn(Card);

/*********************************************************************
** Function: over()
** Description: prints a winner and return true when there is one
    if the deck is empty then the it prints a tie and returns true
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: bool
*********************************************************************/
        bool over();

/*********************************************************************
** Function: set_player_name()
** Description: 
** Parameters: int, string
** Pre-Conditions: int and string
** Post-Conditions: void
*********************************************************************/
        void set_player_name(int, string);

/*********************************************************************
** Function: flip_card
** Description: returns the top card in cards
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: Card
*********************************************************************/
        Card flip_card();
};



#endif