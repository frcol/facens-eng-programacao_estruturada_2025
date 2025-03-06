#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aloca(char **p,int tam);
void maiuscula(char *p,int tam);
int busca_nome(char *p,int tam,char letra,char **pl);

main()
{
char *ptr=NULL,aux[20],op,letra,*pletra=NULL;
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

maiuscula(ptr,tam);  
printf("\nForam alocados %i nomes:\n%s\n\n",cont,ptr);
printf("\nDigite a letra a ser buscada: ");
scanf("%c",&letra);
fflush(stdin);
maiuscula(&letra,1);
cnome=busca_nome(ptr,tam,letra,&pletra);
if(cnome!=0)
  printf("\nTemos %i nome(s) comecados com a letra %c:\n%s\n\n",cnome,letra,pletra);
else
  printf("\nNao temos nomes comecados com a letra %c:\n\n\n",letra);
system("pause");
}//main
  
void aloca(char **p,int tam)
{
if((*p=(char*)realloc(*p,tam*sizeof(char)))==NULL)
  exit(1);
}//aloca

void maiuscula(char *p,int tam)
{
int i;
for(i=0;i<tam;i++)
  if(*(p+i)>='a' && *(p+i)<='z')
    *(p+i)-=32;
}//maiuscula

int busca_nome(char *p,int tam,char letra,char **pl)
{
int i, cont=0,qnome=0;
for(i=0;i<tam;i++)
 {
  if((i==0&&*(p+i)==letra)||(*(p+i)=='\n' && *(p+i+1)==letra))
    {
    qnome++;
    do{
      aloca(pl,cont+1);  //iremos guardar o nome começado com a letra
      *(*pl+cont)=*(p+i);
      cont++;
      i++;
      }while(*(p+i)!='\n' && *(p+i)!='\0');
    i--;  //para retornar no \n
    }//if
}//for
aloca(pl,cont+1);
*(*pl+cont)='\0';
return qnome;
}//busca_nome           
               
               
               
               
               







  
