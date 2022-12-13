#include <stdio.h>
#include <stdlib.h>
#include "ordvetor.h"

//Função de comparação
int myCOMP(void* x, void* y){
	int ptx = *((int*)x);
	int pty = *((int*)y);
	if(ptx - pty < 5){
		return -1;
	}else{
		if(ptx - pty > 5) return 1;
		else return 0;
	}
}

//Print para a estrutura
void print(void** vet, int tamanho){
	int i;
	printf("VETOR DE %d TAMANHO:\n", tamanho);	//Imprime o tamanho do vetor baseado nos dados dentro do vetor
	for(i = 0; i < tamanho; i++){
		printf(" %d ", *((int*)vet[i]));
	}
	printf("\n");
}

int main(){
   	VETORORD* vet = criar(10, myCOMP);

   	int* x;
   	int i;

   	printf("INCLUINDO... \n");
	for(i = 0; i < 10; i++){		//chama a função adicionar 10 vezes a cada novo elemento inserido
		x = malloc(sizeof(int));
		*x = i*10;
		adicionar(vet, x);
	}

	print(vet->elems, vet->tamanho);

  	printf("REMOVENDO!");
  	remover(vet);

	print(vet->elems, vet->tamanho);

	return 0;
}
