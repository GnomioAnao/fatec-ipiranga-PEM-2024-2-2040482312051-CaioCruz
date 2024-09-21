/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    
*--------------------------------------------------------*
* Objetivo do Programa: HP12c      
* Data - 18/09/2024                                         
* Autor: Caio Lima da Cruz
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 4

typedef struct {
    int topo;
    int itens[MAX];
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void empilhar(Pilha *p, int valor) {
    if (pilhaCheia(p)) {
        printf("Pilha cheia!\n");
    } else {
        p->itens[++(p->topo)] = valor;
    }
}

int desempilhar(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return p->itens[(p->topo)--];
    }
}

// Removida a lógica de validação de diferença entre operandos e operadores
int validarRPN(char *entrada) {
    char copiaEntrada[100];
    strcpy(copiaEntrada, entrada); // Faz uma cópia da entrada para validação
    int operandos = 0, operadores = 0;

    for (char *token = strtok(copiaEntrada, " "); token != NULL; token = strtok(NULL, " ")) {
        if (isdigit(token[0])) {
            operandos++;  // Conta operandos
        } else if (strchr("+-*/", token[0])) {
            operadores++; // Conta operadores
            if (operandos < 2) {
                return 0; // Verifica se há operandos suficientes para o operador
            }
            operandos--; // Após cada operação, um operando é consumido
        } else {
            return 0; // Token inválido
        }
    }

    // No final, deve sobrar exatamente 1 operando (resultado final)
    return operandos == 1;
}

void processarRPN(char *entrada) {
    Pilha pilha;
    inicializar(&pilha);
    char copiaEntrada[100];
    strcpy(copiaEntrada, entrada); // Faz uma cópia da entrada para processamento

    for (char *token = strtok(copiaEntrada, " "); token != NULL; token = strtok(NULL, " ")) {
        if (isdigit(token[0])) {
            empilhar(&pilha, atoi(token));
        } else {
            int b = desempilhar(&pilha);
            int a = desempilhar(&pilha);
            switch (token[0]) {
                case '+': empilhar(&pilha, a + b); break;
                case '-': empilhar(&pilha, a - b); break;
                case '*': empilhar(&pilha, a * b); break;
                case '/':
                    if (b == 0) {
                        printf("Erro: Divisao por zero.\n");
                        return;
                    }
                    empilhar(&pilha, a / b); 
                    break;
                default: printf("Operador invalido!\n");
            }
        }
    }

    if (!pilhaVazia(&pilha)) {
        printf("Resultado: %d\n", desempilhar(&pilha));
    } else {
        printf("Erro: Pilha vazia após processamento.\n");
    }
}

int main() {
    char entrada[100];
    while (1) {
        printf("Digite a formula RPN (exemplo: 5 1 2 + 4 * + 3 -): ");
        fgets(entrada, 100, stdin);
        entrada[strcspn(entrada, "\n")] = '\0'; // Remover nova linha

        if (validarRPN(entrada)) {
            processarRPN(entrada);
        } else {
            printf("Formula RPN invalida!\n");
        }

        char resposta;
        printf("Deseja fazer uma nova entrada? (s/n): ");
        scanf(" %c", &resposta);
        getchar(); // Limpar buffer
        if (resposta != 's') {
            break;
        }
    }

    printf("Obrigado por usar nossa Calculadora HP12c\n");
    return 0;
}