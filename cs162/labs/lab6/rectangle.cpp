#include "./shape.h"
#include "./rectangle.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

float Rectangle::area(){
    return width * height;
}

Rectangle::Rectangle(){
    set_name("rectangle");
    set_width(2);
    set_height(1);
}

Rectangle::Rectangle(string c, float w, float h){
    set_name("rectangle");
    set_color(c);
    set_width(w);
    set_height(h);
}

float Rectangle::get_width(){
    return width;
}

float Rectangle::get_height(){
    return height;
}

void Rectangle::set_width(float new_width){
    width = new_width;
}
        
void Rectangle::set_height(float new_height){
    height = new_height;
}

void Rectangle::print(){
    cout << "name: " << get_name() << " - color: " << get_color() << " - area: " << area() << " - width: " << width << " - height: " << height;
}

bool Rectangle::operator>(Rectangle& rect2){
    if(this -> area() > rect2.area())
        return true;
    return false;
}

bool Rectangle::operator<(Rectangle& rect2){
    if(this -> area() < rect2.area())
        return true;
    return false;
}