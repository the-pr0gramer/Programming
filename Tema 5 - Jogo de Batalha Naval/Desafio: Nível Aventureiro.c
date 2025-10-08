#include <stdio.h>

int main() {
    int Tam = 10;
    int Nav = 3;
    int Water = 0;

    int Tabuleiro[10][10];

    for (int i = 0; i < Tam; i++) {
        for (int j = 0; j < Tam; j++) {
            Tabuleiro[i][j] = Water;
        }
    }

    int NavioHorizontal[3] = {3, 3, 3};
    int NavioVertical[3]   = {3, 3, 3};
    int NavioDiagonal1[3]  = {3, 3, 3};
    int NavioDiagonal2[3]  = {3, 3, 3};

    int linhaH = 2, colunaH = 1;  
    int linhaV = 5, colunaV = 7; 
    int linhaD = 3, colunaD = 3; 
    int linhaD1 = 7, colunaD1 = 8;

    for (int i = 0; i < Nav; i++) {
        if (colunaH + i < Tam) {
            Tabuleiro[linhaH][colunaH + i] = NavioHorizontal[i];
        }
    }

    for (int i = 0; i < Nav; i++) {
        if (linhaV + i < Tam && Tabuleiro[linhaV + i][colunaV] == Water) {
            Tabuleiro[linhaV + i][colunaV] = NavioVertical[i];
        }
    }

    for (int i = 0; i < Nav; i++) {
        if (linhaD + i < Tam && colunaD + i < Tam && Tabuleiro[linhaD + i][colunaD + i] == Water) {
            Tabuleiro[linhaD + i][colunaD + i] = NavioDiagonal1[i];
        }
    }

    for (int i = 0; i < Nav; i++) {
        if (linhaD1 + i < Tam && colunaD1 - i >= 0 && Tabuleiro[linhaD1 + i][colunaD1 - i] == Water) {
            Tabuleiro[linhaD1 + i][colunaD1 - i] = NavioDiagonal2[i];
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