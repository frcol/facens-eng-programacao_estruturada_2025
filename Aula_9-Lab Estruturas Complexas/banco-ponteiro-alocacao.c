#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente{
       char nome[30];
       int conta;
       float saldo;
}cliente;

void aloca(cliente **p,int tam);
void cadastro(cliente *p);
int busca(cliente *p,int tam);
void movimento(cliente *p,int op);
void mostra(cliente *p,int tam);

main()
{
	cliente *c=NULL;
	int op,cont=0,achou;
	do
	{
	   system("cls");
	   printf("\n[1]Cadastro\n[2]Deposito\n[3]Retirada\n[4]Mostra Clientes\n[5]Fim\nOpcao: ");
	   scanf("%i",&op);
	   fflush(stdin);
	   switch(op)
	   {
	     case 1: aloca(&c,cont+1);
	             cadastro(c+cont);
	             cont++;
	             break;
	     case 2:
	     case 3: achou=busca(c,cont);
	             if(achou==-1)
	             {
	             	printf("\nConta Inexistente\n\n\n");
	               	system("pause");
	             }
	             else 
				   movimento(c+achou,op);
	        	 break;
	     case 4: mostra(c,cont);
	     		 break;
	    }//switch               
	}while(op!=5);
}//main     
          
void aloca(cliente **p, int tam)
{
	if((*p=(cliente*)realloc(*p,tam*sizeof(cliente)))==NULL)
	  exit(1);
}//aloca

void cadastro(cliente *p)
{
static int n_conta=1000;
	
printf("\nNome: ");
gets(p->nome);
fflush(stdin);
p->conta=n_conta++;
p->saldo=0;
printf("\nConta cadastrada com sucesso - numero: %i\n\n",p->conta);
system("pause");
}//cadastro

int  busca(struct cliente *p,int tam)
{
int i,num_conta;
printf("\nConta: ");
scanf("%i",&num_conta);
fflush(stdin);
for(i=0;i<tam;i++)  					 //for(i=0;i<tam;i++,p++)
  if((p+i)->conta==num_conta)			 //  if(p->conta==num_conta)
    return i;
return -1;     
}//busca

void movimento(struct cliente *p,int op)
{
float valor;
printf("\nNome: %s\nSaldo: %.2f",p->nome,p->saldo);
printf("\nValor a ser depositado/retirado: ");
scanf("%f",&valor);
fflush(stdin);
if(op==2)
  p->saldo+=valor;
else
  {
  if(valor<=p->saldo)
    p->saldo-=valor;
  else
    printf("\nSaldo insuficiente\n");
  }
printf("\nSaldo Atualizado: %.2f\n\n",p->saldo);      
system("pause");
}//movimento    

void mostra(cliente *p,int tam)
{
int i;
for(i=0;i<tam;i++,p++)
  printf("\nNome: %s\nConta: %i\nSaldo: %.2f\n",p->nome,p->conta,p->saldo);
system("pause");
}//mostra


