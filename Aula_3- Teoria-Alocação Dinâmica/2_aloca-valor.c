#include <stdio.h>
#include <stdlib.h>

int *aloca(int *p, int tam);

main()
{
  system("cls");

  int *ptr = NULL;

  printf("\nAlocacao por Valor\n");
  printf("\nMAIN - antes de alocar");
  printf("\nEndereco ptr:%u - Conteudo ptr: %u", &ptr, ptr);

  ptr = aloca(ptr, 1);
  
  printf("\n\nMAIN - depois de alocar\n");
  printf("Endereco ptr:%u - Conteudo ptr: %u\n\n", &ptr, ptr);
  system("pause");
} // main

int *aloca(int *p, int tam)
{
  printf("\n\nFUNCAO - antes de alocar");
  printf("\nEndereco p:%u - Conteudo p: %u", &p, p);

  p = (int *)realloc(p, tam * sizeof(int));

  if (p == NULL)
    exit(1);

  printf("\n\nFUNCAO - depois de alocar");
  printf("\nEndereco p:%u - Conteudo p: %u", &p, p);

  return p;
} 
