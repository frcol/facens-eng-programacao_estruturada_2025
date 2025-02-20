#include <stdio.h>
#include <stdlib.h>

main()
{
int i,qtde;
float A[10],B[10],C[10],*pa,*pb,*pc;
pa=A;
pb=B;
pc=C;	//inicializa o ponteiro

printf("\nCalcula a resultante da soma de 2 vetores\n");
do{
	printf("\nQuantos elementos - max.10: ");
	scanf("%i",&qtde);
	fflush(stdin);
  }while(qtde<0 || qtde>10);
  
//leitura dos vetores
printf("\nLeitura do vetor A:\n");
for(i=0;i<qtde;i++,pa++)
  {
  	printf("%i elemento: ",i+1);
  	scanf("%f",pa);
  	fflush(stdin);
  }//for
printf("\nLeitura do vetor B:\n");
for(i=0;i<qtde;i++,pb++)
  {
  	printf("%i elemento: ",i+1);
  	scanf("%f",pb);
  	fflush(stdin);
  }//for 
  
//Calcula a resultante
pa=A;
pb=B;
for(i=0;i<qtde;i++,pa++,pb++,pc++)
  *pc=*pa+*pb;
  
//Mostrar os vetores
pa=A;
pb=B;
pc=C;
system("cls");
printf("\nVetor A:");
for(i=0;i<qtde;i++,pa++)
  printf("\nA[%i]= %2.f",i,*pa);
  
printf("\n\nVetor B:");
for(i=0;i<qtde;i++,pb++)
  printf("\nB[%i]= %2.f",i,*pb);
  
printf("\n\nVetor C:");
for(i=0;i<qtde;i++,pc++)
  printf("\nC[%i]= %2.f",i,*pc);

printf("\n\n\n");
system("pause");
}//main
