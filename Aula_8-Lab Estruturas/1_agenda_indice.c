#include <stdio.h>
#include <stdlib.h>

typedef struct agenda
{
	int reg;
	char nome[20];
	float nota;
} agenda;

agenda cadastro();

main()
{
	agenda ag[10];
	char op;
	int i, cont = 0;

	do
	{
		system("cls");

		if (cont < 10)
		{
			printf("\nAgenda %i", cont + 1);
			ag[cont] = cadastro();
			cont++;
		}
		else
		{
			printf("\nCadastro Lotado");
		}

		printf("Deseja continuar <S/N>: ");
		scanf("%c", &op);
		fflush(stdin);
	} while (op != 'n' && op != 'N');

	// mostra
	for (i = 0; i < cont; i++)
		printf("\nRegistro: %i\nNome: %s\nNota: %.2f\n", ag[i].reg, ag[i].nome, ag[i].nota);
	
}

agenda cadastro()
{
	static int n = 1;
	agenda aux;

	aux.reg = n++;

	printf("\nNome: ");
	gets(aux.nome);
	fflush(stdin);
	
	printf("Nota: ");
	scanf("%f", &aux.nota);
	fflush(stdin);
	
	return aux;
}
