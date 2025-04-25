#include <stdio.h>
#include <stdlib.h>

typedef struct quarto{
	int 	num;
	char 	categoria;
	char	status;			//L-ivre ou O-cupado
	}quarto ;
         	
typedef struct hospede{
	int 	quarto;
	char 	nome[80];
	int 	acompanhante;
	char 	categoria;
	int 	dias;			
   	}hospede ;

void aloca_quarto(quarto **q,int qq);
void aloca_hospede(hospede **h,int qh);
void cadastro_quarto(quarto *q,int qq);
void cadastro_hospede(hospede *h,quarto *q,int qq);
int  busca_quarto(quarto *q,int qq,char cat);
int  busca_hospede(hospede *h,int qh,int n_quarto);
void check_out(hospede *h,int qh,quarto *q);
void mostra_quarto(quarto *q,int qq);
void mostra_hospede(hospede *h,int qh);

main()
{
quarto *pq=NULL;
hospede *ph=NULL;
int op,cont=0,pos;

aloca_quarto(&pq,15);
cadastro_quarto(pq,15);
do{
	system("cls");
	printf("\n[1]Check-in\n[2]Check-out\n[3]Mostra Quarto\n[4]Mostra Hospede\n[5]Fim\nOpcao: ");
	scanf("%i",&op);
	fflush(stdin);
	switch(op)
	  {
	  	case 1: pos=busca_hospede(ph,cont,-1);   //quarto=-1 - vago
	  	        if(pos==-1)   //nao ha hosped vago
	  	         {
	  	         	aloca_hospede(&ph,cont+1);
	  	         	pos=cont;
	  	         	cont++;
	  	         }//if
	  			cadastro_hospede(ph+pos,pq,15);
	  			break;
	  	case 2: check_out(ph,cont,pq);
	  			break;
	  	case 3: mostra_quarto(pq,15);
	  			break;
	  	case 4: mostra_hospede(ph,cont);
	  			break;
	  }//switch
  }while(op!=5);
}//main

void aloca_quarto(quarto **q,int qq)
{
if((*q=(quarto*)realloc(*q,qq*sizeof(quarto)))==NULL)
  exit(1);
}//aloca_quarto

void aloca_hospede(hospede **h,int qh)
{
if((*h=(hospede*)realloc(*h,qh*sizeof(hospede)))==NULL)
  exit(1);
}//aloca_hospede

void cadastro_quarto(quarto *q,int qq)
{
int i;
for(i=0;i<qq;i++,q++)
  {
  	q->num=i+1;
  	q->status='L';
  	if(i<5)
  	  q->categoria='S';
  	else
  	  q->categoria='F';
  }//for
}//cadastra_quarto

void cadastro_hospede(hospede *h,quarto *q,int qq)
{
printf("\nNome: ");
gets(h->nome);
fflush(stdin);
do{
	printf("\nQtde de acompanhantes - max.3: ");
	scanf("%i",&h->acompanhante);
	fflush(stdin);
  }while(h->acompanhante<0 || h->acompanhante>3);
if(h->acompanhante==0)
  h->categoria='S';
else
  h->categoria='F';
printf("\nDias: ");
scanf("%i",&h->dias);
fflush(stdin);
h->quarto=busca_quarto(q,qq,h->categoria);
if(h->quarto==-1)
  printf("\nNao ha quartos com a categoria desejada\n\n");
else
  printf("\nCadastro com sucesso - quarto = %i\n\n",h->quarto);
printf("\n\n\n");
system("pause");
}//cadastro_hospede

int  busca_quarto(quarto *q,int qq,char cat)
{
int i;
for(i=0;i<qq;i++,q++)	
  if(q->categoria==cat && q->status=='L')
    {
    	q->status='O';
    	return q->num;
	}//if
return -1;  //nao ha quartos livres
}//busca_quarto

int  busca_hospede(hospede *h,int qh,int n_quarto)
{
int i;
for(i=0;i<qh;i++,h++)
  if(h->quarto==n_quarto)
    return i;   //posicao do hospede na estrutura
return -1;
}//busca_hospede

void check_out(hospede *h,int qh,quarto *q)
{
int n_quarto,achou;
float valor;
printf("\nQuarto a ser finalizado: ");
scanf("%i",&n_quarto);
fflush(stdin);
achou=busca_hospede(h,qh,n_quarto);
if(achou==-1)
  printf("\nQuarto invalido\n\n");
else
  {
  	if((h+achou)->categoria=='S')
	  valor=(h+achou)->dias*85;
	else
	  valor=(h+achou)->dias*(((h+achou)->acompanhante)+1)*65;
	printf("\nNome: %s\nAcompanhantes: %i\nCategoria: %c\nDias: %i\nValor a ser pago: %.2f\n\n",(h+achou)->nome,(h+achou)->acompanhante,(h+achou)->categoria,(h+achou)->dias,valor);
	(h+achou)->quarto=-1;  
  }//else
(q+n_quarto-1)->status='L';  //libera o quarto
system("pause"); 
}//check_out

void mostra_quarto(quarto *q,int qq)
{
int i;
for(i=0;i<qq;i++,q++)	
  printf("\nQuarto: %i\nCategoria: %c\nStatus: %c\n\n",q->num,q->categoria,q->status);
system("pause");  
}//mostra_quarto

void mostra_hospede(hospede *h,int qh)
{
int i;
for(i=0;i<qh;i++,h++)
  printf("\nQuarto: %i\nNome: %s\nAcompanhantes: %i\nCategoria: %c\nDias: %i\n\n",h->quarto,h->nome,h->acompanhante,h->categoria,h->dias);
system("pause");  
}//mostra_hospede
