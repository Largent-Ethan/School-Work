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

Game::Game(){
    set_size(4);
    cave.assign(size, vector<Room>(size));
}

Game::Game(int newsize){
    set_size(newsize);
    cave.assign(size, vector<Room>(size));
}

Game::~Game(){
    cave.clear();
}

Game::Game(const Game& existing_game){
    set_size(existing_game.size);
    for(int i = 0; i < size; i ++)
        for(int j = 0; j < size; j ++)
            cave[i][j] = existing_game.cave[i][j];
    playerx = existing_game.playerx;
    playery = existing_game.playery;
    wumpusx = existing_game.wumpusx;
    wumpusy = existing_game.wumpusy;
    player = existing_game.player;
}

void Game::set_size(int newsize){
    size = newsize;
    cave.assign(size, vector<Room>(size));
}

void Game::set_cave(int x, int y, Room newroom){
    cave.at(x).at(y) = newroom;
}

void Game::set_player(Player newplayer){
    player = newplayer;
}

void Game::set_startx(int newx){
    startx = newx;
}

void Game::set_starty(int newy){
    starty = newy;
}

void Game::set_playerx(int newx){
    playerx = newx;
}

void Game::set_playery(int newy){
    playery = newy;
}

void Game::set_wumpusx(int newx){
    wumpusx = newx;
}

void Game::set_wumpusy(int newy){
    wumpusy = newy;
}

int Game::get_size(){
    return size;
}

Room Game::get_cave(int x, int y){
    return cave.at(y).at(x);
}

Player Game::get_player(){
    return player;
}

int Game::get_startx(){
    return startx;
}

int Game::get_starty(){
    return starty;
}

int Game::get_playerx(){
    return playerx;
}

int Game::get_playery(){
    return playery;
}

int Game::get_wumpusx(){
    return wumpusx;
}

int Game::get_wumpusy(){
    return wumpusy;
}

void Game::randomize_rooms(){
    int items = 0;
    int x, y;
    Event* eventptr;
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            cave.at(i).at(j).set_has_event(false);
    while(true){
        while(items < 7){
            y = gen_rand_num(0, size - 1);
            x = gen_rand_num(0, size - 1);
            if(cave.at(y).at(x).get_has_event() == false){
                cave.at(y).at(x).set_has_event(true);
                if(items < 2){
                    eventptr = new Pit;
                }else if(items < 4){
                    eventptr = new Bats;
                }else if(items < 5){
                    pgoldx = x;
                    pgoldy = y;
                    eventptr = new Gold;
                }else if(items < 6){
                    eventptr = new Wumpus;
                    pwumpusx = x;
                    pwumpusy = y;
                    set_wumpusx(x);
                    set_wumpusy(y);
                }else{
                    eventptr = NULL;
                    cave.at(y).at(x).set_has_event(false);
                    set_startx(x);
                    set_starty(y);
                    set_playerx(x);
                    set_playery(y);
                }
                cave.at(y).at(x).set_event(eventptr);
                items = items + 1;
            }
        }
        break;
    }
}

string Game::turn(int mode){
    if(mode == 3){
        print_cave();
        print_percepts();
        return ai_input();
    }else
        while(true){
            if(mode == 2)
                print_cave();
            else
                print_debug_cave();
            print_percepts();
            string input = player_input();
            if(valid_turn(input) == true)
                return input;
        }
}

bool Game::valid_turn(string input){
    if((input == "w" && playery != 0) || (input == "a" && playerx != 0) || (input == "s" && playery != size - 1) || (input == "d" && playerx != size - 1))
        return true;
    else if((input == " w" || input == " a" || input == " s" || input == " d") && player.get_arrows() > 0)
        return true;
    return false;
}

void Game::check_player(){
    if(cave.at(playery).at(playerx).get_has_event() == true){
        if(cave.at(playery).at(playerx).get_event() -> get_name() == "pit" || cave.at(playery).at(playerx).get_event() -> get_name() == "wumpus")
            player.set_is_dead(true);
        else if(cave.at(playery).at(playerx).get_event() -> get_name() == "bats")
            randomize_player();
        else if(cave.at(playery).at(playerx).get_event() -> get_name() == "gold")
            found_gold();
    }
    else if(playerx == startx && playery == starty && player.get_has_gold() == true)
        player.set_in_cave(false);
}

