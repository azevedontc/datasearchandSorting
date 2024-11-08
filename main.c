#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  clock_t inicio, fim;
  char nomeArquivo[80], nomeAlgoritimo[80];
  double results;
  int tipoArquivo, opcaoAlgoritmo, tam, op, search, operacoes = 0;
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
    tam = 15;
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

  printaMenu3();
  scanf("%d", &opcaoAlgoritmo);
  switch (opcaoAlgoritmo) {
  case 1:
    inicio = clock();
    bubbleSort(numeros, tam);
    fim = clock();
    sprintf(nomeAlgoritimo, "BublleSort");
    break;

  case 2:
    inicio = clock();
    insertSort(numeros, tam);
    fim = clock();
    sprintf(nomeAlgoritimo, "InsertSort");
    break;

  case 3:
    inicio = clock();
    selectionSort(numeros, tam);
    fim = clock();
    sprintf(nomeAlgoritimo, "SelectionSort");
    break;

  case 4:
    inicio = clock();
    shellSort(numeros, tam);
    fim = clock();
    sprintf(nomeAlgoritimo, "ShellSort");
    break;

  case 5:
    inicio = clock();
    quickSortHoare(numeros, tam);
    fim = clock();
    sprintf(nomeAlgoritimo, "QuickSortHoare");
    break;

  case 6:
    inicio = clock();
    quickSortLomuto(numeros, tam);
    fim = clock();
    sprintf(nomeAlgoritimo, "QuickSortLomuto");
    break;

  case 7:
    inicio = clock();
    mergeSort(numeros, 0, tam);
    fim = clock();
    sprintf(nomeAlgoritimo, "MergeSort");
    break;

  case 8:
    inicio = clock();
    radixSort(numeros, tam);
    fim = clock();
    sprintf(nomeAlgoritimo, "RadixSort");
    break;

  case 9:
    inicio = clock();
    heapSort(numeros, tam);
    fim = clock();
    sprintf(nomeAlgoritimo, "HeapSort");
    break;

  default:
    printf("Opção inválida.\n");
    break;
  }

  // Printa 15 números para verificação da funcionalidade do algoritmo
  printf("\n");
  for (int i = 0; i < 15; i++) {
    printf("%.2f \n", numeros[i]);
  }
  printf("\n");

  double tempo_execucao = times(inicio);
  
  // Printa o resultado da execução no arquivo "results.txt"
  FILE *arquivo_results = fopen("results.txt", "a");
  if (arquivo_results == NULL) {
    printf("Erro ao abrir o arquivo results.txt\n");
    return 1;
  }
  fprintf(arquivo_results,
          "Tempo de execução do arquivo %s usando o algoritimo %s: %.4f "
          "segundos.\n",
          nomeArquivo, nomeAlgoritimo, tempo_execucao);
  fclose(arquivo_results);

// --------------------------------------------------
// SEARCH - PESQUISA
// --------------------------------------------------

  inicio = clock();
  printf("\nQual número buscar? \n");
  scanf("%d", &search);
  buscaBinaria(numeros, 0, tam-1, search, &operacoes);
  fim = clock();
  printf("\nA quantidade de operações para encontrar o valor: %d foi de: %d operações", search, operacoes);
}