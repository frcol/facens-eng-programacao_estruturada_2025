#include <stdio.h>
#include <stdlib.h>

// declarar as funcoes
void aloca(float **p, int tam);
void leitura(float *p);
int media(float *p, int tam, float **pM);
void mostra(float *p, int tam);

main()
{
  system("cls");
  // declara variaveis
  float *ptr = NULL, *pmaior = NULL;
  char op;
  int cont = 0, qmaior;

  /* 
  loop para ler os numeros digitados pelo usuario
    aloca memoria para o ponteiro ptr
    le o numero digitado
    incrementa o contador
    pergunta se deseja continuar
  */
  do
  {
    aloca(&ptr, cont + 1);
    leitura(ptr + cont);
    cont++;

    printf("\nDeseja continuar <S/N>: ");
    scanf("%c", &op);
    fflush(stdin);
  } while (op != 'n' && op != 'N');

  /*
  imprime os numeros digitados
  chama a funcao media para calcular a media e os numeros maiores que a media
  imprime os numeros maiores que a media
  */
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
  int i, qM = 0; // qM = quantidade de maiores que a media
  float m = 0;

  for (i = 0; i < tam; i++, p++) // calcula a media
    m += *p;

  m /= tam;

  printf("\nMedia = %.2f\n\n", m);

  p -= tam; // tem que retornar o ponteiro p para o inicio
  
  for (i = 0; i < tam; i++, p++) // verifica os maiores que a media e aloca em pM os maiores que a media
    if (*p > m)
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
