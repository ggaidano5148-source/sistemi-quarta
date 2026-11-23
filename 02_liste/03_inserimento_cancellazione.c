#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 30

typedef struct dipendente{
    char matricola[5];
    char cognome[MAX];
    int eta;
    struct dipendente *next;  //puntatore al nodo successivo
}Dipendenti;


Dipendenti * addOnHead(Dipendenti *head, char cogn[], int eta);
Dipendenti * addOnTail(Dipendenti *head, char cogn[], int eta); //sempre head perche lo scorriamofino all'ulitmo dove al posto di next = null mettiamo l'indirizzo di quello nuovo
Dipendenti * addByPos(Dipendenti *head, int pos, char cogn[], int eta);
Dipendenti * delByPos(Dipendenti *head, int pos);
Dipendenti * creaDipendente(char cogn[], int eta);
void showlist(Dipendenti *head);
int contaNodi(Dipendenti *head);


int main(void){
    Dipendenti * testa = NULL;
    srand(time(NULL));

    /*testa = addOnHead(testa, "Rossi", 34);
    testa = addOnHead(testa, "bianchi", 18);
    testa = addOnHead(testa, "gialli", 69);*/

    /*testa = addOnTail(testa, "Rossi", 34);
    testa = addOnTail(testa, "bianchi", 18);
    testa = addOnTail(testa, "gialli", 69);
    */

    testa = addByPos(testa, 2,  "Rossi", 34);
    testa = addByPos(testa, -10, "bianchi", 18);
    testa = addByPos(testa, 20, "gialli", 69);
    testa = addByPos(testa, 2, "verdi", 25);

    showlist(testa);
    testa = delByPos(testa, 1);
    showlist(testa);
    
    return 0;
}

Dipendenti * addOnHead(Dipendenti * head, char cogn[], int eta){
    Dipendenti * new;
    new = creaDipendente(cogn, eta);

    new->next = head;
    head = new;
    return head;
}

Dipendenti * addOnTail(Dipendenti *head, char cogn[], int eta){
    Dipendenti *new, *pLista;
    new = creaDipendente(cogn, eta);
    if(head == NULL)
        head = new;
    else{
        pLista = head;
        while(pLista->next != NULL){//mi fermo all'ultimo nodo
            pLista = pLista->next;
        }
            pLista->next = new;
    }
    return head;
}

Dipendenti * addByPos(Dipendenti *head, int pos, char cogn[], int eta) {
    Dipendenti * new, *pPrec;
    int i;
    if(pos <= 1 || head == NULL)
        head = addOnHead(head, cogn, eta);
    else{
        new = creaDipendente(cogn, eta);
        pPrec = head;
        for(i = 1; (i < pos -1 && pPrec->next != NULL); i++)
            pPrec = pPrec->next;
        new->next = pPrec->next;
        pPrec->next = new;
    }
    return head;
}

Dipendenti * delByPos(Dipendenti *head, int pos){

}


Dipendenti * creaDipendente(char cogn[], int eta)
{
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

void showlist(Dipendenti *head){
    Dipendenti* pLista = head;
    if(head == NULL)
        printf("Lista VUOTA\n");
    else{
        printf("\nLista dipendenti\n");
        printf("Matr.\tCognome\t\tEta'\n");
        while(pLista != NULL){
            printf("%s\t%s\t\t%d\n", pLista->matricola, pLista->cognome, pLista->eta);
            pLista = pLista->next;
        }
    }
}

int contaNodi(Dipendenti *head){
    int cont = 0;
    while(head != NULL){
        cont++;
        head = head->next;
    }
    return cont;
}