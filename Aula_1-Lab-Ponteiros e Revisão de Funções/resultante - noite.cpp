#include <stdio.h>
#include <stdlib.h>

void leitura(float *p,int q);
void resultante(float *pa,float *pb,float *pc,int q);
void imprime(float *p,int q);

main()
{
float a[10],b[10],c[10];
int qtde;
printf("\nCalcula a Resultante\n");
do{
	printf("\nQtde de elementos - max.10: ");
	scanf("%i",&qtde);
	fflush(stdin);
  }while(qtde<1||qtde>10);
printf("\nLeitura - vetor A:");
leitura(a,qtde);
printf("\nLeitura - vetor B:");
leitura(b,qtde); 
resultante(a,b,c,qtde);
system("cls");
printf("\nImprime - vetor A:\n");
imprime(a,qtde);
printf("\nImprime - vetor B:\n");
imprime(b,qtde);
printf("\nImprime - vetor C:\n");
imprime(c,qtde);
printf("\n\n\n");
system("pause");
}//main

void leitura(float *p,int q)
{
int i;
for(i=0;i<q;i++,p++)
  {
  	printf("\nvet[%i]= ",i);
  	scanf("%f",p);
  	fflush(stdin);
  }//for
}//leitura

void resultante(float *pa,float *pb,float *pc,int q)
{
int i;
for(i=0;i<q;i++,pa++,pb++,pc++)
  *pc=*pa+*pb;
}//resultante

void imprime(float *p,int q)
{
int i;
for(i=0;i<q;i++,p++)
  printf("vet[%i]= %.2f\n",i,*p);
}//imprime




