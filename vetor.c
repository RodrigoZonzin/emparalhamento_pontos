#include "vetor.h"
#include "ponto.h"
#include <stdio.h>
#include <stdlib.h> 

//FUNÇÃO CONSTRUTOR DO TIPO VETOR
//O(1)
Vetor* cria_vetor(Ponto *M, Ponto *N){
    Vetor *v = (Vetor*)malloc(sizeof(Vetor)); 

    v->x = N->x - M->x; 
    v->y = N->y - M->y; 

    return v; 
}

//O(1)
void destroi_vetor(Vetor *v){
    free(v);
}

//DADO DOIS PONTOS P E Q, O PRODUTO ESCALAR É DEFINIDO COMO
// <P,Q> = PxQx + PyQy  \in R^1 
//O(1)
double produto_interno(Vetor *A, Vetor *B){
    return (A->x * B->x)+(A->y * B->y); 
}
