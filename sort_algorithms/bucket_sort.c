#include <stdio.h>

// Função para encontrar o valor máximo no vetor
int encontrarMaximo(int vetor[], int n) {
    int max = vetor[0];
    for (int i = 1; i < n; i++) {
        if (vetor[i] > max) {
            max = vetor[i];
        }
    }
    return max;
}

// Função para ordenar um vetor usando o Bucket Sort
void bucketSort(int vetor[], int n) {
    // Encontre o valor máximo no vetor
    int max = encontrarMaximo(vetor, n);

    // Crie baldes
    int baldes[max + 1];

    // Inicialize os baldes
    for (int i = 0; i <= max; i++) {
        baldes[i] = 0;
    }

    // Coloque elementos nos baldes
    for (int i = 0; i < n; i++) {
        baldes[vetor[i]]++;
    }

    // Coloque elementos de volta no vetor
    int indice = 0;
    for (int i = 0; i <= max; i++) {
        while (baldes[i] > 0) {
            vetor[indice++] = i;
            baldes[i]--;
        }
    }
}

int main() {
    printf("Bucket Sort\n");
    int vetor[10] = {23, 45, 12, 67, 89, 5, 32, 66, 49, 8};

    printf("Vetor original:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }

    // Chame a função Bucket Sort
    bucketSort(vetor, 10);

    printf("\nVetor ordenado:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");

    return 0;
}
