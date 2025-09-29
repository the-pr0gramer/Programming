#include <stdio.h>

int main() {
    int Tam = 10; 
    int Nav = 3; 
    int Water = 0;
    int Nav2 = 3;

    int Tabuleiro[10][10];  

    for (int i = 0; i < Tam; i++) {
        for (int j = 0; j < Tam; j++) {
            Tabuleiro[i][j] = Water;
        }
    }

    int NavioHorizontal[3] = {Nav2, Nav2, Nav2};
    int NavioVertical[3] = {Nav2, Nav2, Nav2};

    int linhaH = 2, colunaH = 1;
    int linhaV = 5, colunaV = 7;
 
    for (int i = 0; i < Nav; i++) {
        if (colunaH + i < Tam) {
            Tabuleiro[linhaH][colunaH + i] = NavioHorizontal[i];
        }
    }

    for (int i = 0; i < Nav; i++) {
        if (linhaV + i < Tam) {  
            if (Tabuleiro[linhaV + i][colunaV] == Water) {
                Tabuleiro[linhaV + i][colunaV] = NavioVertical[i];
            }
        }
    }

    printf("*** Tabuleiro de Batalha Naval ***\n");
    for (int i = 0; i < Tam; i++) {
        for (int j = 0; j < Tam; j++) {
            printf("%d ", Tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}