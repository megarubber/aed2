#include <stdio.h>

void bubble(int* array, int n) {
  int i, j, temp;
  for(i = 1; i < n; i++) {
    for(j = 0; j < n - 1; j++) {
      if(array[j] > array[j + 1]) {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

int main() {
  int i;
  int array[] = {3, 2, 7, 9, 0};
  bubble(array, 5);
  for(i = 0; i < 5; i++)
    printf("%d ", array[i]);
  printf("\n");
  return 0;
}
