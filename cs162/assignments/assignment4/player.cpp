#include "./player.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


Player::Player(){
    set_has_gold(false);
    set_in_cave(true);
    set_is_dead(false);
    set_arrows(3);
}

void Player::set_has_gold(bool newhas_gold){
    has_gold = newhas_gold;
}

void Player::set_in_cave(bool newin_cave){
    in_cave = newin_cave;
}

void Player::set_is_dead(bool newis_dead){
    is_dead = newis_dead;
}

void Player::set_arrows(int newarrows){
    arrows = newarrows;
}

bool Player::get_has_gold(){
    return has_gold;
}

bool Player::get_in_cave(){
    return in_cave;
}

bool Player::get_is_dead(){
    return is_dead;
}

int Player::get_arrows(){
    return arrows;
}