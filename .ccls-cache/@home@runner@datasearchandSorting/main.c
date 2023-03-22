#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"

int main() {
  clock_t inicio, fim;
  char nomeArquivo[80], nomeAlgoritimo[80];
  double tempo;
  int tipoArquivo, opcaoAlgoritmo, tam, op;
  int quantidade_numeros = 0;

  printaMenu();
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
    tam = 1000;
    break;
  }
  
  printaMenu2();
  scanf("%d", &tipoArquivo);
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
    printf("Opcao invalida.\n");
    break;
  }

  double *numeros = malloc(tam * sizeof(double));

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
    
  default:
    printf("Opção inválida.\n");
    break;
  }
  
  if (lerArquivo(nomeArquivo, numeros, tam) != 0) {
    printf("Erro ao ler o arquivo.\n");
    return 1;
  }
  
  tempo = (fim - inicio) / CLOCKS_PER_SEC;
  printf("Tempo de execução: %f segundos\n", tempo);

  FILE *arquivo_resultados = fopen("resultados.txt", "a");
  if (arquivo_resultados == NULL) {
    printf("Erro ao abrir o arquivo resultados.txt\n");
    return 1;
  }
  fprintf(
      arquivo_resultados,
      "Tempo de execução do arquivo %s usando o algorítimo %s: %f segundos\n",
      nomeArquivo, nomeAlgoritimo, tempo);
  fclose(arquivo_resultados);
}