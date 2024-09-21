/*Disciplina: Programaçao Estruturada e Modular 
Prof. Carlos Veríssimo                                    
--------------------------------------------------------
Objetivo do Programa: tabuleiro de xadrez      
Data - 28/08/2024                                                
Autor: Caio Lima da Cruz*/

#include <stdio.h>

#define LINHAS 8
#define COLUNAS 8

int main() {
    printf("  a   b   c   d   e   f   g   h\n");
    char* tabuleiro[LINHAS][COLUNAS] = {
        {"PT1", "PC1", "PB1", "PD", "PR", "PB2", "PC2", "PT2"},
        {"PP1", "PP2", "PP3", "PP4", "PP5", "PP6", "PP7", "PP8"},
        {"X", "X", "X", "X", "X", "X", "X", "X"},
        {"X", "X", "X", "X", "X", "X", "X", "X"},
        {"X", "X", "X", "X", "X", "X", "X", "X"},
        {"X", "X", "X", "X", "X", "X", "X", "X"},
        {"BP1", "BP2", "BP3", "BP4", "BP5", "BP6", "BP7", "BP8"},
        {"BT1", "BC1", "BB1", "BR", "BD", "BB2", "BC2", "BT2"}
    };

    int i = 0;
    while (i < LINHAS) {
        printf("%d ", 8 - i);
        int j = 0;
        while (j < COLUNAS) {
            printf("%-3s ", tabuleiro[i][j]); // Alinhamento para melhor visualização
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}
