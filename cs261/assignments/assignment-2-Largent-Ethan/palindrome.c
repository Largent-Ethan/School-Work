#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "queue.h"
#include "stack.h"

#define MAX_STR_LEN 256

/*
 * This function prompts the user for input and stores a maximum of `n`
 * characters of the string they enter into `dest`.  Any trailing line ending
 * characters are removed from the input string.  Returns 1 if a string was
 * successfully read from the user or 0 otherwise.
 */
int get_user_str(char* dest, int n) {
  printf("\nEnter a string, and we'll check whether it's a palindrome:\n");
  if (fgets(dest, MAX_STR_LEN, stdin) != NULL) {
    /*
     * If a string was successfully read from the user, remove any trailing
     * line ending characters.  Here's some documentation on strcspn() to help
     * understand how this works:
     *
     * https://en.cppreference.com/w/c/string/byte/strcspn
     */
    dest[strcspn(dest, "\r\n")] = '\0';
    return 1;
  } else {
    return 0;
  }
}

int main(int argc, char const *argv[]) {
  char* in = malloc(MAX_STR_LEN * sizeof(char));

  while (get_user_str(in, MAX_STR_LEN)) {
    /*
     * Inside this loop body, you'll have an input string from the user in `in`.
     * You should use your stack and your queue to test whether that string is
     * a palindrome (i.e. a string that reads the same backward as forward, e.g.
     * "ABCBA" or "Madam, I'm Adam").  For each string input by the user,
     * print a message letting the user know whether or not their string is
     * is a palindrome.
     *
     * When you test whether the user's string is a palindrome, you should
     * ignore any non-letter characters (e.g. spaces, numbers, punctuation,
     * etc.), and you should ignore the case of letters (e.g. the characters
     * 'a' and 'A' should be considered as equal).  The C functions isalpha()
     * and tolower() from ctype.h might help with this.
     */


  struct stack* s = stack_create(); //reversed word
  struct queue* q = queue_create(); //forward word
  int len = 0; //length of alphabetic word
  char s_cmp, q_cmp; //current letter
  int is_pal = 1; //is a palindrome (true by default)

//Fills queue and stack with alphabetic lower case letters and counts size
  for (int i = 0; i < strlen(in); i++) {
    if(isalpha(in[i])){
      len = len + 1;
      in[i] = tolower(in[i]);
      queue_enqueue(q, &in[i]);
      stack_push(s, &in[i]);
    }
  }

  printf("\n\n");

//Checks each letter in reversed word is equal to the forward word
  for(int i = 0; i < len / 2; i++){
    printf("== Testing...");
    s_cmp = *((char*)(stack_pop(s)));
    q_cmp = *((char*)(queue_dequeue(q)));
    if(s_cmp != q_cmp){
      printf(" Failed at letter %d and %d: %c != %c\n", i + 1, len - i, s_cmp, q_cmp);
      is_pal = 0;
      break;
    }
    printf(" Passed at letter %d and %d: %c != %c\n", i + 1, len - i, s_cmp, q_cmp);
  }

//Ouputs results
  if(is_pal == 1)
    printf("\n\n== Yes Palindrome: %s\n", in);
  else
    printf("\n\n== No Palindrome: %s\n", in);


  printf("\n\n");

  stack_free(s);
  queue_free(q);
  free(in);

  return 0;
  }
}
