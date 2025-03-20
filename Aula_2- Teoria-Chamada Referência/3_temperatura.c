#include <stdio.h>
#include <stdlib.h>
/*
Crie um vetor que armazene as temperaturas diárias registradas durante um mês e em seguida elabore um programa que calcule : 
• A maior temperatura e o dia em que ocorreu 
• A temperatura média mensal 
• As temperaturas inferiores à média e os dias em que ocorreram 
*/
void leitura(float *t, int tam);
void maior_temp(float *t, int tam);
float media_temp(float *t, int tam);
int inf_media(float *t, int tam, float media, int *pos);
void imprime(int *pos, int qtde, float *t);

main()
{
  system("cls");

  float temp[31], media;
  int dias, pos_inf[31], qtde;

  printf("\nTemperaturas Diarias\n");
  printf("\nQtde dias: ");
  scanf("%i", &dias);
  fflush(stdin);

  leitura(temp, dias);
  maior_temp(temp, dias);
  media = media_temp(temp, dias);

  printf("\nTemperatura Media: %.2f\n", media);
  qtde = inf_media(temp, dias, media, pos_inf);
  imprime(pos_inf, qtde, temp);

}

void leitura(float *t, int tam)
{
  int i;

  for (i = 0; i < tam; i++)
  {
    printf("\nTemperatura - %i dia: ", i + 1);
    scanf("%f", t++); // scanf("%f",t+i)
    fflush(stdin);
  }
}

void maior_temp(float *t, int tam)
{
  int i, dia;
  float maior;

  maior = *t;
  dia = 1;
  t++;

  for (i = 1; i < tam; i++, t++)
    if (maior < *t)
    {
      maior = *t;
      dia = i + 1;
    }

  printf("\nA maior temperatura = %.2f - ocorreu no dia %i\n", maior, dia);
}

float media_temp(float *t, int tam)
{
  int i;
  float media = 0;

  for (i = 0; i < tam; i++)
    media += *(t + i); // media+=*t++

  return (media /= tam);
}

int inf_media(float *t, int tam, float media, int *pos)
{
  int i, j;

  for (i = 0, j = 0; i < tam; i++)
    if (*(t + i) < media)
    {
      *(pos + j) = i;
      j++;
    }

  return j;
}

void imprime(int *pos, int qtde, float *t)
{
  int i;

  printf("\nTemperatura inferior a media\n");
  for (i = 0; i < qtde; i++)
    printf("\nTemperatura %.2f - dia: %i\n", *(t + *(pos + i)), *(pos + i) + 1);
}
