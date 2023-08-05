#include <stdio.h>

void selectionSort(int array[], int tamanho) {
    int i, j, minIndex, temp;
    for (i = 0; i < tamanho - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < tamanho; j++) {
            // Encontra o �ndice do menor elemento no subarray n�o ordenado
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        // Troca o elemento atual (array[i]) com o menor elemento encontrado (array[minIndex])
        temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}

void imprimirArray(int array[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    printf("Selection Sort\n");
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int tamanho = sizeof(array) / sizeof(array[0]);

    printf("Array antes da ordenacao: ");
    imprimirArray(array, tamanho);

    selectionSort(array, tamanho);

    printf("Array depois da ordenacao: ");
    imprimirArray(array, tamanho);

    return 0;
}
