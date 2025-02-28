// soma de 2 vetores A e B - resultado C
#include <stdio.h>
#include <stdlib.h>
/*
Sem usar função, com Ponteiro Variavel
Realizar a soma de 2 vetores A e B de nºs reais (int) e de tamanho igual ou inferior  a 10 (n<=10) e gerar um vetor resultante C onde C[i]  =  A[i]  +  B[i] 
Pede ao usuário quantos itens será colocado no Vetor
*/

int main()
{
  system("cls");
  
  int a[10], b[10], c[10], qtde, i;
  int *pa, *pb, *pc;

  // inicializacao do ponteiro
  pa = a; 
  pb = b; 
  pc = c; 
  
  printf("\nSoma 2 vetores");
  do
  {
    printf("\nQtde de elementos - max 10: ");
    scanf("%i", &qtde);
  } while (qtde < 1 || qtde > 10);

  // leitura dos vetores A e B
  printf("\nLeitura - Vetor a:\n");
  for (i = 0; i < qtde; i++, pa++)
  {
    printf("vet[%i]= ", i);
    scanf("%i", pa);
  }

  printf("\nLeitura - Vetor b:\n");
  for (i = 0; i < qtde; i++, pb++)
  {
    printf("vet[%i]= ", i);
    scanf("%i", pb);
  } 

  // calcula resultante
  // posiciona o ponteiro no endereco inicial
  pa = a;
  pb = b;

  for (i = 0; i < qtde; i++, pa++, pb++, pc++)
    *pc = *pa + *pb;
  
  // posiciona o ponteiro no endereco inicial
  pa = a;
  pb = b;
  pc = c;

  // imprime os vetores
  system("cls");

  printf("\nImprime - Vetor a:");
  for (i = 0; i < qtde; i++, pa++)
    printf("\nvet[%i]= %i", i, *pa);
    
  printf("\n\nImprime - Vetor b:");
  for (i = 0; i < qtde; i++, pb++)
    printf("\nvet[%i]= %i", i, *pb);

  printf("\n\nImprime - Vetor c:");
  for (i = 0; i < qtde; i++, pc++)
    printf("\nvet[%i]= %i", i, *pc);

  printf("\n\n\n");
  return 0;
}
