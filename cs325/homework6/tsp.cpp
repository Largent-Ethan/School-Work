#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct node{
    int i;//index
    int x;//x-coordinate
    int y;//y-coordinate
};

/*********************************************************************
** Function: distance
** Description: return the distance between two euclidian points (u and v) in a plane
** Parameters: node, node
** Pre-Conditions: two nodes with valid coordinates
** Post-Conditions: int
*********************************************************************/
int distance(struct node u, struct node v){
    int x = u.x - v.x;
    int y = u.y - v.y;
    return (sqrt(x * x + y * y) + 0.5);
}

/*********************************************************************
** Function: fill_graph
** Description: fill an array of nodes of size s with data provided in a file
** Parameters: node*, ifstream&, int
** Pre-Conditions: node* is an array with a size equal to int s
** Post-Conditions: void
*********************************************************************/
void fill_graph(struct node* g, ifstream& input, int s){
    for(int i = 0; i < s; i++){
        input >> g[i].i;
        input >> g[i].x;
        input >> g[i].y;
    }
    return;
}

/*********************************************************************
** Function: not_in
** Description: checks that an int is not in an array of integers of size s
** Parameters: int, int*, int
** Pre-Conditions: int* is an array with a size equal to int s
** Post-Conditions: bool
*********************************************************************/
bool not_in(int n, int* arr, int s){
    for(int i = 0; i < s; i++)
        if(n == arr[i])
            return false;
    return true;
}

/*********************************************************************
** Function: tsp
** Description: finds the smallest path between an array of nodes where the
    same node is never visited twice returning to its initial node, returns
    an approximate solution to a file including the distance and path took
** Parameters: node*, ofstream&, s
** Pre-Conditions: node* is an array with a size equal to int s
** Post-Conditions: void
*********************************************************************/
void tsp(struct node* g, ofstream& output, int s){
    int solution[s + 1]; //Format: {solution, stop 1, stop 2... stop s}
    //Make Adjacency/Distance Matrix
    int dst_mtx[s][s];
    for(int i = 0; i < s; i++)
        for(int j = 0; j < s; j++)
            dst_mtx[i][j] = distance(g[i], g[j]);
    //Make and Initialize Variables
    int path[s];
    int curr_idx, curr_min;
    for(int i = 0; i < s; i++)
        path[i] = g[0].i;
    solution[1] = g[0].i;
    solution[0] = 0; 
    //Find Closest Neighbor to Last Node Added in Path
    for(int i = 0; i < s - 1; i++){
        curr_min = INFINITY;
        for(int j = 0; j < s; j++)
            if(not_in(g[j].i, path, s) && dst_mtx[path[i]][g[j].i] < curr_min){
                curr_min = dst_mtx[path[i]][g[j].i];
                curr_idx = g[j].i;
            }
        path[i + 1] = curr_idx;
        solution[i + 2] = curr_idx;
        solution[0] = solution[0] + curr_min;
    }
    //Add Final Edge Leading Back to the Start 
    solution[0] = solution[0] + dst_mtx[solution[s]][solution[1]];
    //Output into File
    for(int i = 0; i <= s; i++)
        output << solution[i] << '\n';
    return;
}

int main(int argc, char** argv){
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
    //Output and Time TSP
    string fn = argv[1];
    ofstream outf(fn.append(".tour"));
    clock_t start = clock();
    tsp(graph, outf, size);
    clock_t end = clock();
    printf("Time: < %2.2f sec\n", (double(end - start)/CLOCKS_PER_SEC) + 0.01);
    return 0;
}