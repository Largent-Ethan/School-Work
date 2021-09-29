#include "./shape.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

float Shape::area(){
    return 0;
}

Shape::Shape(){
    set_name("default");
    set_color("default");
}

Shape::Shape(string c){
    set_name("default");
    set_color(c);
}

string Shape::get_name(){
    return name;
}

string Shape::get_color(){
    return color;
}

void Shape::set_name(string new_name){
    name = new_name;
}

void Shape::set_color(string new_color){
    color = new_color;
}

void Shape::print(){
    cout << "name: " << name << " - color: " << color << " - area: " << area();
}