#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strlen()
#include <ctype.h>	//toupper()

int main()
{
	char str[80], letra;
	int tam, i, qtde;

	printf("\nDigite a frase: ");
	gets(str);
	fflush(stdin);

	tam = strlen(str);

	for (letra = 'a'; letra <= 'z'; letra++)
	{
		qtde = 0;

		for (i = 0; i < tam; i++)
			if (tolower(*(str + i)) == letra)
				qtde++;
				
		if (qtde != 0)
			printf("\nA letra %c = %i vez(es)\n", letra, qtde);
	} 

	printf("\n\n");
	system(" pause");
} 
