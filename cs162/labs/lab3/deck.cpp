#include "./deck.h"
#include "./card.h"


#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


Deck::Deck(){
    int card_num = 0;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 13; j++){
            cards[card_num].set_suit(i);
            cards[card_num].set_rank(j);
            card_num += 1;
        }
}

Card Deck::get_card(int index){
    return cards[index];
}

void Deck::set_card(int index, Card new_card){
    cards[index] = new_card;
}

void Deck::print(){
    for(int i = 0; i < 52; i++)
        cout << "c:" << i << "\ts:" << cards[i].get_suit() << "\tr:" << cards[i].get_rank() << endl;
}

void Deck::swap_cards(int i, int j){
    Card placeholder = cards[i];
    cards[i] = cards[j];
    cards[j] = placeholder;
}

void Deck::shuffle(){
    cout << "shuffling..." << endl;
    srand(time(NULL));
    int rand_num;
    for(int i = 0; i < 200; i++)
        for(int j = 0; j < 51; j++){
            rand_num = rand() % 2;
            if(rand_num == 0)
                swap_cards(j, j + 1);
    }
    cout << "shuffled!!!" << endl;
}