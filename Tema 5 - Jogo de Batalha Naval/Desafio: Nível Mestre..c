#include <stdio.h>
#include <string.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5
#define AREA_AFETADA 5
#define AGUA 0

void imprimir_tabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; ++i) {
        for (int j = 0; j < TAM_TABULEIRO; ++j) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void construir_cone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int r = 0; r < TAM_HABILIDADE; ++r)
        for (int c = 0; c < TAM_HABILIDADE; ++c)
            matriz[r][c] = 0;

    for (int r = 0; r < TAM_HABILIDADE; ++r) {
        int raio = (r <= centro) ? r : centro;
        for (int c = centro - raio; c <= centro + raio; ++c) {
            if (c >= 0 && c < TAM_HABILIDADE) {
                matriz[r][c] = 1;
            }
        }
    }
}

void construir_cruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int r = 0; r < TAM_HABILIDADE; ++r)
        for (int c = 0; c < TAM_HABILIDADE; ++c)
            matriz[r][c] = 0;

    for (int i = 0; i < TAM_HABILIDADE; ++i) {
        matriz[centro][i] = 1;
        matriz[i][centro] = 1;
    }
}

void construir_octaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int r = 0; r < TAM_HABILIDADE; ++r)
        for (int c = 0; c < TAM_HABILIDADE; ++c) {
            int dr = (r > centro) ? r - centro : centro - r;
            int dc = (c > centro) ? c - centro : centro - c;
            if (dr + dc <= centro) matriz[r][c] = 1;
            else matriz[r][c] = 0;
        }
}

void aplicar_habilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                        int habilidade[TAM_HABILIDADE][TAM_HABILIDADE],
                        int origem_linha, int origem_coluna,
                        int usar_centro) {
    int centro = TAM_HABILIDADE / 2;
    for (int r = 0; r < TAM_HABILIDADE; ++r) {
        for (int c = 0; c < TAM_HABILIDADE; ++c) {
            if (habilidade[r][c] != 1) continue;

            int linha_tab, coluna_tab;
            if (usar_centro) {
                linha_tab = origem_linha + (r - centro);
                coluna_tab = origem_coluna + (c - centro);
            } else {
                linha_tab = origem_linha + r;
                coluna_tab = origem_coluna + (c - centro);
            }

            if (linha_tab >= 0 && linha_tab < TAM_TABULEIRO && coluna_tab >= 0 && coluna_tab < TAM_TABULEIRO) {
                if (tabuleiro[linha_tab][coluna_tab] == AGUA) {
                    tabuleiro[linha_tab][coluna_tab] = AREA_AFETADA;
                }
            }
        }
    }
}

int main(void) {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    for (int i = 0; i < TAM_TABULEIRO; ++i)
        for (int j = 0; j < TAM_TABULEIRO; ++j)
            tabuleiro[i][j] = AGUA;

    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    construir_cone(cone);
    construir_cruz(cruz);
    construir_octaedro(octaedro);

    int origem_cone_linha = 0, origem_cone_coluna = 2;
    int origem_cruz_linha = 7, origem_cruz_coluna = 2;
    int origem_octa_linha = 5, origem_octa_coluna = 7;

    aplicar_habilidade(tabuleiro, cone, origem_cone_linha, origem_cone_coluna, 0);
    aplicar_habilidade(tabuleiro, cruz, origem_cruz_linha, origem_cruz_coluna, 1);
    aplicar_habilidade(tabuleiro, octaedro, origem_octa_linha, origem_octa_coluna, 1);

    printf("Legenda: 0 = água, 5 = área de habilidade\n\n");
    imprimir_tabuleiro(tabuleiro);

    return 0;
}