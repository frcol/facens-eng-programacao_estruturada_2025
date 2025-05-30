#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct composto{
        char sigla;
        int num;
        }composto;

typedef union estado{
        char sigla;
        composto campo;
        }estado;

typedef struct hospede{
        int  numreg;
        char nome[80];
        int  acompanhante;
        char categoria;
        int  dias;
        estado tabela;
        }hospede;

typedef struct quarto{
        int  num;
        char categoria;
        estado status;
        }quarto;

void aloca_quarto(quarto **pq,int qq);
void aloca_hospede(hospede **ph,int qh);
void cadastro_quarto(quarto *pq,int qq);
void cadastro_hospede(hospede *ph,quarto *pq);
int  verifica_arquivo();
void grava_hospede(hospede *ph);
int  busca_quarto(quarto *pq,char letra,int qq,int numreg);
void  busca_hospede(hospede *ph,int numreg);
void encerra_quarto(hospede *ph,quarto *pq,int qq,int n_quarto);
void mostra_hospede(hospede *ph,int num);
void mostra_quarto(quarto *pq,int qq);

main()
{
quarto *q=NULL;
hospede *hosp=NULL;
int op,qtde=0,pos,num;

aloca_quarto(&q,1);
cadastro_quarto(q,15);
aloca_hospede(&hosp,1);
do{
  system("cls");
  printf("[1]Check-in\n[2]Check-out\n[3]Mostra Hospedes\n[4]Mostra Quarto\n[5]Fim\nOpcao:");
  scanf("%i",&op);
  fflush(stdin);
  switch(op)
     {
     case 1: cadastro_hospede(hosp,q);
             system("pause");
             break;
     case 2: printf("\nQuarto a ser encerrado: ");
             scanf("%i",&num);
             fflush(stdin);
             mostra_hospede(hosp,num);
             encerra_quarto(hosp,q,15,num);
             break;
     case 3: mostra_hospede(hosp,0);  //0 para indicar TODOS
     		 system("pause");
             break;
     case 4: mostra_quarto(q,15);
     		 system("pause");
             break;
     }//switch
  }while(op!=5);      
system("pause");
}//main

void aloca_quarto(quarto **pq,int qq)
{
if(((*pq=(quarto*)realloc(*pq,qq*sizeof(quarto)))==NULL))
  exit(1);
}//aloca_quarto

void aloca_hospede(hospede **ph,int qh)
{
if(((*ph=(hospede*)realloc(*ph,qh*sizeof(hospede)))==NULL))
  exit(1);
}//aloca_hospede
     
void cadastro_quarto(quarto *pq,int qq)
{
FILE *fp=NULL;
int i;
if((fp=fopen("quarto.bin","ab"))==NULL)   //ou   wb - só vai criar 1 única vez
  printf("Erro");
else
  for(i=0;i<qq;i++)
  {
   if(i<5)
     pq->categoria='S';
   else
     pq->categoria='F';
   pq->num=i+1;
   pq->status.sigla='L';  
   fseek(fp,i*sizeof(quarto),0);
   fwrite(pq,sizeof(quarto),1,fp);
  }//for
fclose(fp);
}//cadastra_quarto  

