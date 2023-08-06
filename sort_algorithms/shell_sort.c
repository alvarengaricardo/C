#include <stdio.h>

void shellSort(int array[], int tamanho) {
    int intervalo, i, j, temp;
    for (intervalo = tamanho / 2; intervalo > 0; intervalo /= 2) {
        for (i = intervalo; i < tamanho; i++) {
            temp = array[i];
            for (j = i; j >= intervalo && array[j - intervalo] > temp; j -= intervalo) {
                array[j] = array[j - intervalo];
            }
            array[j] = temp;
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
    printf("Shell Sort\n");
    int array[] = {64, 34, 25, 12, 22, 11, 90, 45, 27, 18};
    int tamanho = sizeof(array) / sizeof(array[0]);

    printf("Array antes da ordenacao: ");
    imprimirArray(array, tamanho);

    shellSort(array, tamanho);

    printf("Array depois da ordenacao: ");
    imprimirArray(array, tamanho);

    return 0;
}
