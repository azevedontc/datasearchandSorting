#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int array[], int n) {
  clock_t fim, inicio = clock(); // pega horario do inicio
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
  fim = clock(); // pega horario do final
  double tempo = (fim - inicio) / CLOCKS_PER_SEC;
  printf("\nTempo gasto %.2f\n", tempo);
}