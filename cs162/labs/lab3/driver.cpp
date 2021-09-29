#include "./deck.h"
#include "./card.h"


#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


int main(){
    Deck deck_of_cards;
    deck_of_cards.print();
    char run;
    do{
    cout << "Shuffle Cards?\n(y - yes)\n(!y = no)\n: ";
    cin >> run;
    if(run == 'y'){
        deck_of_cards.shuffle();
        deck_of_cards.print();
    }
    }while(run == 'y');
}