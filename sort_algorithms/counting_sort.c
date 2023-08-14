/*

Counting Sort

*/
#include <stdio.h>

// Função para encontrar o maior elemento no vetor
int encontrarMaior(int array[], int tamanho) {
    int maior = array[0];
    for (int i = 1; i < tamanho; i++) {
        if (array[i] > maior) {
            maior = array[i];
        }
    }
    return maior;
}

// Função para realizar o Counting Sort
void countingSort(int array[], int tamanho) {
    int maior = encontrarMaior(array, tamanho);

    // Criando arrays auxiliares
    int output[tamanho];
    int count[maior + 1];
    for (int i = 0; i <= maior; i++) {
        count[i] = 0;
    }

    // Contando a frequência de cada elemento
    for (int i = 0; i < tamanho; i++) {
        count[array[i]]++;
    }

    // Atualizando o array de contagem para obter as posições corretas
    for (int i = 1; i <= maior; i++) {
        count[i] += count[i - 1];
    }

    // Construindo o array ordenado
    for (int i = tamanho - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copiando o array ordenado de volta para o array original
    for (int i = 0; i < tamanho; i++) {
        array[i] = output[i];
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
    int array[] = {4, 2, 2, 8, 3, 3, 1, 6, 5, 9};
    int tamanho = sizeof(array) / sizeof(array[0]);
    printf("Counting Soert\n");
    printf("Array antes da ordenacao: ");
    imprimirArray(array, tamanho);

    countingSort(array, tamanho);

    printf("Array depois da ordenacao: ");
    imprimirArray(array, tamanho);

    return 0;
}
