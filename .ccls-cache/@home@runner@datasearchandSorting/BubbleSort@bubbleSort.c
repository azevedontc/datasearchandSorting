#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bubbleSort(int array[], int n) {
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
}

void lerTxt(){
    FILE *fp;
    int arr[MAX_SIZE];
    int i, size = 0;

    fp = fopen("numbers.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%d", &arr[size]) != EOF) {
        size++;
    }

    fclose(fp);

    bubbleSort(arr, size);

    printf("Sorted array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void criarTxt(){
    FILE * ponteiro;
  char nomeArquivo[255];

  if(ponteiro ==NULL){
    printf("Não foi possível criar o arquivo");
    exit(0);
  }

  sprintf(ponteiro, "Ordenado500k.txt", LIM);
  ponteiro = fopen("nomeArquivo", "w");

  for(int cont = 1; cont <= LIM; cont++);
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