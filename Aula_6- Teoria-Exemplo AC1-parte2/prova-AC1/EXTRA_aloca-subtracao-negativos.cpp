#include <stdio.h>
#include <stdlib.h>

void aloca(int **p,int tam);
void leitura(int *p);
int negativos(int *p,int tam,int **pn);
void mostra(int *p,int tam);

main()
{
int *ptr=NULL,cont=0,*pneg=NULL,qneg;
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
qneg=negativos(ptr,cont,&pneg);
printf("\nSubtracao - Negativo(s):\n");
mostra(pneg,qneg);
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

int negativos(int *p,int tam,int **pn)
{
int i,sub,qn=0;
for(i=0;i<tam/2;i++)
  {
  sub=*(p+i)-(*(p+tam-1-i));
  if(sub<0)  //negativo
    { 
    aloca(pn,qn+1);
    *(*pn+qn)=sub;
    qn++;
    }//if
  }//for
if(tam%2==1)    //qtde for impar
  if(*(p+(tam/2))<0)   //elemento impar = negativo
    { 
    aloca(pn,qn+1);
    *(*pn+qn)=*(p+(tam/2));
    qn++;
    }//if
return qn;
}//negativo
    
void mostra(int *p,int tam)
{
int i;
for(i=0;i<tam;i++)
  printf("\n%i",*(p+i));
}//mostra
