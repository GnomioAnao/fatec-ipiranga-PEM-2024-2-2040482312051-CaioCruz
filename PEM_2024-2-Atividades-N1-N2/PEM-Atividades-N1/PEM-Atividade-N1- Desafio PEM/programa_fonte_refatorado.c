/*--------------------------------------------------------
* Disciplina: Programaçao Estruturada e Modular 
*          Prof. Carlos Veríssimo                                    
*--------------------------------------------------------
* Objetivo do Programa: Refatoramento de código fonte da atividade "Desafio PEM"    
* Data - 21/09/2024                                             
* Autor: Caio Lima da Cruz
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAMANHO_PILHA 4

void exibirPilha(int pilha[]) {
    printf("Pilha: [T: %d] [Z: %d] [Y: %d] [X: %d]\n", pilha[3], pilha[2], pilha[1], pilha[0]);
}

void empurrar(int pilha[], int valor) {
    for (int i = 0; i < TAMANHO_PILHA - 1; i++) {
        pilha[TAMANHO_PILHA - 1 - i] = pilha[TAMANHO_PILHA - 2 - i];
    }
    pilha[0] = valor;
}

void executarOperacao(int pilha[], char operador) {
    int resultado;

    if (operador == '+') {
        resultado = pilha[1] + pilha[0];
    } else if (operador == '-') {
        resultado = pilha[1] - pilha[0];
    } else if (operador == '*') {
        resultado = pilha[1] * pilha[0];
    } else if (operador == '/') {
        if (pilha[0] == 0) {
            printf("Erro: Divisão por zero não permitida.\n");
            return;
        }
        resultado = pilha[1] / pilha[0];
    } else {
        printf("Operador inválido!\n");
        return;
    }

    // Atualiza a pilha
    for (int i = 0; i < TAMANHO_PILHA - 1; i++) {
        pilha[i] = pilha[i + 1];
    }
    pilha[TAMANHO_PILHA - 1] = 0; // Zera o último valor
    pilha[0] = resultado; // Coloca o resultado no topo da pilha

    printf("Resultado da operação: %d\n", resultado);
}


int main() {
    int pilha[TAMANHO_PILHA] = {0, 0, 0, 0}; // Inicializando a pilha
    char entrada[100]; // Para armazenar a entrada do usuário
    char continuar;

    printf("Bem-vindo à Calculadora Fatec-HP12c!\n");

    do {
        printf("\nDigite a expressão em formato RPN (ex: 5 1 2 + 4 * + 3 -) ou 'sair' para encerrar: ");
        fgets(entrada, sizeof(entrada), stdin); // Lê a entrada do usuário
        entrada[strcspn(entrada, "\n")] = 0; // Remove nova linha da entrada

        if (strncmp(entrada, "sair", 4) == 0) {
            break; // Encerra o loop se o usuário quiser sair
        }

        char *token = strtok(entrada, " ");
        while (token != NULL) {
            if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
                int valor = atoi(token); // Converte o token para número inteiro
                empurrar(pilha, valor); // Empurra o número para a pilha
                exibirPilha(pilha); // Exibe o estado da pilha
            } else {
                executarOperacao(pilha, token[0]); // Executa a operação
                exibirPilha(pilha); // Exibe o estado da pilha
            }
            token = strtok(NULL, " "); // Avança para o próximo token
        }

        // Exibir o resultado final
        printf("\nResultado final: %d\n", pilha[0]); // Exibe o resultado final

        printf("\nDeseja realizar outra operação? (s/n): ");
        scanf(" %c", &continuar);
        getchar(); // Limpa o buffer

    } while (continuar == 's' || continuar == 'S');

    printf("Obrigado por usar nossa Calculadora Fatec-HP12c!\n");

    return 0;
}
