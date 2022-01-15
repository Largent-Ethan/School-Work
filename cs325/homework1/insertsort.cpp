#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(){
//Insert into array
    ifstream input_file("data.txt", ios::in);
    char* read_size;
    int size = 0;
    
    while(input_file.eof() == 0){
        input_file >> read_size;
        size = atoi(read_size);
        int array[size];
        for(int i = 0; i < size; i++)
            input_file >> array[i];
//Sort Data
        int saved, j;

        for(int i = 1; i < size; i++){
            j = i;
            while(j > 0)
                if(array[j] < array[j - 1]){
                    saved = array[j];
                    array[j] = array[j - 1];
                    array[j - 1] = saved;
                    j = j - 1;
                }
                else
                    j = 0;
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