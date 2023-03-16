#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"

int main() {
  int opcao, valor = 0;
  int i, array[10];
  int n = sizeof(array) / sizeof(array[0]);
  char* nome_arquivo = "Ordenado Aleatório.txt";
  int num_registros, val, tam;
  
  while (opcao != 7) {
    printf("\n\nEscolha uma opcao:\n\n");
    printf("1 - Ler arquivo txt e guardar no Vetor\n");
    printf("2 - Criar Arquivo txt ordenado\n");
    printf("3 - Criar Arquivo txt invertido\n");
    printf("4 - Criar Arquivo txt aleatorio\n");
    printf("5 - BubbleSort\n");
    printf("6 - InsertSort\n");
    printf("7 - Sair\n");
    scanf("%d", &opcao);
    switch (opcao) {
      case 1:
      printf("Digite a quantidade de números no arquivo txt: \n");
      scanf("%d", &tam);
      printf("Numeros lidos no arquivo .txt: \n");
      lerTxt(tam);
      break;
      
      case 2:
      printf("Digite qual valor voce quer ordenado no arquivo txt: \n");
      scanf("%d", &valor);
      criartxtOrdenado(valor);
      printf("\nArquivo criado com sucesso!\n");
      break;

      case 3:
      printf("Digite qual valor voce quer invertido no arquivo txt: \n");
      scanf("%d", &valor);
      criartxtInvertido(valor);
      printf("\nArquivo criado com sucesso!\n");
      break;

      case 4:
      printf("Digite a quantidade de números aleatórios a serem gerados: \n");
      scanf("%d", &num_registros); 
      printf("Digite o limite dos números que serão gerados: \n");
      scanf("%d", &val); 
      criartxtAleatorio(nome_arquivo, num_registros, val);
      printf("\nArquivo criado com sucesso!\n");
      break;

      case 5:
      for(i = 0; i < 10; i++){ // preenche o vetor lendo do teclado
        printf("Digite o elemento da posicao %d: ", i);
        scanf("%d", &array[i]);
      }       
      bubbleSort(array, n);
      // bubblesort vai ordenar valores fornecidos pelo usuario
      printf("\nArray ordenado: \n");
      for (int i = 0; i < n; i++)
      printf("%d ", array[i]);
      break;

      case 6:
      for(i = 0; i < 10; i++){ // preenche o vetor lendo do teclado
        printf("Digite o elemento da posicao %d: ", i);
        scanf("%d", &array[i]);
      } 
      insertionSort(array, n); 
      // insertsort vai ordenar valores fornecidos pelo usuario
      printf("\nArray ordenado: \n");
      for (int i = 0; i < n; i++)
      printf("%d ", array[i]);
      break;

      case 7:
      printf("Saindo...\n");
      break;
      
      default:
      printf("Opcao inválida. Tente novamente.\n");
      break;
      }
  }
  return 0;
}