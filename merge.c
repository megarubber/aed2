#include <stdio.h>

void divide(int* array, int s, int m, int f) {
  int i, j, k;
  int n1 = (m - s) + 1;
  int n2 = f - m;

  int L1[n1], L2[n2];

  for(i = 0; i < n1; i++)
    L1[i] = array[s + i];
  for(i = 0; i < n2; i++)
    L2[i] = array[m + 1 + i];

  i = 0;
  j = 0;
  k = s;

  while(i < n1 && j < n2) {
    if(L1[i] <= L2[j]) {
      array[k] = L1[i];
      i++;
    } else {
      array[k] = L2[j];
      j++;
    }
    k++;
  }

  while(i < n1) {
    array[k] = L1[i];
    i++;
    k++;
  }

  while(j < n2) {
    array[k] = L2[j];
    j++;
    k++;
  }
}

void merge(int* array, int s, int f) {
  if(s < f) {
    int m = s + (f - s) / 2;
    merge(array, s, m);
    merge(array, m + 1, f); 
    divide(array, s, m, f);
  }
}

int main() {
  int i, array[] = {2, 4, 5, 7, 8, 1};
  int size = sizeof(array) / sizeof(array[0]);

  merge(array, 0, size - 1);

  for(i = 0; i < size; i++)
    printf("%d ", array[i]);
  printf("\n");
  return 0;
}
