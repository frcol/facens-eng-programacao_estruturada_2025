// receber e imprimir os elementos de 1 vetor
#include <stdio.h>
#include <stdlib.h>
/*
Usando Indice
Pegue do usuario 5 numeros e armazene em um array.
Mostre os 5 numeros digitados
*/

int main()
{
  int num[5], i;

  printf("\nLer os elementos do vetor\n");

  for (i = 0; i < 5; i++)
  {
    printf("%i elemento: ", i + 1);
    scanf("%i", &num[i]);
  } 

  printf("\nImprimir os elementos do vetor\n");

  for (i = 0; i < 5; i++)
    printf("\nnum[%i]= %i", i, num[i]);

  printf("\n\n\n");

  return 0;
} 
