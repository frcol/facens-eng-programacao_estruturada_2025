#include <stdio.h>
#include <stdlib.h>

typedef struct dados
{
  char produto[20];
  int num;
  float preco;
} Dados;

main()
{
  system("cls");

  Dados p1, p2;
  FILE *fptr = NULL;

  printf("\nDigite produto, registro e preco: \n");
  scanf("%s	%i	%f", p1.produto, &p1.num, &p1.preco);
  fflush(stdin);

  // rotina gravar no arquivo
  fptr = fopen("struct.bin", "wb");
  if (fptr == NULL)
    printf("\nErro");
  else
  {
    fwrite(&p1, sizeof(Dados), 1, fptr);
    fclose(fptr);
  }
    

  // rotina leitura no arquivo
  fptr = fopen("struct.bin", "rb");
  if (fptr == NULL)
    printf("\nErro");
  else
  {
    fread(&p2, sizeof(Dados), 1, fptr);
    fclose(fptr);
  }

  // mostra
  printf("\nProduto= %s\t%s", p1.produto, p2.produto);
  printf("\nRegistro= %i\t%i", p1.num, p2.num);
  printf("\nPreco= %.2f\t%.2f", p1.preco, p2.preco);
} 
