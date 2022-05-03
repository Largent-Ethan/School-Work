#ifndef NODE_H
#define NODE_H



#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


class Node {
    
    public:

        int val;
        Node *next;
        
        Node();

        Node(int);
} ;


#endif