#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "./node.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


class Linked_list : public Node{

    private:

        unsigned int length;
        Node *head;
        Linked_list split(Linked_list&);
        Linked_list merge();

    public:

        Linked_list();
        Node** get_head();
        int get_length();

/*********************************************************************
** Function: print
** Description: prints all node values in the linked list
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void print();

/*********************************************************************
** Function: clear
** Description: deletes all nodes in the linked list
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void clear();

/*********************************************************************
** Function: push_front
** Description: adds a node to the start of the linked list
** Parameters: int
** Pre-Conditions: void
** Post-Conditions: unsigned int
*********************************************************************/
        unsigned int push_front(int);

/*********************************************************************
** Function: push_back
** Description: adds a node to the back of the linked list
** Parameters: int
** Pre-Conditions: void
** Post-Conditions: unsigned int
*********************************************************************/
        unsigned int push_back(int);

/*********************************************************************
** Function: insert
** Description: inserts a node at the specified location in the linked
                list
** Parameters: int, unsigned int
** Pre-Conditions: void
** Post-Conditions: unsigned int
*********************************************************************/
        unsigned int insert(int val, unsigned int index);

/*********************************************************************
** Function: sort_ascending
** Description: sorts the linked list into ascending order
** Parameters: Node**
** Pre-Conditions: 1 Node**
** Post-Conditions: void
*********************************************************************/
        void sort_ascending(Node**);

/*********************************************************************
** Function: sort_descending
** Description: sorts the linked list into descending order
** Parameters: Node**
** Pre-Conditions: 1 Node**
** Post-Conditions: void
*********************************************************************/
        void sort_descending(Node**);

/*********************************************************************
** Function: merge_ascending
** Description: merges 2 portions of list together in ascending order
** Parameters: Node*, Node*
** Pre-Conditions: 2 Node*
** Post-Conditions: Node*
*********************************************************************/
        Node* merge_ascending(Node*, Node*);

/*********************************************************************
** Function: merge_descending
** Description: merges 2 portions of list together in descending order
** Parameters: Node*, Node*
** Pre-Conditions: 2 Node*
** Post-Conditions: Node*
*********************************************************************/
        Node* merge_descending(Node*, Node*);

/*********************************************************************
** Function: split
** Description: splits a portion of a list into two adjacent portions
** Parameters: Node*, Node**, Node**
** Pre-Conditions: 2 Node** and 1 Node*
** Post-Conditions: void
*********************************************************************/
        void split(Node*, Node**, Node**);

/*********************************************************************
** Function: print_primes
** Description: prints the prime numbers and amount of prime numbers
                in a linked list
** Parameters: void
** Pre-Conditions: void
** Post-Conditions: void
*********************************************************************/
        void print_primes();

} ;


#endif