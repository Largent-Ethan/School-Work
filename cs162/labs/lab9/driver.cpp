#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>

using namespace std;


int main(){
    srand(time(NULL));
//variables & declarations
    int size;
    string input = "0";
    while(atoi(input.c_str()) <= 0 || atoi(input.c_str()) > 25){
        cout << "How many items are in your array?\n : ";
        cin >> input;
        if(atoi(input.c_str()) <= 0 || atoi(input.c_str()) > 25)
            cout << "Invalid input | must be between 0 and 26\n";
        else
            size = atoi(input.c_str());
    }
//making the array
    int* intarray = new int[size];
    for(int i = 0; i < size; i ++)
        intarray[i] = rand() % 100 + 1;
//printing unsorted array
    cout << "Unsorted numbers: ";
    for(int i = 0; i < size; i ++){
        if(i != 0)
            cout << " , ";
        cout << intarray[i];
    }
    cout << "\n\n";
//copying array
    int* intarray_sorted = new int[size];
    for(int i = 0; i < size; i ++)
        intarray_sorted[i] = intarray[i];
//sorting array - selection
    int min, index, to_copy;
    int num = 0;
    bool sorted = false;
    while(sorted == false){
        sorted = true;
        min = 100;
        for(int i = num; i < size; i ++)
            if(intarray_sorted[i] < min){
                min = intarray_sorted[i];
                index = i;
                sorted = false;
            }
        if(sorted == false){
            to_copy = intarray_sorted[num];
            intarray_sorted[num] = intarray_sorted[index];
            intarray_sorted[index] = to_copy;
        }
        num++;
    }
//printing sorted array
    cout << "Sorted numbers:\t  ";
    for(int i = 0; i < size; i ++){
        if(i != 0)
            cout << " , ";
        cout << intarray_sorted[i];
    }
    cout << "\n\n";
//printing prime numbers
    bool first_num = true;
    bool is_prime;
    cout << "Prime numbers:\t  ";
    for(int i = 0; i < size; i ++){
        is_prime = true;
        for(int j = 2; j < intarray_sorted[i]; j++)
            if(intarray_sorted[i] % j == 0)
                is_prime = false;
        if(is_prime == true){
            if(first_num != true)
                cout << " , ";
            first_num = false;
            cout << intarray_sorted[i];
        }
    }
    cout << "\n\n";
//clearing memory
    delete [] intarray;
    delete [] intarray_sorted;
    return 0;
}