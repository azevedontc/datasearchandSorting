#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"

#define MAX_REGISTROS 1000

void printaMenu() {
  printf("\nDigite o tamanho do arquivo: ");
  printf("\n1 para 500000\n2 para 750000\n3 para 1000000\n");
}

void printaMenu2() {
  printf("\nEscolha uma opção: \n");
  printf("1 - Gerar arquivo em ordem crescente\n");
  printf("2 - Gerar arquivo em ordem decrescente\n");
  printf("3 - Gerar arquivo em ordem aleatória\n");
}

void printaMenu3() {
  printf("\nQual método de ordenação utilizar?\n");
  printf("1: BubbleSort\n");
  printf("2: InsertSort\n");
  printf("3: SelectionSort\n");
}

void bubbleSort(int tamanho, double *vetor) {
  int i, j;
  double temp;
  for (i = 0; i < tamanho - 1; i++) {
    for (j = 0; j < tamanho - i - 1; j++) {
      if (vetor[j] > vetor[j + 1]) {
        temp = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = temp;
      }
    }
  }
}

void insertSort(int tamanho, double *vetor) {
  int i, j;
  double temp;
  for (i = 1; i < tamanho; i++) {
    temp = vetor[i];
    j = i - 1;
    while (j >= 0 && vetor[j] > temp) {
      vetor[j + 1] = vetor[j];
      j--;
    }
    vetor[j + 1] = temp;
  }
}

void selectionSort(int tamanho, double *vetor) {
  int i, j, pos_menor;
  double temp;

  for (i = 0; i < tamanho - 1; i++) {
    pos_menor = i;
    for (j = i + 1; j < tamanho; j++) {
      if (vetor[j] < vetor[pos_menor]) {
        pos_menor = j;
      }
    }
    if (pos_menor != i) {
      temp = vetor[i];
      vetor[i] = vetor[pos_menor];
      vetor[pos_menor] = temp;
    }
  }
}


int lerArquivo(char *nome_arquivo, double *numeros, int TAMANHO_MAXIMO) {
  int i = 0;
  char linha[100];
  FILE *arquivo;

  arquivo = fopen(nome_arquivo, "r");

  if (arquivo == NULL) {
    printf("Não foi possível abrir o arquivo.\n");
    return 1;
  }

  while (i < TAMANHO_MAXIMO && fgets(linha, 100, arquivo) != NULL) {
    numeros[i] = atof(linha); 
    i++;
  }

  fclose(arquivo);

  return 0;
}

void gerarCrescente(int tam) {
  FILE *fp;
  char nomeArquivo[255];
  sprintf(nomeArquivo, "files/crescente%d.txt", tam);
  fp = fopen(nomeArquivo, "w");
  if (fp == NULL) {
    printf("Erro na abertura do arquivo.");
    exit(0);
  }

  for (int cont = 1; cont <= tam; cont++) {
    fprintf(fp, "%d\n", cont);
  }
  fclose(fp);
}

void gerarDecrescente(int tam) {
  FILE *fp;
  char nomeArquivo[255];
  sprintf(nomeArquivo, "files/decrescente%d.txt", tam);
  fp = fopen(nomeArquivo, "w");
  if (fp == NULL) {
    printf("Erro na abertura do arquivo.");
    exit(0);
  }
  for (int cont = tam; cont >= 1; cont--) {
    fprintf(fp, "%d\n", cont);
  }
  fclose(fp);
}

void gerarAleatorio(int tam, int max) {
  FILE *arquivo;
  char nomeArquivo[80];
  int numero;

  sprintf(nomeArquivo, "files/aleatório%d.txt", tam);
  
  arquivo = fopen(nomeArquivo, "w");
  
  srand(time(NULL));

  for (int i = 0; i < tam; i++) {
    numero = rand() % max + 1;
    fprintf(arquivo, "%d\n", numero);
  }
  fclose(arquivo);
}