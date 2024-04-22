#include <stdio.h>

void selection(int* arr, int size) {
    int i, j, min, temp;
    
    for(i = 0; i < size - 1; i++) {
        min = i;
        for(j = i + 1; j < size; j++) {
            if(arr[min] > arr[j]) min = j;
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int array[] = {2, 3, 1, 6, 0};
    int i, size = sizeof(array) / sizeof(array[0]);
    
    selection(array, size);
    
    for(i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
    return 0;
}