#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strlen()
#include <ctype.h>	//toupper()
/*
Usando indice.
Faça um programa que, dado um string qualquer, mostre quantas repetições de cada caracter há nessa string
#include <string.h> //strlen()
#include <ctype.h>	//toupper()
*/

int main()
{
	system("cls");
	
	char str[80] = "Fabio Colombini", letra;
	int tam, i, qtde;

	// printf("\nDigite a frase: ");
	// gets(str);
	// fflush(stdin);

	tam = strlen(str);

	for (letra = 'a'; letra <= 'z'; letra++)
	{
		qtde = 0;

		for (i = 0; i < tam; i++)
			if (tolower(str[i]) == letra)
				qtde++;

		if (qtde != 0)
			printf("\nA letra %c = %i vez(es)\n", letra, qtde);
	} 

	printf("\n\n");
	return 0;
} 
