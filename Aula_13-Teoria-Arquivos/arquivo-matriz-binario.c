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
  fptr = fopen("matriz.bin", "wb");
  if (fptr == NULL)
    printf("\nErro");
  else
  {
    fwrite(mat, sizeof(int), 10, fptr);
    fclose(fptr); 
  }

  // rotina leitura no arquivo
  fptr = fopen("matriz.bin", "rb");
  if (fptr == NULL)
    printf("\nErro");
  else
  {
    fread(arq, sizeof(int), 10, fptr);
    fclose(fptr);
  }

  // mostra
  for (i = 0; i < 10; i++)
    printf("\nmat[%i]= %i\tarq[%i]= %i", i, *(mat + i), i, *(arq + i));

  printf("\n\n\n");

  system("pause");
} 