void Game::randomize_player(){
    int i = gen_rand_num(0, size - 1);
    int j = gen_rand_num(0, size - 1);
    set_playerx(j);
    set_playery(i);
    check_player();
}

void Game::found_gold(){
    cave.at(playery).at(playerx).set_has_event(false);
    player.set_has_gold(true);
}

void Game::print_percepts(){
    if(playerx != 0)
        if(cave.at(playery).at(playerx - 1).get_has_event() == true)
            cout << cave.at(playery).at(playerx - 1).get_event() -> percept();
    if(playery != 0)
        if(cave.at(playery - 1).at(playerx).get_has_event() == true)
            cout << cave.at(playery - 1).at(playerx).get_event() -> percept();
    if(playerx != size - 1)
        if(cave.at(playery).at(playerx + 1).get_has_event() == true)
            cout << cave.at(playery).at(playerx + 1).get_event() -> percept();
    if(playery != size - 1)
        if(cave.at(playery + 1).at(playerx).get_has_event() == true)
            cout << cave.at(playery + 1).at(playerx).get_event() -> percept();
    cout << endl;
}

void Game::move_player(string direction){
    if(direction == "w" || direction == " w")
        set_playery(playery - 1);
    if(direction == "a" || direction == " a")
        set_playerx(playerx - 1);
    if(direction == "s" || direction == " s")
        set_playery(playery + 1);
    if(direction == "d" || direction == " d")
        set_playerx(playerx + 1);
}

void Game::shoot_arrow(string direction){
    player.set_arrows(player.get_arrows() - 1);
    int y = 0;
    int x = 0;
    if(direction == " w")
        y = -1;
    if(direction == " a")
        x = -1;
    if(direction == " s")
        y = 1;
    if(direction == " d")
        x = 1;
    for(int i = 1; i < 4; i++)
        if(playery + i * y >= 0 && playery + i * y < size && playerx + i * x >= 0 && playerx + i * x < size)
            if(playery + i * y == wumpusy && playerx + i * x == wumpusx)
                cave.at(wumpusy).at(wumpusx).set_has_event(false);
    if(cave.at(wumpusy).at(wumpusx).get_has_event() == true){
        int chance = gen_rand_num(1, 4);
        if(chance > 1)
            move_wumpus();
    }
    return;
}

void Game::move_wumpus(){
    int direction;
    cave.at(wumpusy).at(wumpusx).set_has_event(false);
    for(int i = 0; i < 10; i++){
        direction = gen_rand_num(1, 4);
        if(direction == 1 && wumpusx < size - 1 && cave.at(wumpusy).at(wumpusx + 1).get_has_event() == false){
            wumpusx = wumpusx + 1;
            break;
        }if(direction == 2 && wumpusx > 0 && cave.at(wumpusy).at(wumpusx - 1).get_has_event() == false){
            wumpusx = wumpusx - 1;
            break;
        }if(direction == 3 && wumpusy < size - 1 && cave.at(wumpusy + 1).at(wumpusx).get_has_event() == false){
            wumpusy = wumpusy + 1;
            break;
        }if(direction == 4 && wumpusy > 0 && cave.at(wumpusy - 1).at(wumpusx).get_has_event() == false){
            wumpusy = wumpusy - 1;
            break;
        }
    }
    cave.at(wumpusy).at(wumpusx).set_has_event(true);
    cave.at(wumpusy).at(wumpusx).set_event(new Wumpus);
}

