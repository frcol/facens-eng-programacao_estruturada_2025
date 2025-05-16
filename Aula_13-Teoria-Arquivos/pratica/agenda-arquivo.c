#include <stdio.h>
#include <stdlib.h>

typedef struct agenda
{
  int reg;
  char nome[20];
  float nota;
} Agenda;

void aloca(Agenda **p, int tam);
int verifica();
void cadastro(Agenda *p);
void grava(Agenda *p);
void mostra(Agenda *p);

main()
{
  Agenda *ag = NULL;
  int cont = 0;
  char op;

  aloca(&ag, 1);

  do
  {
    cadastro(ag + cont);
    printf("\nDeseja continuar <S/N>: ");
    scanf("%c", &op);
    fflush(stdin);
  } while (op == 's' || op == 'S');

  mostra(ag);
}

void aloca(Agenda **p, int tam)
{
  if ((*p = (Agenda *)realloc(*p, tam * sizeof(Agenda))) == NULL)
    exit(1);
}

int verifica()
{
  FILE *fptr = NULL;
  int cont = 0;

  fptr = fopen("agenda.bin", "rb");
  if (fptr == NULL)
    return cont;
  else
  {
    fseek(fptr, 0, SEEK_END);                   // posiciona no fim do arquivo
    cont = ftell(fptr) / sizeof(Agenda); // qtde de elementos
    fclose(fptr);                        // dentro do ELSE por conta do rb
    
    return cont;
  } 
} 

void cadastro(Agenda *p)
{
  int qreg;

  qreg = verifica();

  p->reg = qreg + 1;
  printf("\nRegistro: %i", p->reg);
  printf("\nNome: ");
  gets(p->nome);
  fflush(stdin);

  do
  {
    printf("Nota: ");
    scanf("%f", &p->nota);
    fflush(stdin);
  } while (p->nota < 0 || p->nota > 10);

  grava(p);
} 

void grava(Agenda *p)
{
  FILE *fptr = NULL;

  fptr = fopen("agenda.bin", "ab");
  if (fptr == NULL)
    printf("\nErro ao abrir o arquivo");
  else
    fwrite(p, sizeof(Agenda), 1, fptr);

  fclose(fptr); // fora do ELSE por conta do ab
} 

void mostra(Agenda *p)
{
  FILE *fptr = NULL;
  int i, qreg;

  qreg = verifica();

  system("cls");

  fptr = fopen("Agenda.bin", "rb");
  if (fptr == NULL)
    printf("\nErro ao abrir o arquivo");
  else
  {
    for (i = 0; i < qreg; i++)
    {
      fseek(fptr, i * sizeof(Agenda), 0);
      fread(p, sizeof(Agenda), 1, fptr);
      printf("\nRegistro: %i\nNome: %s\nNota: %.2f\n\n", p->reg, p->nome, p->nota);
    } 

    fclose(fptr);
  }
  system("pause");
}