void cadastro_hospede(hospede *ph,quarto *pq)
{
int n,aux_quarto;

n=verifica_arquivo();      //descobre qtos hospedes tem no arquivo
system("cls");
ph->numreg=++n;
printf("\nRegistro: %i\n",ph->numreg);
printf("\nNome: ");
gets(ph->nome);
fflush(stdin);
do{
   printf("\nQtde de acompanhantes - max.3: ");
   scanf("%i",&(ph->acompanhante));
   fflush(stdin);
   }while(ph->acompanhante<0||ph->acompanhante>3);

if(ph->acompanhante==0)
  {
    aux_quarto=busca_quarto(pq,'S',15,ph->numreg);    //retorna o numero do quarto disponivel para a caregoria S
    ph->categoria='S';
  }//if
else
  {
    aux_quarto=busca_quarto(pq,'F',15,ph->numreg);    //retorna o numero do quarto disponivel para a caregoria F
    ph->categoria='F';
  }//else

if(aux_quarto==-1)
  printf("\nHotel Lotado\n\n");
else
  {
  ph->tabela.campo.sigla='O';
  ph->tabela.campo.num=aux_quarto;     //recebe o numero do quarto
  printf("\nQuarto:%i\n",ph->tabela.campo.num);	
  printf("\nCategoria: %c\n",ph->categoria);
  printf("\nQtos dias: ");
  scanf("%i",&(ph->dias));
  fflush(stdin);
  grava_hospede(ph);
  }//else                
}//cadastro_hospede

int  verifica_arquivo()
{
long int cont=0;
FILE *fptr=NULL;
if((fptr=fopen("hospede.bin","rb"))==NULL)
  return cont;
else
  {
  fseek(fptr,0,2);  //posiciona no fim do arquivo
  cont=ftell(fptr)/sizeof(hospede);   //qtde de elementos
  fclose(fptr);    //dentro do ELSE por conta do rb
  return cont;
  }//else
}//verifica_arquivo	

void grava_hospede(hospede *ph)
{
FILE *fptr=NULL;
if((fptr=fopen("hospede.bin","ab"))==NULL)	
  printf("\nErro ao abrir o arquivo");
else
  fwrite(ph,sizeof(hospede),1,fptr);
fclose(fptr);		//fora do ELSE por conta do ab	
}//grava_hospede

int  busca_quarto(quarto *pq,char letra,int qq,int numreg)
{
FILE *fptr;
int i;
if((fptr=fopen("quarto.bin","rb+"))==NULL)
  printf("\nImpossivel abrir o arquivo");
else
  for(i=0;i<qq;i++)
    {
    fseek(fptr,i*sizeof(quarto),0);
    fread(pq,sizeof(quarto),1,fptr);
    if(pq->categoria==letra && pq->status.campo.sigla=='L')    //se encontrou quarto na categoria e disponivel
      {
      pq->status.campo.sigla='O';
      pq->status.campo.num= numreg;              //registro do hospede
      fseek(fptr,i*sizeof(quarto),0);
      fwrite(pq,sizeof(quarto),1,fptr);
      fclose(fptr);
      return(pq->num);
      }
    }//for
fclose(fptr);    
return -1;    //não encontrou quarto disponivel na categoria desejada
}//busca_quarto

void  busca_hospede(hospede *ph,int numreg)
{
FILE *fhosp=NULL;
int i,qh,achou=0;

qh=verifica_arquivo();   //descobre a qtde de hospedes no arquivo
if((fhosp=fopen("hospede.bin","rb+"))==NULL)    //irá ATUALIZAR o arquivo de hospede
  printf("\nArquivo inexistente\n");
else
  {
   for(i=0;i<qh;i++)
    {
     fseek(fhosp,i*sizeof(hospede),0);
     fread(ph,sizeof(hospede),1,fhosp);
     if(ph->numreg==numreg)      //se encontrou  registro do hospede
      {
       achou=1;	
       ph->tabela.campo.sigla='L';      //atualiza a tabela do hospede para LIVRE
   	   ph->tabela.campo.num=-1;         //indica que não há quarto vinculado ao hospede
   	   fseek(fhosp,i*sizeof(hospede),0);
       fwrite(ph,sizeof(hospede),1,fhosp);   //atualiza os dados do hospede no arquivo
       i=qh;                        //forçar a saída do for para ficar com as infos do hospede na memoria
      }//if
    }//for
   if(achou==0)
    {
  	 printf("\nNão foi encontrado hospede com esse numero de registro\n\n\n");
  	 system("pause");
    }//if
  }//else
fclose(fhosp);
}//busca_hospede

