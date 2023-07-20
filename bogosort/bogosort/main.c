#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Fun��o para verificar se o vetor est� ordenado
bool estaOrdenado(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho - 1; i++) {
        if (vetor[i] > vetor[i + 1]) {
            return false;
        }
    }
    return true;
}

// Fun��o para embaralhar os elementos do vetor
void embaralhar(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        int j = rand() % tamanho;
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
}

// Fun��o para exibir o vetor
void exibirVetor(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Fun��o de ordena��o Bogo Sort
void bogoSort(int vetor[], int tamanho) {
    int contator = 1;
    while (!estaOrdenado(vetor, tamanho)) {
        contator ++;
        embaralhar(vetor, tamanho);
    }
    printf("%d\n", contator);
}

int main() {
    int vetor[] = {9, 4, 6, 2, 8, 5, 1, 3, 7, 0};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    srand(time(NULL)); // Inicializa a semente do gerador de n�meros aleat�rios

    printf("Vetor antes da ordenacao: ");
    exibirVetor(vetor, tamanho);

    bogoSort(vetor, tamanho);

    printf("Vetor depois da ordenacao: ");
    exibirVetor(vetor, tamanho);

    return 0;
}
