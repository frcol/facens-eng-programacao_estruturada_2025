#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 	militar{
char	CPF[13];		// CPF do militar
char	nome[20];		// nome do militar
int		numreg;			// número do registro da carreira
}militar;

typedef struct		carreira{
int		reg;			// registro da patente
int		qmilitar;		// quantidade de militares daquela patente
char	org[20];		// organização - exemplo: exército, aeronáutica, marinha
char	patente[20];	// exemplo: soldado, cabo, sargento
float	salario;		// valor do salário
}carreira;


void aloca_patente(carreira **pc,int qc);
void aloca_militar(militar **pm,int qm);
void cadastra_patente(carreira *pc,int qc);
void cadastra_militar(militar *pm,carreira *pc);
int  busca_patente(carreira *pc,char *org,char *pat);
void troca_patente(militar *pm,int qm,carreira *pc);
int  busca_militar(militar *pm,int qm,char *aux_CPF);
void atualiza_numreg(carreira *pc,int n_reg);
void mostra_patente(carreira *pc,int qc);
void maiuscula(char *p);

main()
{
carreira *pcar=NULL;
militar  *pmil=NULL;
int op,cont=0;
aloca_patente(&pcar,5);
cadastra_patente(pcar,5);
do{
  system("cls");
  printf("\n[1]Cadastro Militar \n[2]Troca Patente \n[3]Mostra Patente\n[4]Fim \nOpcao: ");
  scanf("%i",&op);
  fflush(stdin);
  switch(op)
    {
    case 1: aloca_militar(&pmil,cont+1);
            cadastra_militar(pmil+cont,pcar);
            cont++;
			break;
    case 2: troca_patente(pmil,cont,pcar);
            break;
    case 3: mostra_patente(pcar,5);
    		break;
    }//switch
  }while(op!=4);
}//main
    
void aloca_patente(carreira **pcar,int qc)
{
if((*pcar=(carreira*)realloc(*pcar,qc*sizeof(carreira)))==NULL)
  exit(1);
}//aloca_patente

void aloca_militar(militar **pm,int qm)
{
if((*pm=(militar*)realloc(*pm,qm*sizeof(militar)))==NULL)
  exit(1);
}//aloca_militar

void cadastra_patente(carreira *pc,int qc)
{
int i;
for(i=0;i<qc;i++,pc++)
  {
   pc->reg=i+1;
   pc->qmilitar=0;
   printf("\nOrganizacao: Exercito / Aeronautica / Marinha\n");
   gets(pc->org);
   fflush(stdin);
   maiuscula(pc->org);
   printf("\nDigite a patente: ");
   gets(pc->patente);
   fflush(stdin);
   maiuscula(pc->patente);
   printf("\nDigite o salario: ");
   scanf("%f",&pc->salario);
   fflush(stdin);
  }//for
}//cadastra_carreira

void cadastra_militar(militar *pm,carreira *pc)
{
char aux_org[20],aux_pat[20];
printf("\nCPF: ");
gets(pm->CPF);
fflush(stdin);
printf("\nNome: ");
gets(pm->nome);
fflush(stdin);
printf("\nEscolha a Organizacao: Exercito / Aeronautica / Marinha\n");
gets(aux_org);
fflush(stdin);
maiuscula(aux_org);
printf("\nDigite a patente: ");
gets(aux_pat);
fflush(stdin);
maiuscula(aux_pat);
pm->numreg=busca_patente(pc,aux_org,aux_pat);
if(pm->numreg==-1)
  printf("\nNao ha patente solicitada\n\n\n");
else
  printf("\nCadastro feito com sucesso\nRegistro: %i\nSalario: %.2f\n\n",pm->numreg,(pc+(pm->numreg)-1)->salario);
system("pause");
}//cadastra_militar

int busca_patente(carreira *pc,char *org,char *pat)
{
int i;
for(i=0;i<5;i++,pc++)
  if((strcmp(pc->org,org)==0)&&(strcmp(pc->patente,pat)==0))
    {
      pc->qmilitar++;
      return(pc->reg);
    }//if
return -1;
}//busca

void troca_patente(militar *pm,int qm,carreira *pc)
{
int n_reg;
char aux_CPF[13],aux_org[20],aux_pat[20];
printf("\nCPF do militar a ser promovido: ");
gets(aux_CPF);
fflush(stdin);
n_reg=busca_militar(pm,qm,aux_CPF);
if(n_reg==-1)
  printf("\nCPF invalido\n\n");
else
  {
  	atualiza_numreg(pc,n_reg);   //mostra e decrementa o número de patentes atuais
    printf("\nEscolha a NOVA Organização: Exercito / Aeronautica / Marinha\n");
	gets(aux_org);
	fflush(stdin);
	maiuscula(aux_org);
	printf("\nDigite a patente: ");
	gets(aux_pat);
	fflush(stdin);
	maiuscula(aux_pat);
	pm->numreg=busca_patente(pc,aux_org,aux_pat);
if(pm->numreg==-1)
  printf("\nNao ha patente solicitada\n\n\n");
else
  printf("\nCadastro feito com sucesso\nNOVO salario: %.2f\n\n\n",(pc+(pm->numreg)-1)->salario);
  }//else
system("pause");
}//troca_patente

int  busca_militar(militar *pm,int qm,char *aux_CPF)
{
int i;
for(i=0;i<qm;i++,pm++)
   if(strcmp(pm->CPF,aux_CPF)==0)
     return(pm->numreg);
return -1;	
}//busca_militar

void  atualiza_numreg(carreira *pc,int n_reg)
{
int i;
for(i=0;i<5;i++,pc++)
  if(pc->reg==n_reg)
    {
    	printf("\nOrganizacao Atual: %s\nPatente Atual: %s\nSalario Atual: %.2f\n\n",pc->org,pc->patente,pc->salario);
    	pc->qmilitar--;
    }
}//atualiza_numreg

void mostra_patente(carreira *pc,int qc)
{
int i;
for(i=0;i<qc;i++,pc++)
  printf("\nRegistro: %i\nQtde Militares: %i\nOrganizacao: %s\nPatente: %s\nSalario: %.2f\n\n",pc->reg,pc->qmilitar,pc->org,pc->patente,pc->salario);
system("pause");
}//mostra_patente

void maiuscula(char *p)
{
int i,tam;
tam=strlen(p);
for(i=0;i<tam;i++)
  if(*(p+i)>='a' && *(p+i)<='z')
    *(p+i)-=32;
}//maiuscula
