#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int procura(char *p, int tam, char *proc);
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



