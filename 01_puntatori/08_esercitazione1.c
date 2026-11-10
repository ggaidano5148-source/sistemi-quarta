#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

void visualizzaMenu();
int verificaPalindroma(char* str);
void concatenaStringhe(char* str1, char* str2);
void invertiStringa(char* str);
void generaStringaCasuale(char* str, int* dimStr, char min, char max);

int main(void){
    int* scelta;
    //es 1
    char *str;
    //es 6
    char *str1;
    char *str2;
    int* dimStr // dimensione dela stringa casuale

    srand(time(NULL));
    scelta = (int*)malloc(sizeof(int));
    do{
        visualizzaMenu();
        printf("scelta > ");
        scanf("%d", scelta);

        system("@cls||clear"); // pulisce la console 
        fflush(stdin);

        switch(*scelta){
            case 1:
                str = (char*)malloc(sizeof(char) * MAX);
                /*data in input una stringa, verificare se è palindroma */
                printf("inserisci stringa > ");
                gets(str);
                //rialloco per ottimizare spazio in memoria
                str = (char*)realloc(str, sizeof(char) * (strlen(str) + 1));
                /*printf("stringa inserita >%s\n", str);
                printf("dimensione %d\n", strlen(str));*/
                if(verificaPalindroma(str) == 1)
                    printf("la stringa %s e' palindroma\n", str);
                else
                    printf("la stringa %s non e' palindroma\n", str);
                free(str);
            break;
            case 2:
            str = (char*)malloc(sizeof(char) * MAX);
                /*data in input una stringa, verificare se è palindroma */
                printf("inserisci stringa > ");
                gets(str);
                invertiStringa(str);
                printf("il contenuto della stringa inversa: %s\n", str);
                free(str);
            break;
            case 6:
                /*date due stringhe in input, concatenarle e stamparle*/
                if(str1 != NULL && str2 != NULL){
                    str1 = (char*)malloc(sizeof(char) * MAX);
                    str2 = (char*)malloc(sizeof(char) * MAX);
                    printf("inserisci la prima stringa >");
                    gets(str1);
                    printf("inserisci la seconda stringa >");
                    gets(str2);
                    str1 = (char*)realloc(str1, sizeof(char) * (strlen(str1) + strlen(str2) + 1));
                    str2 = (char*)realloc(str2, sizeof(char) * (strlen(str2) + 1));
                    concatenaStringhe(str1, str2);
                    printf("%s\n", str1);
                }
                free(str1);
                free(str2);
            break;
            case 7:
                dimStr = (int*) malloc(sizeof(int));
                printf("inserire dimensione stringa > ");
                scanf("%d", dimStr);
                str = (char*) malloc(sizeof(char)*(*dimStr) + 1);
                *(str + strlen(str)) = '\0';
                generaStringaCasuale(str, dimStr, 'a', 'z');
                printf("stringa finale %s\n", str);
                free(dimStr);
            break;
            case 0:
                printf("Arrivederci....\n");
            break;
            default:
                printf("opzione non disponibile\n");
        }
    }while(*scelta != 0);
    free(scelta);
    return 0;
}

void visualizzaMenu(){
    printf("\nESERCITAZIONE - PUNTATORI\n");
    printf("1. verifica se una stringa e' palindroma\n");
    printf("2. inverti una stringa\n");
    printf("3. conta vocali e consonanti di una stringa\n");
    printf("4. cerca valore in un vettore\n");
    printf("5. calcola minimo, massimo e media di un vettore\n");
    printf("6. concatena due stringhe\n");
    printf("7. caricare stringa casuale (a-z) e trasformare in maiuscolo il contenuto\n");
    printf("0. esci\n");
}

int verificaPalindroma(char* str){
    // 'a' 'n' 'n' 'a'
    // 'l' 'u' 'c' 'a' 
    char* inizio;
    char* fine;
    inizio = str;
    fine = inizio + (strlen(str) - 1);
    while(fine < inizio && *inizio == *fine){
        inizio++;
        fine--;
    }
    if(*inizio == *fine)
        return 1;
    return 0;
}

void concatenaStringhe(char* str1, char* str2){
    char *inizio = str1 + strlen(str1);

    for(; *str2 != '\0' ; str2++, inizio++){
        *inizio = *str2;
    }
    *inizio = '\0';
}

void invertiStringa(char* inizio){
     char* fine = inizio + (strlen(inizio) - 1);
     char* aus = (char*) malloc(sizeof(char));
     while(inizio < fine){
        *aus = *inizio;
        *inizio = *fine;
        *fine = *aus;

        inizio++;
        fine--;
     }
}

void generaStringaCasuale(char* str, int* dimStr, char min, char max){
    int* i;
    i = (int*) malloc(sizeof(int));

    for(*i = 0; *i < *dimStr, (*i)++){
        *(str + *i) = ((rand() % (max - min + 1)) + min);    
    }
}