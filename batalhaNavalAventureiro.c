
#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define TAM_NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se uma posição é válida e não está ocupada
int posicaoValida(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM)
        return 0;

    if (tabuleiro[linha][coluna] != AGUA)
        return 0;

    return 1;
}

// Função para posicionar um navio
// deltaLinha e deltaColuna definem a direção (horizontal, vertical ou diagonal)
int posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna,
                     int deltaLinha, int deltaColuna) {

    // Primeiro valida todas as posições
    for (int i = 0; i < TAM_NAVIO; i++) {
        int novaLinha = linha + i * deltaLinha;
        int novaColuna = coluna + i * deltaColuna;

        if (!posicaoValida(tabuleiro, novaLinha, novaColuna)) {
            return 0; // posição inválida ou sobreposição
        }
    }

    // Depois posiciona o navio
    for (int i = 0; i < TAM_NAVIO; i++) {
        int novaLinha = linha + i * deltaLinha;
        int novaColuna = coluna + i * deltaColuna;
        tabuleiro[novaLinha][novaColuna] = NAVIO;
    }

    return 1;
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("Tabuleiro 10x10:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Posiciona dois navios horizontais/verticais
    posicionarNavio(tabuleiro, 1, 1, 0, 1); // Horizontal
    posicionarNavio(tabuleiro, 4, 3, 1, 0); // Vertical

    // Posiciona dois navios diagonais
    posicionarNavio(tabuleiro, 6, 0, 1, 1);  // Diagonal principal
    posicionarNavio(tabuleiro, 0, 8, 1, -1); // Diagonal secundária

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
