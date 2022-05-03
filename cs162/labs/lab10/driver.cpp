#include "./dog.h"
#include "./pet.h"


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>


using namespace std;


int main(){
    Pet pet1;
    Dog* dogarr;
    string input;
    int num_dogs;

    cout << "\nEnter pet name: ";
    cin >> input;
    pet1.set_name(input);
    cout << "Enter pet weight: ";
    cin >> input;
    pet1.set_weight(atoi(input.c_str()));

    cout << "Pet 1 lifespan = " << pet1.getLifespan() << endl;

    cout << "\nEnter number of dogs: ";
    cin >> input;
    num_dogs = atoi(input.c_str());
    cout << endl;

    dogarr = new Dog[num_dogs];

    for(int i = 0; i < num_dogs; i++){
        cout << "Dog " << i + 1 << endl;
        cout << "\tEnter dogname: ";
        cin >> input;
        dogarr[i].set_name(input);
        cout << "\tEnter dog weight: ";
        cin >> input;
        dogarr[i].set_weight(atoi(input.c_str()));
        cout << "\tEnter dog breed: ";
        cin >> input;
        dogarr[i].set_breed(input);
        cout << endl;
    }

    cout << "Lifespans\n";
    for(int i = 0; i < num_dogs; i++){
        cout << "\tDog " << i + 1 << " lifespan = " << dogarr[i].getLifespan() << endl;
    }
    cout << endl;

    delete [] dogarr;// :(

    return 0;
}