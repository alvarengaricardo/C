#include <stdio.h>

void bubbleSort(int array[], int tamanho) {
    int i, j;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            // Compara elementos adjacentes e os troca, se necessário
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
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
    int array[] = {64, 34, 25, 12, 22, 11, 90, 2, 45, 42};
    int tamanho = sizeof(array) / sizeof(array[0]);

    printf("Array antes da ordenação: ");
    imprimirArray(array, tamanho);

    bubbleSort(array, tamanho);

    printf("Array depois da ordenação: ");
    imprimirArray(array, tamanho);

    return 0;
}

