#include <stdio.h>
#include <stdlib.h>

typedef struct Animal
{
    char nome[20];
    int idade;
} Animal;

main()
{
    system("cls");

    Animal a1, a2;
    FILE *fptr = NULL;

    printf("\nDigite nome, idade : \n");
    scanf("%s	%i", a1.nome, &(a1.idade));
    fflush(stdin);

    // rotina gravar no arquivo
    fptr = fopen("animal.bin", "ab");
    if (fptr == NULL)
        printf("\nErro");
    else
        fwrite(&a1, sizeof(Animal), 1, fptr);

    fclose(fptr);

    // rotina leitura no arquivo
    fptr = fopen("animal.bin", "rb");
    if (fptr == NULL)
        printf("\nErro");
    else
    {
        //fseek(fptr, 1 * sizeof(Animal), 0);

        fread(&a2, sizeof(Animal), 1, fptr);
        fclose(fptr);
    }

    // mostra
    printf("\n## Animal Salvo ##");
    printf("\nNome= %s", a1.nome);
    printf("\nIdade= %i", a1.idade);

    printf("\n\n## Animal Lido ##");
    printf("\nNome= %s", a2.nome);
    printf("\nIdade= %i", a2.idade);

    printf("\n\n\n");
}
