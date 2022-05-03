#include "./shape.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <stdexcept>

using namespace std;

float Shape::area(){
    return 1;
}

Shape::Shape(){
    set_name("shape");
    set_color("white");
}

Shape::Shape(string c){
    set_name("shape");
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
    cout << name << "\n\tcolor: " << color << " \n\tarea: " << area() << "\n\n";
}