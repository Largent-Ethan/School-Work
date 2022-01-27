#include <iostream>
#include <time.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct item{
    int val = 0;
    int wt = 0;
};

struct results{
    int max = 0;
    int num_items = 0;
    int items[63];//im sorry, lets just assume people cannot hold more than 63 things...
};


struct results dyn_prog_ks(struct item* items, int w, int n){
    struct results results;
    struct results res_arr[w + 1][n + 1];
//Set the 0 column and 0 row values to 0
    for(int i = 0; i <= w; i++){
        res_arr[i][0].max = 0;
        res_arr[i][0].items[0];
    }
    for(int i = 0; i <= n; i++){
        res_arr[0][i].max = 0;
        res_arr[0][i].items[0];
    }
//Create the max value table
    for(int i = 1; i <= n; i++)//for each item
        for(int j = 1; j <= w; j++){//for each weight
            if(items[i - 1].wt <= j && items[i - 1].val + res_arr[j - items[i - 1].wt][i - 1].max > res_arr[j][i - 1].max){//if the item can be added and increase the value
                res_arr[j][i].max = items[i - 1].val + res_arr[j - items[i - 1].wt][i - 1].max;//copy max value
                res_arr[j][i].num_items = res_arr[j - items[i - 1].wt][i - 1].num_items + 1;//add one to number of items
                for(int k = 0; k < res_arr[j - items[i - 1].wt][i-1].num_items; k++)//copy item indicies that are used
                    res_arr[j][i].items[k] = res_arr[j - items[i - 1].wt][i - 1].items[k];
                res_arr[j][i].items[res_arr[j][i].num_items - 1] = i;//add newly used item index
            }
            else{//if the item can't be added or won't increase the value
                res_arr[j][i].max = res_arr[j][i - 1].max;//copy max value
                res_arr[j][i].num_items = res_arr[j][i - 1].num_items;//copy number of items
                for(int k = 0; k < res_arr[j][i-1].num_items; k++)//copy item indicies that are used
                    res_arr[j][i].items[k] = res_arr[j][i - 1].items[k];
            }
        }
    return res_arr[w][n];//return bottom right corner of table
}



int main(int argc, char** argv){
//Read input file
    int num_trials;
    ifstream infile("shopping.txt", ios::in);
    infile >> num_trials;
    for(int trial = 0; trial < num_trials; trial++){
        cout << "\n == Test Case " << trial + 1 << endl;
        int num_items, num_shprs;
        infile >> num_items;
        struct item items[num_items];
        for(int i = 0; i < num_items; i++){
            infile >> items[i].val;
            infile >> items[i].wt;
        }
        infile >> num_shprs;
        int shprs[num_shprs];
        for(int i = 0; i < num_shprs; i++)
            infile >> shprs[i];
//Run algorithms
        int total_price = 0;
        struct results results[num_shprs];
        for(int i = 0; i < num_shprs; i++){
            results[i] = dyn_prog_ks(items, shprs[i], num_items);
//Print Results
            total_price = total_price + results[i].max;
        }
        cout << "    Total Price " << total_price << endl;
        for(int s = 0; s < num_shprs; s++){
            printf("     %2d:  ", s + 1);
            for(int i = 0; i < results[s].num_items; i++)
                printf("%2d ", results[s].items[i]);
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}