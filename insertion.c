#include <stdio.h>

void insertion(int* array, int size) {
  int i, j, x;

  for(i = 1; i < size; i++) {
    x = array[i];
    j = i - 1;

    while(j >= 0 && array[j] > x) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = x;
  } 
}

int main() {
  int array[] = {3, 2, 7, 9, 0};
  int i, size = sizeof(array) / sizeof(array[0]);

  insertion(array, size);
  for(i = 0; i < size; i++)
    printf("%d ", array[i]);
  printf("\n");

  return 0;
}
