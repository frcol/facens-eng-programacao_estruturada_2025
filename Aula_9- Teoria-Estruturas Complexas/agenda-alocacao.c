#include <stdio.h>
#include <stdlib.h>

typedef struct agenda{
        int reg;
        char nome[20];
        float nota;
        }agenda;

void aloca(agenda **p,int tam);        
void cadastro(agenda *p);
void mostra(agenda *p,int tam);

main()
{
agenda *ag=NULL;
int cont=0;
char op;

do{
  aloca(&ag,cont+1);
  cadastro(ag+cont);
  cont++;
  printf("\nDeseja continuar <S/N>: ");
  scanf("%c",&op);
  fflush(stdin);
  }while(op=='s'|| op=='S');
mostra(ag,cont);
}//main  

void aloca(agenda **p,int tam)
{
if((*p=(agenda*)realloc(*p,tam*sizeof(agenda)))==NULL)
  exit(1);
}//aloca

void cadastro(agenda *p)
{
static int n=1;

p->reg=n;
n++;
printf("\nNome: ");
gets(p->nome);
fflush(stdin);
do{
   printf("\nNota: ");
   scanf("%f",&p->nota);
   fflush(stdin);
  }while(p->nota<0 || p->nota>10);
}//cadastro


void mostra(agenda *p,int tam)
{
int i;

system("cls");
for(i=0;i<tam;i++)
  printf("Registro:%i\nNome:%s\nNota:%.2f\n\n",(p+i)->reg,(p+i)->nome,(p+i)->nota);
system("pause");
}//mostra





