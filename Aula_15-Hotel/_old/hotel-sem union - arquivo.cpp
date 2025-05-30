#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hospede{
        int    quarto;
        char   nome[30];
        int    acompanhante;    
        int    dias;
        }hospede;
        
typedef struct quarto{
        int    num;
        char   categoria;
        char   status;
        }quarto;

void aloca_quarto(quarto **pq);
void aloca_hospede(hospede **ph);
void cadastro_quarto(quarto *pq,int qq);
void encerra_quarto(hospede *ph,quarto *pq);
void grava_quarto(quarto *pq);
void mostra(hospede *ph,int tam,int num);
int  verifica();
int  busca_vago(hospede *ph,int tam);
void cadastro(hospede *ph,quarto *pq,int pos,int qtde);
int  busca_quarto(quarto *pq,char letra);
void grava_hospede(hospede *ph,int pos,int qtde);
void mostra_quarto(quarto *pq);

main()
{
quarto *q=NULL;
hospede *hosp=NULL;
int op,qtde,pos,num;

aloca_quarto(&q);
cadastro_quarto(q,15);
aloca_hospede(&hosp);
qtde=verifica();   //arquivo hospede
do{
  system("cls");
  printf("[1]Check-in\n[2]Check-out\n[3]Mostra Hospedes\n[4]Fim\nOpcao:");
  scanf("%i",&op);
  fflush(stdin);
  switch(op)
     {
     case 1:pos=busca_vago(hosp,qtde);
     		printf("\nPos vago= %i\n\n",pos);
     		system("pause");
            if(pos==-1)   //nao ha vago
              {
              pos=qtde;
              qtde++;
              }
            cadastro(hosp,q,pos,qtde);
            system("pause");
            break;
     case 2:printf("\nQuarto a ser encerrado: ");
            scanf("%i",&num);
            fflush(stdin);
            mostra(hosp,qtde,num);
            encerra_quarto(hosp,q);
            break;
     case 3:mostra(hosp,qtde,0);
            system("pause");
            break;
     }//switch
  }while(op!=4);      
system("pause");
}//main


void aloca_quarto(quarto **pq)
{
if(((*pq=(quarto*)realloc(*pq,sizeof(quarto)))==NULL))
  exit(1);
}//aloca_quarto

void aloca_hospede(hospede **ph)
{
if(((*ph=(hospede*)realloc(*ph,sizeof(hospede)))==NULL))
  exit(1);
}//aloca_hospede
     
void cadastro_quarto(quarto *pq,int qq)
{
int i;

for(i=0;i<qq;i++)
  {
  if(i<5)
    pq->categoria='S';
  else
    pq->categoria='F';
  pq->num=i+1;
  pq->status='L';
  grava_quarto(pq);
  }//for
}//cadastra_quarto

void encerra_quarto(hospede *ph,quarto *pq)
{
FILE *fp;
int i;
float total;

if((fp=fopen("quarto.bin","rb+"))==NULL)
  printf("\nArquivo inexistente\n");
else
  for(i=0;i<15;i++)
    {
    fseek(fp,i*sizeof(quarto),0);
    fread(pq,sizeof(quarto),1,fp);
    if(pq->num==ph->quarto)
      {
      if(pq->categoria=='S')
        total=ph->dias*85;
      else
        total=ph->dias*45*(ph->acompanhante+1);
      printf("\nValor a ser pago: %.2f\n",total);
      system("pause");
      pq->status='L';
      fseek(fp,i*sizeof(quarto),0);
      fwrite(pq,sizeof(quarto),1,fp);                
      }//if
    }//for
fclose(fp);
}

void grava_quarto(quarto *pq)
{
FILE *fq;

if((fq=fopen("quarto.bin","ab"))==NULL)
  printf("\nArquivo inexistente-1\n");
else
  {
  fwrite(pq,sizeof(quarto),1,fq);
  }
fclose(fq);
}//grava_quarto 

void mostra(hospede *ph,int tam,int num)
{ 
FILE *fh;
int i;

if((fh=fopen("hospede.bin","rb+"))==NULL)
  printf("\nArquivo inexistente\n");
else
  for(i=0;i<tam;i++)
    {
    fseek(fh,i*sizeof(hospede),0);
    fread(ph,sizeof(hospede),1,fh);
    if(num==0)
      printf("\nQuarto: %i\nNome:%s\nAcompanhantes: %i\nDias: %i\n\n\n",ph->quarto,ph->nome,ph->acompanhante,ph->dias);
    if(ph->quarto==num)
      {
      printf("\nQuarto: %i\nNome:%s\nAcompanhantes: %i\nDias: %i\n\n\n",ph->quarto,ph->nome,ph->acompanhante,ph->dias);
      strcpy(ph->nome,"@");
      fseek(fh,i*sizeof(hospede),0);
      fwrite(ph,sizeof(hospede),1,fh);
      }     
    }//for
fclose(fh);
}//mostra

