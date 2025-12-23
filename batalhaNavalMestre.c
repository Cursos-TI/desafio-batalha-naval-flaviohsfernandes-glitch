#include <stdio.h>

#define TAM_TAB 10
#define TAM_HAB 5

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    int i, j;
    for (i = 0; i < TAM_TAB; i++) {
        for (j = 0; j < TAM_TAB; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para aplicar uma habilidade no tabuleiro
void aplicarHabilidade(
    int tabuleiro[TAM_TAB][TAM_TAB],
    int habilidade[TAM_HAB][TAM_HAB],
    int origemLinha,
    int origemColuna
) {
    int i, j;
    int offset = TAM_HAB / 2;

    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {

            if (habilidade[i][j] == 1) {
                int linhaTab = origemLinha + i - offset;
                int colunaTab = origemColuna + j - offset;

                // Verifica limites do tabuleiro
                if (linhaTab >= 0 && linhaTab < TAM_TAB &&
                    colunaTab >= 0 && colunaTab < TAM_TAB) {

                    // Marca área afetada (sem sobrescrever navios)
                    if (tabuleiro[linhaTab][colunaTab] == 0) {
                        tabuleiro[linhaTab][colunaTab] = 5;
                    }
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TAB][TAM_TAB] = {0};
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    int i, j;

    // Exemplo de navios
    tabuleiro[2][2] = 3;
    tabuleiro[5][5] = 3;
    tabuleiro[7][3] = 3;

    /* =========================
       Construção da habilidade CONE
       ========================= */
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            if (j >= (TAM_HAB / 2 - i) && j <= (TAM_HAB / 2 + i)) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    /* =========================
       Construção da habilidade CRUZ
       ========================= */
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    /* =========================
       Construção da habilidade OCTAEDRO (losango)
       ========================= */
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            if ((i - TAM_HAB / 2) + (j - TAM_HAB / 2) <= TAM_HAB / 2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // Aplicando habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 3, 3);
    aplicarHabilidade(tabuleiro, cruz, 6, 6);
    aplicarHabilidade(tabuleiro, octaedro, 8, 2);

    // Exibindo resultado final
    printf("Tabuleiro final:\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}

