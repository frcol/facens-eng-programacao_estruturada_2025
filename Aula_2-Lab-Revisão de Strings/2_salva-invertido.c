#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverte(char *pf, char *pi);

int main()
{
  system("cls");

  char frase[80], inv[80];

  printf("\nInverte a frase\n");
  printf("\nDigite a frase: ");
  gets(frase);
  fflush(stdin);

  inverte(frase, inv);

  printf("\nA frase invertida:\n%s", inv);
} 

void inverte(char *pf, char *pi)
{
  int tam, i;
  tam = strlen(pf);  // qtde de letras
  
  pf = pf + tam - 1; // posiciona ponteiro na ultima letra
  for (i = 0; i < tam; i++, pi++, pf--)
  {
    *pi = *pf;
    //printf("%p: %c\n", pi, *pi);
  }
  
  *pi = '\0';
  //printf("%p: %c", pi, *pi);
} 
