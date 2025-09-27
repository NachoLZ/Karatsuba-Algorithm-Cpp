#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int N, numero, i, j;

	for(i=0;i<1;i++){
		N = rand();
		while(N>10000){
			N = rand();
		}
		printf("%d", N);
		printf (" ");
		for(j=0;j<N;j++){
			numero = rand()%2;
			printf("%d", numero);
		}
		printf(" ");
		for(j=0;j<N;j++){
			numero = rand()%2;
			printf("%d", numero);
		}
		printf("\n");
	}	
}



//fprintf (fichero, "%s %d", cadena1, num);