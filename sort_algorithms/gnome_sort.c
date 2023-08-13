#include <stdio.h>

void gnomeSort(int array[], int tamanho) {
    int posicao = 0;

    while (posicao < tamanho) {
        if (posicao == 0 || array[posicao] >= array[posicao - 1]) {
            posicao++;
        } else {
            int temp = array[posicao];
            array[posicao] = array[posicao - 1];
            array[posicao - 1] = temp;
            posicao--;
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
    int array[] = {64, 34, 25, 12, 22, 11, 90, 45, 27, 18};
    int tamanho = sizeof(array) / sizeof(array[0]);
    printf("Gnome Sort\n");
    printf("Array antes da ordenacao: ");
    imprimirArray(array, tamanho);

    gnomeSort(array, tamanho);

    printf("Array depois da ordenacao: ");
    imprimirArray(array, tamanho);

    return 0;
}
