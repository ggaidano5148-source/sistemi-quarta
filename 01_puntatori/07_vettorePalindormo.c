#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
//dato un vettore di interi grande n(chiesto in input)
//a. caricare il vettore con valori casuali(1-10)
//b. dire se è palindromo
void caricaVet(int *v, int *dim);
void stampaVet(int *v, int *dim);
void controlloVet(int *v, int *dim);

int main(void){

    int *pv;
    int *dim; 
    srand(time(0));

    dim = (int*) malloc(sizeof(int));
    printf("inserisci dimensione array :");
    scanf("%d", dim);

    //allocazione spazio in memoria per array
    pv = (int*) malloc(sizeof(int) * (*dim));

    //caricamento array
    caricaVet(pv, dim);
    //stampa array
    stampaVet(pv, dim);
    //controllo palindromo
    controlloVet(pv, dim);

    return 0;
}

void caricaVet(int *v, int *dim){
    int *i = (int*) malloc(sizeof(int));
    for(*i = 0; *i< *dim; (*i)++){
        *(v+*i) = 1 + rand()%10;
    }
}

void stampaVet(int *v, int *dim){
    int *i = (int*) malloc(sizeof(int));
    for(*i = 0; *i< *dim; (*i)++){
        printf("v[%d]: %d\n", *i, *(v+*i));
    }
}

void controlloVet(int *v, int *dim){
    if((*dim % 2) == 0){
        
    }
    int *i = (int*) malloc(sizeof(int));
    for(*i = 0; *i< *dim; (*i)++){
        
    }
}