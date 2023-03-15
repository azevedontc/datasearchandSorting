#include <stdio.h>
#include "header.h"

int main() {
  int opcao = 0;
  int valor = 0;
  int i, array[10];
  int n = sizeof(array) / sizeof(array[0]);
  
  while (opcao != 5) {
    printf("\nEscolha uma opcao:\n\n");
<<<<<<< HEAD
    printf("1 - Ler arquivo txt e guardar no Vetor\n");
=======
    printf("1 - Ler Arquivo txt e guardar no Vetor\n");
>>>>>>> a1016d252cc35d460c87b2442708743f5f47ca1b
    printf("2 - Criar Arquivo txt ordenado\n");
    printf("3 - BubbleSort\n");
    printf("4 - InsertSort\n");
    printf("5 - Sair\n");
    scanf("%d", &opcao);
    switch (opcao) {
      case 1:
      printf("Numeros lidos no arquivo .txt: \n");
      lerTxt();
      printf("\n");
      break;
      
      case 2:
      printf("Digite qual valor voce quer ordenado no arquivo txt: \n");
      scanf("%d", &valor);
      criartxtOrdenado(valor);
      printf("\n");
      break;

      case 3:
      for(i = 0; i < 10; i++){ // preenche o vetor lendo do teclado
        printf("Digite o elemento da posicao %d: ", i);
        scanf("%d", &array[i]);
      }       
      bubbleSort(array, n);
      // bubblesort vai ordenar valores fornecidos pelo usuario
      printf("\nArray ordenado: \n");
      for (int i = 0; i < n; i++)
      printf("%d ", array[i]);
      printf("\n");
      break;

      case 4:
      for(i = 0; i < 10; i++){ // preenche o vetor lendo do teclado
        printf("Digite o elemento da posicao %d: ", i);
        scanf("%d", &array[i]);
      } 
      insertionSort(array, n); 
      // insertsort vai ordenar valores fornecidos pelo usuario
      printf("\nArray ordenado: \n");
      for (int i = 0; i < n; i++)
      printf("%d ", array[i]);
      printf("\n");
      break;

      case 5:
      printf("Saindo...\n");
      break;
      
      default:
      printf("Opcao invalida. Tente novamente.\n");
      break;
      }
  }
  return 0;
}