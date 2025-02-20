#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    int var = 10;
    int *ptr;
    ptr = &var; // inicialização de um ponteiro

    printf("Mostra o conteúdo de var");
    printf("\n Acesso direto var = % i", var);
    printf("\n Acesso indireto var = % i", *ptr);
    printf("\n\n\n Mostra o endereco de var");
    printf("\n Ponteiro constante = % i", &var);    //ou % u
    printf("\n Ponteiro variavel = % i", ptr);

    return 0;
}