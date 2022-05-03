#include "./date.h"


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;



Date::Date(){
    month = 1;
    day = 1;
    year = 2001;
}

Date::Date(int new_month, int new_day, int new_year){
    set_month(new_month);
    set_day(new_day);
    set_year(new_year);
}

void Date::set_month(int new_month){
    month = new_month;
}

void Date::set_day(int new_day){
    day = new_day;
}

void Date::set_year(int new_year){
    year = new_year;
}

int Date::get_month(){
    return month;
}

int Date::get_day(){
    return day;
}

int Date::get_year(){
    return year;
}

string Date::get_fancier_month(){
    int num = get_month();
    if(num == 1)
        return "January";
    else if(num == 2)
        return "February";
    else if(num == 3)
        return "March";
    else if(num == 4)
        return "April";
    else if(num == 5)
        return "May";
    else if(num == 6)
        return "June";
    else if(num == 7)
        return "July";
    else if(num == 8)
        return "August";
    else if(num == 9)
        return "September";
    else if(num == 10)
        return "October";
    else if(num == 11)
        return "November";
    else if(num == 12)
        return "December";
    else
        return "Unknown_month";
}

void Date::print(){
    cout << get_month() << '/' << get_day() << '/' << get_year() << endl;
}

void Date::fancier_print(){
    cout << get_fancier_month() << ' ' << get_day() << ", " << get_year() << endl;
}