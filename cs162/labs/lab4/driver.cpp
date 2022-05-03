#include "./deck.h"
#include "./card.h"
#include "./hand.h"


#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main(){
    Deck deck;
    deck.shuffle();
    Hand first_hand(deck);
    cout << "First hand: \t";
    first_hand.print();
    Hand second_hand(deck);
    cout << "Second hand: \t";
    second_hand.print();
    Hand new_hand = first_hand;
    cout << "New hand: \t";
    new_hand.print();
    new_hand = second_hand;
    cout << "New hand: \t";
    new_hand.print();
}