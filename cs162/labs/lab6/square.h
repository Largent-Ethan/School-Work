#ifndef SQUARE_H
#define SQUARE_H

#include "./shape.h"
#include "./rectangle.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;




class Square : public Rectangle {
    public:
        Square();

        Square(string, float);
} ;

#endif