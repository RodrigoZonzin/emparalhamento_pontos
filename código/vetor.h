#ifndef _VETOR_H 
#define _VETOR_H 
#include "ponto.h"

struct vetor{
    int x; 
    int y; 
}; 

typedef struct vetor Vetor; 

Vetor* cria_vetor(Ponto*, Ponto*); 
void destroi_vetor(Vetor*);
double produto_interno(Vetor*, Vetor*); 


#endif 