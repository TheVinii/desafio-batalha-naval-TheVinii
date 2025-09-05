#include <stdio.h>
#define TAM_TABULEIRO 10  // Tamanho do tabuleiro (10x10)
#define TAM_NAVIO 3       // Tamanho fixo dos navios

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0}; // Inicializa tabuleiro com 0 (água)
    
    // Coordenadas iniciais dos navios
    int navioH_linha = 1, navioH_coluna = 2; // Horizontal
    int navioV_linha = 4, navioV_coluna = 6; // Vertical
    int navioD1_linha = 0, navioD1_coluna = 0; // Diagonal
    int navioD2_linha = 9, navioD2_coluna = 2; // Diagonal
    
    // Navio horizontal
    if (navioH_coluna + TAM_NAVIO <= TAM_TABULEIRO) {
        printf("Navio horizontal:\n");
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[navioH_linha][navioH_coluna + i] = 3; // Marca navio no tabuleiro
            printf("Parte %d: (%d, %d)\n", i + 1, navioH_linha, navioH_coluna + i);
        }
        printf("\n");
    } else {
        printf("Navio horizontal não cabe nas coordenadas fornecidas!\n");
        return 1;
    }
    
    // Navio vertical
    if (navioV_linha + TAM_NAVIO <= TAM_TABULEIRO) {
        printf("Navio vertical:\n");
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[navioV_linha + i][navioV_coluna] = 3;
            printf("Parte %d: (%d, %d)\n", i+1, navioV_linha + i, navioV_coluna);
            }
        printf("\n");
    } else {
        printf("Navio vertical não cabe nas coordenadas fornecidas!\n");
        return 1;
        }
        
        // Navio diagonal 1
    if (navioD1_linha + TAM_NAVIO <= TAM_TABULEIRO && navioD1_coluna + TAM_NAVIO <= TAM_TABULEIRO) {
        printf("Navio diagonal ↘:\n");
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[navioD1_linha + i][navioD1_coluna + i] = 3;
            printf("Parte %d: (%d, %d)\n", i+1, navioD1_linha + i, navioD1_coluna + i);
        }
        printf("\n");
    } else {
        printf("Navio diagonal não cabe nas coordenadas fornecidas!\n");
        return 1;
    }
    
    // Navio diagonal 2
    if (navioD2_linha - (TAM_NAVIO - 1) >= 0 && navioD2_coluna + TAM_NAVIO <= TAM_TABULEIRO) {
        printf("Navio diagonal ↗:\n");
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[navioD2_linha - i][navioD2_coluna + i] = 3;
            printf("Parte %d: (%d, %d)\n", i+1, navioD2_linha - i, navioD2_coluna + i);
        }
        printf("\n");
    } else {
        printf("Navio diagonal não cabe nas coordenadas fornecidas!\n");
        return 1;
    }
    
    // Exibição do tabuleiro
    printf("Tabuleiro de Batalha Naval:\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return 0;
}
