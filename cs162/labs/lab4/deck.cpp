#include "./deck.h"
#include "./card.h"


#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


Deck::Deck(){
    n_cards = 0;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 13; j++){
            cards[n_cards].set_suit(i);
            cards[n_cards].set_rank(j);
            n_cards += 1;
        }
    n_cards += 1;
}

Card Deck::get_card(int index){
    return cards[index];
}

int Deck::get_n_cards(){
    return n_cards;
}

void Deck::set_card(int index, Card new_card){
    cards[index] = new_card;
}

void Deck::set_n_cards(int new_n_cards){
    n_cards = new_n_cards;
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