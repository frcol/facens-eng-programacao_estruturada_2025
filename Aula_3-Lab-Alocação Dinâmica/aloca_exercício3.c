#include <stdio.h>
#include <stdlib.h>
/*
Pegar um número ilimitado de entrada do usuário e imprimir em ordem inversa.

variáveis: ponteiro, count (contador do "array" dinamico), op
Crie loop para receber um inteiro do usuário.
  Aloque esse espaço de memória.
  Pegue a entrada do usuário e atribua nesse espaço de memória.
Pergunte se deseja continuar <S/N>

se não, imprima na ordem inversa
*/

void aloca(int **p, int tam);
void leitura(int *p);
void mostra_inversa(int *p, int tam);

main()
{
  system("cls");

  int *ptr = NULL, cont = 0;
  char op;

  do
  {
    aloca(&ptr, cont + 1);
    leitura(ptr + cont);
    cont++;

    printf("\nDeseja continuar <S/N>: ");
    scanf("%c", &op);
    fflush(stdin);

  } while (op != 'n' && op != 'N');

  mostra_inversa(ptr, cont);
}

void aloca(int **p, int tam)
{
  if ((*p = (int *)realloc(*p, tam * sizeof(int))) == NULL)
    exit(1);
}

void leitura(int *p)
{
  printf("\nEndereco: %u - Numero: ", p);
  scanf("%i", p);
  fflush(stdin);
}

void mostra_inversa(int *p, int tam)
{
  int i;
  p += tam - 1;
  for (i = 0; i < tam; i++, p--)
    printf("\nEndereco: %u - Numero: %i", p, *p);
}
