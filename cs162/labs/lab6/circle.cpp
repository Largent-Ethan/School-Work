#include "./shape.h"
#include "./circle.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

float Circle::area(){
    return radius * 3.14153;
}

Circle::Circle(){
    set_name("circle");
    set_radius(1);
}

Circle::Circle(string c, float r){
    set_name("circle");
    set_color(c);
    set_radius(r);
}

float Circle::get_radius(){
    return radius;
}

void Circle::set_radius(float new_radius){
    radius = new_radius;
}

void Circle::print(){
    cout << "name: " << get_name() << " - color: " << get_color() << " - area: " << area() << " - radius: " << radius;
}