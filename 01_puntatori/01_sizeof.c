#include <stdio.h>

int main(void)
{
    int i;        //0x005  esempi di indirizzo
    char c = 'c';   //0x00A

    int* pi; //0x01B


    i = 10;
    printf("la variabile occupa %d byte\n", sizeof(i));
    printf("la tipo char occupa %d byte in memoria\n", sizeof(char));
    printf("la tipo double occupa %d byte in memoria\n", sizeof(double));
    printf("la tipo puntatore occupa %d byte in memoria\n", sizeof(pi));

    printf("L'indirizzo di i e' %p e continene %d\n", &i, i);
    printf("L'indirizzo di c e' %p e continene %c\n", &c, c);
    printf("L'indirizzo di pi e' %p e continene %p\n", &pi, pi);



    return 0;
}