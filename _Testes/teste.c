#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float converter(float valorFahrenheit);

main() {
    system("cls");
    // ===============================================
    
    float far;

    printf("Digite um calor em Fahrenheit: ");
    scanf("%f", &far);

    float celcius = converter(far);

    printf("%.2f em Celsius: %.2f", far, celcius);


    // ===============================================
    printf("\n\n");
}

float converter(float valorFahrenheit) {
    return (valorFahrenheit-32)/1.8;
}