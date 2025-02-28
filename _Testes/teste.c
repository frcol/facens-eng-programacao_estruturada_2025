#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipo
int soma(int num1, int num2);

main() {
    system("cls");
    // ===============================================
    int resultado = soma(5, 3);

    printf("%i", resultado);

    // ===============================================
    printf("\n\n");
}

int soma(int num1, int num2) {
    int result = num1+num2;

    if (result > 10) {
        result = 1;
    } 
    else {
        result = 0;
    }

    return result;
}
