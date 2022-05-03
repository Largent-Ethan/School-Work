#include "./card.h"



#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


Card::Card(){
    rank = 0;
    suit = 0;
}

Card::Card(const Card& existing_card){
    suit = existing_card.suit;
    rank = existing_card.rank;
}

Card& Card::operator= (const Card& existing_card){
    if(this != & existing_card){
        this -> suit = existing_card.suit;
        this -> rank = existing_card.rank;
    }
    return *this;
}

Card::Card(int a, int b){
    set_rank(a);
    set_suit(b);
}

int Card::get_rank(){
    return rank;
}

int Card::get_suit(){
    return suit;
}

void Card::set_rank(int new_rank){
    rank = new_rank;
}

void Card::set_suit(int new_suit){
    suit = new_suit;
}

void Card::print(){
    int p_rank;
    string p_suit;
    cout << endl;
    if(suit == 0)
        p_suit = "♥"; 
    else if(suit == 1)
        p_suit = "♦";
    else if(suit == 2)
        p_suit = "♣";
    else 
        p_suit = "♠";
    for(int i = 0; i < 5; i++){
        if(i == 0)
            cout << "┌───┐";
        else if(i == 1 || i == 3)
            cout << "│" << p_suit << " " << p_suit << "│";
        else if(i == 2){
            p_rank = rank + 1;
            cout << "│ ";
            if(p_rank > 1 && p_rank < 10)
                cout << p_rank <<" │";
            else if(p_rank == 10)
                cout << "X │";
            else if(p_rank == 1)
                cout << "A │";
            else if(p_rank == 11)
                cout << "J │";
            else if(p_rank == 12)
                cout << "Q │";
            else
                cout << "K │";
        }
        else
            cout << "└───┘";
        cout << endl;
    }
}