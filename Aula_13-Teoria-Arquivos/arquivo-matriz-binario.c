#include <stdio.h>
#include <stdlib.h>

main()
{
  system("cls");
  
  int mat[10], arq[10], i;
  FILE *fptr = NULL;

  for (i = 0; i < 10; i++)
  {
    printf("\nmat[%i]= ", i);
    scanf("%i", mat + i);
    fflush(stdin);
  }

  // rotina gravar no arquivo
  if ((fptr = fopen("matriz.bin", "ab")) == NULL)
    printf("\nErro");
  else
    fwrite(mat, sizeof(int), 10, fptr);

  fclose(fptr); // fora do else = wb, ab, rb+

  // rotina leitura no arquivo
  if ((fptr = fopen("matriz.bin", "rb")) == NULL)
    printf("\nErro");
  else
  {
    fread(arq, sizeof(int), 10, fptr);
    fclose(fptr); // dentro do else = rb
  }

  // mostra
  for (i = 0; i < 10; i++)
    printf("\nmat[%i]= %i\tarq[%i]= %i", i, *(mat + i), i, *(arq + i));

  printf("\n\n\n");

  system("pause");
} // main
