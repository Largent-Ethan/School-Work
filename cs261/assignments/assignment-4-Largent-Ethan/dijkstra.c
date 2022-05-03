/*
 * In this file, you'll implement Dijkstra's algorithm to find the least
 * expensive paths in the graph defined in `airports.dat`.  Don't forget to
 * include your name and @oregonstate.edu email address below.
 *
 * Name: Ethan Largent
 * Email: largenet@oregonstate.edu
 */

#include <stdio.h>
#include <stdlib.h>

#include "pq.h"
#include "dynarray.h"

#define DATA_FILE "airports.dat"
#define START_NODE 0


int main(int argc, char const *argv[]) {

  FILE* fp;
  int size, paths;
  fp = fopen("airports.dat", "r");
  fscanf(fp, "%d", &size);
  int map[size][size];
  for(int i = 0; i < size; i++)
    for(int j = 0; j < size; j++)
      map[i][j] = 0;
  fscanf(fp, "%d", &paths);
  for(int i = 0; i < paths; i++){
    int start, end, cost;
    fscanf(fp, "%d", &start);
    fscanf(fp, "%d", &end);
    fscanf(fp, "%d", &cost);
    map[start][end] = cost;
  }
  fclose(fp);

  printf("S  E");
  for(int i = 0; i < size; i++)
    printf("%3d:  ", i);
  printf("\n");
  for(int i = 0; i < size; i++){
    printf("%d: ", i);
    for(int j = 0; j < size; j++){
      printf(" %3d |", map[i][j]);
    }
    printf("\n");
  }
  printf("\nwell, well, well... what to do now...\n\n");


  return 0;
}
