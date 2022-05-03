#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;



class Shape {
    private:
        string name;
        string color;
    public:
        float area();

        Shape();

        Shape(string);

        string get_name();
        string get_color();

        void set_name(string);
        void set_color(string);

        void print();
} ;

#endif