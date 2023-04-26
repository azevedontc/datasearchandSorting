#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_REGISTROS 1000

void printaMenu() {
  printf("\nEscolha uma opção: \n");
  printf("1 - Gerar arquivo em ordem crescente\n");
  printf("2 - Gerar arquivo em ordem decrescente\n");
  printf("3 - Gerar arquivo em ordem aleatória\n");
}

void printaMenu2() {
  printf("\nDigite o tamanho do arquivo: ");
  printf("\n1 para 500000\n2 para 750000\n3 para 1000000\n");
}

void printaMenu3() {
  printf("\nQual método de ordenação utilizar?\n");
  printf("1: BubbleSort\n");
  printf("2: InsertSort\n");
  printf("3: SelectionSort\n");
  printf("4: ShellSort\n");
  printf("5: QuickSort Hoare\n");
  printf("6: QuickSort Lomuto\n");
  printf("7: MergeSort\n");
  printf("8: RadixSort\n");
  printf("9: HeapSort\n");
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

double times(clock_t inicio) {
  clock_t fim = clock();
  double tempo;
  tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
  printf("Tempo de execução: %.4f segundos.\n", tempo);
  return tempo;
}

// --------------------------------------------------
// SORT - ORDENAÇÃO
// --------------------------------------------------

void bubbleSort(double *vetor, int tamanho) {
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

void insertSort(double *vetor, int tamanho) {
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

void selectionSort(double *vetor, int tamanho) {
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

void shellSort(double *vetor, int tamanho) {
  int h, i, j;                                  // 1
  double aux;                                   // 1

  for (h = tamanho / 2; h > 0; h /= 2) {        // log(tamanho) + 1
    for (i = h; i < tamanho; i++) {             // log(tamanho) - 1
      aux = vetor[i];                           // (tamanho / h) - 1
      j = i;                                    // (tamanho / h) - 1
      while (j >= h && vetor[j - h] > aux) {    // (tamanho / h) - 1
        vetor[j] = vetor[j - h];                // varia de (tamanho / h) - 1 a (tamanho - 1)
        j -= h;                                 // varia de (tamanho / h) - 1 a (tamanho - 1)
      }
      vetor[j] = aux;                           // (tamanho / h) - 1
    }
  }
}

int partitionHoare(double *vetor, int tam) {
  int x = vetor[tam / 2];
  int esq, dir;
  for (esq = 0, dir = tam - 1;; esq++, dir--) {
    while (vetor[esq] < x) {
      esq++;
    }
    while (vetor[dir] > x) {
      dir--;
    }
    if (esq >= dir) {
      return esq;
    }
    int aux2 = vetor[esq];
    vetor[esq] = vetor[dir];
    vetor[dir] = aux2;
  }
}

void hoare(double *vetor, int tam) {
  if (tam < 2) {
    return;
  }
  int esq = partitionHoare(vetor, tam);
  if (tam > esq) {
    hoare(vetor, esq);
    hoare(vetor + esq, tam - esq);
  }
}

void quickSortHoare(double *vetor, int tam) { hoare(vetor, tam); }

int partitionLomuto(double arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      int tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;
    }
  }
  int tmp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = tmp;
  return (i + 1);
}

void lomuto(double arr[], int low, int high) {
  while (low < high) {
    int index = partitionLomuto(arr, low, high);
    if ((index - low) <= (high - index)) {
      lomuto(arr, low, index - 1);
      low = index + 1;
    } else {
      lomuto(arr, index + 1, high);
      high = index - 1;
    }
  }
}

double quickSortLomuto(double *vetor, int tam) { lomuto(vetor, 0, tam - 1); }

void merge(double *v, double *c, int i, int m, int f) {
  int z, iv = i, ic = m + 1;
  for (z = i; z <= f; z++) {
    c[z] = v[z];
  }
  z = i;
  while (iv <= m && ic <= f) {
    if (c[iv] <= c[ic]) {
      v[z++] = c[iv++];
    } else {
      v[z++] = c[ic++];
    }
  }
  while (iv <= m) {
    v[z++] = c[iv++];
  }
  while (ic <= f) {
    v[z++] = c[ic++];
  }
}

void sort(double *v, double *c, int i, int f) {
  if (i >= f) {
    return;
  }
  int m = (i + f) / 2;
  sort(v, c, i, m);
  sort(v, c, m + 1, f);
  if (v[m] <= v[m + 1]) {
    return;
  }
  merge(v, c, i, m, f);
}

void mergeSort(double *vetor, int esq, int dir) {
  double *c = malloc(sizeof(double) * (dir - esq + 1));
  sort(vetor, c, esq, dir);
  free(c);
}

void radixSort(double *vetor, int tamanho) {
  int i, exp = 1;
  double *temp = (double *)malloc(tamanho * sizeof(double));
  double maior = vetor[0];

  for (i = 1; i < tamanho; i++) {
    if (vetor[i] > maior) {
      maior = vetor[i];
    }
  }
  while ((int)(maior / exp) > 0) {
    int bucket[10] = {0};
    for (i = 0; i < tamanho; i++) {
      bucket[(int)(vetor[i] / exp) % 10]++;
    }
    for (i = 1; i < 10; i++) {
      bucket[i] += bucket[i - 1];
    }
    for (i = tamanho - 1; i >= 0; i--) {
      temp[--bucket[(int)(vetor[i] / exp) % 10]] = vetor[i];
    }
    for (i = 0; i < tamanho; i++) {
      vetor[i] = temp[i];
    }
    exp *= 10;
  }
  free(temp);
}

void heapify(double *vetor, int tamanho, int i) {
  int maior = i;
  int esquerda = 2 * i + 1;
  int direita = 2 * i + 2;

  if (esquerda < tamanho && vetor[esquerda] > vetor[maior])
    maior = esquerda;

  if (direita < tamanho && vetor[direita] > vetor[maior])
    maior = direita;

  if (maior != i) {
    double temp = vetor[i];
    vetor[i] = vetor[maior];
    vetor[maior] = temp;

    heapify(vetor, tamanho, maior);
  }
}

void heapSort(double *vetor, int tamanho) {
  for (int i = tamanho / 2 - 1; i >= 0; i--)
    heapify(vetor, tamanho, i);

  for (int i = tamanho - 1; i >= 0; i--) {
    double temp = vetor[0];
    vetor[0] = vetor[i];
    vetor[i] = temp;

    heapify(vetor, i, 0);
  }
}

// --------------------------------------------------
// SEARCH - PESQUISA
// --------------------------------------------------

double buscaBinaria(double vetor[], int ini, int fim, int key, int *operacoes){
  *operacoes+=1;
  int mei = (ini + fim) / 2;

  if ((ini == fim) && !(key == vetor[mei]))
    return -1;
  else
    if (key == vetor[mei])
      return mei;
    else
      if (key > vetor[mei])
        return buscaBinaria(vetor, mei+1, fim , key, operacoes);
      else
        return buscaBinaria(vetor, ini, mei-1, key, operacoes);
}