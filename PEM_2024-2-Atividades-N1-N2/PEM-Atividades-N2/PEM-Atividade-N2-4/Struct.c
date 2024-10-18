/* Disciplina: Programaçao Estruturada e Modular
Prof. Carlos Veríssimo                                    
--------------------------------------------------------
Objetivo do Programa: Manipulando Struct 
Data - 18/10/2024                                                
Autores: Caio Lima da Cruz 
--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
    char descricao[100];
    float precoUnitario; // Use float para valores monetários
    int qteDispo;
} Produto;

void inserirProduto(Produto *produtos, int *cont){
     if (*cont < 100) { // Verifica se há espaço no array
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
    } else {
        printf("Limite de produtos atingido.\n");
    }
}

void bubbleSort(Produto *produtos, int cont){
    for (int i = 0; i < cont - 1; i++) {
        for (int j = 0; j < cont - i - 1; j++) {
            if (strcmp(produtos[j].nome, produtos[j + 1].nome) > 0) {
                // Troca os produtos
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
}

void listarProdutos(Produto *produtos, int cont){
     if (cont == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    // Ordena produtos antes de listar
    bubbleSort(produtos, cont);

    printf("\nLista de Produtos:\n");
    for (int i = 0; i < cont; i++) {
        printf("ID: %d, Nome: %s, Descricao: %s, Preco: %.2f, Estoque: %d\n", 
            produtos[i].id, produtos[i].nome, produtos[i].descricao, produtos[i].precoUnitario, produtos[i].qteDispo);
    }
}

void comprarProduto(Produto *produtos, int cont){
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


int main() {
    Produto produtos[100]; // Array para armazenar até 100 produtos
    int cont = 0; // Contador de produtos
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir produto\n");
        printf("2. Listar produtos\n");
        printf("3. Comprar produto\n");
        printf("4. Sair\n");
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
                comprarProduto(produtos, cont);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
