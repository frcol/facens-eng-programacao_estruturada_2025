#include <stdio.h>
#include <stdlib.h>

void aloca(float **p,int tam);
void leitura(float *p,int tam);
void maior_temp(float *p,int tam,float *pmaior,int *pdia);
int media(float *p,int tam,float **pm);
void mostra(float *p,int tam);

main()
{
float *ptr=NULL,maior,*pmenor=NULL;
char op;
int cont=0,dia,qmenor;
do{
  aloca(&ptr,cont+1);
  leitura(ptr,cont);
  maior_temp(ptr,cont,&maior,&dia);
  cont++;
  printf("\nMaior Temperatura: %.2f - dia: %i\n",maior,dia);
  printf("\nDeseja continuar <S/N>: ");
  scanf("%c",&op);
  fflush(stdin);
  }while(op!='n' && op!='N');
printf("\nTemperaturas digitadas:\n");
mostra(ptr,cont);
qmenor=media(ptr,cont,&pmenor);
printf("\nMenores que a media\n");
mostra(pmenor,qmenor);
printf("\n\n");
system("pause");
}//main
  
void aloca(float **p,int tam)
{
if((*p=(float*)realloc(*p,tam*sizeof(float)))==NULL)
  exit(1);
}// aloca

void leitura(float *p,int tam)
{
printf("\nTemperatura - %i dia: ",tam+1);
scanf("%f",p+tam);
fflush(stdin);
}//leitura

void maior_temp(float *p,int tam,float *pmaior,int *pdia)
{
if(tam==0)
  {
  	*pmaior=*p;   //primeiro elemento
  	*pdia=1;
  }//if	
else
  if(*(p+tam)>*pmaior)	
    {
      *pmaior=*(p+tam);
	  *pdia=tam+1;	
    }//if
}//maior_temp

int media(float *p,int tam,float **pm)
{
int i,qm=0;
float m=0;
for(i=0;i<tam;i++)
  m+=*(p+i);
m/=tam;
printf("\nMedia = %.2f\n\n",m);
for(i=0;i<tam;i++)
  if(*(p+i)<m)  //menor
    { 
    aloca(pm,qm+1);
    *(*pm+qm)=*(p+i);
    qm++;
    }//if
return qm;
}//media
    
void mostra(float *p,int tam)
{
int i;
for(i=0;i<tam;i++)
  printf("\n%.2f",*(p+i));
}//mostra
