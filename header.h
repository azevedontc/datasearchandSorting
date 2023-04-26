#include <time.h>

void printaMenu();
void printaMenu2();
void printaMenu3();
int lerArquivo(char *nome_arquivo, double *numeros, int TAMANHO_MAXIMO);
void gerarCrescente(int tam);
void gerarDecrescente(int tam);
void gerarAleatorio(int tam, int max);
double times(clock_t inicio);
void bubbleSort(double *vetor, int tamanho);
void insertSort(double *vetor, int tamanho);
void selectionSort(double *vetor, int tamanho);
void shellSort(double *vetor, int tamanho);
int partitionHoare(double *vetor, int tam);
void hoare(double *vetor, int tam);
void quickSortHoare(double *vetor, int tam);
int partitionLomuto(double arr[], int low, int high);
void lomuto(double arr[], int low, int high);
double quickSortLomuto(double *vetor, int tam);
void merge(double *v, double *c, int i, int m, int f);
void sort(double *v, double *c, int i, int f);
void mergeSort(double *vetor, int esq, int dir);
void radixSort(double *vetor, int tamanho);
void heapify(double *vetor, int tamanho, int i);
void heapSort(double *vetor, int tamanho);
double buscaBinaria(double vetor[], int ini, int fim, int key, int *op);