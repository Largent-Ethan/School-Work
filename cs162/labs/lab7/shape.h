#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <stdexcept>

using namespace std;



class Shape {
    private:
        string name;
        string color;
    public:
        virtual float area()=0;

        Shape();

        Shape(string);

        string get_name();
        string get_color();

        void set_name(string);
        void set_color(string);

        virtual void print();
} ;

#endif