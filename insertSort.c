#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int array[], int n) {
  clock_t fim, inicio = clock(); // pega horario do inicio
  int i, aux, j;
  for (i = 1; i < n; i++) {
    aux = array[i];
    j = i - 1;
    while (j >= 0 && array[j] > aux) {
      array[j + 1] = array[j];
      j = j - 1;
    }
    array[j + 1] = aux;
  }
  fim = clock(); // pega horario do final
  double tempo = (fim - inicio) / CLOCKS_PER_SEC;
  printf("\nTempo gasto %.2f\n", tempo);
}