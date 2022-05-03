/*
 * This file is where you should implement your binary search tree.  It already
 * contains skeletons of the functions you need to implement (along with
 * documentation for each function).  Feel free to implement any additional
 * functions you might need.  Also, don't forget to include your name and
 * @oregonstate.edu email address below.
 *
 * Name: Ethan Largent
 * Email: largenet@oregonstate.edu
 */

#include <stdlib.h>
#include <stdio.h>

#include "bst.h"
#include "stack.h"

/*
 * This structure represents a single node in a BST.  In addition to containing
 * pointers to its two child nodes (i.e. `left` and `right`), it contains two
 * fields representing the data stored at this node.  The `key` field is an
 * integer value that should be used as an identifier for the data in this
 * node.  Nodes in the BST should be ordered based on this `key` field.  The
 * `value` field stores data associated with the key.
 *
 * You should not modify this structure.
 */
struct bst_node {
  int key;
  void* value;
  struct bst_node* left;
  struct bst_node* right;
};


/*
 * This structure represents an entire BST.  It specifically contains a
 * reference to the root node of the tree.
 *
 * You should not modify this structure.
 */
struct bst {
  struct bst_node* root;
};

/*
 * This function should allocate and initialize a new, empty, BST and return
 * a pointer to it.
 */
struct bst* bst_create() {
  struct bst* bst = malloc(sizeof(struct bst));
  bst->root = NULL;
  return bst;
}

/*
 * This function should free the memory associated with a BST.  While this
 * function should up all memory used in the BST itself, it should not free
 * any memory allocated to the pointer values stored in the BST.  This is the
 * responsibility of the caller.
 *
 * Params:
 *   bst - the BST to be destroyed.  May not be NULL.
 */
void bst_free(struct bst* bst) {
  if(!(bst->root))
    free(bst);
  struct bst_node* del = bst->root;
  if(del->left)
    del = del->left;
  else if(del->right)
    del = del->right;
  else{
    free(del);
    bst_free(bst);
  }
  return;
}

/*
 * This function should return the total number of elements stored in a given
 * BST.
 *
 * Params:
 *   bst - the BST whose elements are to be counted.  May not be NULL.
 */
int bst_size(struct bst* bst) {
  if(bst->root){
    struct bst * l_bst = malloc(sizeof(bst)), * r_bst = malloc(sizeof(bst));
    l_bst->root = bst->root->left;
    r_bst->root = bst->root->right;
    int size = 1 + bst_size(l_bst) + bst_size(r_bst);
    free(l_bst);
    free(r_bst);
    return size;
  }
  else
    return 0;
}

/*
 * This function should insert a new key/value pair into the BST.  The key
 * should be used to order the key/value pair with respect to the other data
 * stored in the BST.  The value should be stored along with the key, once the
 * right location in the tree is found.
 *
 * Params:
 *   bst - the BST into which a new key/value pair is to be inserted.  May not
 *     be NULL.
 *   key - an integer value that should be used to order the key/value pair
 *     being inserted with respect to the other data in the BST.
 *   value - the value being inserted into the BST.  This should be stored in
 *     the BST alongside the key.  Note that this parameter has type void*,
 *     which means that a pointer of any type can be passed.
 */
void bst_insert(struct bst* bst, int key, void* value) {
  struct bst_node* new = malloc(sizeof(struct bst_node));
  new->key = key;
  new->value = value;
  new->left = NULL;
  new->right = NULL;
  if(!(bst->root)){
    bst->root = new;
    return;
  }
  struct bst_node* prev = bst->root;
  while(1){
    if(prev->key > key){
      if(prev->left)
        prev = prev->left;
      else{
        prev->left = new;
        return;
      }
    }
    else{
      if(prev->right)
        prev = prev->right;
      else{
        prev->right = new;
        return;
      }
    } 
  }
}

/*
 * This function should remove a key/value pair with a specified key from a
 * given BST.  If multiple values with the same key exist in the tree, this
 * function should remove the first one it encounters (i.e. the one closest to
 * the root of the tree).
 *
 * Params:
 *   bst - the BST from which a key/value pair is to be removed.  May not
 *     be NULL.
 *   key - the key of the key/value pair to be removed from the BST.
 */
