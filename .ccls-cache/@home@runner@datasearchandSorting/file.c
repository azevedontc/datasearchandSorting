#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"

#define MAX_REGISTROS 1000

void printaMenu() {
  printf("Escolha uma opcao:\n");
  printf("1 - Gerar arquivo em ordem crescente\n");
  printf("2 - Gerar arquivo em ordem decrescente\n");
  printf("3 - Gerar arquivo em ordem aleatória\n");
}

void lerTxt(int tam) {
    FILE *ponteiro;
    int num[100]; // vetor para armazenar os valores lidos
    int i = 0;
    char line[100];

    ponteiro = fopen("Ler.txt", "r");
    if (ponteiro == NULL) {
      printf("Erro ao abrir o arquivo.");
      exit(1);
    }

    // ler os valores do arquivo e armazená-los no vetor
    while (fgets(line, sizeof(line), ponteiro) != NULL && i < tam) {
      num[i] = atof(line); // converte usando ATOF
      i++;
    }
  
    bubbleSort(num, tam);
  
    // imprime os valores armazenados no vetor
    for (int j = 0; j < i; j++) {
      printf("%d ", num[j]);
    }
    fclose(ponteiro);
}

void criartxtOrdenado(int tam){
  FILE * ponteiro;
  char nomeArquivo[255];
  clock_t fim, inicio = clock(); // pega horario do inicio
  sprintf(nomeArquivo, "Ordenado%d.txt", tam);
  // cria o nome do arquivo de acordo com o tamanho
  ponteiro = fopen(nomeArquivo, "w");

  if(ponteiro == NULL){
    printf("Não foi possível criar o arquivo");
    exit(0);
  }

  // imprime os valores no arquivo .txt
  for(int cont = 1; cont <= tam; cont++){
    fprintf(ponteiro, "%d\n", cont);
  }
  fim = clock(); // pega horario do final
  double tempo = (fim - inicio) / CLOCKS_PER_SEC;
  printf("\nTempo gasto %.2f\n", tempo);
  fclose(ponteiro);
}

void criartxtInvertido(int tam){
  FILE * ponteiro;
  char nomeArquivo[255];
  sprintf(nomeArquivo, "Invertido%d.txt", tam);
  // cria o nome do arquivo de acordo com o tamanho
  ponteiro = fopen(nomeArquivo, "w");
  
  if(ponteiro == NULL){
    printf("Não foi possível criar o arquivo");
    exit(0);
  }

  // imprime os valores no arquivo .txt
  for(int cont = tam; cont >= 1; cont--){
    fprintf(ponteiro, "%d\n", cont);
  }
  fclose(ponteiro);
}

void criartxtAleatorio(char *nomeArquivo, int tam, int val) {
    int i, j, temp, array[tam];
    FILE *fptr;
    fptr = fopen(nomeArquivo, "w");
    if (fptr == NULL) {
        printf("Não foi possível criar o arquivo");
        exit(1);
    }

    srand(time(NULL));
    for (i = 0; i < tam; i++) {
        array[i] = rand() % val;
        fprintf(fptr, "%d\n", array[i]);
    }

    bubbleSort(array, tam);

    fclose(fptr);

    fptr = fopen(nomeArquivo, "w");
    if (fptr == NULL) {
        printf("Não foi possível criar o arquivo");
        exit(1);
    }

    for (i = 0; i < tam; i++) {
        fprintf(fptr, "%d\n", array[i]);
    }
    fclose(fptr);
}