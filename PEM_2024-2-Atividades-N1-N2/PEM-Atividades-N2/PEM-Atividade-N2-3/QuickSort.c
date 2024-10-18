/* Disciplina: Programaçao Estruturada e Modular
Prof. Carlos Veríssimo                                    
--------------------------------------------------------
Objetivo do Programa: QuickSort
Data - 18/10/2024                                                
Autores: Caio Lima da Cruz 
--------------------------------------------------------*/

#include <stdio.h>

// Função para trocar dois elementos
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para imprimir o array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função de partição (usada pelo Quicksort)
int particao(int arr[], int limInf, int limSup) {
    int pivo = arr[limSup];  // Seleciona o último elemento como pivô
    int ind = (limInf - 1);  // Índice do menor elemento

    for (int j = limInf; j <= limSup - 1; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivo) {
            ind++;  // Incrementa o índice do menor elemento
            troca(&arr[ind], &arr[j]);
        }
    }
    troca(&arr[ind + 1], &arr[limSup]);
    return (ind + 1);
}

// Função principal do Quicksort
void quickSort(int arr[], int limInf, int limSup) {
    if (limInf < limSup) {
        int indParticao = particao(arr, limInf, limSup);

        // Recursivamente ordena os elementos antes e depois da partição
        quickSort(arr, limInf, indParticao - 1);
        quickSort(arr, indParticao + 1, limSup);
    }
}

int main() {
    int arr[] = {100, 70, 90, 90, 10, 40, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Array ordenado: ");
    printArray(arr, n);

    return 0;
}
