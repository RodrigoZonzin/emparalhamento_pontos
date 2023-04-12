#include "ponto.h"
#include <stdlib.h>
#include <stdio.h>

//O(1)
Ponto* cria_ponto(int x, int y){
    Ponto *p = (Ponto*)malloc(sizeof(Ponto)); 
    //EM CASO DE SEGMENTATION FAULT, 
    //CONSIDERAR ALOCAR OS PONTOS X E Y

    p->x = x; 
    p->y = y;
    p->tag = 0; //TAG É UM CONTADOR PARA PONTOS SUBJACENTES 

    return p;  
}

//CADA PONTO ALOCADO DEVERÁ SER LIBERADO 
//ANTES DE SE LIBERAR O VETOR DE PONTOS
//O(1)
void destroi_ponto(Ponto *p){
    free(p); 
}

//ALOCA UM ESPAÇO NA MEMÓRIA PARA OS N-PONTOS
//NECESSÁRIOS
//O(1)
Ponto** cria_vetor_de_pontos(int N){
    Ponto **pts = (Ponto**)malloc(sizeof(Ponto*)*N); 

    return pts; 
}

//IMPRIME OS N PONTOS CONTIDOS NO "ARRAY" DE 
//PONTOS
//O(N)
void imprime_vetor_de_pontos(Ponto **pts, int N){
    for(int i =0; i<N; i++){
        printf("(%d, %d)\n", pts[i]->x, pts[i]->y); 
    }
}

//UM LAÇO QUE PERCORRE OS N ELEMENTOS DE UM ARRAY-PONTOS
//LIBERANDO CADA ELEMENTO PERTENCENTE A ELE
//POR FIM, LIBERA O ESPAÇO DO PRÓPRIO PONTEIRO
//O(N)
void destroi_vetor_de_pontos(Ponto** pts, int N){
    for(int i = N-1; i>=0; i--){
        destroi_ponto(pts[i]);
        //printf("pts[%d] == freed\n", i); 
    }
    free(pts);
}


//TROCA A POSICAO DE DOIS PONTOS
void swap_ponto(Ponto *p1, Ponto *p2){
    Ponto* aux = cria_ponto(0, 0); 

    *aux = *p1; 
    *p1  = *p2; 
    *p2  = *aux;

    destroi_ponto(aux); 
}

//SELECTION SORT
void ordena_todos_os_pontos(Ponto** pts, int N){
    int i, j;
    int min;
    
    for(i = 0; i < N-1; i++){
        min = i;

        for(j = i+1; j< N; j++){
            if(pts[j]->y < pts[min]->y){
                min = j; 
            }
        }
        if(i != min){
            swap_ponto(pts[min], pts[i]);
        }
    }
}