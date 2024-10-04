/*--------------------------------------------------------
* Disciplina: Programaçao Estruturada e Modular 
*          Prof. Carlos Veríssimo                                    
*--------------------------------------------------------
* Objetivo do Programa: Programa fonte do Bubble sort melhorado
* Data - 27/09/2024                                                
* Autor: Caio Lima da Cruz
*--------------------------------------------------------*/


#include <stdio.h>

// Função para troca de elementos (Modularização)
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de ordenação Bubble Sort otimizada
void bubbleSort(int arr[], int n) {
    int i, j;
    int swapped;  // Indicador para parar o loop se o array já estiver ordenado

    for (i = 0; i < n - 1; i++) {
        swapped = 0;  // Inicializa como "nenhuma troca"

        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);  // Usa a função swap
                swapped = 1;  // Marca que houve troca
            }
        }

        // Se não houve trocas, o array já está ordenado
        if (swapped == 0) break;
    }
}

// Função para exibir o array (uso de `const` para evitar modificações)
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};  // Mantendo o array fixo
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculando o número de elementos

    // Exibe o array original
    printf("Array original: \n");
    printArray(arr, n);

    // Ordena o array
    bubbleSort(arr, n);

    // Exibe o array ordenado
    printf("Array ordenado: \n");
    printArray(arr, n);

    return 0;
}
