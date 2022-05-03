#include "./linked_list.h"
#include "./node.h"


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>


using namespace std;


Linked_list::Linked_list(){
    length = 0;
    head = NULL;
}

Node** Linked_list::get_head(){
    return &head;
}

int Linked_list::get_length(){
    return length;
}

void Linked_list::print(){
    Node* temp = head;
    for(unsigned int i = 0; i < length; i++){
        cout << (temp -> val); 
        if(i != length - 1)
            cout << ", ";
        temp = temp -> next;
    }
    cout << endl;
}

void Linked_list::clear(){
    if(length != 0){
        Node* temp;
        while(length != 0){
            temp = head;
            if(length != 1){
                while((temp -> next) -> next != NULL)
                    temp = temp -> next;
                delete temp -> next;
                temp -> next = NULL;
            }
            else
                delete temp;
            length--;
        }
    }
}

unsigned int Linked_list::push_front(int val){
    length++;
    Node* temp = new Node(val);
    if(length > 1)
        temp -> next = head;
    head = temp;
    return length;
}

unsigned int Linked_list::push_back(int val){
    length++;
    if(length > 1){
        Node* temp = head;
        while(temp -> next != NULL)
            temp = temp -> next;
        temp -> next = new Node(val);
    }
    else
        head = new Node(val);
    return length;
}

unsigned int Linked_list::insert(int val, unsigned int index){  
    if(index <= length){
        if(index == 0)
            return push_front(val);
        else if(index == length)
            return push_back(val);
        else{
            length++;
            Node* temp = head;
            for(unsigned int i = 0; i < index - 1; i++)
                temp = temp -> next;
            Node* temp2 = temp -> next;
            temp -> next = new Node(val);
            (temp -> next) -> next = temp2;
        }
    }
    return length;
}

void Linked_list::sort_ascending(Node** head_ref){
    Node* head = *head_ref;
    Node* a;
    Node* b;
 
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
 
    split(head, &a, &b);
 
    sort_ascending(&a);
    sort_ascending(&b);
 
    *head_ref = merge_ascending(a, b);
}

void Linked_list::sort_descending(Node** head_ref){
    Node* head = *head_ref;
    Node* a;
    Node* b;
 
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
 
    split(head, &a, &b);
 
    sort_descending(&a);
    sort_descending(&b);
 
    *head_ref = merge_descending(a, b);
}

Node* Linked_list::merge_ascending(Node* left, Node* right){
    Node* result = NULL;
 
    if (left == NULL)
        return (right);
    else if (right == NULL)
        return (left);
 
    if (left->val <= right->val) {
        result = left;
        result->next = merge_ascending(left->next, right);
    }
    else {
        result = right;
        result->next = merge_ascending(left, right->next);
    }
    return (result);
}

Node* Linked_list::merge_descending(Node* left, Node* right){
    Node* result = NULL;
 
    if (left == NULL)
        return (right);
    else if (right == NULL)
        return (left);
 
    if (left->val >= right->val) {
        result = left;
        result->next = merge_descending(left->next, right);
    }
    else {
        result = right;
        result->next = merge_descending(left, right->next);
    }
    return (result);
}

void Linked_list::split(Node* start, Node** front_ref, Node** back_ref){
    Node* fast;
    Node* slow;
    slow = start;
    fast = start->next;
 
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    *front_ref = start;
    *back_ref = slow->next;
    slow->next = NULL;
}

void Linked_list::print_primes(){
    bool is_prime;
    cout << "Prime numbers: ";
    Node* temp = head;
    int num, count = 0;
    for(unsigned int i = 0; i < length; i++){
        is_prime = true;
        num = temp -> val;
        for(int j = 2; j < num; j++)
            if((num % j) == 0){
                is_prime = false;
            }
        if(is_prime == true){
            count++;
            cout << num;
            if(i != length - 1)
                cout << ", ";
        }
        temp = temp -> next;
    }
    cout << "\nPrimes count: " << count << endl;
}



/**************************************************
 * 
 * ATTEMPT 1
 * 
**************************************************/

// Linked_list Linked_list::sort_ascending(Linked_list& list){
//     Linked_list sorted_list;
//     if(list.get_length() <= 1)
//         return sorted_list;

//     int mid = (list.get_length() + 1) / 2;

