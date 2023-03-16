#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

#define MAX_REGISTROS 1000

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
}

// função para gerar um número aleatório entre min e max
int gerar_numero_aleatorio(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void criartxtAleatorio(char * nome_arquivo, int num_registros) {
    FILE * arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Não foi possível criar o arquivo %s\n", nome_arquivo);
        return;
    }

    srand(time(NULL));
    for (int i = 0; i < num_registros; i++) {
        int numero = gerar_numero_aleatorio(1, 1000);
        fprintf(arquivo, "%d\n", numero);
    }

    fclose(arquivo);
}