#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>   //biblioteca para getche()

void aloca(char **p,int tam);
void aloca_string(char **p);

main()
{
char *ptr=NULL,*pnome=NULL,op;
int tam,tam_acum=0,cnome=0;
do{
  printf("\nDigite o nome: ");
  aloca_string(&pnome);
  printf("\nNome: %s",pnome);
  tam=strlen(pnome);     //tamanho de cada nome
  printf("\ntamanho: %i",tam);
  tam_acum+=tam+1;       //não esquecer o \0; 
  printf("\ntamanho acumulado: %i",tam_acum);
  aloca(&ptr,tam);
  if(cnome==0)
    strcpy(ptr,pnome);
  else
    {
    strcat(ptr,"\n");
    strcat(ptr,pnome);
    }
  cnome++;
  printf("\nDeseja continuar <S/N>: ");
  scanf("%c",&op);
  fflush(stdin);
  }while(op!='n'&&op!='N');
printf("\nForam alocados %i nomes:\n%s\n\n",cnome,ptr);
system("pause");
}//main
  
void aloca(char **p,int tam)
{
if((*p=(char*)realloc(*p,tam*sizeof(char)))==NULL)
  exit(1);
}//aloca

void aloca_string(char **p)
{
char letra;
int cont=0;
do{
	aloca(p,cont+1);
	letra = getche();
	fflush(stdin);
	*(*p+cont)=letra;  //guarda as letras, inclusive o '\n' do final
	cont++;
  }while(letra!=13);  //tecla ENTER na tabela ASCII = 13 
*(*p+cont-1)='\0';    //getche - coloca '\n' antes do ENTER, portanto vamos colocar '\0' no lugar do '\n' 	
}//aloca_string




  
