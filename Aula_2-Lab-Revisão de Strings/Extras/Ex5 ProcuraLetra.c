#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int procura(char *p, int tam, char *proc);
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
	
	if( procura(frase,strlen(frase),&letra) == 1 )
	{
		printf("Resultado: O caractere %c foi encontrado.",letra);
	}
	else
	{
		printf("Resultado: O caractere %c nao foi encontrado.",letra);
	}	
	
	return 0;
}

int procura(char *p, int tam, char *proc)
{
	int i=0, achou=0;
	
	while(i<tam && achou==0)
	{
		if(*(p+i)== *proc)
		{
			achou=1;
		}
		else
		{
			i++;
		}
	}	
	return achou;
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





