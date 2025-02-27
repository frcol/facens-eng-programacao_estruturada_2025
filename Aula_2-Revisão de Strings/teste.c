#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int *a);

int main() {
    system("cls");
    
    int x = 27;
    int *p = &x;

    // printf("%d\n", x);
    // printf("%p\n", &x);

    // printf("%d\n", *p);
    // printf("%p\n", p);
    // printf("%p\n", &p);
    
    print(p);
    printf("%d\n", *p);

    printf("\n\n");
    return 0;
}

void print(int *a) {
    printf("%d\n", *a);

    *a = 10;
}