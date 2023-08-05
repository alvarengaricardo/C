#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool estaOrdenado(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho - 1; i++) {
        if (vetor[i] > vetor[i + 1]) {
            return false;
        }
    }
    return true;
}

void embaralhar(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        int j = rand() % tamanho;
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
}

void exibirVetor(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void bogoSort(int vetor[], int tamanho) {
    int contator = 1;
    while (!estaOrdenado(vetor, tamanho)) {
        contator ++;
        embaralhar(vetor, tamanho);
    }
    printf("%d\n", contator);
}

int main() {
    printf("Bogo Sort\n");
    int vetor[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    srand(time(NULL)); // Inicializa a semente do gerador de numeros aleatorios

    printf("Vetor antes da ordenacao: ");
    exibirVetor(vetor, tamanho);

    bogoSort(vetor, tamanho);

    printf("Vetor depois da ordenacao: ");
    exibirVetor(vetor, tamanho);

    return 0;
}
