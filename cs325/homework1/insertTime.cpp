#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

int main(int argc, char** argv){
//Create Random Array
    ofstream output_file("timings.tsv");
    srand(time(NULL));

    for(int arnum = 1; arnum < argc; arnum++){
        int size = atoi(argv[arnum]);
        int array[size];
        for(int i = 0; i < size; i++)
            array[i] = rand() % 100;
//Start Time
        clock_t timer_start = clock();
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
//End Time
        clock_t timer_end = clock();
//Output
        double time = double(timer_end - timer_start) / CLOCKS_PER_SEC;
        printf(" == Size : %d\n    Time: %.3f\n", size, time);
        output_file << size << " " << time << "\n";
    }
    output_file << "\n";
    output_file.close();
    return 0;
}