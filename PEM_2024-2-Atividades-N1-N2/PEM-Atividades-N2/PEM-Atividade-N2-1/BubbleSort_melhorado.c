/*--------------------------------------------------------
* Disciplina: Programaçao Estruturada e Modular 
*          Prof. Carlos Veríssimo                                    
*--------------------------------------------------------
* Objetivo do Programa: Bubble Sort de minha autoria, mas agora melhorado
* Data - 27/09/2024                                                
* Autor: Caio Lima da Cruz
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

// Função para ordenação Bubble Sort
void bubbleSort(int *array, int size) {
    int swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = 0;  // Indica se houve trocas
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {

                // Troca os elementos adjacentes se estiverem fora de ordem
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;  // Marca que houve troca
            }
        }
        // Se não houve troca, a lista já está ordenada
        if (!swapped) break;
    }
}

int main() {
    int n;

    // Solicita ao usuário o número de elementos
    printf("Digite a quantidade de numeros a serem ordenados: ");
    scanf("%d", &n);

    // Aloca dinamicamente o vetor e verifica erro de alocação
    int *array = (int *)calloc(n, sizeof(int));
    if (array == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    // Lê os números do usuário
    printf("Digite %d numeros:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // Chama a função de ordenação
    bubbleSort(array, n);

    // Exibe os números ordenados
    printf("Numeros ordenados:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(array);
    return 0;
}