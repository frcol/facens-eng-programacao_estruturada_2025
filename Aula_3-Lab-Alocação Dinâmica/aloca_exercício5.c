#include <stdio.h>
#include <stdlib.h>
/*
Alocar espaço para armazenar as temperaturas diárias registradas durante um mês. 
O programa deve mostrar diariamente (a medida que as temperaturas são incluídas) a maior temperatura e o dia em que ocorreu.
*/

void aloca(float **p, int tam);
void leitura(float *p, int tam);
void maior_temp(float *p, int tam, float *pmaior, int *pdia);

main()
{
	float *ptr = NULL, maior;
	int dia, cont = 0;
	char op;

	do
	{
		aloca(&ptr, cont + 1);
		leitura(ptr, cont);
		maior_temp(ptr, cont, &maior, &dia);
		cont++;

		printf("\nMaior Temperatura: %.2f - dia: %i\n", maior, dia);
		printf("\nDeseja continuar <S/N>: ");
		scanf("%c", &op);
		fflush(stdin);
	} while (op == 's' || op == 'S');
}

void aloca(float **p, int tam)
{
	if ((*p = (float *)realloc(*p, tam * sizeof(float))) == NULL)
		exit(1);
}

void leitura(float *p, int tam)
{
	printf("\nTemperatura - %i dia: ", tam + 1);
	scanf("%f", p + tam);
	fflush(stdin);
}

void maior_temp(float *p, int tam, float *pmaior, int *pdia)
{
	if (tam == 0)
	{
		*pmaior = *p; // primeiro elemento
		*pdia = 1;
	} // if
	else if (*(p + tam) > *pmaior)
	{
		*pmaior = *(p + tam);
		*pdia = tam + 1;
	}
}
