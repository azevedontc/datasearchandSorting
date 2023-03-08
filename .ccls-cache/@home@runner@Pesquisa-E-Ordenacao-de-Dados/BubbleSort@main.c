#include <stdio.h>
#define TAM 20

int main(void) {
  
  int vetor[TAM];
  int comp = 0, troca = 0;
  int x = TAM;
  
  for(int cont = 0; cont<TAM; cont++){
    vetor[cont] = x--;
  }
  
  for (int i = TAM; i>0; i--){
    for (int j = 0; j<i-1; j++, comp++){
      //Comparação
      printf("\n Comparando %d com %d", vetor[j], vetor[j+1]);
      if (vetor[j] > vetor[j+1]){
        //Troca
        troca++;
        int aux;
        aux = vetor[j];
        vetor[j] = vetor[j+1];
        vetor[j+1] = aux;
      }
    }
  }
  //Escrever o Vetor
  printf("\n\n Vetor ordenado: \n");
  for (int cont=0; cont<TAM; cont++){
    printf("%d \t", vetor[cont]);
  }

  printf("\n Quantidade de comparações feitas: %d \n", comp);
  printf("\n Quantidade de trocas feitas: %d \n", troca);
  
  return 0;
}