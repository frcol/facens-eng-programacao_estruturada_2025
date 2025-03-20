#include <stdio.h>
#include <stdlib.h>

void aloca(int **p,int tam);
void leitura(int *p);
int positivos(int *p,int tam,int **pp);
void mostra(int *p,int tam);

main()
{
int *ptr=NULL,cont=0,*ppos=NULL,qpos;
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
qpos=positivos(ptr,cont,&ppos);
printf("\nSubtracao - positiva\n");
mostra(ppos,qpos);
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

int positivos(int *p,int tam,int **pp)
{
int i,sub,qp=0;
for(i=0;i<tam/2;i++)
  {
  sub=*(p+i)-(*(p+tam-1-i));
  if(sub>=0)  //positivo
    { 
    aloca(pp,qp+1);
    *(*pp+qp)=sub;
    qp++;
    }//if
  }//for
if(tam%2==1)    //qtde for impar
  if(*(p+(tam/2))>=0)   //elemento impar = positivo
    { 
    aloca(pp,qp+1);
    *(*pp+qp)=*(p+(tam/2));
    qp++;
    }//if
return qp;
}//positivo
    
void mostra(int *p,int tam)
{
int i;
for(i=0;i<tam;i++)
  printf("\n%i",*(p+i));
}//mostra