void bst_remove(struct bst* bst, int key) {
  struct bst_node* curr = bst->root, * prev = bst->root, * del;
  while(curr->key != key){
    if(!curr)
      return;
    if(curr->key > key){
      prev = curr;
      curr = curr->left;
    }
    else{
      prev = curr;
      curr = curr->right;
    }
  }
  del = curr;
  if(curr->left == NULL == curr->right){
    del = del;
  }
  else if(!(curr->left)){
    if(prev->left == curr)
      prev->left = curr->right;
    else if(prev->right == curr)
      prev->right = curr->right;
    else
      bst->root = curr->right;
  }
  else if(!(curr->right)){
    if(prev->left == curr)
      prev->left = curr->left;
    else if(prev->right == curr)
      prev->right = curr->left;
    else
      bst->root = curr->left;
  }
  else{
    del = curr->right;
    prev = curr;
    while(del->left){
      prev = del;
      del = del->left;
    }
    curr->key = del->key;
    curr->value = del->value;
    if(prev->left == del)
      prev->left = del->right;
    else
      prev->right = del->right;
  }
  free(del);
  return;
}

/*
 * This function should return the value associated with a specified key in a
 * given BST.  If multiple values with the same key exist in the tree, this
 * function should return the first one it encounters (i.e. the one closest to
 * the root of the tree).  If the BST does not contain the specified key, this
 * function should return NULL.
 *
 * Params:
 *   bst - the BST from which a key/value pair is to be removed.  May not
 *     be NULL.
 *   key - the key of the key/value pair whose value is to be returned.
 *
 * Return:
 *   Should return the value associated with the key `key` in `bst` or NULL,
 *   if the key `key` was not found in `bst`.
 */
void* bst_get(struct bst* bst, int key) {
  struct bst_node* curr = bst->root;
  while(curr){
    if(curr->key > key)
      curr = curr->left;
    else if(curr->key < key)
      curr = curr->right;
    else
      return curr->value;
  }
  return NULL;
}

/*****************************************************************************
 **
 ** BST puzzle functions
 **
 *****************************************************************************/

/*
 * This function should return the height of a given BST, which is the maximum
 * depth of any node in the tree (i.e. the number of edges in the path from
 * the root to that node).  Note that the height of an empty tree is -1 by
 * convention.
 *
 * Params:
 *   bst - the BST whose height is to be computed
 *
 * Return:
 *   Should return the height of bst.
 */
 int bst_height(struct bst* bst) {
  if(!(bst->root))
    return -1;
  int height = 0, l_height, r_height;
  if(bst->root){
    struct bst * l_bst = malloc(sizeof(bst)), * r_bst = malloc(sizeof(bst));
    l_bst->root = bst->root->left;
    r_bst->root = bst->root->right;
    l_height = bst_height(l_bst);
    r_height = bst_height(r_bst);
    if(l_height > r_height)
      height = 1 + l_height;
    else
      height = 1 + r_height;
    free(l_bst);
    free(r_bst);
    return height;
  }
   return 0;
 }

/*
 * This function should determine whether a specified value is a valid path
 * sum within a given BST.  In other words, this function should check whether
 * the given BST contains any path from the root to a leaf in which the keys
 * sum to the specified value.
 *
 * Params:
 *   bst - the BST whose paths sums to search
 *   sum - the value to search for among the path sums of `bst`
 *
 * Return:
 *   Should return 1 if `bst` contains any path from the root to a leaf in
 *   which the keys add up to `sum`.  Should return 0 otherwise.
 */
int bst_path_sum(struct bst* bst, int sum) {
  int l_sum = 0, r_sum = 0;
  if(bst->root == NULL || sum < 0)
    return 0;
  if(sum == 0 && bst->root->left == NULL && bst->root->right == NULL)
    return 1;
  if(bst->root->left){
    struct bst * l_bst = malloc(sizeof(bst));
    l_bst->root = bst->root->left;
    l_sum = bst_path_sum(l_bst, sum - (bst->root->key));
    free(l_bst);
  }
  if(bst->root->right){
    struct bst * r_bst = malloc(sizeof(bst));
    r_bst->root = bst->root->right;
    r_sum = bst_path_sum(r_bst, sum - (bst->root->key));
    free(r_bst);
  }
  if(l_sum == 1 || r_sum == 1)
    return 1;
}

