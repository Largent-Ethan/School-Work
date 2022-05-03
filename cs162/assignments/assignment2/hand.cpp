#include "./card.h"
#include "./hand.h"


#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


Hand::Hand(){
    n_cards = 0;
    cards = new Card[n_cards];
}

Hand::~Hand(){
    delete [] cards;
}

Hand::Hand(const Hand& existing_hand){
    n_cards = existing_hand.n_cards;
    cards = new Card[n_cards];
    for(int i = 0; i < n_cards; i++)
        cards[i] = existing_hand.cards[i];
}


Hand& Hand::operator= (const Hand& existing_hand){
    if(this != & existing_hand){
        this -> n_cards = existing_hand.n_cards;
        delete [] this -> cards;
        this -> cards = new Card[this -> n_cards];
        for(int i = 0; i < n_cards; i++)
            this -> cards[i] = existing_hand.cards[i];
    }
    return *this;
}

void Hand::set_card(int index, Card new_card){
    cards[index] = new_card;
}

void Hand::set_n_cards(int new_n_cards){
    n_cards = new_n_cards;
}

Card Hand::get_card(int index){
    return cards[index];
}

int Hand::get_n_cards(){
    return n_cards;
}

void Hand::add_card(Card new_card){
    n_cards = n_cards + 1;
    Card* temp = new Card[n_cards];
    for(int i = 0; i < n_cards - 1; i++)
        temp[i] = cards[i];
    temp[n_cards - 1] = new_card;
    delete [] this -> cards;
        this -> cards = new Card[this -> n_cards];
        for(int i = 0; i < n_cards; i++)
            this -> cards[i] = temp[i];
    delete [] temp;
}

Card Hand::play_card(int index){
    Card played_card = this -> cards[index];
    this -> n_cards -= 1;
    Card* temp = new Card[this -> n_cards];
    for(int i = 0; i < n_cards; i++){
        if(i >= index)
            temp[i] = this -> cards[i + 1];
        else
            temp[i] = this -> cards[i];
    }
    delete [] this -> cards;
        this -> cards = new Card[this -> n_cards];
        for(int i = 0; i < n_cards; i++)
            this -> cards[i] = temp[i];
    delete [] temp;
    return played_card;
}

void Hand::pick_suit(int index){
    int choice;
    cout << "What suit will your 8 be?\n(0 - ♥ / 1 - ♦ / 2 - ♣ / 3 - ♠)\n: ";
    cin >> choice;
    cards[index].set_suit(choice);
}

void Hand::print(){
    int rank;
    string suit;
    cout << endl;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < n_cards; j++){
            if(j != 0)
                cout << '\t';
            if(i == 0)
                cout << "┌───┐";
            else if(i == 1 || i == 3){
                if(this -> cards[j].get_suit() == 0)
                    suit = "♥"; 
                else if(this -> cards[j].get_suit() == 1)
                    suit = "♦";
                else if(this -> cards[j].get_suit() == 2)
                    suit = "♣";
                else 
                    suit = "♠";
                cout << "│" << suit << " " << suit << "│";
            }
            else if(i == 2){
                rank = this -> cards[j].get_rank() + 1;
                cout << "│ ";
                if(rank > 1 && rank < 10)
                    cout << rank <<" │";
                else if(rank == 10)
                    cout << "X │";
                else if(rank == 1)
                    cout << "A │";
                else if(rank == 11)
                    cout << "J │";
                else if(rank == 12)
                    cout << "Q │";
                else
                    cout << "K │";
            }
            else if(i == 4)
                cout << "└───┘";
            else
                cout << " (" << j + 1 << ") ";
            cout << ' ';
        }
        cout << endl;
    }
}