#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct node{
    int i;
    int x;
    int y;
};

struct edge{
    int u;
    int v;
};

int distance(struct node u, struct node v){
    int x = u.x - v.x;
    int y = u.y - v.y;
    return (sqrt(x * x + y * y) + 0.5);
}

void fill_graph(struct node* g, ifstream& input, int s){
    for(int i = 0; i < s; i++){
        input >> g[i].i;
        input >> g[i].x;
        input >> g[i].y;
    }
    return;
}

bool not_in(int n, int* arr, int s){
    for(int i = 0; i < s; i++)
        if(n == arr[i])
            return false;
    return true;
}

void get_mst(struct node* g, int s){
    int u, v, curr_min, new_min;//variables
    int used[s];
    struct edge edges[s - 1];
    for(int i = 0; i < s; i++)//set all used indicies to 0
        used[i] = 0;
    for(int i = 1; i < s; i++){//for each edge to add
        curr_min = INFINITY;//set the coming edge to add to infinity
        new_min = 0;
        for(int j = 0; j < i; j++)//for each index in used[]
            for(int k = 0; k < s; k++)//for each edge
                if(not_in(k, used, i)){//if k is not in used[]
                    new_min = distance(g[used[j]], g[k]);//extract the edge value from k to used[j]
                    if(new_min < curr_min){//replace edge to add with new edge if its smaller
                        curr_min = new_min;
                        u = k;
                        v = j;
                    }
                }
        used[i] = u;//add the found vertex to used[]
        edges[i - 1].u = u;
        edges[i - 1].v = v;
    }
    return;
}

/*****CHRISTOFIDES*****/
void chris_tsp(struct node* g, ofstream& output, int s){
    int sol[s + 1]; //solution, stop 1, stop 2...
    //struct edge* mst_edges = 
    get_mst(g, s);
    //struct node* odd_v = get_odd_degs(mst_edges, s);

    for(int i = 0; i <= s; i++)
        output << sol[i];
    return;
}

/*****NEAREST NEIGHBOR*****/
void nn_tsp(struct node* g, ofstream& output, int s){
    int sol[s + 1]; //solution, stop 1, stop 2...
    //Make adjacency matrix
    int dst_mtx[s][s];
    for(int i = 0; i < s; i++)
        for(int j = 0; j < s; j++)
            dst_mtx[i][j] = distance(g[i], g[j]);
    //Make and initialize variables
    int path[s];
    int curr_idx, curr_min;
    for(int i = 0; i < s; i++)
        path[i] = g[0].i;
    sol[1] = g[0].i;
    sol[0] = 0; 
    //Find closest neighbor to last node added
    for(int i = 0; i < s - 1; i++){
        curr_min = INFINITY;
        for(int j = 0; j < s; j++)
            if(not_in(g[j].i, path, s) && dst_mtx[path[i]][g[j].i] < curr_min){
                curr_min = dst_mtx[path[i]][g[j].i];
                curr_idx = g[j].i;
            }
        path[i + 1] = curr_idx;
        sol[i + 2] = curr_idx;
        sol[0] = sol[0] + curr_min;
    }
    //Add final edge leading back to the start 
    sol[0] = sol[0] + dst_mtx[sol[s]][sol[1]];
    //Output into file
    for(int i = 0; i <= s; i++)
        output << sol[i] << '\n';
    return;
}

int main(int argc, char** argv){
    int type = 1;//1 = nearest neighbor, 2 = christofide(incomplete)
    //Validate Input
    if(argc != 2)
        return 0;
    ifstream inf(argv[1]);
    if(inf.fail())
        return 0;
    //Create Graph
    int size;
    inf >> size;
    struct node graph[size];
    fill_graph(graph, inf, size);
    //Output TSP
    string fn = argv[1];
    ofstream outf(fn.append(".tour"));
    clock_t start = clock();
    if(type == 1)
        nn_tsp(graph, outf, size);
    if(type == 2)
        chris_tsp(graph, outf, size);
    clock_t end = clock();
    printf("Time: < %2.2f sec\n", (double(end - start)/CLOCKS_PER_SEC) + 0.01);
    return 0;
}