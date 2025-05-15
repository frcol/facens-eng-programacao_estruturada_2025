#include <stdio.h>
#include <stdlib.h>

typedef struct dados{
        int    reg;
        char   produto[20];
        int    qtde;
        float  preco;
   	} dados ;

void aloca(dados **p,int tam);
void cadastro(dados *p);
int  verifica();
void grava(dados *p);
void mostra(dados *p);

main()
{
dados   *pd=NULL;
int op;

aloca(&pd,1);
do{
	system("cls");
	printf("\n[1]Cadastro\n[2]Mostra\n[3]Fim\nOpcao: ");
	scanf("%i",&op);
	fflush(stdin);
	switch(op)
	   {
	   	case 1: cadastro(pd);
	   	        break;
	   	case 2: mostra(pd);
	   			break;
	   }//switch
  }while(op!=3);
}//main

void aloca(dados **p,int tam)
{
if((*p=(dados*)realloc(*p,tam*sizeof(dados)))==NULL)
  exit(1);
}//aloca

void cadastro(dados *p)
{
int qtde;
qtde=verifica();   //qtde de elementos dentro do arquivo
p->reg=qtde+1;    //proximo registro
printf("\nRegistro: %i",p->reg);
printf("\nProduto: ");
gets(p->produto);
fflush(stdin);
printf("\nQuantidade: ");
scanf("%i",&(p->qtde));
fflush(stdin);
printf("\nPreco: ");
scanf("%f",&(p->preco));
fflush(stdin);
grava(p);
printf("\nRegistro cadastrado com sucesso\n\n");
system("pause");
}//cadastro

int  verifica()
{
FILE *fptr=NULL;
long int cont=0;

if((fptr=fopen("estoque.bin","rb"))==NULL)
  return cont;
else
  {
  	fseek(fptr,0,2);   //posiciona fptr no fim do arquivo
  	cont=ftell(fptr)/sizeof(dados);
  	fclose(fptr);     //dentro do else por conta do rb
  	return cont;
  }//else
}//verifica

void grava(dados *p)
{
FILE *fptr=NULL;

if((fptr=fopen("estoque.bin","ab"))==NULL)
  printf("\nErro\n\n");
else
  {
  	fwrite(p,sizeof(dados),1,fptr);
  }//else
fclose(fptr);   //fora do else por conta do ab
}//grava

void mostra(dados *p)
{
FILE *fptr=NULL;
int qtde,i;
qtde=verifica();  //qtde de elementos do arquivo

if((fptr=fopen("estoque.bin","rb"))==NULL)
  printf("\nErro\n\n");
else
  {
   for(i=0;i<qtde;i++)
     {
     	fseek(fptr,i*sizeof(dados),0);   //a partir do inicio
     	fread(p,sizeof(dados),1,fptr);
     	printf("\nRegistro: %i\nProduto: %s\nQuantidade: %i\nPreco: %.2f\n\n",p->reg,p->produto,p->qtde,p->preco);
    }//for
   fclose(fptr);   //dentro do else - por conta do rb
  }//else
system("pause");
}//mostra

