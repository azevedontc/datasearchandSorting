#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  clock_t inicio, fim;
  char nomeArquivo[80], nomeAlgoritimo[80];
  double tempo;
  int tipoArquivo, opcaoAlgoritmo, tam, op;
  int quantidade_numeros = 0;

  // Printa o menu do modelo de arquivo
  printaMenu();
  scanf("%d", &tipoArquivo);

  // Printa o menu do tamanho do arquivo
  printaMenu2();
  scanf("%d", &op);
  switch (op) {
  case 1:
    tam = 500000;
    break;
  case 2:
    tam = 750000;
    break;
  case 3:
    tam = 1000000;
    break;
  default:
    tam = 500000;
    break;
  }

  double *numeros = malloc(tam * sizeof(double));

  switch (tipoArquivo) {
  case 1:
    gerarCrescente(tam);
    sprintf(nomeArquivo, "files/crescente%d.txt", tam);
    break;
  case 2:
    gerarDecrescente(tam);
    sprintf(nomeArquivo, "files/decrescente%d.txt", tam);
    break;
  case 3:
    sprintf(nomeArquivo, "files/aleatório%d.txt", tam);
    gerarAleatorio(tam, tam);
    break;
  default:
    printf("Opção inválida!\n");
    break;
  }

  if (lerArquivo(nomeArquivo, numeros, tam) != 0) {
    printf("Erro ao ler o arquivo!\n");
    return 1;
  }

  // Printa o menu da escolha do algoritmo
  printaMenu3();
  scanf("%d", &opcaoAlgoritmo);
  switch (opcaoAlgoritmo) {
  case 1:
    inicio = clock();
    bubbleSort(tam, numeros);
    fim = clock();
    sprintf(nomeAlgoritimo, "BublleSort");
    break;

  case 2:
    inicio = clock();
    insertSort(tam, numeros);
    fim = clock();
    sprintf(nomeAlgoritimo, "InsertSort");
    break;

  case 3:
    inicio = clock();
    selectionSort(tam, numeros);
    fim = clock();
    sprintf(nomeAlgoritimo, "SelectionSort");
    break;

  case 4:
    inicio = clock();
    shellSort(tam, numeros);
    fim = clock();
    sprintf(nomeAlgoritimo, "ShellSort");
    break;
      
  case 5:
    inicio = clock();
    quickSort(tam, numeros);
    fim = clock();
    sprintf(nomeAlgoritimo, "QuickSort");
    break;

  default:
    printf("Opção inválida.\n");
    break;
  }

  for (int i = 0; i < 15; i++) {
    printf("%.2f \n", numeros[i]);
  }

  tempo = (fim - inicio) / CLOCKS_PER_SEC;
  printf("Tempo de execução: %.2f segundos.\n", tempo);

  FILE *arquivo_results = fopen("results.txt", "a");
  if (arquivo_results == NULL) {
    printf("Erro ao abrir o arquivo results.txt\n");
    return 1;
  }
  fprintf(arquivo_results,
          "Tempo de execução do arquivo %s usando o algoritimo %s: %.2f segundos.\n",
          nomeArquivo, nomeAlgoritimo, tempo);
  fclose(arquivo_results);
}