#include <iostream>
#include <fstream>

using namespace std;

int main(){
//Insert into array
    ifstream input_file("data.txt", ios::in);
    int size = 0;
    
    while(input_file.peek() != EOF){
        input_file >> size;
        int array[size];
        for(int i = 0; i < size; i++)
            input_file >> array[i];
//Sort Data
        int saved;
        int j = 0;

        for(int i = 1; i < size; i++){
            j = i;
            while(j > 0)
                while(array[j] < array[j - 1]){
                    saved = array[j];
                    array[j] = array[j -1];
                    array[j - 1] = saved;
                    j = j - 1;
                }
        }
//Output
        for(int i = 0; i < size; i++)
            cout << array[i];
        cout << endl;
    }
    return 0;
}