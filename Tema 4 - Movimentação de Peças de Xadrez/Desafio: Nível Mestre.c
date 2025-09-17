#include <stdio.h>

void moverTorre(int casas) {
    if (casas <= 0) return;
    printf("Direita\n");
    moverTorre(casas - 1);
}

void moverBispo(int casas) {
    if (casas <= 0) return;
    for (int v = 0; v < 1; v++) {
    for (int h = 0; h < 1; h++) {
            printf("Cima, Direita\n");
        }
    }

    moverBispo(casas - 1);
}

void moverRainha(int casas) {
    if (casas <= 0) return;
    printf("Esquerda\n");
    moverRainha(casas - 1);
}

void moverCavalo() {
    int movimentosCima = 2;   
    int movimentosDireita = 1;   

    printf("*** Movimento do Cavalo ***\n");

    for (int i = 0; i < movimentosCima; i++) {
        printf("Cima\n");
        if (i == 0) {
            continue;
        }
       
    
    for (int j = 0; j < 2; j++) {
        if (j >= movimentosDireita) {
            break;
        }
        printf("Direita\n");
    }
}
}

int main() {
    printf("*** Movimento da Torre ***\n");
    moverTorre(5); 
    printf("\n");

    printf("*** Movimento do Bispo ***\n");
    moverBispo(5);
    printf("\n");

    printf("*** Movimento da Rainha ***\n");
    moverRainha(8);
    printf("\n");

    moverCavalo(); 

    return 0;
}