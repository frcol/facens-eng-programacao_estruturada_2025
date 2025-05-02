#include <stdio.h>
#include <stdlib.h>

typedef struct quarto
{
  int num;
  char categoria; // S-solteiro ou F-familiar
  char status;    // L-livre ou O-ocupado
} Quarto;

typedef struct hospede
{
  int quarto;
  char nome[30];
  int acompanhante;
  int dias;
} Hospede;

void aloca_quarto(Quarto **p_qua, int qtde);
void aloca_hospede(Hospede **p_hos, int qtde);

void cadastra_quarto(Quarto *p_qua, int qtde);
void cadastra_hospede(Hospede *p_hos, Quarto *p_qua);

int busca_quarto(Quarto *quarto, char cat);       // Busca quarto vago. Se achou quarto status Livre, retorna numero do quarto. Se nao achou, retorna -1.
int busca_vago(Hospede *p_hos, int qtde, int q);  // Busca hospede "vago". Se achou hospede com quarto=-1, retorna posicao.

void check_out(Hospede *p_hos, int qtde, Quarto *p_qua);

void mostra_hospede(Hospede *p_hos, int qtde); // FRC
void mostra_quarto(Quarto *p_qua, int qtde); // FRC

main()
{
  Quarto *p_quarto = NULL; 
  Hospede *p_hospede = NULL;
  int op;
  int cont = 0;
  int pos;                // posicao do hospede no vetor de hospedes

  aloca_quarto(&p_quarto, 15);
  cadastra_quarto(p_quarto, 15);

  do
  {
    system("cls");
 
    printf("\n[1]Check-in");;
    printf("\n[2]Check-out ");
    printf("\n[3]Fim");
    printf("\n\nEscolha: ");
    scanf("%i", &op);
    fflush(stdin);

    switch (op)
    {
    case 1:
      pos = busca_vago(p_hospede, cont, -1); // procurar quarto=-1

      if (pos == -1) // nao encontrou quarto vago
      {
        aloca_hospede(&p_hospede, cont + 1);
        pos = cont;
        cont++;
      }

      cadastra_hospede(p_hospede + pos, p_quarto);
      break;
    case 2:
      check_out(p_hospede, cont, p_quarto);
      break;
    }
  } while (op != 3);
}

void aloca_quarto(Quarto **p_qua, int qtde)
{
  if ((*p_qua = (Quarto *)realloc(*p_qua, qtde * sizeof(Quarto))) == NULL)
    exit(1);
}

void aloca_hospede(Hospede **p_hos, int qtde)
{
  if ((*p_hos = (Hospede *)realloc(*p_hos, qtde * sizeof(Hospede))) == NULL)
    exit(1);
}

void cadastra_quarto(Quarto *p_qua, int qtde)
{
  int i;

  for (i = 0; i < qtde; i++)
  {
    (p_qua + i)->num = i + 1;
    (p_qua + i)->status = 'L';

    if (i < 5) // 5 quartos de Solteiro
      (p_qua + i)->categoria = 'S';
    else // 10 quartos Familiar
      (p_qua + i)->categoria = 'F';
  }
}

void cadastra_hospede(Hospede *p_hos, Quarto *p_qua)
{
  char cat;       // categoria do quarto  - S-solteiro ou F-familiar
  int pessoas;    // quantidade de pessoas no quarto    
  int numq;       // numero do quarto

  do
  {
    printf("\nQtde pessoas - max.4: ");
    scanf("%i", &pessoas);
    fflush(stdin);
  } while (pessoas < 1 || pessoas > 4);

  if (pessoas == 1)
    cat = 'S';
  else
    cat = 'F';

  numq = busca_quarto(p_qua, cat);

  if (numq == -1)
    printf("\nNao ha vagas\n\n\n");
  else
  {
    p_hos->quarto = numq;
    p_hos->acompanhante = pessoas - 1;

    printf("\nNome: ");
    gets(p_hos->nome);
    fflush(stdin);

    printf("\nQtos dias: ");
    scanf("%i", &(p_hos->dias));
    fflush(stdin);

    printf("\nCadastro feito com sucesso\nQuarto: %i\n\n\n", p_hos->quarto);
  }
  system("pause");
}

int busca_quarto(Quarto *p_qua, char cat)
{
  int i;

  for (i = 0; i < 15; i++)
    if ((p_qua + i)->categoria == cat && (p_qua + i)->status == 'L')
    {
      (p_qua + i)->status = 'O';
      return ((p_qua + i)->num);
    }

  return -1;
}

void check_out(Hospede *p_hos, int qtde, Quarto *p_qua)
{
  int numq;    // numero do quarto
  int i;

  printf("\nQuarto: ");
  scanf("%i", &numq);
  fflush(stdin);

  (p_qua + numq - 1)->status = 'L';

  for (i = 0; i < qtde; i++)
    if ((p_hos + i)->quarto == numq)
    {
      printf("\nNome: %s\n", (p_hos + i)->nome);

      if ((p_hos + i)->acompanhante == 0)
        printf("\nValor a pagar: %.2f\n\n\n", ((p_hos + i)->dias) * 50.00);
      else
        printf("\nValor a pagar: %.2f\n\n\n", (p_hos + i)->dias * (((p_hos + i)->acompanhante) + 1) * 45.00);
      
      (p_hos + i)->quarto = -1;
    }

    system("pause");
}

int busca_vago(Hospede *p_hos, int qtde, int q)
{
  int i;

  for (i = 0; i < qtde; i++)
    if ((p_hos + i)->quarto == q)
      return i;

  return -1;
}


void mostra_hospede(Hospede *p_hos, int qtde)
{
  int i;

  for (i = 0; i < qtde; i++)
    if ((p_hos + i)->quarto != -1)
      printf("\nNome: %s\nQuarto: %i\nAcompanhantes: %i\nDias: %i\n", (p_hos + i)->nome, (p_hos + i)->quarto, (p_hos + i)->acompanhante, (p_hos + i)->dias);
}

void mostra_quarto(Quarto *p_qua, int qtde)
{
  int i;

  for (i = 0; i < qtde; i++)
    printf("\nQuarto: %i\nCategoria: %c\nStatus: %c\n", (p_qua + i)->num, (p_qua + i)->categoria, (p_qua + i)->status);
}