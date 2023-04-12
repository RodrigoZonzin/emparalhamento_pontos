#ifndef _ANALISE_H
#define _ANALISE_H

#include "ponto.h"

float area_triangulo(Ponto*, Ponto*, Ponto*); 
int contar_pontos_subjacentes(Ponto**, Ponto*, Ponto*, int); 
int esta_dentro(Ponto*, Ponto*, Ponto*, Ponto*);
int analisa_todos_os_pontos(Ponto**, int, Ponto*, Ponto*);

#endif