void mostra_quarto(hospede *ph,int tam,int num)
{ 
FILE *fh;
int i;

if((fh=fopen("hospede.bin","rb+"))==NULL)
  printf("\nArquivo inexistente\n");
else
  for(i=0;i<tam;i++)
    {
    fseek(fh,i*sizeof(hospede),0);
    fread(ph,sizeof(hospede),1,fh);
    if(num==0)
      printf("\nQuarto: %i\nNome:%s\nAcompanhantes: %i\nDias: %i\n\n\n",ph->quarto,ph->nome,ph->acompanhante,ph->dias);
    if(ph->quarto==num)
      {
      printf("\nQuarto: %i\nNome:%s\nAcompanhantes: %i\nDias: %i\n\n\n",ph->quarto,ph->nome,ph->acompanhante,ph->dias);
      strcpy(ph->nome,"@");
      fseek(fh,i*sizeof(hospede),0);
      fwrite(ph,sizeof(hospede),1,fh);
      }     
    }//for
fclose(fh);
}//mostra

int  verifica()
{
FILE *fh;
long int q;

if((fh=fopen("hospede.bin","rb"))==NULL)
  return 0;
fseek(fh,0,2);
q=ftell(fh)/sizeof(hospede);
fclose(fh);
return q;
}//verifica

int  busca_vago(hospede *ph,int tam)
{
FILE *fh=NULL;
int i;

if((fh=fopen("hospede.bin","rb"))==NULL)
  printf("\nArquivo inexistente\n");
else
  {
  for(i=0;i<tam;i++)
    {
    fseek(fh,i*sizeof(hospede),0);
    fread(ph,sizeof(hospede),1,fh);
    if(strcmp(ph->nome,"@")==0)
      {
      fclose(fh);
      return i;
      }
    }//for
  fclose(fh);
  }//else  
return -1;
}//busca_vago     

void cadastro(hospede *ph,quarto *pq,int pos,int qtde)
{
system("cls");
printf("\nNome: ");
gets(ph->nome);
fflush(stdin);
do{
   printf("\nQtde de acompanhantes - max.3: ");
   scanf("%i",&(ph->acompanhante));
   fflush(stdin);
   }while(ph->acompanhante<0||ph->acompanhante>3);
if(ph->acompanhante==0)
  ph->quarto=busca_quarto(pq,'S');
else
  ph->quarto=busca_quarto(pq,'F');
printf("\nTeste - num quarto:%i",ph->quarto);
if(ph->quarto==-1)
  printf("\nHotel Lotado");
else
  {
  printf("\nQtos dias: ");
  scanf("%i",&(ph->dias));
  fflush(stdin);
  grava_hospede(ph,pos,qtde);
  }                
}//cadastro   

int  busca_quarto(quarto *pq,char letra)
{
FILE *fq;
int i;
if((fq=fopen("quarto.bin","rb+"))==NULL)
  printf("\nImpossivel abrir o arquivo");
else
  for(i=0;i<15;i++)
    {
    fseek(fq,i*sizeof(quarto),0);
    fread(pq,sizeof(quarto),1,fq);
    if(pq->categoria==letra && pq->status=='L')
      {
      pq->status='O';
      fseek(fq,i*sizeof(quarto),0);
      fwrite(pq,sizeof(quarto),1,fq);
      fclose(fq);
      return(pq->num);
      }
    }//for
fclose(fq);    
return -1;
}//busca_quarto

void grava_hospede(hospede *ph,int pos,int qtde)
{
FILE *fh;
char aux[4];

if(qtde==1)   //1 vez
  strcpy(aux,"ab");
else
  strcpy(aux,"rb+");
if((fh=fopen("hospede.bin",aux))==NULL)
  printf("\nArquivo inexistente\n");
else
  {
  fseek(fh,pos*sizeof(hospede),0);                  
  fwrite(ph,sizeof(hospede),1,fh);
  }
fclose(fh);
}//grava_hospede 
                               
