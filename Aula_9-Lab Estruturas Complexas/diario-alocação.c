#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct aluno{
        char nome[80];
        char RA[7];
        float nota[2];
        float media;
        }aluno;

void aloca(aluno **p,int tam);
void cadastro(aluno *p);
int busca(aluno *p,int q);
void controle(aluno *p);

main()
{
aluno *al=NULL;
int cont=0,op,ind;

do{
  system("cls");
  printf("\n[1] Cadastro\n[2] Controle de Notas\n[3] Fim\nOpcao: ");
  scanf("%i",&op);
  fflush(stdin);
  switch(op)
    {
    case 1: aloca(&al,cont+1);
            cadastro(al+cont);
            cont++;
            break;
    case 2: ind=busca(al,cont);
            if(ind==-1)
             {
              printf("\nRA inexistente\n\n\n");
              system("pause");
             }
            else
              controle(al+ind);
            break;
    }//switch
  }while(op!=3);
}//main 
    
void aloca(aluno **p,int tam)
{
if((*p=(aluno*)realloc(*p,tam*sizeof(aluno)))==NULL)
  exit(1);
}//aloca

void cadastro(aluno *p)
{
int i;
printf("\nNome: ");
gets(p->nome);
fflush(stdin);
printf("\nRA: ");
gets(p->RA);
fflush(stdin);
for(i=0;i<2;i++)
  *(p->nota+i)=0;   //conteudo de nota[i]=0
p->media=0;
printf("\nCadastro efetuado com sucesso\n\n");
system("pause");
}//cadastro

int busca(aluno *p,int q)
{
int i;
char aux[7];

printf("\nRA: ");
gets(aux);
fflush(stdin);
for(i=0;i<q;i++)
  if(strcmp((p+i)->RA,aux)==0)
    return i;
return -1;
}//busca
  
void controle(aluno *p)
{
int i;
printf("\nNome: %s\n",p->nome);
printf("\nRA:   %s\n",p->RA);  
for(i=0;i<2;i++)
  {
  do
   {
   printf("\nNota[%i] (0~10)= ",i+1);
   scanf("%f",p->nota+i);
   fflush(stdin);
   }while(*(p->nota+i)<0 || *(p->nota+i)>10);
   p->media+=*(p->nota+i);
  }//for
p->media/=i;  
for(i=0;i<2;i++)
  printf("\nNota[%i]= %.2f",i+1,*(p->nota+i));
printf("\nMedia= %.2f\n\n\n",p->media);
system("pause");
}//controle
  
  






  
     
     
     
     
     
     
     
     
     
     





  
  
  
  









