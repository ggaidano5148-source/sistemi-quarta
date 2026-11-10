#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct studente{
    int matr;
    char cognome[MAX];
    float inf, sis, tpsit;
}Studente;

Studente* creaNodo();
void stampaNodo(Studente* nodo);

int main(void){

    Studente * nodo = NULL;
    nodo = creaNodo();
    stampaNodo(nodo);
    free(nodo);

    return 0;
}

void stampaNodo(Studente* nodo){
    printf("\nSTAMPA STUDENTE\n");
    printf("%d\t%s\t%.2f\t%.2f\t%.2f\n", nodo->matr, nodo->cognome, nodo->inf, nodo->sis, nodo->tpsit); 
    //il \t fa una tabulazione
}

Studente* creaNodo(){

    Studente * pStu;
    int matr;
    float info sistemi, tecn;
    char cogn[MAX];

    printf("matricola > ")
    scanf("%d", &matr);
    fflush(stdin);
    printf("cognome > ")
    gets(cogn);
    printf("info > ")
    scanf("%f", &info);
    printf("sis > ")
    scanf("%f", &sistemi);
    printf("tpsit > ")
    scanf("%f", &tecn);

    pStu = (Studente*) malloc(sizeof(Studente));
    pStu->matr = matr;
    pStu->inf = info;
    pStu->sis = sistemi;
    pStu->tpsit = tecn;
    strcpy(pStu->cognome, cogn);

    return pStu;
}
