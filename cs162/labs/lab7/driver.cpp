#include "./shape.h"
#include "./rectangle.h"
#include "./circle.h"
#include "./square.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <stdexcept>

using namespace std;


void print_shape_info(Shape& shape){
    Shape* sptr = &shape;
    sptr -> print();
}

int main(){
    //creating shapes
    Rectangle def_rect;
    Rectangle spe_rect("blue", 3.5, 6);
    Circle def_circ;
    Circle spe_circ("red", 9);
    Square def_sqr;

    //exceptions
    int side_length;
    cout << "Enter square side length: ";
    cin >> side_length;
    Square spe_sqr("green", side_length);

    //printing information
    cout << "\n\n\tWE HAVE SHAPES!\n-------------------------------\n";
    def_rect.print();
    spe_rect.print();
    def_circ.print();
    spe_circ.print();
    def_sqr.print();
    spe_sqr.print();

    //printing information but pointer versions
    cout << "\n\n\tWE HAVE POLYMORPHED SHAPES!\n-------------------------------------------\n";
    print_shape_info(def_rect);
    print_shape_info(spe_rect);
    print_shape_info(def_circ);
    print_shape_info(spe_circ);
    print_shape_info(def_sqr);
    print_shape_info(spe_sqr);
}