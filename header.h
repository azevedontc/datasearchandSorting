#include <time.h>

void printaMenu();
void printaMenu2();
void printaMenu3();
int lerArquivo(char *nome_arquivo, double *numeros, int TAMANHO_MAXIMO);
void gerarCrescente(int tam);
void gerarDecrescente(int tam);
void gerarAleatorio(int tam, int max);
double times(clock_t inicio);
void bubbleSort(int tamanho, double *vetor);
void insertSort(int tamanho, double *vetor);
void selectionSort(int tamanho, double *vetor);
void shellSort(int tamanho, double *vetor);
int partitionHoare(double *vetor, int tam);
void hoare(double *vetor, int tam);
void quickSortHoare(double *vetor, int tam);
int partitionLomuto(double arr[], int low, int high);
void lomuto(double arr[], int low, int high);
double quickSortLomuto(double *vetor, int tam);
void merge(double *v, double *c, int i, int m, int f);
void sort(double *v, double *c, int i, int f);
void mergeSort(double *vetor, int esq, int dir);
void radixSort(int tamanho, double *vetor);
