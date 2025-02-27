#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ler 2 notas e calcular a média. 
Crie uma função que receberá como parâmetro de entrada as duas notas e retorna a média calculada.
*/

float media(float nota1, float nota2);

int main() {
    system("cls");
    //========================================================
    
    float nota1, nota2;

    printf("Nota 1: ");
    scanf("%f", &nota1);

    printf("Nota 2: ");
    scanf("%f", &nota2);

    printf("A media de %.1f e %.1f: %.1f", nota1, nota2, media(nota1, nota2));
    
    //========================================================
    printf("\n\n");
    return 0;
}

float media(float nota1, float nota2) {
    return (nota1+nota2)/2;
}