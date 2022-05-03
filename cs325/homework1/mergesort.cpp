#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(){
//Insert into array
    ifstream input_file("data.txt", ios::in);
    char read_size[0];
    int size = 0;
    
    while(input_file.eof() == 0){
        input_file >> read_size;
        size = atoi(read_size);
        int array[size];
        for(int i = 0; i < size; i++)
            input_file >> array[i];
//Sort Data
        int saved, l, r, split = 1;

        while(split < size){
            for(int i = 0; i < size; i = i + split * 2){
                l = i;
                r = l + split;
                while(!(l == r || r >= size || r >= split * 2 + l)){
                    if(array[l] > array[r]){
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
//Output
        cout << " ==";
        for(int i = 0; i < size; i++)
            cout << " " << array[i];
        cout << endl;
    }
    input_file.close();
    return 0;
}