#include <stdio.h>
#include <stdlib.h>

void aloca(int **p, int tam);
void leitura(int *p, int tam);
void mostra(int *p, int tam);
void media(int *p, int tam);
/*
Aloque espaço para uma sequência de números escolhida pelo usuário, até que Ele digite a opção não.
Em seguida, exiba a média dos elementos

variáveis: ponteiro, count (contador do "array" dinamico), op
Crie loop para receber um inteiro do usuário.
  Aloque esse espaço de memória. (função)
  Pegue a entrada do usuário e atribua nesse espaço de memória. (função)
Pergunte se deseja continuar <S/N>

se não, imprima os numeros (função)
        imprima a média dos números (função)
*/
main()
{
	int *ptr = NULL, cont = 0;
	char op;

	do
	{
		aloca(&ptr, cont + 1);
		leitura(ptr, cont);
		cont++;
		printf("\nDeseja continuar <S/N>: ");
		scanf("%c", &op);
		fflush(stdin);
	} while (op == 's' || op == 'S');

	mostra(ptr, cont);
	media(ptr, cont);

}

void aloca(int **p, int tam)
{
	if ((*p = (int *)realloc(*p, tam * sizeof(int))) == NULL)
		exit(1);
} 

void leitura(int *p, int tam)
{
	printf("\nNumero: ");
	scanf("%i", p + tam);
	fflush(stdin);
}

void mostra(int *p, int tam)
{
	int i;
	for (i = 0; i < tam; i++, p++)
		printf("\nNumero: %i", *p);
}

void media(int *p, int tam)
{
	int i;
	float soma = 0;

	for (i = 0; i < tam; i++, p++)
		soma += *p;

	soma /= tam;

	printf("\nMedia = %.2f\n", soma);
}