//     Linked_list half_1;
//     Linked_list half_2;

//     Node* temp = list.get_head();
//     for(int i = 0; i < mid; i++){
//         half_1.push_back(temp -> val);
//         temp = temp -> next;
//     }
    
//     for(int i = mid; i < list.get_length(); i++){
//         half_1.push_back(temp -> val);
//         temp = temp -> next;
//     }

//     half_1 = sort_ascending(half_1);
//     half_2 = sort_ascending(half_2);
//     return merge_ascending(half_1, half_2);
// }

// Linked_list Linked_list::sort_descending(Linked_list& list){
//     Linked_list sorted_list;
//     if(list.get_length() <= 1)
//         return sorted_list;

//     int mid = (list.get_length() + 1) / 2;

//     Linked_list half_1;
//     Linked_list half_2;

//     Node* temp = list.get_head();
//     for(int i = 0; i < mid; i++){
//         half_1.push_back(temp -> val);
//         temp = temp -> next;
//     }
    
//     for(int i = mid; i < list.get_length(); i++){
//         half_1.push_back(temp -> val);
//         temp = temp -> next;
//     }

//     half_1 = sort_descending(half_1);
//     half_2 = sort_descending(half_2);
//     return merge_descending(half_1, half_2);

// }

// Linked_list Linked_list::merge_ascending(Linked_list list1, Linked_list list2){
//     Node* temp1 = list1.get_head();
//     Node* temp2 = list2.get_head();
//     Linked_list sorted_list;
//     while(temp1 == NULL && temp2 == NULL){
//         if(temp1 != NULL && temp2 != NULL){
//             if(temp1 <= temp2){
//                 sorted_list.push_front(temp1 -> val);
//                 temp1 = temp1 -> next;
//             }
//             else{
//                 sorted_list.push_front(temp2 -> val);
//                 temp2 = temp2 -> next;
//             }
//         }
//         else if(temp2 == NULL){
//             while(temp1 != NULL){
//                 sorted_list.push_front(temp1 -> val);
//                 temp1 = temp1 -> next;
//             }
//         }
//         else{
//             while(temp1 == NULL){
//                 sorted_list.push_front(temp2 -> val);
//                 temp2 = temp2 -> next;
//             }
//         }
//     }
//     return sorted_list;
// }

// Linked_list Linked_list::merge_descending(Linked_list list1, Linked_list list2){
//     Node* temp1 = list1.get_head();
//     Node* temp2 = list2.get_head();
//     Linked_list sorted_list;
//     while(temp1 == NULL && temp2 == NULL){
//         if(temp1 != NULL && temp2 != NULL){
//             if(temp1 <= temp2){
//                 sorted_list.push_back(temp1 -> val);
//                 temp1 = temp1 -> next;
//             }
//             else{
//                 sorted_list.push_back(temp2 -> val);
//                 temp2 = temp2 -> next;
//             }
//         }
//         else if(temp2 == NULL){
//             while(temp1 != NULL){
//                 sorted_list.push_back(temp1 -> val);
//                 temp1 = temp1 -> next;
//             }
//         }
//         else{
//             while(temp2 != NULL){
//                 sorted_list.push_back(temp2 -> val);
//                 temp2 = temp2 -> next;
//             }
//         }
//     }
//     return sorted_list;
// }


/**************************************************
 * 
 * ATTEMPT 2
 * 
**************************************************/
// Linked_list Linked_list::sort_ascending(){
//     Node* templ;
//     Node* tempr;
//     int lele;
//     int rele;
//     int run = 1;
//     int sizes = 1;
//     int size_run = 1;
//     while(sizes < length){
//         templ = head;
//         for(int i = 0; i < (sizes * (2 * (run -1) ) ); i++)
//             if(templ != NULL)
//                 templ = templ -> next;
//         tempr = templ;
//         for(int i = 0; i < sizes; i++)
//             if(tempr != NULL)
//                 tempr = tempr -> next;
//         for(int i = 0; i < sizes * 2; i++){
//             if(templ -> val > tempr -> val){
//                 ...
//             }
//         }
//         if(run * 2 * size_run >= length){
//             run = 0;
//             sizes = sizes * 2;
//             size_run = size_run + 1;
//         }
//         run++;
//     }
// }
