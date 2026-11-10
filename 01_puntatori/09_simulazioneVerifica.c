#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void visualizzaMenu(char* sc);
void caricaraArrayInt(int* array, int* dim, int min, int max);
void stampaArrayInt(int* array, int* dim);
void caricaMultipli(int* array, int* dim, int* x);
void caricaArrayChar(char* array, char* dim, char min, char max);
void stampaArrayChar(char* array, char* dim);
void gnomeSort(char* v, char* n);
int* contaVocali(char* str);

int main(void){
    char* scelta;
    //es1
    int* pv;
    int* dim;
    int* x;
    //es2
    char* pC;
    //es3
    int* vocali;

    srand(time(NULL));
    scelta = (char*) malloc(sizeof(char));
    do{
        visualizzaMenu(scelta);
        system("@cls||clear");
        fflush(stdin);

        switch(*scelta){
            case 'a':
            case 'A':
            /*Dopo aver allocato dinamicamente un array di interi, la cui dimensione è chiesta in input,
            caricare il contenuto con valori casuali generati tra -100 e 100.
            Sviluppare una procedura void caricaMultipli passando come parametro l’array, la sua
            lunghezza ed un valore intero X (riferimento multipli).
            Il sottoprogramma dovrà caricare e stampare un secondo array che conterrà soltanto i
            multipli di X. OTTIMIZZARE L’OCCUPAZIONE IN MEMORIA */
                dim = (int*) malloc(sizeof(int));
                do{
                    printf("dimensione array > ");
                    scanf("%d", dim);
                }while(*dim < 1);
                pv = (int*) malloc(sizeof(int) * (*dim));
                x = (int*) malloc(sizeof(int));

                printf("inserisci il valore x > ");
                scanf("%d", x);

                caricaraArrayInt(pv, dim, -100, 100);
                stampaArrayInt(pv, dim);
                
                caricaMultipli(pv, dim, x);

                free(dim);
                free(pv);
                free(x);
                break;
            case 'b':
            case 'B':
            /*
            Dopo aver allocato dinamicamente un array di char, la cui dimensione è chiesta in input,
            caricare il contenuto con valori casuali generati tra ‘a’ e ‘z’.
            Sviluppare una procedura void gnomeSort passando come parametro l’array e la sua
            lunghezza che si occupi di ordinare il contenuto del vettore. Applicare l’algoritmo di
            ordinamento (non è consentito l’utilizzo di indici) e visualizzare il risultato.*/
                dim = (int*) malloc(sizeof(int));
                do{
                    printf("dimensione array > ");
                    scanf("%d", dim);
                }while(*dim < 1);
                pC = (char*) malloc(sizeof(char) * (*dim));
                caricaArrayChar(pC, dim, 'a', 'z');
                stampaArrayChar(pC, dim);
                gnomeSort(pC, dim);
                printf("Array ordinato:\n");
                stampaArrayChar(pC, dim);
                free(dim);
                free(pC);
                break;
            case 'c':
            case 'C':
            /*
            Dopo aver allocato dinamicamente un array di char chiedere in input una stringa e salvarla.
            Sviluppare una procedura int * contaVocali, passando come parametro la stringa il cui
            spazio di allocazione è già stato ottimizzato, cui scopo è quello di restituire al main il totale
            delle vocali presenti all’interno della porzione di stringa racchiusa tra *
            Stampare infine il risultato “Il totale delle vocali presenti nella sotto stringa è ...”
            ES : “ Ciao 4 *INF questa e’ la prima verifica* di sistemi e reti ”
             “Il totale delle vocali presenti nella sotto stringa è: 12“*/
                pC= (char*) malloc(sizeof(char) * 1000);
                printf("stringa > ");
                gets(pC);
                pC = (char*) realloc(pC, sizeof(char) * (strlen(pC) + 1));
                vocali = contaVocali(pC);
                printf("il totale delle vocali presenti nella sotto stringa e' %d\n", *vocali);
                free(vocali);
                free(pC);
                break;
        }
    }while(*scelta != 'q');
    free(scelta);
    printf("Arrivederci...\n");

    return 0;
}

void visualizzaMenu(char* sc){
    printf("===SIMULAZIONE VERIFICA===\n");
    printf("a. svolgi es 1\n");
    printf("b. svolgi es 2\n");
    printf("c. svolgi es 3\n");
    printf("q. termina\n");
    printf("Scelta > ");
    scanf("%c", sc);
}

//es1
void caricaraArrayInt(int* array, int* dim, int min, int max){
    int* i = (int*) malloc(sizeof(int));
    *i = 0;
    for(; *i < *dim; *(i)++)
        *(array + *i) = min + (rand() % (max - min + 1));
    free(i);
}

void stampaArrayInt(int* array, int* dim){
    int* i = (int*) malloc(sizeof(int));
    *i = 0;
    for(; *i < *dim; *(i)++)
        printf("%d", *(array + *i));
    printf("\n");
    free(i);
}

void caricaMultipli(int* array, int* dim, int* x){
    int* vMul = (int*) malloc(sizeof(int) * (*dim));
    int* cnt = (int*) calloc(1, sizeof(int));
    int* i = (int*) calloc(1, sizeof(int));

    for(; *i < *dim; (*i)++){
        if(*(array + *i) % *x == 0){

            *(vMul + *cnt) = *(array + *i);
            (*cnt)++;
        }
    }
    printf("multipli d %d:\n", *x);
    vMul = (int*) realloc(vMul, (*cnt) * sizeof(int));
    stampaArrayInt(vMul, cnt);

    free(vMul);
    free(cnt);
    free(i);
}

void gnomeSort(char* v, char* n)
{
    int* index = (int*) calloc(1, sizeof(int));
    char* tmp;

    while(*index < *n) {
        if(*index == 0) {
            (*index)++;
        }
        if(*(v + *index) >= *(v + (*index - 1))) 
        {
            (*index)++;
        } else {
            tmp = (char*) malloc(sizeof(char));
            *tmp = *(v + *index);
            *(v + *index) = *(v + (*index - 1));
            *(v + (*index - 1)) = *tmp;
            (*index) -- ;
            free(tmp);
        }
    }
    free(index);
}

//es 3
int* contaVocali(char* str){
    int * cnt = (int*) calloc(1, sizeof(int));
    int* second = (int*) calloc(1, sizeof(int));

    while(*str != '\0' || (*second < 2)){
        if(*second == 1){
            if(*str == '*')
                (*second)++;
            else{
                if( *str == 'a' ||*str == 'e' ||*str == 'i' ||*str == 'o' ||*str == 'u'){
                    (*cnt)++;
                }
                str++;
            }
        }
        else{
            if(*str == '*')
                (*second)++;
            str++;
        }
    }
    free(second);
    return cnt;
} 

