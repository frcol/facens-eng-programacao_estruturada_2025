#include <stdio.h>
#include <stdlib.h>

void leitura(float *p,int q);
void media(float *p1,float *p2,float *pm,int q);

main()
{
float n1[10],n2[10],med[10];
int q;

do{
   printf("\nDigite a quantidade de alunos - max. 10: ");
   scanf("%i",&q);
   fflush(stdin);
  }while(q<0 || q>10); 
printf("\nDigite a Nota1 dos alunos");
leitura(n1,q);
printf("\nDigite a Nota1 dos alunos");
leitura(n2,q);
media(n1,n2,med,q);
}//main

void leitura(float *p,int q)
{
int i;
for(i=0;i<q;i++,p++)
  {
  	do{
  		printf("\nNota do %i aluno (0~10): ",i+1);
  		scanf("%f",p);
  		fflush(stdin);
	  }while(*p<0||*p>10);
  }//for
}//leitura

void media(float *p1,float *p2,float *pm,int q)
{
int i;
for(i=0;i<q;i++,p1++,p2++)    //for(i=0;i<q;i++,p1++,p2++,pm++)
   *(pm+i)=(*p1+*p2)/2;   		//*pm=(*p1+*p2)/2
							  //pm-=q;
for(i=0;i<q;i++,pm++)
  {
  printf("\nMedia - aluno %i = %.2f",i+1,*pm);
   if(*pm>=7)    
     printf("- Aprovado\n");
   else 
     {
     if(*pm>=4)
       printf("- Exame\n");
     else
       printf("- Reprovado\n");
     }//else
   }//for 
system("pause"); 
}//media
