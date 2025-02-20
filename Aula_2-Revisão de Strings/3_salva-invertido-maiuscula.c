#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverte(char *pf,char *pi);
char maiuscula(char letra);
char minuscula(char letra);

main()
{
char frase[80],inv[80];

printf("\nInverte a frase\n");
printf("\nDigite a frase: ");
gets(frase);
fflush(stdin);
inverte(frase,inv);
printf("\nA frase invertida:\n%s",inv);
}//main

void inverte(char *pf,char *pi)
{
int tam,i;
tam=strlen(pf);   //qtde de letras
pf=pf+tam-1;      //posiciona ponteiro na ultima letra
for(i=0;i<tam;i++,pi++,pf--)
  {
  	*pi=minuscula(*pf);
  	if(i==0)  //1 vez
  	  *pi=maiuscula(*pf);
  	if(*pf==' ')
  	  {
  	  	i++;
  	  	pi++;
  	  	pf--;
  	  	*pi=maiuscula(*pf);
	  }//if
  }//for
*pi='\0';
}//inverte

char maiuscula(char letra)
{
if(letra>='a' && letra<='z')
  return(letra-32);
return letra;
}//maiuscula

char minuscula(char letra)
{
if(letra>='A' && letra<='Z')
  return(letra+32);
return letra;
}//minuscula
