#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int conta(char *p, int tam, char *proc);
void minuscula_string(char *p, int tam);
char minuscula(char l);

int main()
{
	char frase[80], letra;
	
	printf("String: ");
	gets(frase);
	minuscula_string(frase,strlen(frase));
	
	fflush(stdin);
	printf("Procurar pela letra: ");
	scanf("%c",&letra);
	letra=minuscula(letra);
	
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


void minuscula_string(char *p, int tam)
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

char minuscula(char l)
{
	if (l>='A' && l<='Z')
	{
		return (l+32);
	}
	return l;
}



