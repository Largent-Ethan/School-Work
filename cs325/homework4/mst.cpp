#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct vertex{
    int x;
    int y;
};

bool not_in(int n, int* arr, int s){
    for(int i = 0; i < s; i++)
        if(n == arr[i])
            return false;
    return true;
}

int get_edge(struct vertex u, struct vertex v){
    int x = u.x - v.x;
    int y = u.y - v.y;
    return (sqrt(x * x + y * y) + 0.5);
}

int get_mst(struct vertex* g, int s){
    int to_add, u, dst, val = 0;//variables
    int used[s];
    for(int i = 0; i < s; i++)//set all used indicies to 0
        used[i] = 0;
    for(int i = 1; i < s; i++){//for each edge to add
        to_add = INFINITY;//set the coming edge to add to infinity
        dst = 0;
        for(int j = 0; j < i; j++)//for each index in used[]
            for(int k = 0; k < s; k++)//for each edge
                if(not_in(k, used, i)){//if k is not in used[]
                    dst = get_edge(g[used[j]], g[k]);//extract the edge value from k to used[j]
                    if(dst < to_add){//if the found edge is smaller than the saved edge to add, replace the saved edge with this one
                        to_add = dst;
                        u = k;
                    }
                }
        used[i] = u;//add the found edge to used[i]
        val = val + to_add;//add its edge value to the total
    }
    return val;
}

int main(){
//read file
    ifstream inf("graph.txt");
    int cases, edges;
    inf >> cases;
    for(int case_num = 1; case_num <= cases; case_num++){
        inf >> edges;
        struct vertex graph[edges];
        for(int i = 0; i < edges; i++){
            inf >> graph[i].x;
            inf >> graph[i].y;
        }
//get mst and print results
        printf(" == Test case%3d: MST weight%4d\n\n", case_num, get_mst(graph, edges));
    }
    return 0;
}