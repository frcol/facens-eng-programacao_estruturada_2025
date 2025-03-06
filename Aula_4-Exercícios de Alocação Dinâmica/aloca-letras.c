#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>		//biblioteca para getche()

void aloca(char **p,int tam);

main()
{
char *ptr=NULL,letra;
int cont=0;
printf("\nDigite a frase: ");
do{
	aloca(&ptr,cont+1);
	letra = getche();
	fflush(stdin);
	*(ptr+cont)=letra;  //guarda as letras, inclusive o '\n' do final 
	cont++;
  }while(letra!=13);  //tecla ENTER na tabela ASCII = 13 
*(ptr+cont-1)='\0';   //getche - coloca '\n' antes do ENTER, portanto vamos colocar '\0' no lugar do '\n' 
printf("\nFrase: %s\n\n",ptr);
system("pause");
}//main
  
void aloca(char **p,int tam)
{
if((*p=(char*)realloc(*p,tam*sizeof(char)))==NULL)
  exit(1);
}//aloca






  
