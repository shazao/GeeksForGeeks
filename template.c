/*

*/

// Star: 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void main(int argc, char * argv[]) {

  if (argc != 2) {
    printf("Please specify the correct arguments.\n");
    return;
  }

  int n = atoi(argv[1]);

}

  int i = 0;
  int * arr = (int *)malloc(sizeof(int)*(argc-1));
  for (; i<argc-1; ++i)
    arr[i] = atoi(argv[i+1]);
  printf("\nArray: ");
  for (i=0; i<argc-1; ++i)
    printf("%d ", arr[i]);
  printf("\n");


  free(arr);
