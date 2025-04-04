#include <stdio.h>
#include <stdlib.h>

void aloca(int **p, int tam);
void leitura(int *p);
int positivos(int *p, int tam, int **pp);
void mostra(int *p, int tam);

main()
{
  system("cls");

  int *ptr = NULL, *ppos = NULL;
  int cont = 0, qpos;
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

  printf("\nNumeros digitados:\n");
  mostra(ptr, cont);

  qpos = positivos(ptr, cont, &ppos);

  printf("\n\nSubtracao - positiva\n");

  mostra(ppos, qpos);
  printf("\n\n");
}

void aloca(int **p, int tam)
{
  if ((*p = (int *)realloc(*p, tam * sizeof(int))) == NULL)
    exit(1);
}

void leitura(int *p)
{
  printf("\nNumero: ");
  scanf("%i", p);
  fflush(stdin);
}

int positivos(int *p, int tam, int **pp)
{
  int i, sub, qp = 0, vezes;

  if (tam % 2 == 1) // qtde for impar
    vezes = tam - 1;
  else
    vezes = tam;

  for (i = 0; i < vezes; i += 2)
  {
    sub = *(p + i) - *(p + i + 1);

    if (sub >= 0) // positivo
    {
      aloca(pp, qp + 1);
      *(*pp + qp) = sub;
      qp++;
    }
  }

  if (tam % 2 == 1)          // qtde for impar
    if (*(p + tam - 1) >= 0) // último elemento = positivo
    {
      aloca(pp, qp + 1);
      *(*pp + qp) = *(p + tam - 1);
      qp++;
    }

  return qp;
}

void mostra(int *p, int tam)
{
  int i;
  for (i = 0; i < tam; i++)
    printf("\n%i", *(p + i));
}

