#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aloca(char **p,int tam);

main()
{
char *ptr=NULL,aux[20],op;
int tam=0,cont=0,cnome;
do{
  printf("\nDigite o nome: ");
  gets(aux);
  fflush(stdin);
  tam+=strlen(aux)+1;  //não esquecer o \0
  aloca(&ptr,tam);
  if(cont==0)
    strcpy(ptr,aux);
  else
    {
    strcat(ptr,"\n");
    strcat(ptr,aux);
    }
  cont++;
  printf("\nDeseja continuar <S/N>: ");
  scanf("%c",&op);
  fflush(stdin);
  }while(op!='n'&&op!='N');
printf("\nForam alocados %i nomes:\n%s\n\n",cont,ptr);
system("pause");
}//main
  
void aloca(char **p,int tam)
{
if((*p=(char*)realloc(*p,tam*sizeof(char)))==NULL)
  exit(1);
}//aloca






  
