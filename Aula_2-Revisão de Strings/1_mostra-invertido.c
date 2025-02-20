#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostra_invertido(char *p);

main()
{
char frase[80];

printf("\nImprime a frase invertida\n");
printf("\nDigite a frase: ");
gets(frase);
fflush(stdin);
mostra_invertido(frase);
}//main

void mostra_invertido(char *p)
{
int tam,i;
tam=strlen(p);    //qtde de letras na frase
p=p+tam-1;        //posiciona o ponteiro na ultima letra
for(i=0;i<tam;i++,p--)
  printf("%c",*p);
  
printf("\n\n");
system("pause");
}//mostra_invertido
