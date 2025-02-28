#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int conta(char *p, int tam, char *proc);
void minuscula(char *p, int tam);


int main()
{
	char frase[80], letra;
	
	printf("String: ");
	gets(frase);
	fflush(stdin);
	minuscula(frase,strlen(frase));
	printf("Procurar pela letra: ");
	scanf("%c",&letra);
	fflush(stdin);
	minuscula(&letra,1);
	
	printf("Quantidade de ocorrencias: %i",conta(frase,strlen(frase),&letra));
	
	return 0;
}

int conta(char *p, int tam, char *proc)
{
	int i ,cont=0;
	
	for(i=0;i<tam;i++,p++)
	{
		if(*p == *proc)
		{
			cont++;
		}
	}	
	return cont;
}


void minuscula(char *p, int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		if(*(p+i)>='A' && *(p+i)<='Z')
		{
			*(p+i)+=32;
		}
	}
}


