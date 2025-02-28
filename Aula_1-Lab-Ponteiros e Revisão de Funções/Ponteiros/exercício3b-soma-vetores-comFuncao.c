#include <stdio.h>
#include <stdlib.h>
/*
Usando Função, enviando Ponteiro
 Realizar a soma de 2 vetores A e B de nºs reais (int) e de tamanho igual ou inferior  a 10 (n<=10) e gerar um vetor resultante C onde C[i]  =  A[i]  +  B[i] 
 Pede ao usuário quantos itens será colocado no Vetor
*/

void leitura(int *p, int q);
void resultante(int *pa, int *pb, int *pc, int q);
void imprime(int *p, int q);

main()
{
  system("cls");

  int a[10], b[10], c[10], qtde;

  printf("\nSoma 2 vetores");
  do
  {
    printf("\nQtde de elementos - max 10: ");
    scanf("%i", &qtde);
  } while (qtde < 1 || qtde > 10);
  
  // Leitura
  printf("\nLeitura do vetor A:\n");
  leitura(a, qtde);

  system("cls");
  printf("\nLeitura do vetor B:\n");
  leitura(b, qtde);

  // Processa
  resultante(a, b, c, qtde);

  // Imprime
  system("cls");
  printf("\nMostra o vetor A:");
  imprime(a, qtde);
  printf("\nMostra o vetor B:");
  imprime(b, qtde);
  printf("\nMostra o vetor C:");
  imprime(c, qtde);

  return 0;
}


void leitura(int *p, int q)
{
  int i;
  for (i = 0; i < q; i++, p++)
  {
    printf("\nvet[%i]= ", i);
    scanf("%i", p);
  }
}

void resultante(int *pa, int *pb, int *pc, int q)
{
  int i;
  for (i = 0; i < q; i++, pa++, pb++, pc++)
    *pc = *pa + *pb;
}

void imprime(int *p, int q)
{
  int i;
  for (i = 0; i < q; i++, p++)
    printf("\nvet[%i]= %i", i, *p);
}
