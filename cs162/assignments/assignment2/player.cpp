#include "./card.h"
#include "./hand.h"
#include "./player.h"



#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

Player::Player(){
    name = "computer";
}

Player::Player(const Player&){
    
}

Player& Player::operator= (const Player&){

}

void Player::set_hand(Hand new_hand){
    hand = new_hand;
}

void Player::set_name(string new_name){
    name = new_name;
}
        
Hand Player::get_hand(){
    return hand;
}

string Player::get_name(){
    return name;
}

bool Player::valid_card(int player, Card played_card, Card top_card){
    if(played_card.get_rank() == 7)
        return true;
    if(played_card.get_rank() == top_card.get_rank() || played_card.get_suit() == top_card.get_suit())
        return true;
    if(player == 0)
        cout << "\nError | Card is not playable" << endl;
    return false;
}

bool Player::valid_action(int action, Card top_card){
    if(action < 0 || action > hand.get_n_cards()){
        cout << "\nError | Card number does not exist" << endl;
        return false;
    }
    if(action == 0)
        return true;
    if(valid_card(0, hand.get_card(action - 1), top_card) == false)
        return false;
    return true;
}

void Player::add_to_hand(Card drawn_card){
    hand.add_card(drawn_card);
}

Card Player::remove_from_hand(int index){
    return hand.play_card(index);
}

void Player::played_eight(int index){
    hand.pick_suit(index);
}

void Player::print_hand(){
    hand.print();
}