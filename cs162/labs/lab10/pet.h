#ifndef PET_H
#define PET_H




#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>


using namespace std;


class Pet{
    
    private:

    protected:
        string name;
        int weight;

    public:
        string get_name();
        void set_name(string);
        int get_weight();
        void set_weight(int);
        virtual string getLifespan();

} ;


#endif