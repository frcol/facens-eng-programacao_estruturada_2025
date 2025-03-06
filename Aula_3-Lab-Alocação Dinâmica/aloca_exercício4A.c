#include <stdio.h>
#include <stdlib.h>

void aloca(int **p,int tam);
void leitura(int *p,int tam);
void mostra(int *p,int tam);
void media(int *p,int tam);

main()
{
int *ptr=NULL,cont=0;
char op;

do{
	aloca(&ptr,cont+1);
	leitura(ptr,cont);
	cont++;
	printf("\nDeseja continuar <S/N>: ");
	scanf("%c",&op);
	fflush(stdin);
	}while(op=='s' || op=='S');
mostra(ptr,cont);
media(ptr,cont);
system("pause");
}//main

void aloca(int **p,int tam)
{
if((*p=(int*)realloc(*p,tam*sizeof(int)))==NULL)
  exit(1);
}//aloca

void leitura(int *p,int tam)
{
printf("\nNumero: ");
scanf("%i",p+tam);
fflush(stdin);	
}//leitura

void mostra(int *p,int tam)
{
int i;
for(i=0;i<tam;i++,p++)
  printf("\nNumero: %i",*p);
}//mostra

void media(int *p,int tam)
{
int i;
float soma=0;
for(i=0;i<tam;i++,p++)
   soma+=*p;
      
soma/=tam;
printf("\nMedia = %.2f\n",soma);	
}//media













