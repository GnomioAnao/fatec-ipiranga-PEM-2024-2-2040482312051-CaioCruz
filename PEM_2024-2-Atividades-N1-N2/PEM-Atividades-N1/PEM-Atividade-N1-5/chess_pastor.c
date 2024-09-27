/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular           *
*          Prof. Carlos Veríssimo                         *                                  *                                                         *
*---------------------------------------------------------*
* Objetivo do Programa: Simulador Xeque-Pastor            *
*   ***PROGRAMA CODIFICADO DE FORMA LINEAR**              *          
* Data – 12/09/2024                                       * 
* Autor: Caio Lima da Cruz                             *
*--------------------------------------------------------*/

#include <stdio.h>

// Função para imprimir o tabuleiro de forma organizada
void imprimirTabuleiro(char tabuleiro[8][8]) {
    printf("  a b c d e f g h\n");
    printf("  ----------------\n");
    for (int i = 0; i < 8; i++) {
        printf("%d|", 8 - i); // Numeração das linhas de 8 a 1
        for (int j = 0; j < 8; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("|\n");
    }
    printf("  ----------------\n\n");
}

// Função para inicializar o tabuleiro com as peças na posição inicial
void inicializarTabuleiro(char tabuleiro[8][8]) {
    char temp[8][8] = {
        {'t', 'c', 'b', 'd', 'r', 'b', 'c', 't'}, // Pretas
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, // Brancas
        {'T', 'C', 'B', 'D', 'R', 'B', 'C', 'T'}
    };

    // Copia o tabuleiro inicial para o tabuleiro principal
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tabuleiro[i][j] = temp[i][j];
        }
    }
}

// Função para mover uma peça de uma posição para outra
void moverPeca(char tabuleiro[8][8], int origemX, int origemY, int destinoX, int destinoY) {
    tabuleiro[destinoX][destinoY] = tabuleiro[origemX][origemY];
    tabuleiro[origemX][origemY] = '.';
}

// Função principal (execução do jogo)
int main() {
    // Inicializa o tabuleiro
    char tabuleiro[8][8];
    inicializarTabuleiro(tabuleiro);
    printf("\n\n");
    printf("Tabuleiro inicial:\n");
    imprimirTabuleiro(tabuleiro);
     printf("\n\n");
     
    // Jogada #1 Brancas (Peão do Rei e2 para e4)
    moverPeca(tabuleiro, 6, 4, 4, 4);
    printf("Apos jogada #1 das Brancas (Peão do Rei e2 para e4):\n");
    imprimirTabuleiro(tabuleiro);
     printf("\n\n");

    // Jogada #1 Pretas (Peão do Rei e7 para e5)
    moverPeca(tabuleiro, 1, 4, 3, 4);
    printf("Apos jogada #1 das Pretas (Peão do Rei e7 para e5):\n");
    imprimirTabuleiro(tabuleiro);
     printf("\n\n");

    // Jogada #2 Brancas (Bispo do Rei f1 para c4)
    moverPeca(tabuleiro, 7, 5, 4, 2);
    printf("Apos jogada #2 das Brancas (Bispo do Rei f1 para c4):\n");
    imprimirTabuleiro(tabuleiro);
     printf("\n\n");

    // Jogada #2 Pretas (Cavalo da Dama b8 para c6)
    moverPeca(tabuleiro, 0, 1, 2, 2);
    printf("Apos jogada #2 das Pretas (Cavalo da Dama b8 para c6):\n");
    imprimirTabuleiro(tabuleiro);
     printf("\n\n");

    // Jogada #3 Brancas (Dama d1 para h5)
    moverPeca(tabuleiro, 7, 3, 3, 7);
    printf("Apos jogada #3 das Brancas (Dama d1 para h5):\n");
    imprimirTabuleiro(tabuleiro);
     printf("\n\n");

    // Jogada #3 Pretas (Cavalo do Rei g8 para f6)
    moverPeca(tabuleiro, 0, 6, 2, 5);
    printf("Após jogada #3 das Pretas (Cavalo do Rei g8 para f6):\n");
    imprimirTabuleiro(tabuleiro);
     printf("\n\n");

    // Jogada #4 Brancas (Dama h5 captura Peão f7 - Xeque Mate)
    moverPeca(tabuleiro, 3, 7, 1, 5);
    printf("Apos jogada #4 das Brancas (Dama h5 captura Peão f7 - Xeque Mate):\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}