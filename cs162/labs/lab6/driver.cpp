#include "./shape.h"
#include "./rectangle.h"
#include "./circle.h"
#include "./square.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


int main(){
    //creating shapes
    Shape def_shape;
    Shape spe_shape("orange");
    Rectangle def_rect;
    Rectangle spe_rect("blue", 3.5, 6);
    Circle def_circ;
    Circle spe_circ("red", 9);
    Square def_sqr;
    Square spe_sqr("green", 4);
    //printing information
    cout << "\n\nWE HAVE SHAPES!\n\nDefault shape:\n\t";
    def_shape.print();
    cout << "\nParameterized shape:\n\t";
    spe_shape.print();
    cout << "\nDefault rectangle:\n\t";
    def_rect.print();
    cout << "\nParameterized rectangle:\n\t";
    spe_rect.print();
    cout << "\nDefault circle:\n\t";
    def_circ.print();
    cout << "\nParameterized circle:\n\t";
    spe_circ.print();
    cout << "\nDefault square:\n\t";
    def_sqr.print();
    cout << "\nParameterized square:\n\t";
    spe_sqr.print();
    //printing area comparisons
    if(spe_rect > def_rect)
        cout << "\n\nParameterized rectangle\'s area is larger than our default one\n\t" << spe_rect.area() << " > " << def_rect.area() << endl;
    else if(spe_rect < def_rect)
        cout << "\n\nDefault rectangle\'s area is larger than our parameterized one\n\t" << def_rect.area() << " > " << spe_rect.area() << endl;
    else
        cout << "\n\nDefault rectangle\'s area is equal to our parameterized one\n\t" << def_rect.area() << " = " << spe_rect.area() << endl;
}