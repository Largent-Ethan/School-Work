#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

struct activity{
    int n;//number
    int s;//start
    int f;//finish
};

void mergesort(struct activity* array, int size){
    struct activity saved;
    int l, r, split = 1;
    while(split < size){
        for(int i = 0; i < size; i = i + split * 2){
            l = i;
            r = l + split;
            while(!(l == r || r >= size || r >= split * 2 + l)){
                if(!(array[l].f < array[r].f)){
                    saved = array[r];
                    for(int k = r; k > l; k--)
                        array[k] = array[k - 1];
                    array[l] = saved;
                    r = r + 1;
                }
                l = l + 1;
            }
        }
        split = split * 2;
    }
    return;
}

vector<struct activity> last_to_start(struct activity* acts, int size){
    vector<struct activity> opt_acts;//create empty "dynamic array"
    opt_acts.push_back(acts[size - 1]);//add largest finish time as the item to test
    for(int i = size - 2; i >= 0; i--){//for each element of array(sorted in ascending order so works backwards)
        if(acts[i].s > opt_acts.back().s){//if start of next element is later than currently test item
            opt_acts.pop_back();//delete test item
            opt_acts.push_back(acts[i]);//make the found item the new test item
        }
        if(acts[i].f <= opt_acts.back().s)//if the next elements finish time is before the test items start time
            opt_acts.push_back(acts[i]);//add the found item and make it the test item
    }
    return opt_acts;//return the "array" of items left in the array of tested items
}

int main(){
    //read file
    ifstream inf("act.txt");
    int set_num = 1;
    while(!inf.eof()){
        int size;
        inf >> size;
        if(!inf.eof()){
            struct activity* acts = new struct activity[size];
            for(int i = 0; i < size; i++){
                inf >> acts[i].n;
                inf >> acts[i].s;
                inf >> acts[i].f;
            }
        //sort and find activities
            mergesort(acts, size);
            vector<struct activity> optimal_acts = last_to_start(acts, size);
        //print results
            printf("Set %d\nMaximum number of activities = %d\n", set_num, optimal_acts.size());
            for(int i = optimal_acts.size() - 1; i >= 0; i--)
                cout << " " << optimal_acts[i].n;
            cout << "\n\n";
            set_num = set_num + 1;
            delete [] acts;
        }
    }
    return 0;
}