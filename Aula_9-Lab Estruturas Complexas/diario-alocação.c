#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct aluno
{
  char nome[80];
  char RA[7];
  float nota[2];
  float media;
} Aluno;

void aloca(Aluno **p, int tam);
void cadastro(Aluno *p);
int busca(Aluno *p, int q);
void controle(Aluno *p);

int main()
{
  system("cls");

  Aluno *al = NULL;
  int cont = 0, op, ind;

  do
  {
    system("cls");
    printf("\n[1] Cadastro\n[2] Controle de Notas\n[3] Fim\nOpcao: ");
    scanf("%i", &op);
    fflush(stdin);

    switch (op)
    {
      case 1:
        aloca(&al, cont + 1);
        cadastro(al + cont);
        cont++;
        break;
      case 2:
        ind = busca(al, cont);

        if (ind == -1)
        {
          printf("\nRA inexistente\n\n\n");
          system("pause");
        }
        else
          controle(al + ind);
        break;
    } 
  } while (op != 3);
} 

// ========================
void aloca(Aluno **p, int tam)
{
  if ((*p = (Aluno *)realloc(*p, tam * sizeof(Aluno))) == NULL)
    exit(1);
}

void cadastro(Aluno *p)
{
  int i;

  printf("\nNome: ");
  gets(p->nome);
  fflush(stdin);

  printf("\nRA: ");
  gets(p->RA);
  fflush(stdin);

  for (i = 0; i < 2; i++)
    *(p->nota + i) = 0; // conteudo de nota[i]=0

  p->media = 0;

  printf("\nCadastro efetuado com sucesso\n\n");
  system("pause");
}

int busca(Aluno *p, int q)
{
  int i;
  char aux[7];

  printf("\nRA: ");
  gets(aux);
  fflush(stdin);

  for (i = 0; i < q; i++)
    if (strcmp((p + i)->RA, aux) == 0)
      return i;

  return -1;
} 

void controle(Aluno *p)
{
  int i;

  printf("\nNome: %s", p->nome);
  printf("\nRA:   %s\n", p->RA);

  for (i = 0; i < 2; i++)
  {
    do
    {
      printf("\nNota[%i] (0~10)= ", i + 1);
      scanf("%f", p->nota + i);
      fflush(stdin);

    } while (*(p->nota + i) < 0 || *(p->nota + i) > 10);

    p->media += *(p->nota + i);
  }
  p->media /= i;

  for (i = 0; i < 2; i++)
    printf("\nNota[%i]= %.2f", i + 1, *(p->nota + i));

  printf("\nMedia= %.2f\n\n\n", p->media);
  
  system("pause");
} 