void Game::print_cave(){
    cout << "\n\n\n\n\n╔═════";
    for(int i = 1; i < size; i++)
        cout << "╦═════";
    cout << "╗" << endl;
    for(int i = 0; i < size; i++)
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < size; k++){
                if(j == 0){
                    if(cave.at(i).at(k).get_has_event() == true && playerx == k && playery == i)
                        cout << "║" << cave.at(i).at(k).get_event() -> icon_top();
                    else if(playerx == k && playery == i){
                        if(player.get_has_gold() == true)
                            cout << "║ _$_ ";
                        else
                            cout << "║ _Θ_ ";
                    }else if(startx == k && starty == i)
                        cout << "║  ф  ";
                    else
                        cout << "║     ";
                }
                else if(j == 1){
                    if(cave.at(i).at(k).get_has_event() == true && playerx == k && playery == i)
                        cout << "║" << cave.at(i).at(k).get_event() -> icon_bottom();
                    else if(playerx == k && playery == i)
                        cout << "║ ┎╨┒ ";
                    else if(startx == k && starty == i)
                        cout << "║  ξ  ";
                    else
                        cout << "║     ";
                }
                else{
                    if(k == 0 && i == size - 1)
                        cout << "╚═════";
                    else if(i == size - 1)
                        cout << "╩═════";
                    else if(k == 0)
                        cout << "╠═════";
                    else
                        cout << "╬═════";
                }
            }
            if(j == 2 && i == size - 1)
                cout << "╝" << endl;
            else if(j == 2)
                cout << "╣" << endl;
            else
                cout << "║" << endl;
        }
}

void Game::print_debug_cave(){
    cout << "\n\n\n\n\n╔═════";
    for(int i = 1; i < size; i++)
        cout << "╦═════";
    cout << "╗" << endl;
    for(int i = 0; i < size; i++)
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < size; k++){
                if(j == 0){
                    if(cave.at(i).at(k).get_has_event() == true)
                        cout << "║" << cave.at(i).at(k).get_event() -> icon_top();
                    else if(playerx == k && playery == i){
                        if(player.get_has_gold() == true)
                            cout << "║ _$_ ";
                        else
                            cout << "║ _Θ_ ";
                    }else if(startx == k && starty == i)
                        cout << "║  ф  ";
                    else
                        cout << "║     ";
                }
                else if(j == 1){
                    if(cave.at(i).at(k).get_has_event() == true)
                        cout << "║" << cave.at(i).at(k).get_event() -> icon_bottom();
                    else if(playerx == k && playery == i)
                        cout << "║ ┎╨┒ ";
                    else if(startx == k && starty == i)
                        cout << "║  ξ  ";
                    else
                        cout << "║     ";
                }
                else{
                    if(k == 0 && i == size - 1)
                        cout << "╚═════";
                    else if(i == size - 1)
                        cout << "╩═════";
                    else if(k == 0)
                        cout << "╠═════";
                    else
                        cout << "╬═════";
                }
            }
            if(j == 2 && i == size - 1)
                cout << "╝" << endl;
            else if(j == 2)
                cout << "╣" << endl;
            else
                cout << "║" << endl;
        }
}

void Game::print_end(){
    print_cave();
    cout << "\n\n\n\n\t\tGAME OVER\n";
    if(player.get_in_cave() == false)
        cout << "\t\tYOU WIN!!\n\n\n\n";
    else
        cout << "\t\tYOU LOSE!\n\n\n\n";
    cout << "What wil you do now?\n\t(1 - play on a new map of a new size)\n\t(2 - play on a new map of the same size)\n\t(3 - play again on the same map)\n\t(4 - exit program)\n : ";
}

void Game::reset_game(){
    player.set_has_gold(false);
    player.set_in_cave(true);
    player.set_is_dead(false);
    player.set_arrows(3);
    playerx = startx;
    playery = starty;
    cave[wumpusy][wumpusx].set_has_event(false);
    wumpusx = pwumpusx;
    wumpusy = pwumpusy;
    cave[pwumpusy][pwumpusx].set_has_event(true);
    cave[pgoldy][pgoldx].set_has_event(true);
}

string Game::player_input(){
    string input;
    cout << "What will you do?\n\t(wasd for movement)\n\t(precede with a space to shoot in a direction)\n\t(Arrows left: " << player.get_arrows() << ")\n : ";
    getline(cin, input);
    return input;
}

string Game::ai_input(){
    int choice;
    while(true){
        choice = gen_rand_num(1, 4);
        if(choice == 1 && playery > 0)
            return "w";
        if(choice == 2 && playerx > 0)
            return "a";
        if(choice == 3 && playery < size - 1)
            return "s";
        if(choice == 4 && playerx < size - 1)
            return "d";
    }
}

int Game::gen_rand_num(int lower_bound, int upper_bound){
    return rand() % (upper_bound + 1 - lower_bound) + lower_bound;
}