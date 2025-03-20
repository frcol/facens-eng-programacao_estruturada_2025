#include <stdio.h>
#include <stdlib.h>

void aloca(int **p,int tam);
void leitura(int *p);
int pares(int *p,int tam,int **pp);
void mostra(int *p,int tam);

main()
{
int *ptr=NULL,cont=0,*ppar=NULL,qpar;
char op;
do{
  aloca(&ptr,cont+1);
  leitura(ptr+cont);
  cont++;
  printf("\nDeseja continuar <S/N>: ");
  scanf("%c",&op);
  fflush(stdin);
  }while(op!='n' && op!='N');
printf("\nNumeros digitados:\n");
mostra(ptr,cont);
qpar=pares(ptr,cont,&ppar);
printf("\n\nSoma - Par(es):\n");
mostra(ppar,qpar);
printf("\n\n");
system("pause");
}//main
  
void aloca(int **p,int tam)
{
if((*p=(int*)realloc(*p,tam*sizeof(int)))==NULL)
  exit(1);
}// aloca

void leitura(int *p)
{  
printf("\nNumero: ");
scanf("%i",p);
fflush(stdin);
}//leitura

int pares(int *p,int tam,int **pp)
{
int i,soma,qp=0;
for(i=0;i<tam/2;i++)
  {
  soma=*(p+i)+(*(p+tam-1-i));
  if(soma%2==0)  //par
    { 
    aloca(pp,qp+1);
    *(*pp+qp)=soma;
    qp++;
    }//if
  }//for
if(tam%2==1)    //qtde for impar
  if(*(p+(tam/2))%2==0)   //elemento impar = par
    { 
    aloca(pp,qp+1);
    *(*pp+qp)=*(p+(tam/2));
    qp++;
    }//if
return qp;
}//pares
    
void mostra(int *p,int tam)
{
int i;
for(i=0;i<tam;i++)
  printf("\n%i",*(p+i));
}//mostra
