#include <stdio.h>
#include "header.h"

int main() {
  int opcao = 0;
  int valor, valor2, valor3 = 0;
  int i, array[10];
  int n = sizeof(array) / sizeof(array[0]);
  char* nome_arquivo = "numeros_aleatorios.txt";
  int num_registros;
  
  while (opcao != 7) {
    printf("\nEscolha uma opcao:\n\n");
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
      printf("Numeros lidos no arquivo .txt: \n");
      lerTxt();
      printf("\n");
      break;
      
      case 2:
      printf("Digite qual valor voce quer ordenado no arquivo txt: \n");
      scanf("%d", &valor);
      criartxtOrdenado(valor);
      printf("Arquivo criado com sucesso!\n");
      printf("\n");
      break;

      case 3:
      printf("Digite qual valor voce quer invertido no arquivo txt: \n");
      scanf("%d", &valor2);
      criartxtInvertido(valor2);
      printf("Arquivo criado com sucesso!\n");
      printf("\n");
      break;

      case 4:
      printf("Digite a quantidade de números aleatórios a serem gerados: ");
      scanf("%d", &num_registros); 
      criartxtAleatorio(nome_arquivo, num_registros); 
      printf("Arquivo criado com sucesso!\n");  
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
      printf("\n");
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
      printf("\n");
      break;

      case 7:
      printf("Saindo...\n");
      break;
      
      default:
      printf("Opcao invalida. Tente novamente.\n");
      break;
      }
  }
  return 0;
}