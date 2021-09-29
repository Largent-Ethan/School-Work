/******************************************************
** Program: driver.cpp (Crazy 8s)
** Author: Ethan Largent
** Date: 04/25/2021
** Description: A player vs computer crazy 8s game
** Input: int turn_action, int pick_suit(for 8s)
** Output: your hand, card in play, winner
******************************************************/

#include "./deck.h"
#include "./card.h"
#include "./hand.h"
#include "./game.h"
#include "./player.h"

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main(){
    int game_run = 0;

    while(game_run == 0){
        Game game;
        string name;

        game.print_rules();

        cout << "\n\nWhat is your player name?\n(you may break the last rule this one time / no spaces)\n: ";
        cin >> name;
        cout << endl;

        game.set_player_name(0, name);

        Card top_card = game.flip_card();
        do{
            top_card = game.player_turn(top_card);
            if(game.over() == true)
                break;
            top_card = game.computer_turn(top_card);
        }while(game.over() == false);

        cout << "Do you want to play again?\n(0 - yes / !0 - no)\n: ";
        cin >> game_run;
    }
    return 0;
}