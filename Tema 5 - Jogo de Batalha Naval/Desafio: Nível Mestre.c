#include <stdio.h>
#include <stdlib.h> 

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
        if (colunaH + i < Tam)
            Tabuleiro[linhaH][colunaH + i] = NavioHorizontal[i];
    }

    for (int i = 0; i < Nav; i++) {
        if (linhaV + i < Tam)
            Tabuleiro[linhaV + i][colunaV] = NavioVertical[i];
    }

    for (int i = 0; i < Nav; i++) {
        if (linhaD + i < Tam && colunaD + i < Tam)
            Tabuleiro[linhaD + i][colunaD + i] = NavioDiagonal1[i];
    }

    for (int i = 0; i < Nav; i++) {
        if (linhaD1 + i < Tam && colunaD1 - i >= 0)
            Tabuleiro[linhaD1 + i][colunaD1 - i] = NavioDiagonal2[i];
    }

    int Cone[5][5] = {0};
    int Cruz[5][5] = {0};
    int Octaedro[5][5] = {0};

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j >= 2 - i && j <= 2 + i)
             Cone[i][j] = 1;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2)
             Cruz[i][j] = 1;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2)
            Octaedro[i][j] = 1;
        }
    }

    int origemConeX = 4, origemConeY = 4;  
    int origemCruzX = 5, origemCruzY = 5;  
    int origemOctX  = 6, origemOctY  = 3;  

    int tamanho = 5;
    int offset = tamanho / 2;


    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (Cone[i][j] == 1) {
                int x = origemConeX + (i - offset);
                int y = origemConeY + (j - offset);
                if (x >= 0 && x < Tam && y >= 0 && y < Tam && Tabuleiro[x][y] == 0)
                    Tabuleiro[x][y] = 2;
            }
            if (Cruz[i][j] == 1) {
                int x = origemCruzX + (i - offset);
                int y = origemCruzY + (j - offset);
                if (x >= 0 && x < Tam && y >= 0 && y < Tam && Tabuleiro[x][y] == 0)
                    Tabuleiro[x][y] = 2;
            }
            if (Octaedro[i][j] == 1) {
                int x = origemOctX + (i - offset);
                int y = origemOctY + (j - offset);
                if (x >= 0 && x < Tam && y >= 0 && y < Tam && Tabuleiro[x][y] == 0)
                    Tabuleiro[x][y] = 2;
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