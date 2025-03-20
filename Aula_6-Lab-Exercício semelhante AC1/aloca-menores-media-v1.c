#include <stdio.h>
#include <stdlib.h>

void aloca(float **p, int tam);
void leitura(float *p);
int media(float *p, int tam, float **pm);
void mostra(float *p, int tam);

main()
{
  system("cls");

  float *ptr = NULL, *pmenor = NULL;
  char op;
  int cont = 0, qmenor;

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

  qmenor = media(ptr, cont, &pmenor);

  printf("\nMenores que a media\n");
  mostra(pmenor, qmenor);

 
  system("pause");
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

int media(float *p, int tam, float **pm)
{
  int i, qm = 0;
  float m = 0;

  for (i = 0; i < tam; i++, p++)
    m += *p;

  m /= tam;

  printf("\nMedia = %.2f\n\n", m);

  p -= tam; // tem que retornar o ponteiro p para o inicio

  for (i = 0; i < tam; i++, p++)
    if (*p < m) 
    {
      aloca(pm, qm + 1);
      *(*pm + qm) = *p;
      qm++;
    }

  return qm;
} 

void mostra(float *p, int tam)
{
  int i;
  
  for (i = 0; i < tam; i++, p++)
    printf("\n%.2f", *p);
}

