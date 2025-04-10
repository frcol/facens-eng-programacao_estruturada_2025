#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente{
       char nome[30];
       int conta;
       float saldo;
       };

void cadastro(struct cliente *p);
int  busca(struct cliente *p,int tam);
void movimento(struct cliente *p,int op);

main()
{
struct cliente cli[10],*c;
int op,cont=0,achou;
c=cli;
do{
   system("cls");
   printf("[1]Cadastro\n[2]Deposito\n[3]Retirada\n[4]Fim\nOpcao: ");
   scanf("%i",&op);
   fflush(stdin);
   switch(op){
      case 1: if(cont<10)
               {
               cadastro(c+cont);
               cont++;
               }
              else
               printf("\nCadastro Lotado\n");
              break;
      case 2:
      case 3: achou=busca(c,cont); 
              if(achou==-1)
                printf("\nConta invalida\n");
              else
                movimento(c+achou,op);
              break;
              }//switch
      }while(op!=4);
}//main
           
void cadastro(struct cliente *p)
{
static int n_conta=1000;
printf("\nNome: ");
gets((*p).nome);
fflush(stdin);
(*p).conta=n_conta;
(*p).saldo=0;
n_conta++;
printf("\nConta: %i\n",(*p).conta);
system("pause");
}//cadastro

int  busca(struct cliente *p,int tam)
{
int i,num_conta;
printf("\nConta: ");
scanf("%i",&num_conta);
fflush(stdin);
for(i=0;i<tam;i++)					//for(i=0;i<tam;i++,p++)
  if((*(p+i)).conta==num_conta)		//  if((*p).conta==num_conta)
    return i;
return -1;     
}//busca

void movimento(struct cliente *p,int op)
{
float valor;
printf("\nNome: %s\nSaldo: %.2f",(*p).nome,(*p).saldo);
printf("\nValor a ser depositado/retirado: ");
scanf("%f",&valor);
fflush(stdin);
if(op==2)
  (*p).saldo+=valor;
else
  {
  if(valor<=(*p).saldo)
    (*p).saldo-=valor;
  else
    printf("\nSaldo insuficiente\n");
  }
printf("\nSaldo Atualizado: %.2f\n\n",(*p).saldo);      
system("pause");
}//movimento       
       
           
   
   
   
   
   














             
