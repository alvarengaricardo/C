#include <stdio.h>

// Função para ajustar a raiz do heap máximo
void maxHeapify(int array[], int tamanho, int indiceRaiz) {
    int maior = indiceRaiz;
    int filhoEsquerda = 2 * indiceRaiz + 1;
    int filhoDireita = 2 * indiceRaiz + 2;

    // Verifica se o filho da esquerda é maior que a raiz
    if (filhoEsquerda < tamanho && array[filhoEsquerda] > array[maior])
        maior = filhoEsquerda;

    // Verifica se o filho da direita é maior que a raiz
    if (filhoDireita < tamanho && array[filhoDireita] > array[maior])
        maior = filhoDireita;

    // Se o maior não for a raiz, troca a raiz com o maior e ajusta o heap
    if (maior != indiceRaiz) {
        int temp = array[indiceRaiz];
        array[indiceRaiz] = array[maior];
        array[maior] = temp;

        // Recursivamente ajusta a subárvore afetada
        maxHeapify(array, tamanho, maior);
    }
}

// Função para ordenar o vetor usando o HeapSort
void heapSort(int array[], int tamanho) {
    // Constrói o heap máximo
    for (int i = tamanho / 2 - 1; i >= 0; i--)
        maxHeapify(array, tamanho, i);

    // Extrai os elementos do heap e ajusta o heap novamente
    for (int i = tamanho - 1; i >= 0; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        maxHeapify(array, i, 0);
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
    printf("Heap Sort\n");
    int array[] = {64, 34, 25, 12, 22, 11, 90, 45, 27, 18};
    int tamanho = sizeof(array) / sizeof(array[0]);

    printf("Array antes da ordenacao: ");
    imprimirArray(array, tamanho);

    heapSort(array, tamanho);

    printf("Array depois da ordenacao: ");
    imprimirArray(array, tamanho);

    return 0;
}
