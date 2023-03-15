#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define LIM 500000

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

void criarTxtordenado(int tam){
  FILE * ponteiro;
  char nomeArquivo[255];
  sprintf(nomeArquivo, "Ordenado%dk.txt", tam);
  ponteiro = fopen(nomeArquivo, "w");

  if(ponteiro ==NULL){
    printf("Não foi possível criar o arquivo");
    exit(0);
  }
  
  for(int cont = 1; cont <= tam; cont++){
    fprintf(ponteiro, "%d", cont);
  }
}