void encerra_quarto(hospede *ph,quarto *pq,int qq,int n_quarto)
{
FILE *fquarto=NULL;
int i,n_hosp;
float total;

if((fquarto=fopen("quarto.bin","rb+"))==NULL)   //arquivo quarto será ATUALIZADO
  printf("\nArquivo inexistente\n");
else
  for(i=0;i<qq;i++)
    {
    fseek(fquarto,i*sizeof(quarto),0);
    fread(pq,sizeof(quarto),1,fquarto);	
    if(pq->num==n_quarto)      //achou o quarto a ser encerrado
      {
      n_hosp=pq->status.campo.num;       //numero do registro do hospede
	  busca_hospede(ph,n_hosp);     //trás para a memoria as infos do hospede 	
      if(pq->categoria=='S')
        total=ph->dias*85;
      else
        total=ph->dias*45*ph->acompanhante+1;
      printf("\nValor a ser pago: %.2f\n",total);
      system("pause");
      pq->status.campo.sigla='L';            //atualiza o status do quarto para LIVRE
      pq->status.campo.num=-1;               //indica que não há hospede viculado ao quarto
      fseek(fquarto,i*sizeof(quarto),0);
      fwrite(pq,sizeof(quarto),1,fquarto);                
      }//if
    }//for
fclose(fquarto);
}//encerra_quarto

void mostra_hospede(hospede *ph,int num)
{ 
FILE *fptr=NULL;
int i,qtde;

qtde=verifica_arquivo();   //descobre a qtde de hospedes no arquivo
if((fptr=fopen("hospede.bin","rb"))==NULL)
  printf("\nArquivo inexistente\n");
else
  {
   for(i=0;i<qtde;i++)
    {
     fseek(fptr,i*sizeof(hospede),0);
     fread(ph,sizeof(hospede),1,fptr);	
     if(num==0 )    //mostra todos os quartos
	   {
	    printf("\nRegistro: %i\nNome:%s\nAcompanhantes: %i\nCategoria: %c\nDias: %i\nTabela: %c",ph->numreg,ph->nome,ph->acompanhante,ph->categoria,ph->dias,ph->tabela.campo.sigla);
        if(ph->tabela.campo.sigla=='O')
          printf("\tNumero do quarto: %i\n\n\n",ph->tabela.campo.num);
        else
          printf("\n\n\n");     //só pular linha para não ficar grudado
       }//if
     else     //mostra só o quarto solicitado
       if(ph->tabela.campo.num==num)
         {
	      printf("\nRegistro: %i\nNome:%s\nAcompanhantes: %i\nCategoria: %c\nDias: %i\nTabela: %c",ph->numreg,ph->nome,ph->acompanhante,ph->categoria,ph->dias,ph->tabela.campo.sigla);
          if(ph->tabela.campo.sigla=='O')
            printf("\tNumero do quarto: %i\n\n\n",ph->tabela.campo.num);
          else
            printf("\n\n\n");     //só pular linha para não ficar grudado
         }//if
    }//for
  fclose(fptr);
 }//else
}//mostra_hospede

void mostra_quarto(quarto *pq,int tam)
{ 
FILE *fptr=NULL;
int i;

if((fptr=fopen("quarto.bin","rb"))==NULL)
  printf("\nArquivo inexistente\n");
else
  {
   for(i=0;i<tam;i++)
    {
      fseek(fptr,i*sizeof(quarto),0);
      fread(pq,sizeof(quarto),1,fptr); 	
      printf("\nQuarto: %i\nCategoria:%c\nStatus: %c",pq->num,pq->categoria,pq->status.campo.sigla);
      if(pq->status.campo.sigla=='O')
	   printf("\tHospede: %i\n",pq->status.campo.num);  
	  else
	   printf("\n");     //só pular linha para não ficar grudado
    }//for
    fclose(fptr);
 }//else
}//mostra_quarto



                               
