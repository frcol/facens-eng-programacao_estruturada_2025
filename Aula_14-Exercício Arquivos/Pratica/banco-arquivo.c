#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente{
       char nome[30];
       int conta;
       float saldo;
}cliente;

void aloca(cliente **p,int tam);
int  verifica();   
void cadastro(cliente *p);
void grava(cliente *p,char *str,int pos);
int busca(cliente *p,int n_conta);
void movimento(cliente *p,int op);
void mostra(cliente *p);

main()
{
	cliente *pcli=NULL;
	int op;
	aloca(&pcli,1);
	do
	{
	   system("cls");
	   printf("\n[1]Cadastro\n[2]Deposito\n[3]Retirada\n[4]Mostra Clientes\n[5]Fim\nOpcao: ");
	   scanf("%i",&op);
	   fflush(stdin);
	   switch(op)
	   {
	     case 1: cadastro(pcli);
	             break;
	     case 2:
	     case 3: movimento(pcli,op);
	        	 break;
	     case 4: mostra(pcli);
	     		 break;
	    }//switch               
	}while(op!=5);
}//main     
          
void aloca(cliente **p, int tam)
{
	if((*p=(cliente*)realloc(*p,tam*sizeof(cliente)))==NULL)
	  exit(1);
}//aloca

int  verifica()
{
FILE *fptr=NULL;
int qtde=0;
if((fptr=fopen("cliente.bin","rb"))==NULL)
  return qtde;
else
  {
  fseek(fptr,0,2);  //posiciona no fim do arquivo
  qtde=ftell(fptr)/sizeof(cliente);   //qtde de elementos
  fclose(fptr);    //dentro do ELSE por conta do rb
  return qtde;
  }//else
}//verifica

void cadastro(cliente *p)
{
static int n_conta=1000;
	
printf("\nNome: ");
gets(p->nome);
fflush(stdin);
p->conta=n_conta++;
p->saldo=0;
printf("\nConta cadastrada com sucesso - numero: %i\n\n",p->conta);
grava(p,"ab",1);
system("pause");
}//cadastro

void grava(cliente *p,char *str,int pos)
{
FILE *fptr=NULL;

if((fptr=fopen("cliente.bin",str))==NULL)
  printf("\nErro\n\n");
else
  {
  	if(strcmp(str,"rb+")==0)
  	  fseek(fptr,pos*sizeof(cliente),0);
  	fwrite(p,sizeof(cliente),1,fptr);
  }//else
fclose(fptr);   //fora do else por conta do ab e rb+
}//grava

int  busca(struct cliente *p,int n_conta)
{
int qtde,i,pos=-1;
FILE *fptr=NULL;
qtde=verifica();
if((fptr=fopen("cliente.bin","rb"))==NULL)
  return pos;
else
  {
  	for(i=0;i<qtde;i++)
  	  {
  	  	fseek(fptr,i*sizeof(cliente),0);
  	  	fread(p,sizeof(cliente),1,fptr);
  	  	if(p->conta==n_conta)
  	  	  {
  	  	  	pos=i;   //registro desejado
  	  	  	i=qtde;  //forca a saida do for
		  }//if
		}//for
  	fclose(fptr);  //por conta do ab
  	return pos;
  }//else  
}//busca

void movimento(struct cliente *p,int op)
{
int num_conta,pos;
float valor;
printf("\nConta: ");
scanf("%i",&num_conta);
fflush(stdin);
pos=busca(p,num_conta);
if(pos==-1)
   	printf("\nConta Inexistente\n\n\n");
else 
  {
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
  	  }//else
	printf("\nSaldo Atualizado: %.2f\n\n",p->saldo);  
	grava(p,"rb+",pos);
}//else    
system("pause");
}//movimento    

void mostra(cliente *p)
{
FILE *fptr=NULL;
int i,qtde;
qtde=verifica();
system("cls");
if((fptr=fopen("cliente.bin","rb"))==NULL)
  printf("\nErro ao abrir o arquivo");
else
  {
  for(i=0;i<qtde;i++)
    {
	fseek(fptr,i*sizeof(cliente),0);
	fread(p,sizeof(cliente),1,fptr);
	printf("\nNome: %s\nConta: %i\nSaldo: %.2f\n\n",p->nome,p->conta,p->saldo);
    }//for
  fclose(fptr);
  }//else
system("pause");
}//mostra


