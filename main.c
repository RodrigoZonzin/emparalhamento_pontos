#include <stdio.h>
#include <stdlib.h> 
#include <stdio_ext.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <time.h>

#include "ponto.h"
#include "analise.h"
#include "vetor.h"

int main(int argc,char *argv[]){
    FILE *f = fopen(argv[2], "r"); 
    FILE *output = fopen(argv[4], "w+"); 

    int N, Xa, Xb;
    int x, y, resultado;  

    /*
    struct rusage comeco, fim;
    double tempo_usuario, tempo_sistema;
    getrusage(RUSAGE_SELF, &comeco);   
    */ 

    fscanf(f, "%d %d %d", &N, &Xa, &Xb); 
    Ponto *A = cria_ponto(Xa, 0); Ponto *B = cria_ponto(Xb, 0);
    

    Ponto **pts = cria_vetor_de_pontos(N); 

    for(int i = 0; i<N; i++){
        fscanf(f, "%d %d", &x, &y);
        pts[i] = cria_ponto(x,y); 
        
    }

    ordena_todos_os_pontos(pts, N);    

    
    resultado = analisa_todos_os_pontos(pts, N, A, B);
    printf("%d\n", resultado);
    fprintf(output, "%d", resultado);
    

    /*
    getrusage(RUSAGE_SELF, &fim); 
    tempo_usuario = (double)(fim.ru_utime.tv_sec-comeco.ru_utime.tv_sec)+(double)(fim.ru_utime.tv_usec-comeco.ru_utime.tv_usec)/1000000.0;
    tempo_sistema = (double)(fim.ru_stime.tv_sec-comeco.ru_stime.tv_sec)+(double)(fim.ru_stime.tv_usec-comeco.ru_stime.tv_usec)/1000000.0;
    printf("Tempo sistema: %lf (s)\nTempo usuario: %lf (s)\n", tempo_sistema, tempo_usuario); 
    */ 

    destroi_vetor_de_pontos(pts, N);
    destroi_ponto(A); destroi_ponto(B);
    
    fclose(f);
    return 0;
}


