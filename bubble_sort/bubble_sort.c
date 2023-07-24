#include <stdio.h>

void bubbleSort(int array[], int tamanho) {
    int i, j, contador;
    contador = 0;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            // Compara elementos adjacentes e os troca, se necess�rio
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
            contador ++;
        }
    }
    printf("%d\n", contador);
}

void imprimirArray(int array[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    printf("Bubble Sort\n");
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int tamanho = sizeof(array) / sizeof(array[0]);

    printf("Array antes da ordenacao: ");
    imprimirArray(array, tamanho);

    bubbleSort(array, tamanho);

    printf("Array depois da ordenacao: ");
    imprimirArray(array, tamanho);

    return 0;
}

