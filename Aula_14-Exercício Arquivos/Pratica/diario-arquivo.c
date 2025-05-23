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

void aloca(Aluno **p, int tam);             // aloca memoria
int verifica();                             // retorna qtde de registros 
void cadastro(Aluno *p);                    // cadastro de Aluno sem notas (notas=0, media=0)
void grava(Aluno *p, char *str, int pos);   // grava Aluno no arquivo - cadastro (str = "ab") ou controle (str = "rb+")
int busca(Aluno *p, char *aux_RA);          // busca Aluno no arquivo por RA e reto
void controle(Aluno *p);                    // Entra com RA e altera notas
void mostra(Aluno *p);                      // Mostra todos os Alunos cadastrados

main()
{
  Aluno *palu = NULL;
  int op, ind;

  aloca(&palu, 1);

  do
  {
    system("cls");
    printf("\n[1] Cadastro\n[2] Controle de Notas\n[3] Mostra Alunos\n[4] Fim\nOpcao: ");
    scanf("%i", &op);
    fflush(stdin);

    switch (op)
    {
      case 1:
        cadastro(palu);
        break;
      case 2:
        controle(palu);
        break;
      case 3:
        mostra(palu);
        break;
    }
  } while (op != 4);
}

void aloca(Aluno **p, int tam)
{
  if ((*p = (Aluno *)realloc(*p, tam * sizeof(Aluno))) == NULL)
    exit(1);
}

int verifica()
{
  FILE *fptr = NULL;
  int qtde = 0;

  if ((fptr = fopen("aluno.bin", "rb")) == NULL)
    return qtde;
  else
  {
    fseek(fptr, 0, SEEK_END);           // posiciona no fim do arquivo
    qtde = ftell(fptr) / sizeof(Aluno); // qtde de elementos
    fclose(fptr);                       // dentro do ELSE por conta do rb

    return qtde;
  }
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
  grava(p, "ab", 1);

  system("pause");
}

void grava(Aluno *p, char *str, int pos)
{
  FILE *fptr = NULL;

  if ((fptr = fopen("aluno.bin", str)) == NULL)
    printf("\nErro\n\n");
  else
  {
    if (strcmp(str, "rb+") == 0)
      fseek(fptr, pos * sizeof(Aluno), 0);

    fwrite(p, sizeof(Aluno), 1, fptr);
  } 

  fclose(fptr); // fora do else por conta do ab e rb+
}

int busca(Aluno *p, char *aux_RA)
{
  int qtde, i, pos = -1;
  FILE *fptr = NULL;
  qtde = verifica();

  if ((fptr = fopen("aluno.bin", "rb")) == NULL)
    return pos;
  else
  {
    for (i = 0; i < qtde; i++)
    {
      fseek(fptr, i * sizeof(Aluno), 0);
      fread(p, sizeof(Aluno), 1, fptr);

      if (strcmp(p->RA, aux_RA) == 0)
      {
        pos = i;  // registro desejado
        break; // forca a saida do for
      }
    } 

    fclose(fptr); // por conta do ab

    return pos;
  }
}

void controle(Aluno *p)
{
  int i, pos;
  char aux_RA[7];

  printf("\nRA: ");
  gets(aux_RA);
  fflush(stdin);

  pos = busca(p, aux_RA);   // p é passado por referencia

  if (pos == -1)
    printf("\nRA inexistente\n\n\n");
  else
  {
    printf("\nNome: %s\n", p->nome);
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

    grava(p, "rb+", pos);
  }
  system("pause");
}

void mostra(Aluno *p)
{
  FILE *fptr = NULL;
  int i, qtde;
  qtde = verifica();

  system("cls");

  if ((fptr = fopen("aluno.bin", "rb")) == NULL)
    printf("\nErro ao abrir o arquivo");
  else
  {
    for (i = 0; i < qtde; i++)
    {
      fseek(fptr, i * sizeof(Aluno), 0);
      fread(p, sizeof(Aluno), 1, fptr);

      printf("\nNome: %s\nRA: %s\nNota1: %.2f\nNota2: %.2f\nMedia: %.2f\n\n", p->nome, p->RA, *(p->nota + 0), *(p->nota + 1), p->media);
    }
    
    fclose(fptr);
  }

  system("pause");
}
