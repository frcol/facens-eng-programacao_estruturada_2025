#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct quarto
{
	int num;
	char categoria;	// S-Simples ou F-Familiar
	char status; // L-ivre ou O-cupado
} quarto;

typedef struct hospede
{
	int quarto;
	char nome[80];
	int acompanhante; // numero de acompanhantes, max. 3
	char categoria;	 // S-Simples ou F-Familiar
	int dias;
} hospede;

void aloca_quarto(quarto **q, int qq);
int verifica_quarto();						//	verifica a quantidade de quartos
void cadastro_quarto(quarto *q, int qq);	// cadastra os quartos. 5 quartos simples e 10 quartos familiares
void grava_quarto(quarto *q);				// adicion ou altera o registro de quarto no arquivo (ab ou rb+)
int busca_quarto(quarto *q, int qq, char cat);	// procura um quarto livre de acordo com a categoria e retorna o numero do quarto
void atualiza_quarto(quarto *q, int n_quarto);	// atualiza o status do quarto para livre
void mostra_quarto(quarto *q);
void check_out(hospede *h, quarto *q);			// finaliza o hospede, libera o quarto e calcula o valor a ser pago

void aloca_hospede(hospede **h, int qh);
int verifica_hospede();				// verifica a quantidade de hospedes	
void cadastro_hospede(hospede *h, quarto *q, int qq);	// cadastra o hospede, procura um quarto livre e grava o hospede no arquivo	
void grava_hospede(hospede *h, char *aux, int pos);	// adiciona ou altera o registro de hospede no arquivo (ab ou rb+)
int busca_hospede(hospede *h, int n_quarto);	// procura o hospede no quarto informado e tras a posicao do hospede
												// h tras o hospede econtrado e altera o quarto do hospede para -1 (vago)	
int busca_vago(hospede *h, int qh);			// procura por um hospede vago para cadastrar um novo hospede
void mostra_hospede(hospede *h);

main()
{
	quarto *pq = NULL;
	hospede *ph = NULL;
	int op, pos, qquarto;

	aloca_quarto(&pq, 1);
	qquarto = verifica_quarto();

	if (qquarto == 0)
		cadastro_quarto(pq, 15);	// cadastra os quartos. 5 quartos simples e 10 quartos familiares

	aloca_hospede(&ph, 1);

	do
	{
		system("cls");
		printf("\n[1]Check-in\n[2]Check-out\n[3]Mostra Quarto\n[4]Mostra Hospede\n[5]Fim\nOpcao: ");
		scanf("%i", &op);
		fflush(stdin);

		switch (op)
		{
			case 1:
				cadastro_hospede(ph, pq, 15);
				break;
			case 2:
				check_out(ph, pq);
				break;
			case 3:
				mostra_quarto(pq);
				break;
			case 4:
				mostra_hospede(ph);
				break;
			}
	} while (op != 5);
}

void aloca_quarto(quarto **q, int qq)
{
	if ((*q = (quarto *)realloc(*q, qq * sizeof(quarto))) == NULL)
		exit(1);
}

void aloca_hospede(hospede **h, int qh)
{
	if ((*h = (hospede *)realloc(*h, qh * sizeof(hospede))) == NULL)
		exit(1);
}

int verifica_quarto()
{
	FILE *fq = NULL;
	int qtde = 0;

	if ((fq = fopen("quartos.bin", "rb")) == NULL)
		return qtde;
	else
	{
		fseek(fq, 0, SEEK_END); // posiciona fq no final
		qtde = ftell(fq) / sizeof(quarto);

		fclose(fq);
		return qtde;
	}
}

int verifica_hospede()
{
	FILE *fh = NULL;
	int qtde = 0;

	if ((fh = fopen("hospedes.bin", "rb")) == NULL)
		return qtde;
	else
	{
		fseek(fh, 0, SEEK_END); // posiciona fh no final
		qtde = ftell(fh) / sizeof(hospede);

		fclose(fh);
		return qtde;
	}
}

void cadastro_quarto(quarto *q, int qq)
{
	int i;

	for (i = 0; i < qq; i++)
	{
		q->num = i + 1;
		q->status = 'L';

		if (i < 5)
			q->categoria = 'S';
		else
			q->categoria = 'F';

		grava_quarto(q);
	}
}

void cadastro_hospede(hospede *h, quarto *q, int qq)
{
	int qhosp, pos;

	qhosp = verifica_hospede(); 	// qtde de hospedes
	pos = busca_vago(h, qhosp);		// procura por um hospede vago

	printf("\nNome: ");
	gets(h->nome);
	fflush(stdin);

	do
	{
		printf("Qtde de acompanhantes - max.3: ");
		scanf("%i", &h->acompanhante);
		fflush(stdin);
	} while (h->acompanhante < 0 || h->acompanhante > 3);

	if (h->acompanhante == 0)
		h->categoria = 'S';
	else
		h->categoria = 'F';

	printf("Dias: ");
	scanf("%i", &h->dias);
	fflush(stdin);

	h->quarto = busca_quarto(q, qq, h->categoria);

	if (h->quarto == -1)
		printf("\nNao ha quartos com a categoria desejada\n\n");
	else
	{
		printf("\nCadastro com sucesso - quarto = %i\n\n", h->quarto);
		if (pos == -1)				   // nao ha hospede vago
			grava_hospede(h, "ab", 1); // adiciona registro no fim
		else
			grava_hospede(h, "rb+", pos); // sobreescrever no lugar do vago
	}
	
	printf("\n\n\n");
	system("pause");
}

void grava_quarto(quarto *q)
{
	FILE *fq = NULL;

	if ((fq = fopen("quartos.bin", "ab")) == NULL)
		printf("\nErro\n\n");
	else
		fwrite(q, sizeof(quarto), 1, fq);

	fclose(fq);
}

