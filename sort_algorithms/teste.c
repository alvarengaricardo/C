#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool e1(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho - 1; i++) {
        if (vetor[i] > vetor[i + 1]) {
            return false;
        }
    }
    return true;
}

void e2(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        int j = rand() % tamanho;
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
}

void e3(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void aa(int vetor[], int tamanho) {
    int contator = 1;
    while (!e1(vetor, tamanho)) {
        contator ++;
        e2(vetor, tamanho);
    }
    printf("%d\n", contator);
}

int main() {
    int vetor[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    srand(time(NULL));

    e3(vetor, tamanho);

    aa(vetor, tamanho);

    e3(vetor, tamanho);

    return 0;
}
