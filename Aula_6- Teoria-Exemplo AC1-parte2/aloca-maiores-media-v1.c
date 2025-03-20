#include <stdio.h>
#include <stdlib.h>

void aloca(float **p, int tam);
void leitura(float *p);
int media(float *p, int tam, float **pM);
void mostra(float *p, int tam);

main()
{
  system("cls");
  
  float *ptr = NULL, *pmaior = NULL;
  char op;
  int cont = 0, qmaior;

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
  qmaior = media(ptr, cont, &pmaior);

  printf("\n\nMaiores que a media\n");
  mostra(pmaior, qmaior);

  printf("\n\n");
}

void aloca(float **p, int tam)
{
  if ((*p = (float *)realloc(*p, tam * sizeof(float))) == NULL)
    exit(1);
}

void leitura(float *p)
{
  printf("\nNumero: ");
  scanf("%f", p);
  fflush(stdin);
}

int media(float *p, int tam, float **pM)
{
  int i, qM = 0;
  float m = 0;

  for (i = 0; i < tam; i++, p++)
    m += *p;

  m /= tam;

  printf("\nMedia = %.2f\n\n", m);

  p -= tam; // tem que retornar o ponteiro p para o in�cio
  
  for (i = 0; i < tam; i++, p++)
    if (*p > m) // maior
    {
      aloca(pM, qM + 1);
      *(*pM + qM) = *p;
      qM++;
    }
  return qM;
}

void mostra(float *p, int tam)
{
  int i;
  for (i = 0; i < tam; i++)
    printf("\n%.2f", *(p + i));
}
