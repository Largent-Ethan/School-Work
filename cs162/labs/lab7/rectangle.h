#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "./shape.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <stdexcept>

using namespace std;



class Rectangle : public Shape {
    private:
        float width;
        float height;
    public:
        float area();

        Rectangle();

        Rectangle(string, float, float);

        float get_width();
        float get_height();

        void set_width(float);
        void set_height(float);

        bool operator>(Rectangle&);
        bool operator<(Rectangle&);
} ;

#endif