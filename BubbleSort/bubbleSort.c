#include <stdio.h>

void bubbleSort(int array[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    // última i elementos já estão ordenados
    for (j = 0; j < n - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        // troca array[j] e array[j+1]
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

int main() {
  int array[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(array) / sizeof(array[0]);
  bubbleSort(array, n);
  printf("Array ordenado: \n");
  for (int i = 0; i < n; i++)
    printf("%d ", array[i]);
  return 0;
}
