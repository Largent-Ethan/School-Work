#ifndef GAME_H
#define GAME_H


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


class Game {

    private:

        int size;
        vector<vector<Room> > cave;
        Player player;
        int startx;
        int starty;
        int playerx;
        int playery;
        int wumpusx;
        int wumpusy;
        int pwumpusx;
        int pwumpusy;
        int pgoldx;
        int pgoldy;

    protected:

    public:

        Game();

        Game(int);

        ~Game();

        Game(const Game&);

        void set_size(int);

        void set_cave(int, int, Room);

        void set_player(Player);

        void set_startx(int);

        void set_starty(int);

        void set_playerx(int);

        void set_playery(int);

        void set_wumpusx(int);

        void set_wumpusy(int);

        int get_size();

        Room get_cave(int, int);

        Player get_player();

        int get_startx();

        int get_starty();

        int get_playerx();

        int get_playery();

        int get_wumpusx();

        int get_wumpusy();

/*********************************************************************
** Function: randomize rooms
** Description: assigns random rooms to be a specific event or a player
                2 pits, 2 bats, 1 gold, 1 wumpus, 1 player; 7 total
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void randomize_rooms();

/*********************************************************************
** Function: turn
** Description: prints all the neccesary parts of a player turn
                returns a valid input
** Parameters: int
** Pre-Conditions: 1 int passed
** Post-Conditions: string
*********************************************************************/
        string turn(int);

/*********************************************************************
** Function: valid turn
** Description: checks if the player input for a turn is valid
** Parameters: string
** Pre-Conditions: 1 string passed
** Post-Conditions: bool
*********************************************************************/
        bool valid_turn(string);

/*********************************************************************
** Function: check player
** Description: updates the player based on the room it is in
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void check_player();

/*********************************************************************
** Function: randomize player
** Description: puts the player in any random room
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void randomize_player();

/*********************************************************************
** Function: found gold
** Description: deletes gold and makes has gold for player true
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void found_gold();

/*********************************************************************
** Function: print percepts
** Description: prints the percepts of each room adjacent to the player
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void print_percepts();

/*********************************************************************
** Function: move player
** Description: moves the player in the direction specifed
** Parameters: string
** Pre-Conditions: 1 string passed
** Post-Conditions: void
*********************************************************************/
        void move_player(string);

/*********************************************************************
** Function: shoot arrow
** Description: shoots an arrow in the direction specifed
** Parameters: string
** Pre-Conditions: 1 string passed
** Post-Conditions: void
*********************************************************************/
        void shoot_arrow(string);

/*********************************************************************
** Function: move wumpus
** Description: moves wumpus to a valid adjacent room
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void move_wumpus();

/*********************************************************************
** Function: print cave
** Description: prints the cave
                player, start, and the current room event are seen
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void print_cave();

/*********************************************************************
** Function: print debug cave
** Description: prints the cave
                player, start, and all events are seen
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void print_debug_cave();

/*********************************************************************
** Function: print end
** Description: prints a win screen or a lose screen
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void print_end();

/*********************************************************************
** Function: reset game
** Description: reset the player and game values
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void reset_game();

/*********************************************************************
** Function: player input
** Description: prompts the player for input
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: string
*********************************************************************/
        string player_input();

/*********************************************************************
** Function: ai input
** Description: automatically generates a valid input
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: string
*********************************************************************/
        string ai_input();

/*********************************************************************
** Function: gen rand num
** Description: return a random number within bouns given
** Parameters: int, int
** Pre-Conditions: 2 ints are passed
** Post-Conditions: int
*********************************************************************/
        int gen_rand_num(int, int);

} ;


#endif