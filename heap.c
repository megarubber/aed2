#include <stdio.h>

void maxheapify(int *arr, int i, int n) {
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int largest = i, temp, size = n - 1;

  if(l < size && arr[l] > arr[i])
    largest = l;
  if(r < size && arr[r] > arr[largest])
    largest = r;

  if(largest != i) {
    temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
    maxheapify(arr, largest, n);
  }
}

void buildmaxheap(int* arr, int n) {
  int i;
  int start = (n / 2) - 1;
  for(i = start; i >= 0; i--)
    maxheapify(arr, i, n);
}

void heap(int* arr, int n) {
  buildmaxheap(arr, n);
  int i, temp;
  int size = n;

  for(i = n - 1; i > 1; i--) {
    temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    size--;
    maxheapify(arr, 0, size);
  } 
}

int main() {
  int i;
  int array[] = {3, 2, 7, 9, 0};
  heap(array, 5);
  //buildmaxheap(array, 5);
  for(i = 0; i < 5; i++)
    printf("%d ", array[i]);
  printf("\n");
  return 0;
}
