#include <stdio.h>
#include <stdlib.h>

typedef struct dados{
        int    reg;
        char   produto[20];
        int    qtde;
        float  preco;
        }dados;

void aloca(dados **p,int tam);  
int  verifica();  
void cadastro(dados *p);    
void grava(dados *p);
void mostra(dados *p);

main()
{
dados *pd=NULL;
char op;
aloca(&pd,1);
do{
  cadastro(pd);
  printf("\nDeseja continuar <S/N>:");
  scanf("%c",&op);
  fflush(stdin);
  }while(op!='n' && op!='N');
mostra(pd);
}//main

void aloca(dados **p,int tam)
{
if((*p=(dados*)realloc(*p,tam*sizeof(dados)))==NULL)
  exit(1);
}//aloca

int  verifica()
{
FILE *fptr=NULL;
long int cont=0;
if((fptr=fopen("estoque.bin","rb"))==NULL)
  return cont;
else
  {
  fseek(fptr,0,2);  //posiciona no fim do arquivo
  cont=ftell(fptr)/sizeof(dados);   //qtde de elementos
  fclose(fptr);    //dentro do ELSE por conta do rb
  return cont;
  }//else
}//verifica

void cadastro(dados *p)
{
int qreg;
qreg=verifica();
p->reg=qreg+1;
printf("\nRegistro: %i",p->reg);
printf("\nProduto: ");
gets(p->produto);
fflush(stdin);
printf("Qtde estoque: ");
scanf("%i",&(p->qtde));
fflush(stdin);
printf("Preco: ");
scanf("%f",&(p->preco));
fflush(stdin);
grava(p);
}//cadastro

void grava(dados *p)
{
FILE *fptr=NULL;
if((fptr=fopen("estoque.bin","ab"))==NULL)	
  printf("\nErro ao abrir o arquivo");
else
  fwrite(p,sizeof(dados),1,fptr);
fclose(fptr);		//fora do ELSE por conta do ab	
}//grava
	
void mostra(dados *p)
{
FILE *fptr=NULL;
int i,qreg;
qreg=verifica();
system("cls");
if((fptr=fopen("estoque.bin","rb"))==NULL)
  printf("\nErro ao abrir o arquivo");
else
  {
  for(i=0;i<qreg;i++)
    {
	fseek(fptr,i*sizeof(dados),0);
	fread(p,sizeof(dados),1,fptr);
	printf("\nRegistro: %i\nProduto: %s\nQtde: %i\nPreco: %.2f\n\n",p->reg,p->produto,p->qtde,p->preco);
    }//for
  fclose(fptr);
  }//else
system("pause");
}//mostra
	
	
	
	
	
	
	
	
	
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


































