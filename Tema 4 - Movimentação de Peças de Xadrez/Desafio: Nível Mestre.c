#include <stdio.h>

void Torre (int C){
    if(C > 0){
        printf("Direita\n", C);
        Torre(C - 1);

    }
void Bispo(int C) {
    if ( <= 0) return;  // caso base

    // loop externo: movimento vertical
    for (int v = 0; v < 1; v++) {
        // loop interno: movimento horizontal
        for (int h = 0; h < 1; h++) {
            printf("Cima Direita\n");
        }
    }

    moverBispo(casas - 1);   // chamada recursiva
}

int main () {
    int Casas = 5;
    printf("*** Movimento da Torre ***\n");
    Torre (Casas);
    return 0;

    int Casas2 = 5;
    printf("*** Movimento do Bispo ***\n");
    Bispo (Casas2);
    return 0;

}