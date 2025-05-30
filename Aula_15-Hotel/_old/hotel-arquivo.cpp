#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hospede
{
  int quarto; // -1 se vago
              // ou o número do quarto ocupado
  char nome[30];
  int acompanhante; // numero de acompanhantes (0 a 3)
  int dias;
} hospede;

typedef struct quarto
{
  int num;
  char categoria; // S(olteiro) ou F(amiliar)
  char status; // L(ivre) ou O(cupado)
} quarto;

void aloca_quarto(quarto **pq, int qq);
void aloca_hospede(hospede **ph, int qh);

int verifica_quarto();    // verifica se o arquivo existe e retorna a quantidade de quartos              
int verifica_hospede();   // verifica se o arquivo existe e retorna a quantidade de hospedes

void cadastro_quarto(quarto *pq, int qq);
void cadastro_hospede(hospede *ph, quarto *pq, int qq);

void grava_quarto(quarto *pq);  // grava os quartos no arquivo na ordem de cadastro sendo os 
                                // primeiros 5 quartos do tipo S(olteiro) e os demais do tipo F(amiliar)
                                // e o status Livre                  
void grava_hospede(hospede *ph, char *aux, int pos);

int busca_vago(hospede *ph, int qh);
int busca_quarto(quarto *pq, int qq, char letra);

void encerra_quarto(hospede *ph, quarto *pq, int qq);

void mostra_hospede(hospede *ph, int num);
void mostra_quarto(quarto *pq, int qq);

main()
{
  system("cls");

  quarto *q = NULL;
  hospede *hosp = NULL;
  int op, qhosp, pos, num, qq;

  aloca_quarto(&q, 1);
  qq = verifica_quarto();

  if (qq == 0)
    cadastro_quarto(q, 15); // cadastra os 15 quartos no arquivo 

  aloca_hospede(&hosp, 1);

  do
  {
    system("cls");
    printf("[1]Check-in\n[2]Check-out\n[3]Mostra Hospedes\n[4]Mostra Quarto\n[5]Fim\nOpcao:");
    scanf("%i", &op);
    fflush(stdin);

    switch (op)
    {
      case 1:
        cadastro_hospede(hosp, q, 15);
        break;
      case 2:
        encerra_quarto(hosp, q, 15);
        break;
      case 3:
        mostra_hospede(hosp, 0);
        break;
      case 4:
        mostra_quarto(q, 15);
        break;
      }
  } while (op != 5);

  system("pause");
}

void aloca_quarto(quarto **pq, int qq)
{
  if (((*pq = (quarto *)realloc(*pq, qq * sizeof(quarto))) == NULL))
    exit(1);
}

void aloca_hospede(hospede **ph, int qh)
{
  if (((*ph = (hospede *)realloc(*ph, qh * sizeof(hospede))) == NULL))
    exit(1);
}

int verifica_quarto()
{
  FILE *fq = NULL;
  long int q;

  if ((fq = fopen("quarto.bin", "rb")) == NULL)
    return 0;

  fseek(fq, 0, SEEK_END);
  q = ftell(fq) / sizeof(quarto);

  fclose(fq);
  return q;
}

int verifica_hospede()
{
  FILE *fh = NULL;
  long int q;

  if ((fh = fopen("hospede.bin", "rb")) == NULL)
    return 0;

  fseek(fh, 0, 2);
  q = ftell(fh) / sizeof(hospede);

  fclose(fh);
  return q;
}

void cadastro_quarto(quarto *pq, int qq)
{
  int i;

  for (i = 0; i < qq; i++)
  {
    if (i < 5)
      pq->categoria = 'S';
    else
      pq->categoria = 'F';

    pq->num = i + 1;
    pq->status = 'L';

    grava_quarto(pq);
  }
} 

void cadastro_hospede(hospede *ph, quarto *pq, int qq)
{
  int qhosp, pos;

  system("cls");
  qhosp = verifica_hospede(); // qtde de hospedes
  pos = busca_vago(ph, qhosp);
  printf("\nNome: ");
  gets(ph->nome);
  fflush(stdin);
  do
  {
    printf("\nQtde de acompanhantes - max.3: ");
    scanf("%i", &(ph->acompanhante));
    fflush(stdin);
  } while (ph->acompanhante < 0 || ph->acompanhante > 3);
  if (ph->acompanhante == 0)
    ph->quarto = busca_quarto(pq, qq, 'S');
  else
    ph->quarto = busca_quarto(pq, qq, 'F');
  printf("\nNum quarto:%i", ph->quarto);
  if (ph->quarto == -1)
    printf("\nHotel Lotado");
  else
  {
    printf("\nQtos dias: ");
    scanf("%i", &(ph->dias));
    fflush(stdin);
    if (pos == -1)                // nao ha hospede vago
      grava_hospede(ph, "ab", 1); // adiciona registro no fim
    else
      grava_hospede(ph, "rb+", pos); // sobreescrever no lugar do vago
  }
} // cadastro_hospede

