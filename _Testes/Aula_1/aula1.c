#include <stdio.h>
#include <stdlib.h>

int main() {
    int num = 27;
    printf("%d\n", num);
    printf("%p\n", &num);

    printf("\nLista\n");
    int lista[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%p\n", lista);      // tem o endereço do primeiro elemento
    printf("%p\n", &lista[0]);
    printf("%p\n", &lista[1]);

    printf("\nPonteiro\n");
    int *p = &num;
    printf("Conteudo de p (endereco de x): %p\n", p);
    printf("valor do endereco do coteudo de p: %d\n", *p);
    printf("endereco de p: %p\n", &p);
    
    return 0;
}