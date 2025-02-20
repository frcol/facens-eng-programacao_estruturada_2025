//soma de 2 vetores A e B - resultado C
#include <stdio.h>
#include <stdlib.h>

void leitura(int *p,int q);
void resultante(int *pa,int *pb,int *pc,int q);
void imprime(int *p,int q);

main()
{
int a[10],b[10],c[10],qtde;
printf("\nSoma 2 vetores");
do{
  printf("\nQtde de elementos - max 10: ");
  scanf("%i",&qtde);
  }while(qtde<1 || qtde>10);
printf("\nLeitura do vetor A:\n");
leitura(a,qtde);
system("cls");
printf("\nLeitura do vetor B:\n");
leitura(b,qtde);
resultante(a,b,c,qtde);
system("cls");
printf("\nMostra o vetor A:");
imprime(a,qtde);
printf("\nMostra o vetor B:");
imprime(b,qtde);
printf("\nMostra o vetor C:");
imprime(c,qtde);
system("pause");
}//main

void leitura(int *p,int q)
{
int i;
for(i=0;i<q;i++,p++)
  {
  	printf("\nvet[%i]= ",i);
  	scanf("%i",p);
  	fflush(stdin);
  }//for
}//leitura

void resultante(int *pa,int *pb,int *pc,int q)
{
int i;
for(i=0;i<q;i++,pa++,pb++,pc++)
  *pc=*pa+*pb;
}//resultante

void imprime(int *p,int q)
{
int i;
for(i=0;i<q;i++,p++)
  printf("\nvet[%i]= %i",i,*p);	
}//imprime


