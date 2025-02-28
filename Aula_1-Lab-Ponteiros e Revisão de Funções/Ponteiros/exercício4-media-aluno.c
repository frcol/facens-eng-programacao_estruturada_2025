#include <stdio.h>
#include <stdlib.h>
/*
Apostila - pg29 - Exercício 4
Perguntar quantos alunos serão cadastrados (1 a 10).
Ler e armazenar 2 notas de cada aluno, verificar se estão no intervalo de 0 à 10.
Calcular a média para no máximo 10 alunos (utilizar array) e verificar:
se m >= 7 – imprimir APROVADO
se 4 <= m < 7 – imprimir EXAME
se m < 4 – imprimir REPROVADO.
*/

void leitura(float *p, int q);
void media(float *p1, float *p2, float *pm, int q);
void mostrarMedias(float *pm, int q);

int main()
{
  system("cls");

  float n1[10], n2[10], med[10];
  int q;

  do
  {
    printf("\nDigite a quantidade de alunos - max. 10: ");
    scanf("%i", &q);
  } while (q < 1 || q > 10);

  leitura(n1, q);
  leitura(n2, q);

  media(n1, n2, med, q);

  mostrarMedias(med, q);
}

// ====================================================
void leitura(float *p, int q)
{
  int i;

  for (i = 0; i < q; i++, p++)
  {
    do
    {
      printf("\nNota do %i aluno: ", i + 1);
      scanf("%f", p);
    } while (*p < 0 || *p > 10);
  }
}

void media(float *p1, float *p2, float *pm, int q)
{
  int i;

  for (i = 0; i < q; i++, p1++, p2++, pm++)
    *pm = (*p1 + *p2) / 2;
}

void mostrarMedias(float *pm, int q)
{
  for (int i = 0; i < q; i++, pm++)
  {
    printf("\nMedia - aluno %i = %.2f", i + 1, *pm);
    if (*pm >= 7)
      printf("- Aprovado\n");
    else
    {
      if (*pm >= 4)
        printf("- Exame\n");
      else
        printf("- Reprovado\n");
    }
  }
}