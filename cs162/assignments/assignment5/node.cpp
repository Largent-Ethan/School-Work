#include "./node.h"



#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>


using namespace std;

    
Node::Node(){
    next = NULL;
    val = 0;
}

Node::Node(int newval){
    next = NULL;
    val = newval;
}
