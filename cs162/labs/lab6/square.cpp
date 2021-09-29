#include "./shape.h"
#include "./rectangle.h"
#include "./square.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

Square::Square(){
    set_name("square");
    set_width(1);
    set_height(1);
}

Square::Square(string c, float w){
    set_name("square");
    set_color(c);
    set_width(w);
    set_height(w);   
}