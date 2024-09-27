/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular 
*          Prof. Carlos Veríssimo                                    
*--------------------------------------------------------*
* Objetivo do Programa: Realiza o xeque pastor passo a passo.    
* Data - 05/09/2024                                                
* Autor: Caio Lima da Cruz e Thiago Santana (um amigo meu fora da classe).
*--------------------------------------------------------*/

#include <stdio.h>

void inicializa_tabuleiro(char tabuleiro[8][8][4]);
void inicializa_colunas(char colunas[8][4]);
void imprime_tabuleiro(char tabuleiro[8][8][4], char colunas[8][4]);
void realiza_movimento(char tabuleiro[8][8][4], int linha_origem, int coluna_origem, int linha_destino, int coluna_destino, char peca[4]);

void inicializa_tabuleiro(char tabuleiro[8][8][4]) {
    char pecas_brancas[8][4] = {"BT1", "BC1", "BB1", "BD1", "BR1", "BB2", "BC2", "BT2"};
    char pecas_pretas[8][4] = {"PT1", "PC1", "PB1", "PD1", "PR1", "PB2", "PC2", "PT2"};
    char peoes_brancos[8][4] = {"BP1", "BP2", "BP3", "BP4", "BP5", "BP6", "BP7", "BP8"};
    char peoes_pretos[8][4] = {"PP1", "PP2", "PP3", "PP4", "PP5", "PP6", "PP7", "PP8"};

    // Limpa o tabuleiro
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 4; k++) {
                tabuleiro[i][j][k] = ' ';
            }
        }
    }

    // Coloca as peças brancas na linha 1 (torres, cavalos, bispos, dama, rei)
    for (int j = 0; j < 8; j++) {
        for (int k = 0; k < 4; k++) {
            tabuleiro[0][j][k] = pecas_brancas[j][k];
        }
    }

    // Coloca os peões brancos na linha 2
    for (int j = 0; j < 8; j++) {
        for (int k = 0; k < 4; k++) {
            tabuleiro[1][j][k] = peoes_brancos[j][k];
        }
    }

    // Coloca os peões pretos na linha 7
    for (int j = 0; j < 8; j++) {
        for (int k = 0; k < 4; k++) {
            tabuleiro[6][j][k] = peoes_pretos[j][k];
        }
    }

    // Coloca as peças pretas na linha 8 (torres, cavalos, bispos, dama, rei)
    for (int j = 0; j < 8; j++) {
        for (int k = 0; k < 4; k++) {
            tabuleiro[7][j][k] = pecas_pretas[j][k];
        }
    }
}

void inicializa_colunas(char colunas[8][4]) {
    char letras[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    for (int i = 0; i < 8; i++) {
        colunas[i][0] = ' ';
        colunas[i][1] = letras[i];
        colunas[i][2] = ' ';
        colunas[i][3] = ' ';
    }
}

void imprime_tabuleiro(char tabuleiro[8][8][4], char colunas[8][4]) {
    printf("  ");
    for (int j = 0; j < 8; j++) {
        printf("%c%c%c%c ", colunas[j][0], colunas[j][1], colunas[j][2], colunas[j][3]);
    }
    printf("\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 8; j++) {
            printf("%c%c%c%c ", tabuleiro[i][j][0], tabuleiro[i][j][1], tabuleiro[i][j][2], tabuleiro[i][j][3]);
        }
        printf("\n");
    }
    printf("\n");
}

void realiza_movimento(char tabuleiro[8][8][4], int linha_origem, int coluna_origem, int linha_destino, int coluna_destino, char peca[4]) {
    // Limpa a posição original
    for (int k = 0; k < 4; k++) {
        tabuleiro[linha_origem][coluna_origem][k] = ' ';
    }

    // Coloca a peça na nova posição
    for (int k = 0; k < 4; k++) {
        tabuleiro[linha_destino][coluna_destino][k] = peca[k];
    }
}

int main() {
    char tabuleiro[8][8][4];
    char colunas[8][4];
    inicializa_tabuleiro(tabuleiro);
    inicializa_colunas(colunas);

    printf("Tabuleiro inicial:\n");
    imprime_tabuleiro(tabuleiro, colunas);

    // Jogada 1: Peão do Rei branco para e4
    realiza_movimento(tabuleiro, 1, 4, 3, 4, "BP5");
    // Pretas jogam Peão do Rei para e5
    realiza_movimento(tabuleiro, 6, 4, 4, 4, "PP5");
    printf("Jogada 1:\n");
    imprime_tabuleiro(tabuleiro, colunas);

    // Jogada 2: Bispo branco para c4
    realiza_movimento(tabuleiro, 0, 2, 3, 2, "BB1");
    // Pretas jogam Cavalo da Dama para c6
    realiza_movimento(tabuleiro, 7, 1, 5, 2, "PC2");
    printf("Jogada 2:\n");
    imprime_tabuleiro(tabuleiro, colunas);

    // Jogada 3: Dama branca para h5
    realiza_movimento(tabuleiro, 0, 3, 4, 7, "BD1");
    // Pretas jogam Cavalo do Rei para f6
    realiza_movimento(tabuleiro, 7, 6, 5, 5, "PC1");
    printf("Jogada 3:\n");
    imprime_tabuleiro(tabuleiro, colunas);

    // Jogada 4: Dama captura o Peão e dá xeque-mate 
    realiza_movimento(tabuleiro, 4, 7, 6, 5, "BD1");
    printf("Xeque-Mate (Dxf7#):\n");
    imprime_tabuleiro(tabuleiro, colunas);

    return 0;
}