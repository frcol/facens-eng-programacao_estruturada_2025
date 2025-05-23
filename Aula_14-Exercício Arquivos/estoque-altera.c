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
void altera(dados *p);
int busca_registro(dados *p, int nreg);
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
		printf("\n[1]Cadastro\n[2]Altera\n[3]Mostra\n[4]Fim\nOpcao: ");
		scanf("%i", &op);
		fflush(stdin);

		switch (op)
		{
			case 1:
				cadastro(pd);
				printf("\nRegistro cadastrado com sucesso\n\n");
				system("pause");
				break;
			case 2:
				altera(pd);
				break;
			case 3:
				mostra(pd);
				break;
		}
	} while (op != 4);
}

void aloca(dados **p, int tam)
{
	if ((*p = (dados *)realloc(*p, tam * sizeof(dados))) == NULL)
		exit(1);
}

void cadastro(dados *p)
{
	int qtde;
	qtde = verifica(); // qtde de elementos dentro do arquivo

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

	grava(p, "ab", 1);
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

void altera(dados *p)
{
	int num_reg, pos;

	mostra(p);

	printf("\nQual registro a ser alterado: ");
	scanf("%i", &num_reg);
	fflush(stdin);

	pos = busca_registro(p, num_reg);

	if (pos == -1)
		printf("\nRegistro invalido\n\n");
	else
	{
		printf("\nRegistro: %i\nProduto: %s\nQtde: %i\nPreco: %.2f", p->reg, p->produto, p->qtde, p->preco);

		printf("\nNOVO preco: ");
		scanf("%f", &p->preco);
		fflush(stdin);

		grava(p, "rb+", pos);
	}
} // altera

int busca_registro(dados *p, int nreg)
{
	int qreg, i, pos = -1;
	FILE *fptr = NULL;
	qreg = verifica();

	if ((fptr = fopen("estoque.bin", "rb")) == NULL)
		return pos;
	else
	{
		for (i = 0; i < qreg; i++)
		{
			fseek(fptr, i * sizeof(dados), 0);
			fread(p, sizeof(dados), 1, fptr);

			if (p->reg == nreg)
			{
				pos = i;  // registro desejado
				i = qreg; // forca a saida do for
			} 
		}

		fclose(fptr); // por conta do ab
		return pos;
	}
}

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
	} 

	fclose(fptr); // fora do else por conta do ab e rb+
}

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
		} 
		
		fclose(fptr); // dentro do else - por conta do rb
	}
	system("pause");
}
