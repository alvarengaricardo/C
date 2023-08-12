/*

Radix Sort

*/

#include <stdio.h>

// Função para encontrar o maior número no vetor
int encontrarMaior(int array[], int tamanho) {
    int maior = array[0];
    for (int i = 1; i < tamanho; i++) {
        if (array[i] > maior) {
            maior = array[i];
        }
    }
    return maior;
}

// Função para realizar a ordenação por contagem para um dígito específico
void countingSort(int array[], int tamanho, int exp) {
    int output[tamanho];
    int i, contagem[10] = {0};

    // Conta a frequência dos dígitos
    for (i = 0; i < tamanho; i++) {
        contagem[(array[i] / exp) % 10]++;
    }

    // Atualiza a contagem para obter a posição correta de cada dígito no output
    for (i = 1; i < 10; i++) {
        contagem[i] += contagem[i - 1];
    }

    // Constrói o output
    for (i = tamanho - 1; i >= 0; i--) {
        output[contagem[(array[i] / exp) % 10] - 1] = array[i];
        contagem[(array[i] / exp) % 10]--;
    }

    // Copia o output para o array original
    for (i = 0; i < tamanho; i++) {
        array[i] = output[i];
    }
}

// Função para realizar o Radix Sort
void radixSort(int array[], int tamanho) {
    int maior = encontrarMaior(array, tamanho);

    // Aplica o counting sort para cada dígito
    for (int exp = 1; maior / exp > 0; exp *= 10) {
        countingSort(array, tamanho, exp);
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
    int array[] = {170, 45, 75, 90, 802, 24, 2, 66, 105, 110};
    int tamanho = sizeof(array) / sizeof(array[0]);
    printf("Radix Sort\n");
    printf("Array antes da ordenacao: ");
    imprimirArray(array, tamanho);

    radixSort(array, tamanho);

    printf("Array depois da ordenacao: ");
    imprimirArray(array, tamanho);

    return 0;
}
