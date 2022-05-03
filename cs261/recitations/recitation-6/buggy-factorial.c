/*
 * This program should compute the factorial of a user-specified value, but
 * it's currently broken.  Use GDB and Valgrind to help debug it.
 *
 * H/T to Muhammed Emin Ozturk for the idea for this program:
 *   https://u.osu.edu/cstutorials/2018/09/28/how-to-debug-c-program-using-gdb-in-6-simple-steps/
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  if (argc < 2) {
    printf("Error: You must specify the value of n.\n");
    printf("\nusage: %s <n>\n", argv[0]);
    return 1;
  }

  /*
   * Convert user-specified value of n from a strint to an integer.
   */
  int n = strtol(argv[1], NULL, 0);
  if (n <= 0) {
    printf("Error: n must be a positive integer value.\n");
    printf("\nusage: %s <n>\n", argv[0]);
    return 1;
  }

  /*
   * Compute n!
   */
  int i, f = 1;
  for (i = 1; i <= n; i++) {
    f *= i;
  }
  printf("%d! = %d\n", n, f);

  return 0;
}
