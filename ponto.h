#ifndef _PONTO_H
#define _PONTO_H

#include <stdio.h>
#include <stdlib.h> 



//ESTRUTURA DE DADOS PARA REPRESENTAR DADOS 
//NO PLANO CARTESIANO
struct ponto{
	int x; 
	int y; 
	int tag; 
}; 
typedef struct ponto Ponto;

//FUNÇÕES QUE IMPLEMENTARÃO O TAD PONTO
Ponto* cria_ponto(int, int); 
void destroi_ponto(Ponto*); 
Ponto** cria_vetor_de_pontos(int); 
void imprime_vetor_de_pontos(Ponto **, int); 
void destroi_vetor_de_pontos(Ponto**, int);
void ordena_todos_os_pontos(Ponto**, int);
void swap_ponto(Ponto*, Ponto*);

#endif