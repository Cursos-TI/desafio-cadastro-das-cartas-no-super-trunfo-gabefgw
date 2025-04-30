#include <stdio.h>


// TORRE

void moverTorre (int casasRestantes) {
    if (casasRestantes == 0)
        return;
    printf("Direita\n");
    moverTorre(casasRestantes - 1);    
}

// BISPO (Recursivo + Loop aninhado)

void moverBispoRecursivo(int casasRestantes) {
    if (casasRestantes == 0)
        return;
    printf("Cima Direita\n");
    moverBispoRecursivo(casasRestantes - 1);
} 

void moverBispoLoops(int passos) {
    printf("\nMovimento do bispo (com loops):\n");
    for (int i = 1; i <= passos; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == i)
                printf("Cima Direita\n");
        }
    }
}

// RAINHA

void moverRainha (int casasRestantes) {
    if (casasRestantes == 0)
    return;
    printf("Esquerda\n");
    moverRainha(casasRestantes - 1);
}

// CAVALO (Loops aninhados e controle de fluxo)

void moverCavalo () {
    printf("\nMovimento do Cavalo (em L)\n");
    //Simulando possíveis saltos em L para cima e para direita no tabuleiro 8x8
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            int novoX = x - 2;
            int novoY = y + 1;
            if (novoX = 0 || novoY > 7){
                continue; //movimento inválido
            }
            printf("De (%d,%d) para (%d,%d) Cima Cima Direita\n", x, y, novoX, novoY);
            if (novoX == 0 && novoY == 7) {
                break;
            }
        }
    }
}

int main () {

    int casasTorre = 5;
    int casasBispo = 5;
    int casasRainha = 8;

    printf("Movimento da Torre (recursivo):\n");
    moverTorre (casasTorre);   

    printf("\nMovimento do Bispo (recursivo):\n");
    moverBispoRecursivo (casasBispo);

    moverBispoLoops (casasBispo);

    printf("\nMovimento da Rainha (recursivo):\n");
    moverRainha (casasRainha);

    moverCavalo();

    return 0;
}