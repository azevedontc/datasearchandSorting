#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void lerTxt() {
    FILE *ponteiro;
    int num[100]; // vetor para armazenar os valores lidos
    int i = 0;

    ponteiro = fopen("Ler.txt", "r");
    if (ponteiro == NULL) {
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }

    // ler os valores do arquivo e armazená-los no vetor
    while (fscanf(ponteiro, "%d", &num[i]) != EOF) {
        i++;
    }

    // imprime os valores armazenados no vetor
    for (int j = 0; j < i; j++) {
        printf("%d ", num[j]);
    }
    fclose(ponteiro);
}


void criartxtOrdenado(int tam){
  FILE * ponteiro;
  char nomeArquivo[255];
  sprintf(nomeArquivo, "Ordenado%dk.txt", tam);
  ponteiro = fopen(nomeArquivo, "w");

  if(ponteiro ==NULL){
    printf("Não foi possível criar o arquivo");
    exit(0);
  }

  // imprime os valores no arquivo .txt
  for(int cont = 1; cont <= tam; cont++){
    fprintf(ponteiro, "%d\n", cont);
  }
}