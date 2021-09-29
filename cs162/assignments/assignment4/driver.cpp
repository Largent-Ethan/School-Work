/******************************************************
** Program: driver.cpp (Wumpus Cave)
** Author: Ethan Largent
** Date: 23 May 2021
** Description: A wumpus cave game
** Input: 
** Output: 
******************************************************/
#include "./game.h"
#include "./player.h"
#include "./room.h"
#include "./event.h"
#include "./wumpus.h"
#include "./bats.h"
#include "./pit.h"
#include "./gold.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>

using namespace std;


int main(int argc, char** argv){
    srand(time(NULL));
    //variable declarations
    string turn, end_size;
    string end_choice = "2";
    int mode = 1;
    Game game;
    //check for command line argumets
    if(argc > 2)
        mode = atoi(argv[2]);
    if(argc > 1)
        if(atoi(argv[1]) > 3)
            game.set_size(atoi(argv[1]));
    //create game copy
    game.randomize_rooms();
    do{
    //play game
        do{
            turn = game.turn(mode);
            if((turn == " w" || turn == " a" || turn == " s" || turn == " d") && game.get_player().get_arrows() > 0)
                game.shoot_arrow(turn);
            else
                game.move_player(turn);
            game.check_player();
        }while(game.get_player().get_is_dead() == false && game.get_player().get_in_cave() == true);
    //after a game
        game.print_end();
        game.reset_game();
        getline(cin, end_choice);
        if(end_choice == "3")
            cout << "";
        else if(end_choice == "2"){
            game.set_size(game.get_size());
            game.randomize_rooms();
        }else if(end_choice != "4"){
            cout << "What will your board size be?\n : ";
            getline(cin, end_size);
            if(atoi(end_size.c_str()) > 3)
                game.set_size(atoi(end_size.c_str()));
            else
                game.set_size(4);
            game.randomize_rooms();
        }
    }while(end_choice != "4");
    return 0;
}