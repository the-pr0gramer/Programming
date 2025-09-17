#include <stdio.h>

int main() {
    int i; 
    int Torre = 5;

    printf("*** Movimento da Torre ***\n");
    for(i = 1; i <= Torre; i++) {
        printf("Direita (Casa %d)\n", i);
    }
    printf("\n");

    int j = 1;
    int Bispo = 5;

    printf("*** Movimento do Bispo ***\n");
    while(j <= Bispo) {
        printf("Cima, Direita (Casa %d)\n", j);
        j++;
    }
    printf("\n");

    int k = 1;
    int Rainha = 8;

    printf("*** Movimento da Rainha ***\n");
    do {
        printf("Esquerda (Casa %d)\n", k);
        k++;
    } while(k <= Rainha);
    printf("\n");

    return 0;
}