/*--------------------------------------------------------
* Disciplina: Programaçao Estruturada e Modular 
*          Prof. Carlos Veríssimo                                    
*--------------------------------------------------------
* Objetivo do Programa: Bubble Sort de minha autoria
* Data - 27/09/2024                                                
* Autor: Caio Lima da Cruz, Alicia Muniz
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
 
 
void bubbleSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Troca
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
 
int main() {
    int n;
 
    // Solicita ao usuário o número de elementos
    printf("Digite a quantidade de números a serem ordenados: ");
    scanf("%d", &n);
 
    // Alocação dinâmica do vetor
    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }
 
    // Lê os números do usuário
    printf("Digite %d números:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
 
    bubbleSort(array, n);
 
    // Exibe os números ordenados
    printf("Números ordenados:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
 
    // Liberação da memória
    free(array);
    return 0;
}