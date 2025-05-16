#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stand{
    int reg;
    char tam;
    char tipo;
    char status;
    float valor;
} Stand;

typedef struct cliente {
    char CPF[13];
    char nome[80];
    int numreg;
    int dias;
} Cliente;

// ======================== Functions =======================
void aloca_stand(Stand** stands, int n);
void aloca_cliente(Cliente** clientes, int n);

void cadastra_cliente(Cliente* c, Stand* v, int* total);
void cadastra_stand(Stand* v);  

int busca_stand(Stand* v, char tam, char tipo);

void mostra_cliente(Cliente* c, int total);
void mostra_stand(Stand* v) ;
// ======================================================

int main() {
    system("cls");

    Stand* stands = NULL;
    Cliente* clientes = NULL;

    aloca_stand(&stands, 6);
    cadastra_stand(stands);

    int totalClientes = 0;
    int opcao;

    do {
        system("cls");

        printf("\n[1] Locacao\n[2] Mostra Cliente\n[3] Fim\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                mostra_stand(stands);
                aloca_cliente(&clientes, totalClientes + 1);
                cadastra_cliente(clientes, stands, &totalClientes);
                system("pause");
                break;
            case 2:
                mostra_cliente(clientes, totalClientes);
                system("pause");
                break;
            case 3:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção invalida!\n");
        }
    } while (opcao != 3);

    return 0;
}


// ======================================================
 void aloca_stand(Stand** stands, int n) {
    *stands = (Stand*) realloc(NULL, n * sizeof(Stand));
    if (stands == NULL) {
        printf("Erro ao alocar memoria para os stands.\n");
        exit(1);
    }
}

void aloca_cliente(Cliente** cliente, int n) {
    *cliente = (Cliente*) realloc(NULL, n * sizeof(Cliente));
    if (*cliente == NULL) {
        printf("Erro ao alocar memoria para os clientes.\n");
        exit(1);
    }
}

void cadastra_stand(Stand* stands) {
    char tamanhos[] = {'P', 'P', 'M', 'M', 'G', 'G'};
    char tipos[]    = {'F', 'A', 'F', 'A', 'F', 'A'};
    float valores[] = {500, 300, 700, 400, 900, 600};

    for (int i = 0; i < 6; i++) {
        stands[i].reg = i + 1;
        stands[i].tam = tamanhos[i];
        stands[i].tipo = tipos[i];
        stands[i].status = 'L';
        stands[i].valor = valores[i];
    }
}

int busca_stand(Stand* stands, char tam, char tipo) {
    for (int i = 0; i < 6; i++) {
        if ((stands + i)->tam == tam && (stands + i)->tipo == tipo && (stands + i)->status == 'L') {
            return i;
        }
    }

    return -1;
}

void cadastra_cliente(Cliente* clientes, Stand* stands, int* total) {
    if (*total >= 6) {
        printf("Limite de clientes atingido.\n");
        return;
    }

    char tam, tipo;

    printf("\nCPF: ");
    scanf("%s", (clientes + *total)->CPF);
    fflush(stdin);

    printf("Nome: ");
    gets((clientes + *total)->nome);
    fflush(stdin);
  
    printf("Tamanho do stand [P/M/G]: ");
    scanf("%c", &tam);
    fflush(stdin);

    printf("Tipo do stand [F/A]: ");
    scanf("%c", &tipo);
    fflush(stdin);

    int idx = busca_stand(stands, tam, tipo);
    
    if (idx != -1) {
        (stands + idx)->status = 'E';
        (clientes + *total)->numreg = (stands + idx)->reg;
        
        printf("Dias de locacao: ");
        scanf("%d", &(clientes + *total)->dias);

        printf("Valor da diaria: R$ %.2f\n", (stands + idx)->valor);
        (*total)++;
    } else {
        printf("Nenhum stand disponivel para essa combinacao.\n");
    }
}

void mostra_stand(Stand* stands) {
    printf("\nReg \tTam \tTipo \tStatus\tValor\n");
    for (int i = 0; i < 6; i++) {
        printf("%d \t%c \t%c \t%c \t%.2f\n",
               stands[i].reg, stands[i].tam, stands[i].tipo, stands[i].status, stands[i].valor);
    }
}

void mostra_cliente(Cliente* clientes, int total) {
    printf("\nCPF \tNome \tNumreg \tDias\n");
    for (int i = 0; i < total; i++) {
        printf("%s \t%s \t%d \t%d\n", 
                clientes[i].CPF, clientes[i].nome, clientes[i].numreg, clientes[i].dias);
    }
}