void grava_quarto(quarto *pq)
{
  FILE *fq = NULL;

  if ((fq = fopen("quarto.bin", "ab")) == NULL)
    printf("\nArquivo inexistente-1\n");
  else
  {
    fwrite(pq, sizeof(quarto), 1, fq);
  }
  fclose(fq);
} // grava_quarto

void grava_hospede(hospede *ph, char *aux, int pos)
{
  FILE *fh = NULL;

  if ((fh = fopen("hospede.bin", aux)) == NULL)
    printf("\nArquivo inexistente\n");
  else
  {
    if (strcmp(aux, "rb+") == 0)
      fseek(fh, pos * sizeof(hospede), 0);
    fwrite(ph, sizeof(hospede), 1, fh);
  } // else
  fclose(fh); // fora do ELSE por conta do ab ou rb+
} // grava_hospede

int busca_vago(hospede *ph, int qh)
{
  FILE *fh = NULL;
  int i;

  if ((fh = fopen("hospede.bin", "rb")) == NULL)
    printf("\nArquivo inexistente\n");
  else
  {
    for (i = 0; i < qh; i++)
    {
      fseek(fh, i * sizeof(hospede), 0);
      fread(ph, sizeof(hospede), 1, fh);
      if (ph->quarto == -1) // if(strcmp(ph->nome,"@")==0)
      {
        fclose(fh);
        return i;
      }
    } // for
    fclose(fh);
  } // else
  return -1;
} // busca_vago

int busca_quarto(quarto *pq, int qq, char letra)
{
  FILE *fq = NULL;
  int i;
  if ((fq = fopen("quarto.bin", "rb+")) == NULL)
    printf("\nImpossivel abrir o arquivo");
  else
    for (i = 0; i < qq; i++)
    {
      fseek(fq, i * sizeof(quarto), 0);
      fread(pq, sizeof(quarto), 1, fq);
      if (pq->categoria == letra && pq->status == 'L')
      {
        pq->status = 'O';
        fseek(fq, i * sizeof(quarto), 0);  // volta o ponteiro para a posi��o correta
        fwrite(pq, sizeof(quarto), 1, fq); // atualiza o quarto para Ocupado
        fclose(fq);
        return (pq->num); // retorna o n�mero do quarto
      }
    } // for
  fclose(fq);
  return -1;
} // busca_quarto

void encerra_quarto(hospede *ph, quarto *pq, int qq)
{
  FILE *fq = NULL;
  int i, num;
  float total;

  printf("\nQuarto a ser encerrado: ");
  scanf("%i", &num);
  fflush(stdin);
  mostra_hospede(ph, num);

  if ((fq = fopen("quarto.bin", "rb+")) == NULL)
    printf("\nArquivo inexistente\n");
  else
    for (i = 0; i < qq; i++)
    {
      fseek(fq, i * sizeof(quarto), 0);
      fread(pq, sizeof(quarto), 1, fq);
      if (pq->num == num)
      {
        if (pq->categoria == 'S')
          total = ph->dias * 85;
        else
          total = ph->dias * 45 * (ph->acompanhante + 1);
        printf("\nValor a ser pago: %.2f\n", total);
        system("pause");
        pq->status = 'L';
        fseek(fq, i * sizeof(quarto), 0);  // volta o ponteiro para a posi��o correta
        fwrite(pq, sizeof(quarto), 1, fq); // atualiza o quarto para Livre
      } // if
    } // for
  fclose(fq);
}

void mostra_hospede(hospede *ph, int num)
{
  FILE *fh = NULL;
  int i, qhosp;
  qhosp = verifica_hospede();

  if ((fh = fopen("hospede.bin", "rb+")) == NULL)
    printf("\nArquivo inexistente\n");
  else
    for (i = 0; i < qhosp; i++)
    {
      fseek(fh, i * sizeof(hospede), 0);
      fread(ph, sizeof(hospede), 1, fh);
      printf("\nQuarto: %i\nNome:%s\nAcompanhantes: %i\nDias: %i\n\n\n", ph->quarto, ph->nome, ph->acompanhante, ph->dias);
      if (ph->quarto == num)
      {
        ph->quarto = -1;                    // strcpy(ph->nome,"@");
        fseek(fh, i * sizeof(hospede), 0);  // volta o ponteiro para a posi��o correta
        fwrite(ph, sizeof(hospede), 1, fh); // atualiza o hospede como vago
        i = qhosp;                          // for�a a sa�da do for para n�o ler mais nenhum hospede
      }
    } // for
  fclose(fh);
  system("pause");
} // mostra_hospede

void mostra_quarto(quarto *pq, int qq)
{
  FILE *fq = NULL;
  int i;

  if ((fq = fopen("quarto.bin", "rb")) == NULL)
    printf("\nArquivo inexistente\n");
  else
    for (i = 0; i < qq; i++)
    {
      fseek(fq, i * sizeof(quarto), 0);
      fread(pq, sizeof(quarto), 1, fq);
      printf("\nNumero Quarto: %i\nCategoria: %c\nStatus: %c\n\n", pq->num, pq->categoria, pq->status);
    } // for
  fclose(fq);
  system("pause");
} // mostra quarto
