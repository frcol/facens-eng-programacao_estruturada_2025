#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Escreva um programa com uma função que receba um número de entrada e retorne 1 se o número lido for par e 0 se não for par. 
Na função main() mostre a mensagem apropriada para cada caso.
*/

int parOuImpar(int value);

int main() {
    system("cls");
    //========================================================
    
    int num;

    printf("Digite um numero: ");
    scanf("%i", &num);

    if (parOuImpar(num) == 1) {
        printf("O numero e PAR");
    }
    else {
        printf("O numero e IMPAR");
    }

    //========================================================
    printf("\n\n");
    return 0;
}

int parOuImpar(int value) {
    if (value%2 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}