/*
 * This file contains a few basic structure and function definitions for a
 * singly-linked list.  The list is defined in such a way as to hide its
 * internal implementation details from code outside this file.
 */

#include <stdlib.h>

#include "list.h"

/*
 * This structure is used to represent a single link in a singly-linked list.
 * For simplicity, this structure can only store integer values.  Note that
 * this structure is not defined in list.h, so it is not visible outside this.
 * file.  In other words, link structures can only be used within the current
 * file.
 */
struct link {
  int val;
  struct link* next;
};

/*
 * This structure is used to represent an entire singly-linked list.  Note that
 * only a forward declaration of this structure is present in list.h.  This
 * means that, while code outside the current file can use list structures,
 * that code cannot access the internals of a list structure.  For example,
 * code outside the current file can't access any fields of the list structure,
 * and pointers to list structures can't be dereferenced outside this file.
 */
struct list {
  struct link* head;
};


/*
 * This function allocates, initializes, and fills a small linked list and
 * returns a pointer to it.
 */
struct list* list_setup() {
  struct list* list = malloc(sizeof(struct list));
  struct link* next = NULL;
  int i;

  for (i = 10; i > 0; i--) {
    struct link* link = malloc(sizeof(struct link));
    link->val = i;
    link->next = next;
    next = link;
  }
  list->head = next;
  return list;
}
