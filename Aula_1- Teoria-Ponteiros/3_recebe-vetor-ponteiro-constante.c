// receber e imprimir os elementos de 1 vetor
#include <stdio.h>
#include <stdlib.h>
/*
Usando aritmética de Ponteiro Constante
Pegue do usuario 5 numeros e armazene em um array.
Mostre os 5 numeros digitados
*/

int main()
{
  int num[5], i;

  printf("\nLer os elementos do vetor\n");
  for (i = 0; i < 5; i++)
  {
    printf("elemento: ");
    scanf("%i", (num + i));
  } // for

  printf("\nImprimir os elementos do vetor\n");
  for (i = 0; i < 5; i++)
    printf("\nnum[%i]= %i", i, *(num + i));
  printf("\n\n\n");
  system("pause");

  return 0;
} // main
