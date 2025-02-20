#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void busca_letra(char *p, char *proc, int *ppos, int *pq);
void mostra(char l, int *ppos, int qtd);
void minuscula_string(char *p, int tam);
char minuscula(char l);

int main()
{
	char frase[80], letra;
	int pos[80], qtd = 0;
	
	printf("String: ");
	gets(frase);
	minuscula_string(frase,strlen(frase));
	
	fflush(stdin);
	printf("Procurar pela letra: ");
	scanf("%c",&letra);
	letra=minuscula(letra);
	
	busca_letra(frase,&letra,pos,&qtd);
	
	if(qtd==0)
	{
		printf("\nA letra procurada %c nao foi encontrada",letra);
	}
	else
	{
		mostra(letra,pos,qtd);
	}
	
	
	return 0;
}

void busca_letra(char *p, char *proc, int *ppos, int *pq)
{
	int i, tam;
	tam = strlen(p);
	
	for(i=0;i<tam;i++,p++)
	{
		if(*p == *proc)
		{
			(*pq)++; //contando as ocorrencias
			*ppos=i;
			ppos++;
		}
	}	
}

void mostra(char l, int *ppos, int qtd)
{
	int i;
	printf("\nA letra \"%c\" aparece %i vez(es) na frase nas posicoes:\n",l,qtd);
	for(i=0;i<qtd;i++,ppos++)
	{
		printf("%i\t",*ppos);
	}	
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



