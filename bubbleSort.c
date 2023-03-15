#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int array[], int n) {
<<<<<<< HEAD
  clock_t fim, inicio = clock(); // pega horario do inicio
=======
  clock_t fim, inicio = clock(); //pega horario do inicio
>>>>>>> a1016d252cc35d460c87b2442708743f5f47ca1b
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
<<<<<<< HEAD
  fim = clock(); // pega horario do final
=======
  fim = clock();
>>>>>>> a1016d252cc35d460c87b2442708743f5f47ca1b
  double tempo = (fim - inicio) / CLOCKS_PER_SEC;
  printf("\nTempo gasto %.2f\n", tempo);
}