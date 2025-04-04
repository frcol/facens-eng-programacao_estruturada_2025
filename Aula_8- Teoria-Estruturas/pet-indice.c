#include <stdio.h>
#include <stdlib.h>

// definicação de Estruturas
typedef struct pet
{
	char nome[30];
	int idade;
	char sexo;
} Pet;

// prototipo de funcao
Pet cadastro();

int main()
{
	system("cls");

	Pet pet[10];
	char op;
	int i, cont = 0;

	do
	{
		system("cls");

		printf("\nCadastro de Pets");
		if (cont < 10)
		{
			pet[cont] = cadastro();
			cont++;
		}
		else
			printf("\nCadastro Lotado");

		printf("\nDeseja continuar <S/N>: ");
		scanf("%c", &op);
		fflush(stdin);
	} while (op != 'n' && op != 'N');

	for (i = 0; i < cont; i++)
		printf("\nPet %i\nNome: %s\nIdade: %i\nSexo: %c\n", i + 1, pet[i].nome, pet[i].idade, pet[i].sexo);

	printf("\n\n");

	return 0;
}

Pet cadastro()
{
	Pet aux;

	printf("\nNome: ");
	gets(aux.nome);
	fflush(stdin);
	
	printf("Idade: ");
	scanf("%i", &aux.idade);
	fflush(stdin);
	
	printf("Sexo: ");
	scanf("%c", &aux.sexo);
	fflush(stdin);
	
	return aux;
}
