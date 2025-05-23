#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dados
{
	int reg;
	char produto[20];
	int qtde;
	float preco;
} dados;

void aloca(dados **p, int tam);
void cadastro(dados *p);
int verifica();
void altera(dados *p, int op);
int busca_registro(dados *p, int n_reg);
int busca_vago(dados *p);
void grava(dados *p, char *str, int pos);
void mostra(dados *p);

main()
{
	system("cls");

	dados *pd = NULL;
	int op;

	aloca(&pd, 1);
	do
	{
		system("cls");
		printf("\n[1]Cadastro\n[2]Mostra\n[3]Altera\n[4]Deleta\n[5]Fim\nOpcao: ");
		scanf("%i", &op);
		fflush(stdin);

		switch (op)
		{
			case 1:
				cadastro(pd);
				break;
			case 2:
				mostra(pd);
				break;
			case 3:
			case 4:
				altera(pd, op);
				break;
		}
	} while (op != 5);
}

void aloca(dados **p, int tam)
{
	if ((*p = (dados *)realloc(*p, tam * sizeof(dados))) == NULL)
		exit(1);
}

void cadastro(dados *p)
{
	int qtde, achou;
	qtde = verifica(); // qtde de elementos dentro do arquivo
	achou = busca_vago(p);

	if (achou == -1)	   // nao tem registro vago
		p->reg = qtde + 1; // proximo registro

	printf("\nRegistro: %i", p->reg);
	printf("\nProduto: ");
	gets(p->produto);
	fflush(stdin);

	printf("\nQuantidade: ");
	scanf("%i", &(p->qtde));
	fflush(stdin);

	printf("\nPreco: ");
	scanf("%f", &(p->preco));
	fflush(stdin);

	if (achou == -1)
		grava(p, "ab", -1);
	else
		grava(p, "rb+", achou);

	printf("\nRegistro cadastrado com sucesso\n\n");

	system("pause");
} 

int verifica()
{
	FILE *fptr = NULL;
	long int cont = 0;

	if ((fptr = fopen("estoque.bin", "rb")) == NULL)
		return cont;
	else
	{
		fseek(fptr, 0, SEEK_END); // posiciona fptr no fim do arquivo
		cont = ftell(fptr) / sizeof(dados);
		fclose(fptr); // dentro do else por conta do rb

		return cont;
	}
}

void altera(dados *p, int op)
{
	int n_reg;

	printf("\nRegistro a ser alterado/deletado: ");
	scanf("%i", &n_reg);
	fflush(stdin);

	n_reg = busca_registro(p, n_reg);

	if (n_reg == -1)
		printf("\nRegistro invalido\n\n");
	else
	{
		printf("\nRegistro: %i\nProduto: %s\nQuantidade: %i\nPreco: %.2f\n\n", p->reg, p->produto, p->qtde, p->preco);

		if (op == 3) // altera
		{
			printf("\nNOVO preco: ");
			scanf("%f", &p->preco);
			fflush(stdin);
		} 
		else
			p->qtde = -1;  // marca como -1 arquivo deletado
	} 

	grava(p, "rb+", n_reg);

	printf("\nRegistro alterado com sucesso\n\n");
	system("pause");
} // altera

int busca_registro(dados *p, int n_reg)
{
	FILE *fptr = NULL;
	int qtde, i, reg = -1;

	qtde = verifica(); // qtde de registros no arquivo

	if ((fptr = fopen("estoque.bin", "rb")) == NULL)
		printf("\nErro no arquivo\n\n");
	else
	{
		for (i = 0; i < qtde; i++)
		{
			fseek(fptr, i * sizeof(dados), 0);
			fread(p, sizeof(dados), 1, fptr);
			if (p->reg == n_reg)
			{
				reg = i;  // posicao do registro no arquivo
				i = qtde; // forca a saida do for
			}
		}
		
		fclose(fptr); // dentro do else - rb
	}

	return reg;
}

int busca_vago(dados *p)
{
	FILE *fptr = NULL;
	int qtde, achou = -1, i;

	qtde = verifica();
	if ((fptr = fopen("estoque.bin", "rb")) == NULL)
		return achou;
	else
	{
		for (i = 0; i < qtde; i++)
		{
			fseek(fptr, i * sizeof(dados), 0);
			fread(p, sizeof(dados), 1, fptr);
			if (p->qtde == -1)
			{
				achou = i;
				i = qtde; // forca a saida do for
			} // if
		} // for
		fclose(fptr); // dentro do else - rb
		return achou;
	} // else
} // busca_vago

void grava(dados *p, char *str, int pos)
{
	FILE *fptr = NULL;

	if ((fptr = fopen("estoque.bin", str)) == NULL)
		printf("\nErro\n\n");
	else
	{
		if (strcmp(str, "rb+") == 0)
			fseek(fptr, pos * sizeof(dados), 0);
		fwrite(p, sizeof(dados), 1, fptr);
	} // else
	fclose(fptr); // fora do else por conta do ab
} // grava

void mostra(dados *p)
{
	FILE *fptr = NULL;
	int qtde, i;
	qtde = verifica(); // qtde de elementos do arquivo

	if ((fptr = fopen("estoque.bin", "rb")) == NULL)
		printf("\nErro\n\n");
	else
	{
		for (i = 0; i < qtde; i++)
		{
			fseek(fptr, i * sizeof(dados), 0); // a partir do inicio
			fread(p, sizeof(dados), 1, fptr);
			printf("\nRegistro: %i\nProduto: %s\nQuantidade: %i\nPreco: %.2f\n\n", p->reg, p->produto, p->qtde, p->preco);
		} // for
		fclose(fptr); // dentro do else - por conta do rb
	} // else
	system("pause");
} // mostra
