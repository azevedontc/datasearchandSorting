#include <stdio.h>
#define TAM 10

void insert(int vetor []){
  for(int x = 1; x < TAM; x++){
    int aux = vetor[x];
    int y = x - 1;
    while((y>=0) && (aux<vetor[y])){
      vetor[y+1] = vetor[y];
      y = y-1;
      vetor[y+1] = aux;
    }
  }
}