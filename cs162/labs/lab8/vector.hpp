#include <stdlib.h>
#include <iostream>

template <class T>

class vector {

    private:
       T *v;
       int s;
       int c;
 
    public:
        vector(){
            s = 0;
            v = NULL;
            c = 1;
        }
    
        ~vector(){
            delete [] v;
        }

        vector(vector<T> &other){
            this -> s = other.s;
            this -> v = new T[s];
            for(int i = 0; i < s; i++)
                this -> v[i] = other.v[i];
        }
        
        void operator=(vector<T> &other){
            delete [] this -> v;
            this -> s = other.s;
            this -> c = other.c;
            this -> v = new T[s];
            for(int i = 0; i < s; i++)
                this -> v[i] = other.v[i];
        }
        
        T& operator[](int index){
            return v[index];
        }

        T& at(int index){
            if(index < 0 || index >= s)
                std::cout << "Out of range!" << std::endl;
            else
                return v[index];
        }

        int size() {
            return s;
        }

        void push_back(T ele) {
            s = s + 1;
            if(c <= s){
                c = 2 * c;
                T *temp;
                temp = new T[c];
                for(int i = 0; i < s - 1; i++)
                    temp[i] = v[i];
                delete [] v;
                v = temp;
            }
            v[s - 1] = ele;
        }

        void resize(int size){
            if(s > size){
                T *temp;
                temp = new T[size];
                for(int i = 0; i < size; i++)
                    temp[i] = v[i];
                delete [] v;
                this = temp;
            }
        }

        void print(){
            for(int i = 0; i < s; i++){
                std::cout << v[i];
                if(i != s - 1)
                    std::cout << ", ";
            }
            std::cout << "\n";
        }
} ;