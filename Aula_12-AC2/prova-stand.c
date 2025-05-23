#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct stand
{
  int reg;     // registro do stand � gerado automaticamente
  char tam;    // [P] /[M] / [G] � gerado automaticamente
  char tipo;   // [A] / [F] � gerado automaticamente
  char status; // [L]ivre / [E]mprestado � gerado automaticamente
  float valor; // valor do stand � solicitar ao cadastrar
} stand;

typedef struct cliente
{
  char CPF[13];  // CPF do cliente
  char nome[80]; // nome do cliente
  int numreg;    // n�mero do registro do stand
  int dias;      // tempo de permanencia
} cliente;

void aloca_stand(stand **psta, int qsta);
void aloca_cliente(cliente **pcli, int qcli);
void cadastra_stand(stand *psta, int qsta);
void cadastra_cliente(cliente *pcli, stand *psta, int qsta);
int busca_stand(stand *psta, int qsta, char mod, char aux_turno);
void mostra_stand(stand *psta, int qsta);
void mostra_cliente(cliente *pcli, int qcli);

main()
{
  stand *sta = NULL;
  cliente *cli = NULL;

  int op, cont = 0;
  
  aloca_stand(&sta, 6);
  cadastra_stand(sta, 6);
  
  do
  {
    system("cls");
    printf("\n[1]Locacao \n[2]Mostra Cliente \n[3]Fim \nOpcao: ");
    scanf("%i", &op);
    fflush(stdin);

    switch (op)
    {
    case 1:
      mostra_stand(sta, 6);
      aloca_cliente(&cli, cont + 1);
      cadastra_cliente(cli + cont, sta, 6);
      cont++;
      break;
    case 2:
      mostra_cliente(cli, cont);
      break;
    }
  } while (op != 3);
}

void aloca_stand(stand **psta, int qsta)
{
  if ((*psta = (stand *)realloc(*psta, qsta * sizeof(stand))) == NULL)
    exit(1);
}

void aloca_cliente(cliente **pcli, int qcli)
{
  if ((*pcli = (cliente *)realloc(*pcli, qcli * sizeof(cliente))) == NULL)
    exit(1);
} 

void cadastra_stand(stand *psta, int qsta)
{
  int i;
  for (i = 0; i < qsta; i++, psta++)
  {
    psta->reg = i + 1;
    psta->status = 'L';

    if (i < 2)
      psta->tam = 'P';
    else if (i < 4)
      psta->tam = 'M';
    else if (i < 6)
      psta->tam = 'G';

    if (i == 0 || i == 2 || i == 4)
      psta->tipo = 'F';
    if (i == 1 || i == 3 || i == 5)
      psta->tipo = 'A';

    printf("\nRegistro: %i\nTamanho: %c\nTipo: %c\nStatus: %c", psta->reg, psta->tam, psta->tipo, psta->status);
    printf("\nValor do Stand: ");
    scanf("%f", &psta->valor);
    fflush(stdin);
  } 
} 

void cadastra_cliente(cliente *pcli, stand *psta, int qsta)
{
  char aux_tam, aux_tipo;

  printf("\nTamanho do Stand = P - M - G: ");
  scanf("%c", &aux_tam);
  fflush(stdin);
  aux_tam = toupper(aux_tam);

  printf("\nTipo do Stand = [F]echado - [A]berto: ");
  scanf("%c", &aux_tipo);
  fflush(stdin);
  aux_tipo = toupper(aux_tipo);

  pcli->numreg = busca_stand(psta, qsta, aux_tam, aux_tipo);

  if (pcli->numreg == -1)
    printf("\nNao ha stands disponiveis com esse tamanho e tipo\n\n\n");
  else
  {
    printf("\nCPF: ");
    gets(pcli->CPF);
    fflush(stdin);

    printf("\nNome: ");
    gets(pcli->nome);
    fflush(stdin);

    printf("\nDias: ");
    scanf("%i", &pcli->dias);
    fflush(stdin);

    printf("\nCadastro feito com sucesso\nStand: %i\nValor da diaria: %.2f\n\n", pcli->numreg, (psta + pcli->numreg - 1)->valor);
  }
  system("pause");
}

int busca_stand(stand *psta, int qsta, char aux_tam, char aux_tipo)
{
  int i;
  for (i = 0; i < qsta; i++, psta++)
    if (psta->tam == aux_tam && psta->tipo == aux_tipo && psta->status == 'L')
    {
      psta->status = 'E';
      return (psta->reg);
    }
  return -1;
}

void mostra_stand(stand *psta, int qsta)
{
  int i;
  for (i = 0; i < qsta; i++, psta++)
    printf("\nRegistro Stand: %i\nTamanho: %c\nTipo: %c\nStatus: %c\nValor: %.2f\n\n", psta->reg, psta->tam, psta->tipo, psta->status, psta->valor);

  printf("\n\n\n");
  system("pause");
}

void mostra_cliente(cliente *pcli, int qcli)
{
  int i;
  for (i = 0; i < qcli; i++, pcli++)
    printf("\nCPF: %s\nNome: %s\nRegistro do stand: %i\nDias: %i", pcli->CPF, pcli->nome, pcli->numreg, pcli->dias);
  printf("\n\n\n");
  system("pause");
}
