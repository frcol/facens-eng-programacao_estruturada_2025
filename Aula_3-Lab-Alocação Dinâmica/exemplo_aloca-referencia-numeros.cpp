#include <stdio.h>
#include <stdlib.h>

void aloca(int **p,int tam);
void leitura(int *p);
void mostra(int *p,int tam);

main()
{
char op;
int *ptr=NULL,cont=0;

do{
  aloca(&ptr,cont+1);
  leitura(ptr+cont);
  cont++;
  printf("\nDeseja continuar <S/N>: ");
  scanf("%c",&op);
  fflush(stdin);
  }while (op!='n' && op!='N');
mostra(ptr,cont);
system("pause");
}//main

void aloca(int **p,int tam)
{
if((*p=(int*)realloc(*p,tam*sizeof(int)))==NULL)
  exit(1);
}//aloca

void leitura(int *p)
{
printf("\nEndereco:%u - Numero:",p);
scanf("%i",p);
fflush(stdin);
}//leitura

void mostra(int *p,int tam)
{
int i;
for(i=0;i<tam;i++,p++)
   printf("\nEndereco:%u - Numero:%i\n",p,*p);
}//mostra
