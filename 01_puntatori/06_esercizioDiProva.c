#include <stdio.h>
#include <stdlib.h>
//dati 3 numeri calcolare la media
int main(void){

    int *n1;
    n1 = (int*) malloc(sizeof(int));
    printf("inserisci n1: ");
    scanf("%d", n1);

    int *n2;
    n2 = (int*) malloc(sizeof(int));
    printf("inserisci n2: ");
    scanf("%d", n2);

    int *n3;
    n3 = (int*) malloc(sizeof(int));
    printf("inserisci n3: ");
    scanf("%d", n3);

    float *media;
    media = (float*) malloc(sizeof(float));
    *media = (*n1+*n2+*n3)/3;

    printf("n1: %d\nn2: %d\nn3: %d\n", *n1, *n2, *n3);
    printf("media :%.2f", *media);

    return 0;
}