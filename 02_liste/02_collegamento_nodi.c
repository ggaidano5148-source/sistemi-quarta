#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

typedef struct dipendente{
    char matricola[5];
    char cognome[MAX];
    int eta;
    struct dipendente *next;  //puntatore al nodo successivo
}Dipendenti;

Dipendenti* creaDipendente(char cogn[], int eta);
void stampaLista(Dipendenti* head);

int main(void){

    Dipendenti *head;
    Dipendenti *n1, *n2, *n3;
    srand(time(NULL));

    //creazione dei nodi ancora scollegati
    n1 = creaDipendente("Rossi", 35);
    n2 = creaDipendente("Bianchi", 41);
    n3 = creaDipendente("Verdi", 28);

    //collegamento nodi: n1->n2->n3->NULL
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;
    head = n1;

    stampaLista(head);
    return 0;
}

Dipendenti* creaDipendente(char cogn[], int eta){
    Dipendenti* nodo;
    char matr[5];
    int i;

    //carico casualmente matricola
    for(i = 0; i < 2; i++)
        matr[i] = 'A' + (rand() % ('Z' - 'A' + 1));
    for(i = 2; i < 4; i++)
        matr[i] = '0' + rand() % 10;
    matr[4] = '\0';

    nodo = (Dipendenti*) malloc(sizeof(Dipendenti));
    strcpy(nodo->matricola, matr);
    strcpy(nodo->cognome, cogn);
    nodo->eta = eta;
    nodo->next = NULL;

    return nodo;
}

void stampaLista(Dipendenti* head){
    Dipendenti* pLista = head;
    if(head == NULL)
        printf("Lista VUOTA\n");
    else{
        printf("\nLista dipendenti");
        printf("Matr.\tCognome\t\tEta'\n");
        while(pLista != NULL){
            printf("%s\t%s\t\t%d\n", pLista->matricola, pLista->cognome, pLista->eta);
            pLista = pLista->next;
        }
    }
}