#include <stdio.h>

int partition(int* arr, int p, int r) {
  int pivot = arr[r];
  int i = p - 1, j, temp;
  for(j = p; j < r - 1; j++) {
    if(arr[j] <= pivot) {
      i++;
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  temp = arr[i + 1];
  arr[i + 1] = arr[r];
  arr[r] = temp;
  return i + 1;
}

void quick(int* arr, int p, int r) {
  int q;
  if(p < r) {
    q = partition(arr, p, r);
    quick(arr, p, q - 1);
    quick(arr, q + 1, r);
  }
}

int main() {
  int i;
  int array[] = {3, 2, 7, 9, 0};
  quick(array, 0, 4);
  for(i = 0; i < 5; i++)
    printf("%d ", array[i]);
  printf("\n");
  return 0;
}
