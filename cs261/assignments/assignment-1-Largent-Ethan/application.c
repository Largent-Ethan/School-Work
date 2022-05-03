/*
 * In this file, you should implement an application that compares the
 * performance of a dynamic array and a linked list, as described in the
 * README. Don't forget to include your name and @oregonstate.edu email
 * address below.
 *
 * Name: Ethan Largent
 * Email: largenet@oregonstate.edu
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "dynarray.h"
#include "list.h"

#define TEST_DATA_SIZE 50000000

/*
 * This function generates and an array of random integers of size n.
 */
int* generate_random_array(int n) {
  int* arr = malloc(n * sizeof(int));
  int i;

  for (i = 0; i < n; i++) {
    arr[i] = rand();
  }

  return arr;
}

int main(int argc, char const *argv[]) {
  printf("== Making test data...\n\n");
  int* test_data = generate_random_array(TEST_DATA_SIZE);

  /*
   * You should write code here to insert the data in test_data into a
   * dynamic array using the dynamic array interface you implemented.  As
   * you're doing this, measure two things:
   *   1. The total amount of time it takes to insert all the data into the
   *      dynamic array.
   *   2. The maximum amount of time it takes to insert any single element into
   *      the dynamic array.
   * To help with this, you can use the C functions time() and difftime()
   * from time.h.  Don't forget to include time.h above!
   */

  time_t start, end, m_start, m_end;
  double dynmax = 0, listmax = 0;

  printf("\n== Creating dynamic array...\n");
  struct dynarray* da;
  da = dynarray_create();
  time(&start);

  printf("== Filling dynamic array...\n");
  for (int i = 0; i < TEST_DATA_SIZE; i++){
    time(&m_start);
    dynarray_insert(da, &test_data[i]);
    time(&m_end);
    if(difftime(m_end, m_start) > dynmax)
      dynmax = m_end - m_start;
  }
  time(&end);

  printf("== Took %f seconds to fill the array.\n", difftime(end, start));
  printf("== Took %f seconds max for one item.\n\n", dynmax);

  printf("== Freeing dynamic array...\n");
  dynarray_free(da);

   /*
    * You should write code here to insert the data in test_data into a
    * linked list using the linked list interface you implemented.  As
    * you're doing this, measure two things:
    *   1. The total amount of time it takes to insert all the data into the
    *      linked list.
    *   2. The maximum amount of time it takes to insert any single element into
    *      the linked list.
    * Again, you can use the C functions time() and difftime() from time.h to
    * help with this.
    *
    * How do the times associated with the dynamic array compare to the times
    * associated with the linked list?  How does this change if you modify the
    * value of TEST_DATA_SIZE above?
    */

  printf("\n== Creating linked list...\n");
  struct list* li;
  li = list_create();
  time(&start);
  
  printf("== Filling linked list...\n");
  for (int i = 0; i < TEST_DATA_SIZE; i++){
    time(&m_start);
    list_insert(li, &test_data[i]);
    time(&m_end);
    if(difftime(m_end, m_start) > listmax)
      listmax = m_end - m_start;
  }
  time(&end);

  printf("== Took %f seconds to fill the list.\n", difftime(end, start));
  printf("== Took %f seconds max for one item.\n\n", listmax);
  
  printf("== Freeing linked list...\n");
  list_free(li);

  printf("== Freeing test data...\n");
  free(test_data);

  return 0;
}
