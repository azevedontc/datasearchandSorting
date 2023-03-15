#include <stdio.h>
#include <stdlib.h>

void insertionSort(int array[], int n) {
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = array[i];
    j = i - 1;
    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j = j - 1;
    }
    array[j + 1] = key;
  }
}

// int main() {
//   int array[] = {64, 34, 25, 12, 22, 11, 90};
//   int n = sizeof(array) / sizeof(array[0]);
//   insertionSort(array, n);
//   printf("Array ordenado: \n");
//   for (int i = 0; i < n; i++)
//     printf("%d ", array[i]);
//   return 0;
// }