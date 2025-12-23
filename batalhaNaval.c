#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    /* 
       Declaração do tabuleiro 10x10.
       Todas as posições começam com 0, representando água.
    */
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    /* Inicializa o tabuleiro com água */
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    /*
       Vetores que representam os navios.
       Cada posição do vetor contém o valor 3, indicando parte do navio.
    */
    int navioHorizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAM_NAVIO]   = {NAVIO, NAVIO, NAVIO};

    /*
       Coordenadas iniciais dos navios
       (definidas diretamente no código)
    */
    int linhaH = 2, colunaH = 1;  // Navio horizontal
    int linhaV = 5, colunaV = 6;  // Navio vertical

    /*
       Validação simples para garantir que o navio horizontal
       cabe no tabuleiro
    */
    if (colunaH + TAM_NAVIO <= TAM_TABULEIRO) {
        /* Posiciona o navio horizontal no tabuleiro */
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
        return 1;
    }

    /*
       Validação simples para garantir que o navio vertical
       cabe no tabuleiro e não se sobrepõe a outro navio
    */
    if (linhaV + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            /* Verifica sobreposição */
            if (tabuleiro[linhaV + i][colunaV] == NAVIO) {
                printf("Erro: Sobreposição de navios detectada.\n");
                return 1;
            }
            tabuleiro[linhaV + i][colunaV] = navioVertical[i];
        }
    } else {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
        return 1;
    }

    /*
       Exibição do tabuleiro no console
       0 representa água
       3 representa navio
    */
    printf("Tabuleiro Batalha Naval (10x10):\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
