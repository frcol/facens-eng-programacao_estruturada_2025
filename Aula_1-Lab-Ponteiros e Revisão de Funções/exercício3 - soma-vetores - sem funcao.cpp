//soma de 2 vetores A e B - resultado C
#include <stdio.h>
#include <stdlib.h>

main()
{
int a[10],b[10],c[10],qtde,i,*pa,*pb,*pc;
pa=a;		//inicialização do ponteiro
pb=b;		//inicialização do ponteiro
pc=c;		//inicialização do ponteiro
printf("\nSoma 2 vetores");
do{
  printf("\nQtde de elementos - max 10: ");
  scanf("%i",&qtde);
  }while(qtde<1 || qtde>10);

//leitura dos vetores A e B  
printf("\nLeitura - Vetor a:\n");
for(i=0;i<qtde;i++,pa++)
  {
  printf("vet[%i]= ",i);
  scanf("%i",pa);
  fflush(stdin);
  }//for
printf("\nLeitura - Vetor b:\n");
for(i=0;i<qtde;i++,pb++)
  {
  printf("vet[%i]= ",i);
  scanf("%i",pb);
  fflush(stdin);
  }//for
  
//calcula resultante
pa=a;		//posiciona o ponteiro no endereço inicial
pb=b;		//posiciona o ponteiro no endereço inicial
for(i=0;i<qtde;i++,pa++,pb++,pc++)
  *pc=*pa+*pb;
pa=a;		//posiciona o ponteiro no endereço inicial
pb=b;		//posiciona o ponteiro no endereço inicial
pc=c;		//posiciona o ponteiro no endereço inicial

//imprime os vetores
system("cls");
printf("\nImprime - Vetor a:");
for(i=0;i<qtde;i++,pa++)
  printf("\nvet[%i]= %i",i,*pa);
printf("\n\nImprime - Vetor b:");
for(i=0;i<qtde;i++,pb++)
  printf("\nvet[%i]= %i",i,*pb);
printf("\n\nImprime - Vetor c:");
for(i=0;i<qtde;i++,pc++)
  printf("\nvet[%i]= %i",i,*pc);
printf("\n\n\n");
system("pause");
}//main


