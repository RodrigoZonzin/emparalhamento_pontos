#ifndef _ANALISE_H
#define _ANALISE_H

#include "ponto.h"

double produto_interno(Vetor*, Vetor*); 
int esta_dentro(Ponto*, Ponto*, Ponto*, Ponto*);
int apenas_na_ancora(Ponto*, Ponto*, Ponto*, Ponto*);
int analisa_todos_os_pontos(Ponto**, int, int, int);
void contar_pontos_subjacentes(Ponto**, Ponto*, Ponto*, int);
void printar_tags(Ponto**, int);


#endif