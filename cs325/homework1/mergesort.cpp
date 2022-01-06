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


//Output
        for(int i = 0; i < size; i++)
            cout << array[i];
        cout << endl;
    }
    return 0;
}