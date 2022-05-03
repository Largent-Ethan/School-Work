#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


class Player {

    private:

        bool has_gold;
        bool in_cave;
        bool is_dead;
        int arrows;

    protected:

    public:

        Player();

        void set_has_gold(bool);

        void set_in_cave(bool);

        void set_is_dead(bool);

        void set_arrows(int);

        bool get_has_gold();

        bool get_in_cave();

        bool get_is_dead();

        int get_arrows();
    
} ;


#endif