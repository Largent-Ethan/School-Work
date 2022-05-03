#ifndef CIRCLE_H
#define CIRCLE_H

#include "./shape.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;



class Circle : public Shape {
    private:
        float radius;
    public:
        float area();

        Circle();

        Circle(string, float);

        float get_radius();

        void set_radius(float);

        void print();
} ;

#endif