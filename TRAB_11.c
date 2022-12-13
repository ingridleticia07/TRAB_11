#include <stdio.h>
#include <stdlib.h>
#include "ordvetor.h"

/*
Cria um vetor todo nulo baseado na funçao compara. 
A alocaçao de espaço se torna necessária.
Retorna um ponteiro vetord.
*/

VETORORD* criar(int tam, COMP* compara){          
    VETORORD* vetorord = malloc(sizeof(VETORORD));      
    vetorord->comparador = compara;
    vetorord->tamanho = tam;       
    vetorord->num_elem = 0;        
    vetorord->elems = malloc(tam * sizeof(void *));       
    for(int i = 0;i<tam;i++){
        vetorord->elems[i] = NULL;
    }
    return vetorord;
}

/* 
Adiciona um novo elemento na posiçao correta. 
O vetor organiza os elementos em ordem crescente.
*/

void adicionar(VETORORD* vetor, void* newelem){      
    if (vetor->num_elem < vetor->tamanho) {
        if (vetor->num_elem == 0) {
            vetor->elems[0] = newelem;
        }
        else if (vetor->comparador(newelem, vetor->elems[vetor->num_elem-1]) == -1 || 
        vetor->comparador(newelem, vetor->elems[vetor->num_elem-1]) == 0) {
            vetor->elems[vetor->num_elem] = newelem;
        }else {
            for (int i = vetor->num_elem-1; i > -1; i--) {
                if (vetor->comparador(newelem, vetor->elems[i]) == 1) {
                    vetor->elems[i+1] = vetor->elems[i];
                    vetor->elems[i] = newelem;
                }
                else break;
            }
        }
        vetor->num_elem++;
    }
}

/*
Remove o menor elemento do vetor por meio da funçao compara.
Reorganiza o vetor para manter a ordem correta.
*/

void* remover(VETORORD* vetor){
    void* aux = vetor->elems[0];
    for(int i = 0;i<vetor->num_elem;i++){
        vetor->elems[i] = vetor->elems[i+1]; 
    }
    vetor->num_elem--;
    return aux;
}