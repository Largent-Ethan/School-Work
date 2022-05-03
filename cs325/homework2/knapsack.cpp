#include <iostream>
#include <time.h>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

struct results{
    double time = 0;
    int max = 0;
};


int rec_ks_recursion(int* val, int* wt, int w, int n){
    if(n == 0 || w == 0)
        return 0;
    if(wt[n - 1] > w)
        return rec_ks_recursion(val, wt, w, n - 1);
    int take = val[n - 1] + rec_ks_recursion(val, wt, (w - wt[n - 1]), n - 1);
    int leave = rec_ks_recursion(val, wt, w, n - 1);
    if(take <= leave)
        return leave;
    return take;
}


struct results rec_ks(int* val, int* wt, int w, int n){
    struct results results;
    clock_t timer_start = clock();
    results.max = rec_ks_recursion(val, wt, w, n);
    clock_t timer_end = clock();
    results.time = (double(timer_end - timer_start) / CLOCKS_PER_SEC);
    return results;
}


struct results dyn_prog_ks(int* val, int* wt, int w, int n){
    struct results results;
    clock_t timer_start = clock();
    vector<vector<int> > max_arr(w + 1, vector<int> (n + 1));
    //int max_arr[w + 1][n + 1];
    for(int i = 0; i <= w; i++)
        max_arr[i][0] = 0;
    for(int i = 0; i <= n; i++)
        max_arr[0][i] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= w; j++){
            if(wt[i - 1] <= j && val[i - 1] + max_arr[j - wt[i - 1]][i - 1] > max_arr[j][i - 1])
                max_arr[j][i] = val[i - 1] + max_arr[j - wt[i - 1]][i-1];
            else
                max_arr[j][i] = max_arr[j][i - 1];
        }
    results.max = max_arr[w][n];
    clock_t timer_end = clock();
    results.time = (double(timer_end - timer_start) / CLOCKS_PER_SEC);
// Printing the DP max weight table(optional)
/*
    cout << "\n\n";
    for(int i = 0; i <= w; i++){
        for(int j = 0; j <= n; j++)
            printf(" %3d", max_arr[i][j]);
        cout << "\n";
    }
    cout << "\n\n";
*/
    return results;
}



int main(int argc, char** argv){
//Declare Variables
    int n = 0, w = 0, max_v = 0, max_w = 0;
    srand(time(NULL));
    max_v = atoi(argv[1]);
    max_w = atoi(argv[2]);


    for(int argnum = 3; argnum < argc; argnum = argnum + 2){
//Read Arguments - max value, max weight, number of items, weight, number of items, weight, etc.
        n = atoi(argv[argnum]);
        w = atoi(argv[argnum + 1]);
//Create Random Arrays
        int* val = new int[n];
        int* wt = new int[n];
        for(int i = 0; i < n; i++){
            val[i] = rand() % max_v + 1;
            wt[i] = rand() % max_w + 1;
        }
//Run Algorithms
        struct results rec_results = rec_ks(val, wt, w, n);
        struct results dyn_prog_results;// = dyn_prog_ks(val, wt, w, n);
//Print Results
        printf("\n\n == N:%5d | W:%5d | Rec time:%5.2f | DP time:%5.2f | max Rec:%5d | max DP:%5d\n",
                n, w, rec_results.time , dyn_prog_results.time , rec_results.max , dyn_prog_results.max);
//Print Elements(optional)
/*
        cout << "    Elements: n:  wt - val" << endl;
        for(int i = 0; i < n; i++)
            printf("            %3d: %3d - %3d\n",
            i, wt[i], val[i]);
*/
        delete[] val;
        delete[] wt;
    }
    return 0;
}

//use dynamically allocated memory for the DP algorithm and val/wt arrays