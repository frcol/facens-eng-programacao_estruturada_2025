#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostra_invertido(char *p);

int main()
{
  system("cls");
  
  char frase[80];

  printf("\nImprime a frase invertida\n");
  printf("\nDigite a frase: ");
  gets(frase);
  fflush(stdin);

  // frase - endereço do primeiro caractere
  // &frase - endereço do vetor de caracteres
  // *frase - valor do primeiro caractere

  mostra_invertido(frase);
} 

void mostra_invertido(char *p)
{
  // p - endereço do primeiro caractere
  // &p - endereço do ponteiro que aponta para o primeiro caractere
  // *p - valor do primeiro caractere

  int tam, i;
  tam = strlen(p); // qtde de letras na frase

  p = p + tam - 1; // posiciona o ponteiro na ultima letra
  for (i = 0; i < tam; i++, p--)
    printf("%c", *p);

  printf("\n\n");
  system("pause");
} 
