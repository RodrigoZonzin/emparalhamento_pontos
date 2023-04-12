#include "ponto.h"
#include "analise.h"
#include "vetor.h"

/*
PARA SABERMOS SE HÁ INTERSECÇÃO ENTRE DOIS PONTOS APENAS NAS ANCORAS
TOMAREMOS A SEGUINTE ABORDAGEM:
DADO DOIS PONTOS M e N PERTENCENTES AO CONJUNTO DE PONTOS P
SE 
    O TRIANGULO DETERMINADO POR ABM* CONTÉM N OU 
    O TRIANGULO DETERMINADO POR ABN CONTÉM M 

ENTAO NÃO HÁ INTERSECÇÃO ENTRE AS RETAS
*A = (Xa, 0) e B = (Xb, 0)
*/




//OS PONTOS ABC e ABP DETERMINAM UM TRIANGULO 
//VAMOS VERIFICAR SE O PONTO P ESTA EM ABC OU 
//SE O PONTO C ESTÁ EM ABP
int esta_dentro(Ponto *A, Ponto *B, Ponto *C, Ponto *P){
    //VETORES AB, AC e AP 
    Vetor *AB  = cria_vetor(A, B); 
    Vetor *AC  = cria_vetor(A, C); 
    Vetor *AP  = cria_vetor(A, P); 

    double inter_AB_AB, inter_AC_AC, inter_AB_AC, inter_AB_AP, inter_AC_AP;
    double DIV, U, V;

    inter_AB_AB = produto_interno(AB,AB);
    inter_AC_AC = produto_interno(AC,AC);
    inter_AB_AC = produto_interno(AB,AC);
    inter_AB_AP = produto_interno(AB,AP);
    inter_AC_AP = produto_interno(AC,AP);

    //DESALOCANDO OS VETORES AUXILIARES
    //ME ARREPENDO DESSA ABORDAGEM, POIS TAL COMO
    //NA ALGEBRA LINEAR, VETORES E PONTOS SÃO NOTAÇÕES
    //INTERCAMBIÁVEIS
    destroi_vetor(AB);
    destroi_vetor(AC);
    destroi_vetor(AP);

    DIV = inter_AC_AC*inter_AB_AB - inter_AB_AC*inter_AB_AC;
    U = (inter_AC_AC*inter_AB_AP - inter_AB_AC*inter_AC_AP) / DIV;
    V = (inter_AB_AB*inter_AC_AP - inter_AB_AC*inter_AB_AP) / DIV;

    if(U>= 0 && V >= 0 && U+V <1){
        return 1; //RETORNA UM BOOL TRUE (1)
    }
    else{
        return 0; //RETORNA UM BOOL FALSE (0)
    }
}
//VAMOS ANALISAR OS TRIANGULOS ABC E ABD 
int apenas_na_ancora(Ponto *A, Ponto *B, Ponto *C, Ponto *D){
    return (esta_dentro(A, B, C, D) || esta_dentro(A, B, D, C)); 
    //RETORNA UM BOOL TRUE 1 OU FALSE 0 
}

/*
int analisa_todos_os_pontos(Ponto **pts, int N, int Xa, int Xb){
    int contador = 0; 
    //int *res = (int*)malloc(sizeof(int)*N); 
    //ISSO AQUI FOI GAMBIARRA
    Ponto *A = cria_ponto(Xa, 0, 0); 
    Ponto *B = cria_ponto(Xb, 0, 0);

    int maior = 0; 
    for(int i = 0; i<N; i++){
        for(int j = i; j<N-1; j++){  
            if(apenas_na_ancora(A, B, pts[i], pts[j+1]) == 1){
                contador++; 
            }
        }
        if(contador >= maior){
            maior = contador; 
        }
        contador = 0;
    }

    destroi_ponto(A);
    destroi_ponto(B);

    return maior+1;
}
*/ 

//
int contar_pontos_subjacentes(Ponto **pts, Ponto *A, Ponto *B, int posicao){
    for(int i = 0; i< N-1; i++){
        if(esta_dentro(A, B, pts[i], pts[i+1])){
            
        }
    }
    
    return maior; 
}


int analisa_todos_os_pontos(Ponto **pts, int N, int Xa, int Xb){
    int maior = 0; 
    int dentro = 0; 
    int temp; 

    Ponto *A = cria_ponto(Xa, 0, 0);
    Ponto *B = cria_ponto(Xb, 0, 0);

    for(int i =0; i<N; i++){
       //dentro = contar(A, B, pts, i+1); 
       //dentro = 
       contar_pontos_subjacentes(pts, A, B, i);
        if(dentro == 0){
            pts[i]->tag_contador = 1;
        }
        else{
            for(int j =0; j< i; j++){
                
                if(esta_dentro(A, B, pts[i], pts[j])){
                    temp = 1 + pts[j]->tag_contador; 

                    if(temp > pts[j]->tag_contador){
                        pts[i]->tag_contador = temp; 
                    }
                }
            }
        }

        if(pts[i]->tag_contador > maior){
            maior = pts[i]->tag_contador; 
        }

        return maior;
    }

}


//PRINTAR TAGS DO 
void printar_tags(Ponto **pts, int N){
    printf("["); 
    for(int i = 0; i<N;i++){
        printf("%d", pts[i]->tag_contador);
        if(i == N-1)continue;
        printf(", ");
    }
    printf("]\n");
}