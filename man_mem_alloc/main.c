#include <stdlib.h> // malloc(), calloc(), free()
#include <stdio.h> // printf()
#include <string.h> // memset()
/* Chapter Notes:
 malloc(bytes to allocate) returns void pntr to block of new memory

 free(ptr from malloc) will free memory region allocated by malloc

 malloc() will return NULL if the memory cannot be allocate for some reason

 char *array = malloc(3490); array of 3490 chars

 There is no initialization on newly-allocated memory, we can clear it with
 memset() or use calloc()

 calloc(size of element, how many elements), the newly-allocated memory will
 be set to zero when allocated with calloc()

 realloc() can be used to add more space to memory allocated by malloc or calloc
 it will return a pointer to the start of the chunk of memory. This pointer may be
 different to the pointer returned by malloc if the memory had to be moved else where.
 
 
 */
int main(void) {
  // ----------------------- malloc with basics
  int *p = malloc(sizeof *p); // same as malloc(sizeof(int)) since *p is an int
  *p = 12; // store 12 in int

  if (p == NULL) {
    printf("Error allocating int\n");
    return 1;
  } else {
    printf("%d\n", *p); 
    free(p); // free memory created by malloc
  }

  // ------------------------ malloc array with memset()
  int *arr = malloc(sizeof(int) * 10); // array of 10 ints
  memset(arr, 0, sizeof(int) * 10); // zero set values in array

  for (int i = 0; i < 10; i++) {
    arr[i] = i * 5;
  }

  for (int i = 0; i < 10; i++) {
    printf("%d\n", arr[i]);
  }

  free(arr);

  // ----------------------- calloc array
  int *p2 = calloc(sizeof(int), 10);
  for (int i = 0; i < 10; i++) {
    printf("%d\n", p2[i]);
  }
  free(p2);

  // -------------------------- realloc
  float *fl = malloc(sizeof *fl * 20);

  for (int i = 0; i < 20; i++) {
    fl[i] = i / 20.0;
  }

  float *new_fl = realloc(fl, sizeof *fl * 40); // make this an array of 40 elements

  if (new_fl == NULL) {
    printf("Error reallocating\n");
    return 1;
  }

  fl = new_fl; // reassign fl

  for (int i = 20; i < 40; i++) {
    fl[i] = 1.0 + (i - 20) / 20.0;
  }

  for (int i = 0; i < 40; i++) {
    printf("%f\n", fl[i]);
  }

  free(fl);
  
  return 0;
}