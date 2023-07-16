#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Função para verificar se o vetor está ordenado
bool estaOrdenado(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho - 1; i++) {
        if (vetor[i] > vetor[i + 1]) {
            return false;
        }
    }
    return true;
}

// Função para embaralhar os elementos do vetor
void embaralhar(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        int j = rand() % tamanho;
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
}

// Função para exibir o vetor
void exibirVetor(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Função de ordenação Bogo Sort
void bogoSort(int vetor[], int tamanho) {
    while (!estaOrdenado(vetor, tamanho)) {
        embaralhar(vetor, tamanho);
    }
}

int main() {
    int vetor[] = {9, 4, 6, 2, 8, 5, 1, 3, 7, 0};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios

    printf("Vetor antes da ordenacao: ");
    exibirVetor(vetor, tamanho);

    bogoSort(vetor, tamanho);

    printf("Vetor depois da ordenacao: ");
    exibirVetor(vetor, tamanho);

    return 0;
}
