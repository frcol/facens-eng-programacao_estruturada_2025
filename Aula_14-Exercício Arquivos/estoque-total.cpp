#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dados{
        int    reg;
        char   produto[20];
        int    qtde;
        float  preco;
   	} dados ;

void aloca(dados **p,int tam);
void cadastro(dados *p);
int  verifica();
void altera(dados *p,int op);
int  busca_produto(dados *p,int aux_reg);
int  busca_vago(dados *p);
void grava(dados *p,char *str,int pos);
void mostra(dados *p);

main()
{
dados   *pd=NULL;
int op;

aloca(&pd,1);
do{
	system("cls");
	printf("\n[1]Cadastro\n[2]Mostra\n[3]Altera\n[4]Deleta\n[5]Fim\nOpcao: ");
	scanf("%i",&op);
	fflush(stdin);
	switch(op)
	   {
	   	case 1: cadastro(pd);
	   	        break;
	   	case 2: mostra(pd);
	   			break;
	   	case 3: 
	   	case 4: altera(pd,op);
	   			break;
	   }//switch
  }while(op!=5);
}//main

void aloca(dados **p,int tam)
{
if((*p=(dados*)realloc(*p,tam*sizeof(dados)))==NULL)
  exit(1);
}//aloca

void cadastro(dados *p)
{
int qtde,achou;
qtde=verifica();   //qtde de elementos dentro do arquivo
achou=busca_vago(p);
if(achou==-1)  //nao ha registro vago
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
if(achou==-1) //nao ha registro vago
  grava(p,"ab",-1);
else
  grava(p,"rb+",achou);
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

void altera(dados *p,int op)
{
int aux_reg,pos;
printf("\nRegistro a ser alterado/deletado: ");
scanf("%i",&aux_reg);
fflush(stdin);
pos=busca_produto(p,aux_reg);
if(pos==-1)  //nao encontrou  
  printf("\nRegistro invalido\n\n");
else
  {
  	printf("\nProduto: %s\nQtde: %i\nPreco: %.2f\n\n",p->produto,p->qtde,p->preco);
  	if(op==3)  //altera
  	  {
  	 	printf("\nNOVO preco: ");
  		scanf("%f",&p->preco);
  		fflush(stdin);
	   }//if
	else   //deleta
	  p->qtde=-1;
	grava(p,"rb+",pos);
  	printf("\nRegistro alterado/deletado com sucesso\n\n");
  }//else
system("pause");
}//altera

int  busca_produto(dados *p,int aux_reg)
{
FILE *fptr=NULL;
int qtde,i,achou=-1;
qtde=verifica();   //retorna qtde de registros
if((fptr=fopen("estoque.bin","rb"))==NULL)
  printf("\nErro\n\n");   //nao existe o arquivo
else
  {
  	for(i=0;i<qtde;i++)
  	  {
  	  	fseek(fptr,i*sizeof(dados),0);
  	  	fread(p,sizeof(dados),1,fptr);
  	  	if(p->reg==aux_reg)
  	  	  {
  	  	  	achou=i;  //posicao do registro buscado
  	  	  	i=qtde;   //forca a saida do for
		  }//if
		}//for
	fclose(fptr);   //dentro do else - rb
  }//else
return achou; 
}//busca_produto

int  busca_vago(dados *p)
{
FILE *fptr=NULL;
int qtde,achou=-1,i;
qtde=verifica();   //qtos elementos no arquivo	
if((fptr=fopen("estoque.bin","rb"))==NULL)
  printf("\nErro\n\n");
else
  {
  	for(i=0;i<qtde;i++)
  	  {
  	  	fseek(fptr,i*sizeof(dados),0);
  	  	fread(p,sizeof(dados),1,fptr);
  	  	if(p->qtde==-1)
  	  	  {
  	  	  	achou=i;
  	  	  	i=qtde;   //forca a saida do for
		  }//if
		}//for
	fclose(fptr); //dentro do else - rb	
  }//else
return achou;
}//busca_vago

void grava(dados *p,char *str,int pos)
{
FILE *fptr=NULL;

if((fptr=fopen("estoque.bin",str))==NULL)
  printf("\nErro\n\n");
else
  {
  	if(strcmp(str,"rb+")==0)
  		fseek(fptr,pos*sizeof(dados),0);
	fwrite(p,sizeof(dados),1,fptr);
  }//else
fclose(fptr);   //fora do else por conta do ab , rb+
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

