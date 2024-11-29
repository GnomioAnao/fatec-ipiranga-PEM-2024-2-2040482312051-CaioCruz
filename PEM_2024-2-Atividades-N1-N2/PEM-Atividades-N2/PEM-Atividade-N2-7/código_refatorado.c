/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular 
*          Prof. Carlos Veríssimo                                    
*--------------------------------------------------------*
* Objetivo do Programa: Refatoração do Código enviado por Email     
* Data - 29/11/2024                                              
* Autor: Caio Lima da Cruz
*--------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definição da struct Produto
typedef struct {
    int id;
    char nome_produto[50];
    int estoque;
    double preco;
} Produto;

// Função auxiliar para buscar um produto por ID
int buscar_produto_por_id(Produto *produtos[], int cont, int id) {
    for (int i = 0; i < cont; i++) {
        if (produtos[i]->id == id) {
            return i; // Retorna o índice do produto encontrado
        }
    }
    return -1; // Retorna -1 se não encontrar
}

// Função auxiliar para ler um inteiro com validação
int ler_inteiro(const char *mensagem) {
    int valor;
    char buffer[100];
    while (1) {
        printf("%s", mensagem);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &valor) == 1) {
                return valor;
            }
        }
        printf("Entrada invalida. Tente novamente.\n");
    }
}

// Função auxiliar para ler um double com validação
double ler_double(const char *mensagem) {
    double valor;
    char buffer[100];
    while (1) {
        printf("%s", mensagem);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%lf", &valor) == 1) {
                return valor;
            }
        }
        printf("Entrada invalida. Tente novamente.\n");
    }
}

// Função auxiliar para ler uma string com validação de tamanho
void ler_string(const char *mensagem, char *destino, int tamanho) {
    printf("%s", mensagem);
    if (fgets(destino, tamanho, stdin) != NULL) {
        size_t len = strlen(destino);
        if (len > 0 && destino[len - 1] == '\n') {
            destino[len - 1] = '\0'; // Remove o caractere de nova linha
        }
    }
}

// Adicionar produto
void adicionar_produto(Produto *produtos[], int *cont) {
    int id = ler_inteiro("\nDigite o ID do produto: ");

    if (buscar_produto_por_id(produtos, *cont, id) != -1) {
        printf("Erro: Ja existe um produto com este ID.\n");
        return;
    }

    Produto *novo_produto = (Produto *)malloc(sizeof(Produto));
    if (!novo_produto) {
        printf("Erro ao alocar memoria.\n");
        return;
    }

    novo_produto->id = id;
    ler_string("Digite o nome do produto: ", novo_produto->nome_produto, sizeof(novo_produto->nome_produto));
    novo_produto->estoque = ler_inteiro("Quantidade em estoque: ");
    novo_produto->preco = ler_double("Digite o preco: ");

    if (novo_produto->estoque < 0 || novo_produto->preco < 0) {
        printf("Erro: Estoque ou preco nao podem ser valores negativos.\n");
        free(novo_produto);
        return;
    }

    produtos[*cont] = novo_produto;
    (*cont)++;
    printf("\nProduto de ID %d foi adicionado com sucesso.\n", id);
}

// Alterar produto
void alterar_produto(Produto *produtos[], int cont) {
    int id = ler_inteiro("\nDigite o ID do produto a ser alterado: ");

    int index = buscar_produto_por_id(produtos, cont, id);
    if (index == -1) {
        printf("Erro: Produto nao encontrado.\n");
        return;
    }

    Produto *produto = produtos[index];
    ler_string("Digite o novo nome do produto: ", produto->nome_produto, sizeof(produto->nome_produto));
    produto->estoque = ler_inteiro("Digite a nova quantidade em estoque: ");
    produto->preco = ler_double("Digite o novo preco: ");

    if (produto->estoque < 0 || produto->preco < 0) {
        printf("Erro: Estoque ou preço nao podem ser valores negativos.\n");
        return;
    }

    printf("\nProduto de ID %d alterado com sucesso.\n", id);
}

// Consultar produto
void consultar_produto(Produto *produtos[], int cont) {
    int id = ler_inteiro("\nDigite o ID do produto para consulta: ");

    int index = buscar_produto_por_id(produtos, cont, id);
    if (index == -1) {
        printf("Erro: Produto nao encontrado.\n");
        return;
    }

    Produto *produto = produtos[index];
    printf("\nID: %d\nNome: %s\nEstoque: %d\nPreco: R$ %.2lf\n",
           produto->id, produto->nome_produto, produto->estoque, produto->preco);
}

// Excluir produto
void excluir_produto(Produto *produtos[], int *cont) {
    int id = ler_inteiro("\nDigite o ID do produto a ser excluido: ");

    int index = buscar_produto_por_id(produtos, *cont, id);
    if (index == -1) {
        printf("Erro: Produto nao encontrado.\n");
        return;
    }

    free(produtos[index]);
    for (int i = index; i < *cont - 1; i++) {
        produtos[i] = produtos[i + 1];
    }
    (*cont)--;
    printf("\nProduto de ID %d foi excluido com sucesso.\n", id);
}

// Vender produto
void vender_produto(Produto *produtos[], int *cont) {
    int id = ler_inteiro("\nDigite o ID do produto a ser vendido: ");
    int quantidade;

    int index = buscar_produto_por_id(produtos, *cont, id);
    if (index == -1) {
        printf("Erro: Produto nao encontrado.\n");
        return;
    }

    Produto *produto = produtos[index];
    quantidade = ler_inteiro("Digite a quantidade desejada: ");

    if (quantidade > produto->estoque) {
        printf("Erro: Estoque insuficiente.\n");
        return;
    }

    produto->estoque -= quantidade;
    double total = quantidade * produto->preco;
    printf("\nVoce comprou %d unidades de %s. Total: R$ %.2lf\n",
           quantidade, produto->nome_produto, total);
}

// Função principal
int main() {
    Produto *produtos[100];
    int cont = 0, opcao;

    do {
        printf("\n1. Adicionar produto\n");
        printf("2. Consultar produto\n");
        printf("3. Alterar produto\n");
        printf("4. Vender produto\n");
        printf("5. Excluir produto\n");
        printf("0. Encerrar o programa\n");
        printf("Escolha uma opcao: ");
        opcao = ler_inteiro("");

        switch (opcao) {
            case 1:
                adicionar_produto(produtos, &cont);
                break;
            case 2:
                consultar_produto(produtos, cont);
                break;
            case 3:
                alterar_produto(produtos, cont);
                break;
            case 4:
                vender_produto(produtos, &cont);
                break;
            case 5:
                excluir_produto(produtos, &cont);
                break;
            case 0:
                printf("\nPrograma encerrado.\n");
                break;
            default:
                printf("Erro: Opcao invalida.\n");
        }
    } while (opcao != 0);

    for (int i = 0; i < cont; i++) {
        free(produtos[i]);
    }

    return 0;
}
