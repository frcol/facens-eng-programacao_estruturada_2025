#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente
{
  char nome[30];
  int conta;
  float saldo;
} Cliente;

Cliente cadastro();
Cliente movimento(Cliente x, int op);

int main()
{
  system("cls");

  Cliente cli[10];
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
      
      for (i = 0; i < cont; i++) {
        if (cli[i].conta == num_conta)
        {
          cli[i] = movimento(cli[i], op);
          achou = 1;
        }
      }

      if (achou == 0)
        printf("\nConta invalida\n");

      break;
    }
  } while (op != 4);

  return 0;
}

Cliente cadastro()
{
  Cliente aux;
  static int n_conta = 1000;

  printf("\nNome: ");
  gets(aux.nome);
  fflush(stdin);

  aux.conta = n_conta;
  aux.saldo = 0;
  n_conta++;

  printf("\nConta: %i\n", aux.conta);
  system("pause");

  return aux;
}

Cliente movimento(Cliente cli, int op)
{
  float valor;

  printf("\nNome: %s\nSaldo: %.2f", cli.nome, cli.saldo);
  printf("\nValor a ser depositado/retirado: ");
  scanf("%f", &valor);
  fflush(stdin);

  if (op == 2)
    cli.saldo += valor;
  else
  {
    if (valor <= cli.saldo)
      cli.saldo -= valor;
    else
      printf("\nSaldo insuficiente\n");
  }

  printf("\nSaldo Atualizado: %.2f\n\n", cli.saldo);
  
  system("pause");

  return cli;
}
