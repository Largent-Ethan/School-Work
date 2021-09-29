/******************************************************
** Program: driver.cpp (Zoo Tycoon)
** Author: Ethan Largent
** Date: 10 May 2021
** Description: A zoo tycoon game
** Input: 
** Output: 
******************************************************/
#include "./zoo.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


int main(){
    string zoo_name;
    Zoo zoo;
    zoo.print_open();
    cin >> zoo_name;
    zoo.set_zoo_name(zoo_name);
    do{
        zoo.print_game();
        zoo.one_month_passes();
        zoo.print_game();
        zoo.determine_event();
        zoo.print_game();
        cout << " • Your zoo made $" << zoo.generate_money() << "! ... (1 to continue) : ";
        cin >> zoo_name;
        zoo.print_game();
        zoo.buy_animals();
        zoo.print_game();
        zoo.buy_food();
        zoo.print_game();
    }while(zoo.keep_playing() == true);
    zoo.print_close();
    return 0;
}