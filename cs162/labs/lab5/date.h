#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;



class Date {
    private:

        int month;
        int day;
        int year;

    public:

        Date();
        Date(int, int, int);

        void set_month(int);
        void set_day(int);
        void set_year(int);

        int get_month();
        int get_day();
        int get_year();

        string get_fancier_month();
        void print();
        void fancier_print();
} ;

#endif