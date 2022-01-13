#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char** argv){
//Create Random Array
    srand(time(NULL));
    for(int arnum = 1; arnum < argc; arnum++){
        int size = atoi(argv[arnum]);
        int array[size];
        for(int i = 0; i < size; i++)
            array[i] = rand() % 100;
//Start Time
        clock_t timer_start = clock();
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
//End Time
        clock_t timer_end = clock();
//Output
        printf(" == Size : %d\n    Time: %.3f\n", size, double(timer_end - timer_start) / CLOCKS_PER_SEC);
    }
    return 0;
}