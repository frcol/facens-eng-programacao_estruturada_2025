#include <stdio.h>
#include <stdlib.h>

typedef struct dados
{
  char produto[20];
  int num;
  float preco;
} dados;
main()
{
  dados p1, p2;
  FILE *fptr = NULL;

  printf("\nDigite produto, registro e preco: \n");
  scanf("%s	%i	%f", p1.produto, &(p1.num), &(p1.preco));
  fflush(stdin);

  // rotina gravar no arquivo
  if ((fptr = fopen("struct.bin", "ab")) == NULL)
    printf("\nErro");
  else
    fwrite(&p1, sizeof(dados), 1, fptr);
  fclose(fptr); // fora do if = wb, ab,....

  // rotina leitura no arquivo
  if ((fptr = fopen("struct.bin", "rb")) == NULL)
    printf("\nErro");
  else
  {
    fread(&p2, sizeof(dados), 1, fptr);
    fclose(fptr); // dentro do else = rb
  }

  // mostra
  printf("\nProduto= %s\t%s", p1.produto, p2.produto);
  printf("\nRegistro= %i\t%i", p1.num, p2.num);
  printf("\nPreco= %.2f\t%.2f", p1.preco, p2.preco);
  system("pause");
} // main
