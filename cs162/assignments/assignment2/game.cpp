#include "./card.h"
#include "./hand.h"
#include "./player.h"
#include "./deck.h"
#include "./game.h"

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

Game::Game(){
    for(int i = 1; i < 15; i++){
        Card temp = cards.draw_card();
        players[i % 2].add_to_hand(temp);
    }
}

void Game::set_cards(Deck new_deck){
    cards = new_deck;
}

void Game::set_player(int index, Player new_player){
    players[index] = new_player;
}

Deck Game::get_cards(){
    return cards;
}

Player Game::get_player(int index){
    return players[index];
}

void Game::print_rules(){
    cout << "\n\n\tI shouldn't be in your terminal! >:(   resize me!\n\tI should be in your terminal! : )\n\n\n ♥ ♦ ♣ ♠ ♥ ♦ ♣ ♠ ♥ ♦ ♣ ♠ ♥ ♦ ♣ ♠\n      WELCOME TO CRAZY 8's\n\n• this game is player vs computer\n• you take turns playing cards\n• played cards must be same suit\n  or rank as the top card in\n  order to be played\n• 8's are always playable and you\n  pick the its suit when played\n• please only type in whole\n  number values as input or the\n  code will break and you will\n  get barfed on\n ♥ ♦ ♣ ♠ ♥ ♦ ♣ ♠ ♥ ♦ ♣ ♠ ♥ ♦ ♣ ♠\n";
}

Card Game::player_turn(Card top_card){
    int action;
    do{
    cout << "\n\nThis is the top card:";
    top_card.print();
    cout << "\nThis is your hand:";
    players[0].print_hand();
    cout << "\n - "<< cards.get_n_cards() << " cards left in the deck / " << players[1].get_hand().get_n_cards() << " cards left in opponenets hand - \n\nWhat action will you take this turn\n(# of card - play card / 0 - draw card)\n: ";
    cin >> action;
    cout << endl;
    }while(players[0].valid_action(action, top_card) == false);
    if(action != 0){
        if(players[0].get_hand().get_card(action - 1).get_rank() + 1 == 8)
            players[0].played_eight(action - 1);
        return players[0].remove_from_hand(action - 1);
    }
    else{
        if(cards.get_n_cards() == 0)
            return top_card;
        players[0].add_to_hand(cards.draw_card());
        return player_turn(top_card);
    }
}

Card Game::computer_turn(Card top_card){
    for(int i = players[1].get_hand().get_n_cards(); i >= 0; i--)
        if(players[1].valid_card(1, players[1].get_hand().get_card(i), top_card))
            return players[1].remove_from_hand(i);
    if(cards.get_n_cards() == 0)
        return top_card;
    players[1].add_to_hand(cards.draw_card());
    return computer_turn(top_card);
}

bool Game::over(){
    if(players[0].get_hand().get_n_cards() == 0){
        cout << "\n\n\n\n\n\n\n\n♥ ♦ ♣ ♠ ♥ ♦ ♣ ♠ ♥ ♦ ♣ ♠ ♥ ♦ ♣ ♠\n \n\t" << players[0].get_name() << " wins\n \n♥ ♦ ♣ ♠ ♥ ♦ ♣ ♠ ♥ ♦ ♣ ♠ ♥ ♦ ♣ ♠\n\n\n\n\n\n\n" << endl;
        return true;
    }
    else if(players[1].get_hand().get_n_cards() == 0){
        cout << "\n\n\n\n\n\n\n\n♥ ♦ ♣ ♠ ♥ ♦ ♣ ♠ ♥ ♦ ♣ ♠ ♥ ♦ ♣ ♠\n \n\t" << players[1].get_name() << " wins\n \n♥ ♦ ♣ ♠ ♥ ♦ ♣ ♠ ♥ ♦ ♣ ♠ ♥ ♦ ♣ ♠\n\n\n\n\n\n\n" << endl;
        return true;
    }
    else if(cards.get_n_cards() == 0){
        cout << "\n\n\n\n\n\n\n\n♥ ♦ ♣ ♠ ♥ ♦ ♣ ♠ ♥ ♦ ♣ ♠ ♥ ♦ ♣ ♠\n \n\ttie game\n \n♥ ♦ ♣ ♠ ♥ ♦ ♣ ♠ ♥ ♦ ♣ ♠ ♥ ♦ ♣ ♠\n\n\n\n\n\n\n" << endl;
        return true;
    }
    else
        return false;
}

void Game::set_player_name(int index, string name){
    players[index].set_name(name);
}

Card Game::flip_card(){
    return cards.draw_card();
}