void grava_hospede(hospede *h, char *aux, int pos)
{
	FILE *fh = NULL;

	if ((fh = fopen("hospedes.bin", aux)) == NULL)
		printf("\nArquivo inexistente\n");
	else
	{
		if (strcmp(aux, "rb+") == 0)
			fseek(fh, pos * sizeof(hospede), 0);

		fwrite(h, sizeof(hospede), 1, fh);
	} 

	fclose(fh); // fora do ELSE por conta do ab ou rb+
} 

void atualiza_quarto(quarto *q, int n_quarto)
{
	FILE *fq = NULL;
	int qq, i;
	qq = verifica_quarto();

	if ((fq = fopen("quartos.bin", "rb+")) == NULL)
		printf("\nErro\n\n");
	else
	{
		for (i = 0; i < qq; i++)
		{
			fseek(fq, i * sizeof(quarto), 0);
			fread(q, sizeof(quarto), 1, fq);

			if (q->num == n_quarto)
			{
				q->status = 'L';
				fseek(fq, i * sizeof(quarto), 0); // volta para a posicao lida
				fwrite(q, sizeof(quarto), 1, fq);

				break; // forca a saida
			}
		}
	}

	fclose(fq);
}

int busca_quarto(quarto *q, int qq, char cat)
{
	int pos = -1, i;
	FILE *fq = NULL;

	if ((fq = fopen("quartos.bin", "rb+")) == NULL)
		printf("\nErro\n\n");
	else
	{
		for (i = 0; i < qq; i++)
		{
			fseek(fq, i * sizeof(quarto), SEEK_SET);
			fread(q, sizeof(quarto), 1, fq);

			if (q->categoria == cat && q->status == 'L')
			{
				q->status = 'O';
				fseek(fq, i * sizeof(quarto), 0);
				fwrite(q, sizeof(quarto), 1, fq);
				
				pos = q->num; // numero do quarto
				break; // forca a saida do for
			}
		} 
	}

	fclose(fq);

	return pos;
}

int busca_hospede(hospede *h, int n_quarto)
{
	int pos = -1, i, qh;
	FILE *fh = NULL;
	qh = verifica_hospede();

	if ((fh = fopen("hospedes.bin", "rb+")) == NULL)
		printf("\nErro\n\n");
	else
	{
		for (i = 0; i < qh; i++)
		{
			fseek(fh, i * sizeof(hospede), 0);
			fread(h, sizeof(hospede), 1, fh);

			if (h->quarto == n_quarto)
			{
				h->quarto = -1;

				fseek(fh, i * sizeof(hospede), SEEK_SET); // volta para a posicao lida
				fwrite(h, sizeof(hospede), 1, fh);

				pos = i; // posicao do hospede
				break;	 // forca a saida
			}
		}
	}
	
	fclose(fh);
	
	return pos;
}

int busca_vago(hospede *h, int qh)
{
	FILE *fh = NULL;
	int i;

	if ((fh = fopen("hospedes.bin", "rb")) == NULL)
		return -1;
	else
	{
		for (i = 0; i < qh; i++)
		{
			fseek(fh, i * sizeof(hospede), 0);
			fread(h, sizeof(hospede), 1, fh);

			if (h->quarto == -1)
			{
				fclose(fh);
				return i;
			}
		}

		fclose(fh);
	} 
	
	return -1;
}

void check_out(hospede *h, quarto *q)
{
	int n_quarto, achou;
	float valor;

	printf("\nQuarto a ser finalizado: ");
	scanf("%i", &n_quarto);
	fflush(stdin);

	achou = busca_hospede(h, n_quarto);  // procura o hospede no quarto informado e tras a posicao do hospede
										 // h tras o hospede econtrado e altera o quarto do hospede para -1 (vago)
	if (achou == -1)
		printf("\nQuarto invalido\n\n");
	else
	{
		if (h->categoria == 'S')
			valor = h->dias * 85;
		else
			valor = h->dias * ((h->acompanhante) + 1) * 65;

		printf("\nNome: %s\nAcompanhantes: %i\nCategoria: %c\nDias: %i\nValor a ser pago: %.2f\n\n", h->nome, h->acompanhante, h->categoria, h->dias, valor);

		atualiza_quarto(q, n_quarto);	// atualiza o status do quarto para livre
	}

	system("pause");
}

void mostra_quarto(quarto *q)
{
	int i, qq;
	FILE *fq = NULL;
	qq = verifica_quarto();

	if ((fq = fopen("quartos.bin", "rb")) == NULL)
		printf("\nArquivo Inexistente\n\n");
	else
	{
		for (i = 0; i < qq; i++)
		{
			fseek(fq, i * sizeof(quarto), 0);
			fread(q, sizeof(quarto), 1, fq);

			printf("\nQuarto: %i\nCategoria: %c\nStatus: %c\n", q->num, q->categoria, q->status);
		}
		
		fclose(fq); // dentro do else por conta do rb
	}
	
	system("pause");
} 

void mostra_hospede(hospede *h)
{
	int i, qh;
	FILE *fh = NULL;
	qh = verifica_hospede();

	if ((fh = fopen("hospedes.bin", "rb")) == NULL)
		printf("\nErro\n\n");
	else
	{
		for (i = 0; i < qh; i++)
		{
			fseek(fh, i * sizeof(hospede), 0);
			fread(h, sizeof(hospede), 1, fh);

			printf("\nQuarto: %i\nNome: %s\nAcompanhantes: %i\nCategoria: %c\nDias: %i\n\n", h->quarto, h->nome, h->acompanhante, h->categoria, h->dias);
		}

		fclose(fh); // dentro do else por conta do rb
	}

	system("pause");
}
