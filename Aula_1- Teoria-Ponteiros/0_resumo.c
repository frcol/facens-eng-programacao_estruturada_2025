#include <stdio.h>

main()
{
    system("cls");

    int var = 10;
    int *ptr;

    ptr = &var; // inicialização de um ponteiro
    
    printf("Mostra o conteudo de var");
    printf("\n Acesso direto - var = %i", var);
    printf("\n Acesso indireto var = %i", *ptr);
    
    printf("\n\n\n Mostra o endereco de var");
    printf("\n Ponteiro constante = %p", &var);
    printf("\n Ponteiro variavel = %p", ptr);
}
