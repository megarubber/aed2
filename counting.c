#include <stdio.h>

void counting(int* a, int size) {
  int i, k = a[0];

  for(i = 0; i < size; i++)
    if(a[i] > k) k = a[i];

  int c[k + 1], b[size];

  for(i = 0; i < k + 1; i++)
    c[i] = 0;

  for(i = 0; i < size; i++)
    c[a[i]]++;

  for(i = 1; i <= k; i++)
    c[i] += c[i - 1];

  for(i = size - 1; i >= 0; i--) {
    b[c[a[i]] - 1] = a[i];
    c[a[i]]--;
  }

  for(i = 0; i < size; i++)
    a[i] = b[i];
}

int main() {
  int array[] = {6, 4, 7, 2, 8};
  int i, size = sizeof(array) / sizeof(array[0]);

  counting(array, size);

  for(i = 0; i < size; i++)
    printf("%d ", array[i]);
  printf("\n");
  return 0;
}
