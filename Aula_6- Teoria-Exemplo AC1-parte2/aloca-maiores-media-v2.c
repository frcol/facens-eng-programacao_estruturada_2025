#include <stdio.h>
#include <stdlib.h>

void aloca(float **p, int tam);
void leitura(float *p);
void media(float *p, int tam, float **pM, int *qM);
void mostra(float *p, int tam);

main()
{
  system("cls");
  
  float *ptr = NULL, *pmaior = NULL;
  char op;
  int cont = 0, qmaior = 0;

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
  media(ptr, cont, &pmaior, &qmaior);

  printf("\n\nMaiores que a media\n");
  mostra(pmaior, qmaior);

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

void media(float *p, int tam, float **pM, int *qM)
{
  int i;
  float m = 0;

  for (i = 0; i < tam; i++)
    m += *(p + i);

  m /= tam;

  printf("\nMedia = %.2f\n\n", m);
  system("pause");

  for (i = 0; i < tam; i++)
    if (*(p + i) > m)
    {
      aloca(pM, *qM + 1);
      *(*pM + *qM) = *(p + i);
      (*qM)++;
    }
}

void mostra(float *p, int tam)
{
  int i;
  for (i = 0; i < tam; i++)
    printf("\n%.2f", *(p + i));
}
