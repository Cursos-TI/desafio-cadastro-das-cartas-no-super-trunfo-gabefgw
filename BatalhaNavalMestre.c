#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define TAM_HAB 5

void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;
}

void posicionarNavios(int tabuleiro[TAM][TAM]) {
    // Horizontal (linha 2, col 1 a 3)
    for (int i = 1; i <= 3; i++)
        tabuleiro[2][i] = 3;

    // Vertical (coluna 6, linha 5 a 7)
    for (int i = 5; i <= 7; i++)
        tabuleiro[i][6] = 3;
}

void criarCone(int hab[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= TAM_HAB / 2 - i && j <= TAM_HAB / 2 + i)
                hab[i][j] = 1;
            else
                hab[i][j] = 0;
        }
    }
}

void criarCruz(int hab[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                hab[i][j] = 1;
            else
                hab[i][j] = 0;
        }
    }
}

void criarOctaedro(int hab[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2) {
                hab[i][j] = 1; // Área afetada pela habilidade
            } else {
                hab[i][j] = 0; // Fora da área
            }
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemX, int origemY) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int x = origemX - TAM_HAB / 2 + i;
            int y = origemY - TAM_HAB / 2 + j;

            if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[x][y] == 0)
                    tabuleiro[x][y] = 5;
            }
        }
    }
}

void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    aplicarHabilidade(tabuleiro, cone, 1, 2);      // Cone em (1,2)
    aplicarHabilidade(tabuleiro, cruz, 5, 5);      // Cruz em (5,5)
    aplicarHabilidade(tabuleiro, octaedro, 7, 2);  // Octaedro em (7,2)

    imprimirTabuleiro(tabuleiro);

    return 0;
}
