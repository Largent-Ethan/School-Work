/*
 * In this file, you will write the structures and functions needed to
 * implement a priority queue.  Feel free to implement any helper functions
 * you need in this file to implement a priority queue.  Make sure to add your
 * name and @oregonstate.edu email address below:
 *
 * Name: Ethan Largent
 * Email: largenet@oregonstate.edu
 */

#include <stdlib.h>
#include <stdio.h>

#include "pq.h"
#include "dynarray.h"

struct pq_node{
  void* val;
  int p;
};

/*
 * This is the structure that represents a priority queue.  You must define
 * this struct to contain the data needed to implement a priority queue.
 */

struct pq{
  struct dynarray* data;
};


/*
 * This function should allocate and initialize an empty priority queue and
 * return a pointer to it.
 */
struct pq* pq_create() {
  struct pq* pq = malloc(sizeof(struct pq));
  pq->data = dynarray_create();
  return pq;
}


/*
 * This function should free the memory allocated to a given priority queue.
 * Note that this function SHOULD NOT free the individual elements stored in
 * the priority queue.  That is the responsibility of the caller.
 *
 * Params:
 *   pq - the priority queue to be destroyed.  May not be NULL.
 */
void pq_free(struct pq* pq) {
  dynarray_free(pq->data);
  free(pq);
  return;
}


/*
 * This function should return 1 if the specified priority queue is empty and
 * 0 otherwise.
 *
 * Params:
 *   pq - the priority queue whose emptiness is to be checked.  May not be
 *     NULL.
 *
 * Return:
 *   Should return 1 if pq is empty and 0 otherwise.
 */
int pq_isempty(struct pq* pq) {
  if(dynarray_size(pq->data) > 0)
    return 0;
  return 1;
}

void pq_swap(struct dynarray* data, int idx1, int idx2){
  void* to_swap = dynarray_get(data, idx2);
  dynarray_set(data, idx2, dynarray_get(data, idx1));
  dynarray_set(data, idx1, to_swap);
  return;
}

void pq_balance_up(struct dynarray* data, int cidx, int pidx){
  if(((struct pq_node*)dynarray_get(data, pidx))->p > ((struct pq_node*)dynarray_get(data, cidx))->p){
    pq_swap(data, cidx, pidx);
    return pq_balance_up(data, pidx, (pidx - 1) / 2);
  }
  else
    return;
}

/*
 * This function should insert a given element into a priority queue with a
 * specified priority value.  Note that in this implementation, LOWER priority
 * values are assigned to elements with HIGHER priority.  In other words, the
 * element in the priority queue with the LOWEST priority value should be the
 * FIRST one returned.
 *
 * Params:
 *   pq - the priority queue into which to insert an element.  May not be
 *     NULL.
 *   value - the value to be inserted into pq.
 *   priority - the priority value to be assigned to the newly-inserted
 *     element.  Note that in this implementation, LOWER priority values
 *     should correspond to elements with HIGHER priority.  In other words,
 *     the element in the priority queue with the LOWEST priority value should
 *     be the FIRST one returned.
 */
void pq_insert(struct pq* pq, void* value, int priority) {
  printf("%d, ", priority);
  struct pq_node* node = malloc(sizeof(struct pq_node));
  node->val = value;
  node->p = priority;
  dynarray_insert(pq->data, node);
  pq_balance_up(pq->data, dynarray_size(pq->data) - 1, (dynarray_size(pq->data) - 2) / 2);
  return;
}


/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
void* pq_first(struct pq* pq) {
  return ((struct pq_node*)(dynarray_get(pq->data, 0)))->val;
}


/*
 * This function should return the priority value of the first item in a
 * priority queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a priority value.  May not be
 *     NULL or empty.
 *
 * Return:
 *   Should return the priority value of the first item in pq, i.e. the item
 *   with LOWEST priority value.
 */
int pq_first_priority(struct pq* pq) {
  return ((struct pq_node*)(dynarray_get(pq->data, 0)))->p;
}

void pq_balance_down(struct dynarray* data, int index){
  if(index * 2 + 1 <= (dynarray_size(data) - 1)){
    if(((struct pq_node*)dynarray_get(data, index * 2 + 1))->p < ((struct pq_node*)dynarray_get(data, index))->p){
      pq_swap(data, index, index * 2 + 1);
      pq_balance_down(data, index * 2 + 1);
    }
  if(index * 2 + 2 <= (dynarray_size(data) - 1))
    if(((struct pq_node*)dynarray_get(data, index * 2 + 2))->p < ((struct pq_node*)dynarray_get(data, index))->p){
      pq_swap(data, index, index * 2 + 2);
      pq_balance_down(data, index * 2 + 2);
    }
  }
  return;
}

/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value, and then remove that item
 * from the queue.
 *
 * Params:
 *   pq - the priority queue from which to remove a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
void* pq_remove_first(struct pq* pq) {
  void* value = pq_first(pq);
  dynarray_set(pq->data, 0, dynarray_get(pq->data, dynarray_size(pq->data) - 1));
  dynarray_remove(pq->data, dynarray_size(pq->data) - 1);
  pq_balance_down(pq->data, 0);
  return value;
}
