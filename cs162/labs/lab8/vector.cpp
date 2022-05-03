#include "./vector.hpp"
#include <vector>
#include <iostream>

//We do not want to include either statement. We wouldn't be able to compare our vector template to the Standard
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

int main (){
    vector<int> v1;

    v1.push_back(23);

    cout << "Vector 1: size = " << v1.size() << "\t";
    v1.print();

    v1.push_back(24);
    vector<int> v2 = v1;
    cout << "Vector 2: size = " << v2.size() << "\t";
    v2.print();

    v1.push_back(25);
    vector<int> v3;
    v3.push_back(3);
    v1.push_back(26);
    v3 = v1;
    cout << "Vector 3: size = " << v3.size() << "\t";
    v3.print();

    v3.resize(2);
    cout << "Vector 3: size = " << v3.size() << "\t";
    v3.print();



    return 0;
}