#include <stdio.h>
#include <stdlib.h>

void aloca(float **p,int tam);
void leitura(float *p);
void media(float *p,int tam,float **pm,int *qm);
void mostra(float *p,int tam);

main()
{
float *ptr=NULL,*pmenor=NULL;
char op;
int cont=0,qmenor=0;
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
media(ptr,cont,&pmenor,&qmenor);
printf("\n\nMenores que a media\n");
mostra(pmenor,qmenor);
printf("\n\n");
system("pause");
}//main
  
void aloca(float **p,int tam)
{
if((*p=(float*)realloc(*p,tam*sizeof(float)))==NULL)
  exit(1);
}// aloca

void leitura(float *p)
{  
printf("\nNumero: ");
scanf("%f",p);
fflush(stdin);
}//leitura

void media(float *p,int tam,float **pm,int *qm)
{
int i;
float m=0;
for(i=0;i<tam;i++)
  m+=*(p+i);
m/=tam;
printf("\nMedia = %.2f\n\n",m);
for(i=0;i<tam;i++)
  if(*(p+i)<m)  //menor
    { 
    aloca(pm,*qm+1);
    *(*pm+*qm)=*(p+i);
    (*qm)++;
    }//if
}//media
    
void mostra(float *p,int tam)
{
int i;
for(i=0;i<tam;i++)
  printf("\n%.2f",*(p+i));
}//mostra
