#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aloca(float **p, int tam);
void leitura(float *p, int tam);
float media(float *p, int tam);
int maiores(float *p, int tam, float **pM, float m);
void mostrar(float *p, int tam);

int main() {
    system("cls");
    
    float *ptr = NULL, *pMaior = NULL;
    int cont = 0, qMaior;
    float m = 0;
    char opt;

    do {
        aloca(&ptr, cont+1);
        leitura(ptr, cont);
        cont++;

        printf("Continuar s/n?");
        scanf("%c", &opt);
        fflush(stdin);
    } while (opt != 'N' && opt != 'n');

    printf("Numeros digitados:\n");
    mostrar(ptr, cont);

    printf("\nMedia: ");
    m = media(ptr, cont);
    qMaior = maiores(ptr, cont, &pMaior, m);
    
    printf("\nNumeros acima da media:\n");
    mostrar(pMaior, qMaior);

    printf("\n\n");
    return 0;
}

// ==============================================
void aloca(float **p, int tam) {
    *p = (float *)realloc(*p, tam * sizeof(float));

    if (*p == NULL) exit(1);
}

void leitura(float *p, int tam) {
    printf("Numero: ");
    scanf("%f", p+tam);
    fflush(stdin);
}

float media(float *p, int tam){
    float m=0;

    for (int i=0; i<tam; i++, p++) {
        m += *p;
    }

    m /= tam;
    printf("%.2f", m);

    return m;
}

int maiores(float *p, int tam, float **pM, float m) {
    int qM = 0;

    for (int i = 0; i < tam; i++, p++) {
        if (*p > m) {
            aloca(pM, qM + 1);
            *(*pM + qM) = *p;
            qM++;
        }
    }

    return qM;
}

void mostrar(float *p, int tam) {
    for (int i = 0; i < tam; i++, p++) {
        printf("%.2f\n", *p);
    }
}