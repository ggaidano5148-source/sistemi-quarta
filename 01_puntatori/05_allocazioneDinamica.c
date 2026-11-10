#include <stdio.h>
#include <stdlib.h>

/*
memoria statica: stack
memoria dinamica: heap
 */

 void stampavet(int a[], int dim);

int main(void){

    int v[] = {1, 2, 3, 4, 5};
    
    /*int dimA = 5;
    int *dim;
    dim = (int) malloc(sizeof(int));
    *dim = 5;*/
    
    printf("array statico di %d elementi\n", dimA);
    stampavet(v, dimA);

    /* ALLOCAZIONE DINAMICA */
    int numElem = 10;
    int *p;

    /*MALLOC*/
    p = (int*) malloc(sizeof(int)*numElem);
    stampavet(p, numElem);

    /* CALLOC => calloc(numero celle per tipo, dimensione singolo elemento/tipo)*/
    p = (int) calloc(numElem, sizeof(int));
    stampavet(p, numElem);

    /* REALLOC => realloc(p, nuova dimensione)*/
    numElem = 15;
    p = realloc(p, numElem*sizeof(int));
    stampavet(p, numElem);

    /* FREE => free(indirizzo)*/
    free(p);

    return 0;
}

void stampavet(int a[], int dim){
    int i;
    for(i = 0; i < dim; i++){
        printf("v[%d]: %d - %p\n", i, a[i], &a[i]);
    }
}