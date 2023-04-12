#include "ponto.h"
#include "analise.h"
#include "vetor.h"


//CALCULA A AREA DE UM TRIANGULO DETERMINADO PELOS PONTOS ABP
//O(1)
float area_triangulo(Ponto *A, Ponto *B, Ponto *P) {
    
    float area = (float) (A->x*(B->y-P->y) + B->x*(P->y-A->y) + P->x*(A->y-B->y)) / 2;
    
    if (area < 0) return -area;  
    else return area;
}


//CONTA TODOS OS PONTOS QUE UM TRIANGULO ABpi CONTÉM 
//SENDO pi UM PONTO PERTENCENTE AO CONJUNTO DOS PONTOS P
//O(N)
int contar_pontos_subjacentes(Ponto **pts, Ponto *A, Ponto *B, int N){
    
    int cont = 0;
    float _ABP, _APpi, _ABpi, _PBpi;
    
    Ponto *P = pts[N-1];

    _ABP = area_triangulo(A, B, P);
    
    for (int i = N-2; i >= 0; i--) {
        _ABpi = area_triangulo(A, B, pts[i]);
        _APpi = area_triangulo(A, P, pts[i]);
        _PBpi = area_triangulo(P, B, pts[i]);   

        if (_ABP == (_ABpi + _APpi + _PBpi) && _ABpi!=0 && _APpi!=0 && _PBpi!=0) {
            cont++;
        }     
    }

    return cont;
}


//RETORNA UM BOOL TRUE(1) OU FALSE(0) SE 
//O PONTO P ESTIVER CONTIDO NO TRIANGULO ABC OU 
//O PONTO C ESTIVER CONTIDO NO TRIANGULI ABP
//O(1)
int esta_dentro(Ponto *A, Ponto *B, Ponto *C, Ponto *P){
    //VETORES AB, AC e AP 
    Vetor *AB  = cria_vetor(A, B); //V0
    Vetor *AC  = cria_vetor(A, C); //V1
    Vetor *AP  = cria_vetor(A, P); //V2

    double P00, P11, P01, P02, P12, DIV, U ,V;
    P00 = produto_interno(AB,AB);
    P11 = produto_interno(AC,AC);
    P01 = produto_interno(AB,AC);
    P02 = produto_interno(AB,AP);
    P12 = produto_interno(AC,AP);

    //DESALOCANDO OS VETORES AUXILIARES
    //ME ARREPENDO DESSA ABORDAGEM, POIS TAL COMO
    //NA ALGEBRA LINEAR, VETORES E PONTOS SÃO NOTAÇÕES
    //INTERCAMBIÁVEIS
    destroi_vetor(AB);
    destroi_vetor(AC);
    destroi_vetor(AP);

    DIV = P11*P00 - P01*P01;
    U = (P11*P02 - P01*P12) / DIV;
    V = (P00*P12 - P01*P02) / DIV;

    if(U>= 0 && V >= 0 && U+V <1){
        return 1; //RETORNA UM BOOL TRUE (1)
    }
    else{
        return 0; //RETORNA UM BOOL FALSE (0)
    }
}

//PASSA POR TODOS OS PONTOS ANALISANDO SE ELES RESPEITAM 
//OU NÃO A CONDIÇÃO DE INTERCEPTAR-SE COM OS DEMAIS PONTOS APENAS NA 
//ANCORA
//O(n)*[O(N)+O(N)] = O(N^2)
int analisa_todos_os_pontos(Ponto **pts, int N, Ponto *A, Ponto *B){
    int maior = 0; 

    for(int i = 0; i<N; i++){
        int dentro = contar_pontos_subjacentes(pts, A, B, i+1); 

        if(!dentro){
            pts[i]->tag = 1; 
        }
        else{
            for(int j = 0; j<i; j++){
                if(esta_dentro(A, B, pts[i], pts[j])){
                    int _aux = 1 + pts[j]->tag; 

                    if(_aux > pts[j]->tag){
                        pts[i]->tag = _aux;
                    }
                }
            }


        }
        if(pts[i]->tag > maior){
            maior = pts[i]->tag; 
        }
    }
    return maior; 
}