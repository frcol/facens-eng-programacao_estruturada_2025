#include <stdio.h>
#include <stdlib.h>

typedef struct dados
{
  int reg;
  char produto[20];
  int qtde;
  float preco;
} Dados;

void cadastro(Dados p);
void grava(Dados p);
void mostra(Dados p);
int verifica();

main()
{
  system("cls");

  Dados pd;
  char op;

  do
  {
    cadastro(pd);

    printf("\nDeseja continuar <S/N>:");
    scanf("%c", &op);
    fflush(stdin);
  } while (op != 'n' && op != 'N');

  mostra(pd);
}

int verifica()
{
  FILE *fptr = NULL;
  long int cont = 0;

  fptr = fopen("estoque.bin", "rb");
  if (fptr == NULL)
    return cont;
  else
  {
    fseek(fptr, 0, SEEK_END);           // posiciona no fim do arquivo, 
                                        // fseek(arquivo, deslocamento em bytes, origem);
                                        /*0 (ou SEEK_SET) = do início do arquivo
                                          1 (ou SEEK_CUR) = da posição atual
                                          2 (ou SEEK_END) = do fim do arquivo*/
    cont = ftell(fptr) / sizeof(Dados); // qtde de elementos
    fclose(fptr);                       // dentro do ELSE por conta do rb

    return cont;
  } 
}

void cadastro(Dados p)
{
  int qreg = verifica();
  p.reg = qreg + 1;

  printf("\nRegistro: %i", p.reg);
  printf("\nProduto: ");
  gets(p.produto);
  fflush(stdin);

  printf("Qtde estoque: ");
  scanf("%i", &(p.qtde));
  fflush(stdin);

  printf("Preco: ");
  scanf("%f", &(p.preco));
  fflush(stdin);

  grava(p);
}

void grava(Dados p)
{
  FILE *fptr = NULL;

  fptr = fopen("estoque.bin", "ab");
  if (fptr == NULL)
    printf("\nErro ao abrir o arquivo");
  else
    fwrite(&p, sizeof(Dados), 1, fptr);
    
  fclose(fptr); 
} 

void mostra(Dados p)
{
  FILE *fptr = NULL;
  Dados p;
  int i, qreg;
  qreg = verifica();
  
  system("cls");
  
  fptr = fopen("estoque.bin", "rb");
  if (fptr == NULL)
    printf("\nErro ao abrir o arquivo");
  else
  {
    for (i = 0; i < qreg; i++)
    {
      fseek(fptr, i * sizeof(Dados), SEEK_SET);
      fread(&p, sizeof(Dados), 1, fptr);
      printf("\nRegistro: %i\nProduto: %s\nQtde: %i\nPreco: %.2f\n\n", p.reg, p.produto, p.qtde, p.preco);
    } 

    fclose(fptr);
  } 

  system("pause");
} 

