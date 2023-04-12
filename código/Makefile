all: analise.o ponto.o vetor.o 
	gcc main.c analise.o ponto.o vetor.o -o main

analise.o: analise.c analise.h ponto.o vetor.o
	gcc -c analise.c  

ponto.o: ponto.h ponto.c 
	gcc -c ponto.c

vetor.o: vetor.h vetor.c ponto.o
	gcc -c vetor.c  

remove:
	rm *.o main

