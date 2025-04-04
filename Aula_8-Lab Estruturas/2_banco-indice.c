#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente
{
  char nome[30];
  int conta;
  float saldo;
};

struct cliente cadastro();
struct cliente movimento(struct cliente x, int op);

main()
{
  struct cliente cli[10];
  int op, cont = 0, num_conta, i, achou;

  do
  {
    system("cls");

    printf("[1]Cadastro\n[2]Deposito\n[3]Retirada\n[4]Fim\nOpcao: ");
    scanf("%i", &op);
    fflush(stdin);

    switch (op)
    {
    case 1:
      if (cont < 10)
      {
        cli[cont] = cadastro();
        cont++;
      }
      else
        printf("\nCadastro Lotado\n");
      break;

    case 2:
    case 3:
      printf("\nConta: ");
      scanf("%i", &num_conta);
      fflush(stdin);

      achou = 0;

      for (i = 0; i < cont; i++)
        if (cli[i].conta == num_conta)
        {
          cli[i] = movimento(cli[i], op);
          achou = 1;
        }

      if (achou == 0)
        printf("\nConta invalida\n");
      break;
    }
  } while (op != 4);
} 

struct cliente cadastro()
{
  struct cliente aux;
  static int n_conta = 1000;

  printf("\nNome: ");
  gets(aux.nome);
  fflush(stdin);

  aux.conta = n_conta;
  aux.saldo = 0;
  n_conta++;

  printf("\nConta: %i\n", aux.conta);

  return aux;
}

struct cliente movimento(struct cliente x, int op)
{
  float valor;
  
  printf("\nNome: %s\nSaldo: %.2f", x.nome, x.saldo);
  printf("\nValor a ser depositado/retirado: ");
  scanf("%f", &valor);
  fflush(stdin);

  if (op == 2)
    x.saldo += valor;
  else
  {
    if (valor <= x.saldo)
      x.saldo -= valor;
    else
      printf("\nSaldo insuficiente\n");
  }

  printf("\nSaldo Atualizado: %.2f\n\n", x.saldo);

  return x;
}