/*
 * This function should compute a range sum in a given BST.  Specifically, it
 * should compute the sum of all keys in the BST between a given lower bound
 * and a given upper bound.  For full credit, you should not process any subtree
 * whose keys cannot be included in the range sum.
 *
 * Params:
 *   bst - the BST within which to compute a range sum
 *   lower - the lower bound of the range over which to compute a sum; this
 *     should be considered an *inclusive* bound; in other words a key that's
 *     equal to this bound should be included in the sum
 *   upper - the upper bound of the range over which to compute a sum; this
 *     should be considered an *inclusive* bound; in other words a key that's
 *     equal to this bound should be included in the sum
 *
 * Return:
 *   Should return the sum of all keys in `bst` between `lower` and `upper`.
 */
int bst_range_sum(struct bst* bst, int lower, int upper) {
  int size = 0;
  if(bst->root){
    struct bst * l_bst = malloc(sizeof(bst)), * r_bst = malloc(sizeof(bst));
    l_bst->root = bst->root->left;
    r_bst->root = bst->root->right;
    if(lower <= (bst->root->key) && (bst->root->key) <= upper)
      size = bst->root->key;
    size = size + bst_range_sum(l_bst, lower, upper) + bst_range_sum(r_bst, lower, upper);
    free(l_bst);
    free(r_bst);
  }
  return size;
}

/*****************************************************************************
 **
 ** BST iterator definition (extra credit only)
 **
 *****************************************************************************/

/*
 * Structure used to represent a binary search tree iterator.  It contains
 * only a reference to a stack to be used to implement the iterator.
 *
 * You should not modify this structure.
 */
struct bst_iterator {
  struct stack* stack;
};

/*
 * This function should allocate and initialize an iterator over a specified
 * BST and return a pointer to that iterator.
 *
 * Params:
 *   bst - the BST for over which to create an iterator.  May not be NULL.
 */
struct bst_iterator* bst_iterator_create(struct bst* bst) {
  return NULL;
}

/*
 * This function should free all memory allocated to a given BST iterator.
 * It should NOT free any memory associated with the BST itself.  This is the
 * responsibility of the caller.
 *
 * Params:
 *   iter - the BST iterator to be destroyed.  May not be NULL.
 */
void bst_iterator_free(struct bst_iterator* iter) {
  return;
}

/*
 * This function should indicate whether a given BST iterator has more nodes
 * to visit.  It should specifically return 1 (true) if the iterator has at
 * least one more node to visit or 0 (false) if it does not have any more
 * nodes to visit.
 *
 * Param:
 *   iter - the BST iterator to be checked for remaining nodes to visit.  May
 *     not be NULL.
 */
int bst_iterator_has_next(struct bst_iterator* iter) {
  return 0;
}

/*
 * This function should return both the value and key associated with the
 * current node pointed to by the specified BST iterator and advnce the
 * iterator to point to the next node in the BST (in in-order order).
 *
 * Because a function can't return two things, the key associated with the
 * current node should be returned the normal way, while its value should be
 * returned via the argument `value`.  Specifically, the argument `value`
 * is a pointer to a void pointer.  The current BST node's value (a void
 * pointer) should be stored at the address represented by `value` (i.e. by
 * dereferencing `value`).  This will look something like this:
 *
 *   *value = current_node->value;
 *
 * Parameters:
 *   iter - BST iterator.  The key and value associated with this iterator's
 *     current node should be returned, and the iterator should be updated to
 *     point to the next node in the BST (in in-order order).  May not be NULL.
 *   value - pointer at which the current BST node's value should be stored
 *     before this function returns.
 *
 * Return:
 *   This function should return the key associated with the current BST node
 *   pointed to by `iter`.
 */
int bst_iterator_next(struct bst_iterator* iter, void** value) {
  if (value) {
    *value = NULL;
  }
  return 0;
}
