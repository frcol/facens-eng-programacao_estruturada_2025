// receber e imprimir os elementos de 1 vetor
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int num[5], i, *p_num;
  p_num = num; // inicializacao do ponteiro

  printf("\nLer os elementos do vetor\n");

  for (i = 10; i < 15; i++, p_num++)
  {
    printf("elemento: ");
    scanf("%i", p_num);
  } 

  p_num = num; // posiciona o ponteiro no endereco inicial
  printf("\nImprimir os elementos do vetor\n");
  for (i = 0; i < 5; i++, p_num++)
    printf("\nnum[%i]= %i", i, *p_num);
}
