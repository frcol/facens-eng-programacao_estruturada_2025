//receber e imprimir os elementos de 1 vetor
#include <stdio.h>
#include <stdlib.h>

main()
{
int num[5],i;

printf("\nLer os elementos do vetor\n");
for(i=0;i<5;i++)
  {
  	printf("elemento: ");
  	scanf("%i",(num+i));
  }//for

printf("\nImprimir os elementos do vetor\n");
for(i=0;i<5;i++)  
  printf("\nnum[%i]= %i",i,*(num+i));
printf("\n\n\n");
system("pause");
}//main
