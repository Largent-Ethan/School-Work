#include "./deck.h"
#include "./card.h"
#include "./hand.h"


#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


Hand::Hand(Deck draw_pile){
    this -> n_cards = 7;
    this -> cards = new Card[7];
    for(int i = 0; i < 7; i++){
        this -> cards[i] = draw_pile.get_card(i + 52 - draw_pile.get_n_cards());
        draw_pile.set_n_cards(draw_pile.get_n_cards() - 1);
    }
    cout << "Constructor called!?!" << endl;
}

Hand::~Hand(){
    delete [] cards;
    cout << "Deconstructor called!!!" << endl;
}

Hand::Hand(const Hand& existing_hand){
    this -> n_cards = existing_hand.n_cards;
    this -> cards = new Card[this -> n_cards];
    for(int i = 0; i < n_cards; i++)
        this -> cards[i] = existing_hand.cards[i];
    cout << "Copy constructor called" << endl;
}


Hand& Hand::operator= (const Hand& existing_hand){
    if(this != & existing_hand){
        this -> n_cards = existing_hand.n_cards;
        delete [] this -> cards;
        this -> cards = new Card[this -> n_cards];
        for(int i = 0; i < n_cards; i++)
            this -> cards[i] = existing_hand.cards[i];
        cout << "Assignment operator overload called!" << endl;
    }
    return *this;
}

void Hand::print(){
    for(int i = 0; i < n_cards; i++){
        if(i != 0)
            cout << ",";
        cout << " " << cards[i].get_suit() << "|" << cards[i].get_rank();
    }
    cout << endl;
}