#include <stdio.h>
#define TAM_TABULEIRO 10  // Tamanho do tabuleiro (10x10)
#define TAM_NAVIO 3       // Tamanho fixo dos navios

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0}; // Inicializa tabuleiro com 0 (água)
    
    // Coordenadas iniciais dos navios
    int navioH_linha = 2;  // linha do navio horizontal
    int navioH_coluna = 4; // coluna inicial do navio horizontal
    
    int navioV_linha = 5;  // linha inicial do navio vertical
    int navioV_coluna = 7; // coluna do navio vertical
    
    // Posicionamento do navio horizontal
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
    
    // Posicionamento do navio vertical
    if (navioV_linha + TAM_NAVIO <= TAM_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[navioV_linha + i][navioV_coluna] == 3) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao) {
            printf("Navio vertical:\n");
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[navioV_linha + i][navioV_coluna] = 3;
                printf("Parte %d: (%d, %d)\n", i + 1, navioV_linha + i, navioV_coluna);
            }
            printf("\n");
        } else {
            printf("Navio vertical se sobrepõe a outro navio!\n");
            return 1;
        }
    } else {
        printf("Navio vertical não cabe nas coordenadas fornecidas!\n");
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
