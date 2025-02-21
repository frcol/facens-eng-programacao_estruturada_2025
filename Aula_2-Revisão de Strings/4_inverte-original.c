#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverte(char *pf);
char maiuscula(char letra);
char minuscula(char letra);

int main()
{
	system("cls");

	char frase[80];

	printf("\nInverte a frase\n");
	printf("\nDigite a frase: ");
	gets(frase);
	fflush(stdin);

	inverte(frase);

	printf("\nA frase invertida:\n%s", frase);
} 

void inverte(char *pf)
{
	char aux;
	int tam, i;
	tam = strlen(pf); // qtde de letras

	// troca
	for (i = 0; i < (tam / 2); i++)
	{
		aux = *(pf + i);
		*(pf + i) = *(pf + tam - 1 - i);
		*(pf + tam - 1 - i) = aux;
	}

	// arruma maiuscula
	for (i = 0; i < tam; i++, pf++)
	{
		*pf = minuscula(*pf);

		if (i == 0) // 1 vez
			*pf = maiuscula(*pf);
			
		if (*pf == ' ')
		{
			i++;
			pf++;
			*pf = maiuscula(*pf);
		} 
	} 
} 

char maiuscula(char letra)
{
	if (letra >= 'a' && letra <= 'z')
		return (letra - 32);
	return letra;
} 

char minuscula(char letra)
{
	if (letra >= 'A' && letra <= 'Z')
		return (letra + 32);
	return letra;
}
