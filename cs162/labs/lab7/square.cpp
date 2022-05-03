#include "./shape.h"
#include "./rectangle.h"
#include "./square.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <stdexcept>

using namespace std;

Square::Square(){
    set_name("square");
    set_width(1);
    set_height(1);
}

Square::Square(string c, float w){
    set_name("square");
    set_color(c);
    while(1){
        try{
            if(w > 0){
                set_width(w);
                set_height(w);
                break;
            }else
                throw invalid_argument("Invalid constructor argument");
        }
        catch(invalid_argument(x)){
            cout << "Enter square side length: ";
            cin >> w;
            set_width(w);
            set_height(w);
        }
    } 
}