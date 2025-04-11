#include <stdio.h>
#include <stdlib.h>

typedef struct agenda
{
  int reg;
  char nome[20];
  float nota;
} Agenda;

void aloca(Agenda **p, int tam);
void cadastro(Agenda *p);
void mostra(Agenda *p, int tam);

main()
{
  system("cls");

  Agenda *ag = NULL;
  int cont = 0;
  char op;

  do
  {
    aloca(&ag, cont + 1);
    cadastro(ag + cont);
    cont++;

    printf("\nDeseja continuar <S/N>: ");
    scanf("%c", &op);
    fflush(stdin);
  } while (op == 's' || op == 'S');

  mostra(ag, cont);
}

void aloca(Agenda **p, int tam)
{
  if ((*p = (Agenda *)realloc(*p, tam * sizeof(Agenda))) == NULL)
    exit(1);
}

void cadastro(Agenda *p)
{
  static int n = 1;

  p->reg = n;
  n++;

  printf("\nNome: ");
  gets(p->nome);
  fflush(stdin);

  do
  {
    printf("\nNota: ");
    scanf("%f", &p->nota);
    fflush(stdin);
  } while (p->nota < 0 || p->nota > 10);
}

void mostra(Agenda *p, int tam)
{
  system("cls");
  int i;

  for (i = 0; i < tam; i++)
    printf("Registro:%i\nNome:%s\nNota:%.2f\n\n", (p + i)->reg, (p + i)->nome, (p + i)->nota);
  system("pause");
}
