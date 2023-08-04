#include <stdio.h>

void merge(int array[], int inicio, int meio, int fim) {
    int tamanhoEsquerda = meio - inicio + 1;
    int tamanhoDireita = fim - meio;

    int esquerda[tamanhoEsquerda];
    int direita[tamanhoDireita];

    // Copia os elementos para os subarrays temporários
    int i, j;
    for (i = 0; i < tamanhoEsquerda; i++)
        esquerda[i] = array[inicio + i];
    for (j = 0; j < tamanhoDireita; j++)
        direita[j] = array[meio + 1 + j];

    // Combina os subarrays em ordem
    i = 0; // Índice para o subarray da esquerda
    j = 0; // Índice para o subarray da direita
    int k = inicio; // Índice para o array final

    while (i < tamanhoEsquerda && j < tamanhoDireita) {
        if (esquerda[i] <= direita[j]) {
            array[k] = esquerda[i];
            i++;
        } else {
            array[k] = direita[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes, se houver, dos subarrays para o array final
    while (i < tamanhoEsquerda) {
        array[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < tamanhoDireita) {
        array[k] = direita[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        // Divide o array em duas partes e chama o mergeSort recursivamente para ambas
        mergeSort(array, inicio, meio);
        mergeSort(array, meio + 1, fim);

        // Combina as duas partes ordenadas usando a função merge
        merge(array, inicio, meio, fim);
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
    printf("Merge Sort\n");
    int array[] = {64, 34, 25, 12, 22, 11, 90, 45, 27, 18};
    int tamanho = sizeof(array) / sizeof(array[0]);

    printf("Array antes da ordenacao: ");
    imprimirArray(array, tamanho);

    mergeSort(array, 0, tamanho - 1);

    printf("Array depois da ordenacao: ");
    imprimirArray(array, tamanho);

    return 0;
}
