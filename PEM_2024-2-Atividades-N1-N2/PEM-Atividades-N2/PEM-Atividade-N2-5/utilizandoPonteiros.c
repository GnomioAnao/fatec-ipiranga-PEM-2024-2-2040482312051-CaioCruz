/* Disciplina: Programaçao Estruturada e Modular
Prof. Carlos Veríssimo                                    
--------------------------------------------------------
Objetivo do Programa: Ponteiros
Data - 04/11/2024                                                
Autores: Caio Lima da Cruz 
--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100
#define NOME_MAX 50
#define DESCRICAO_MAX 100

typedef struct {
    int id;
    char nome[NOME_MAX];
    char descricao[DESCRICAO_MAX];
    float precoUnitario; // Usar float para valores monetários
    int qteDispo;
} Produto;

void inserirProduto(Produto *produtos, int *cont);
void consultarProduto(Produto *produtos, int cont);
void alterarProduto(Produto *produtos, int cont);
void excluirProduto(Produto *produtos, int *cont);
void listarProdutos(Produto *produtos, int cont);
void comprarProduto(Produto *produtos, int cont);
void imprimirProduto(Produto *produto);

int main() {
    Produto produtos[MAX_PRODUTOS]; // Array para armazenar até 100 produtos
    int cont = 0; // Contador de produtos
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir produto\n");
        printf("2. Listar produtos\n");
        printf("3. Consultar produto\n");
        printf("4. Alterar produto\n");
        printf("5. Excluir produto\n");
        printf("6. Comprar produto\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirProduto(produtos, &cont);
                break;
            case 2:
                listarProdutos(produtos, cont);
                break;
            case 3:
                consultarProduto(produtos, cont);
                break;
            case 4:
                alterarProduto(produtos, cont);
                break;
            case 5:
                excluirProduto(produtos, &cont);
                break;
            case 6:
                comprarProduto(produtos, cont);
                break;
            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 7);

    return 0;
}

void inserirProduto(Produto *produtos, int *cont) {
    if (*cont < MAX_PRODUTOS) { // Verifica se há espaço no array
        Produto novoProduto;

        printf("Informe o ID do produto: ");
        scanf("%d", &novoProduto.id);
        printf("Informe o nome do produto: ");
        scanf(" %[^\n]", novoProduto.nome); // Lê string com espaços
        printf("Informe a descricao do produto: ");
        scanf(" %[^\n]", novoProduto.descricao);
        printf("Informe o preco unitario: ");
        scanf("%f", &novoProduto.precoUnitario);
        printf("Informe a quantidade disponivel: ");
        scanf("%d", &novoProduto.qteDispo);

        produtos[*cont] = novoProduto; // Adiciona o novo produto ao array
        (*cont)++; // Incrementa o contador
        printf("Produto inserido com sucesso!\n");
    } else {
        printf("Limite de produtos atingido.\n");
    }
}

void listarProdutos(Produto *produtos, int cont) {
    if (cont == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("\nLista de Produtos:\n");
    for (int i = 0; i < cont; i++) {
        imprimirProduto(&produtos[i]);
    }
}

void imprimirProduto(Produto *produto) {
    printf("ID: %d, Nome: %s, Descricao: %s, Preco: %.2f, Estoque: %d\n", 
        produto->id, produto->nome, produto->descricao, produto->precoUnitario, produto->qteDispo);
}

void consultarProduto(Produto *produtos, int cont) {
    int idProduto;
    printf("Informe o ID do produto que deseja consultar: ");
    scanf("%d", &idProduto);

    for (int i = 0; i < cont; i++) {
        if (produtos[i].id == idProduto) {
            imprimirProduto(&produtos[i]);
            return;
        }
    }
    printf("Produto inexistente.\n");
}

void alterarProduto(Produto *produtos, int cont) {
    int idProduto;
    printf("Informe o ID do produto que deseja alterar: ");
    scanf("%d", &idProduto);

    for (int i = 0; i < cont; i++) {
        if (produtos[i].id == idProduto) {
            printf("Novo nome do produto: ");
            scanf(" %[^\n]", produtos[i].nome);
            printf("Nova descricao do produto: ");
            scanf(" %[^\n]", produtos[i].descricao);
            printf("Novo preco unitario: ");
            scanf("%f", &produtos[i].precoUnitario);
            printf("Nova quantidade disponivel: ");
            scanf("%d", &produtos[i].qteDispo);
            printf("Produto alterado com sucesso!\n");
            return;
        }
    }
    printf("Produto inexistente.\n");
}

void excluirProduto(Produto *produtos, int *cont) {
    int idProduto;
    printf("Informe o ID do produto que deseja excluir: ");
    scanf("%d", &idProduto);

    for (int i = 0; i < *cont; i++) {
        if (produtos[i].id == idProduto) {
            for (int j = i; j < *cont - 1; j++) {
                produtos[j] = produtos[j + 1]; // Move os produtos para preencher o espaço
            }
            (*cont)--; // Decrementa o contador
            printf("Produto excluido com sucesso!\n");
            return;
        }
    }
    printf("Produto inexistente.\n");
}

void comprarProduto(Produto *produtos, int cont) {
    if (cont == 0) {
        printf("Nenhum produto cadastrado para compra.\n");
        return;
    }

    int idProduto, quantidade;
    printf("Informe o ID do produto que deseja comprar: ");
    scanf("%d", &idProduto);

    // Busca o produto pelo ID
    for (int i = 0; i < cont; i++) {
        if (produtos[i].id == idProduto) {
            printf("Informe a quantidade que deseja comprar: ");
            scanf("%d", &quantidade);

            if (quantidade > produtos[i].qteDispo) {
                printf("Estoque insuficiente. Apenas %d disponiveis.\n", produtos[i].qteDispo);
            } else {
                produtos[i].qteDispo -= quantidade; // Atualiza a quantidade disponível
                printf("Compra realizada com sucesso! Total: %.2f\n", produtos[i].precoUnitario * quantidade);
            }
            return;
        }
    }
    printf("Produto inexistente.\n");
}
