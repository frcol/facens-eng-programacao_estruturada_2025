// soma de 2 vetores A e B - resultado C
#include <stdio.h>
#include <stdlib.h>
/*
Apostila - pg29 - Exercício 3
Sem usar função, com Ponteiro Constante
Realizar a soma de 2 vetores A e B de nºs reais (int) e de tamanho igual ou inferior  a 10 (n<=10) e gerar um vetor resultante C onde C[i]  =  A[i]  +  B[i] 
Pede ao usuário quantos itens será colocado no Vetor
*/

int main()
{
  system("cls");
  
  int a[10], b[10], c[10], qtde, i;

  printf("\nSoma 2 vetores");
  do
  {
    printf("\nQtde de elementos - max 10: ");
    scanf("%i", &qtde);
  } while (qtde < 1 || qtde > 10);

  // leitura dos vetores A e B
  printf("\nLeitura - Vetor a:\n");
  for (i = 0; i < qtde; i++)
  {
    printf("vet[%i]= ", i);
    scanf("%i", a+i);
   }

  printf("\nLeitura - Vetor b:\n");
  for (i = 0; i < qtde; i++)
  {
    printf("vet[%i]= ", i);
    scanf("%i", b+i);
  } 

  // calcula resultante
   for (i = 0; i < qtde; i++) {
      *(c+i) = *(a+i) + *(b+i);
   }

  
   // imprime os vetores
  system("cls");

  printf("\nImprime - Vetor a:");
  for (i = 0; i < qtde; i++)
    printf("\nvet[%i]= %i", i, *(a+i));
    
  printf("\n\nImprime - Vetor b:");
  for (i = 0; i < qtde; i++)
    printf("\nvet[%i]= %i", i, *(b+i));

  printf("\n\nImprime - Vetor c:");
  for (i = 0; i < qtde; i++)
    printf("\nvet[%i]= %i", i, *(c+i));

  printf("\n\n\n");
  return 0;
}
