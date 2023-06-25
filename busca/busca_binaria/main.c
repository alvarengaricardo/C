#include <stdio.h>

int buscaBinaria(int array[], int inicio, int fim, int elemento) {
    if (fim >= inicio) {
        int meio = inicio + (fim - inicio) / 2;

        // Se o elemento está no meio, retorna sua posição
        if (array[meio] == elemento)
            return meio;

        // Se o elemento é menor que o valor do meio, busca na metade esquerda
        if (array[meio] > elemento)
            return buscaBinaria(array, inicio, meio - 1, elemento);

        // Caso contrário, busca na metade direita
        return buscaBinaria(array, meio + 1, fim, elemento);
    }

    // Elemento não encontrado
    return -1;
}

int main() {
    int array[] = {2, 4, 7, 10, 14, 20, 25, 30};
    int tamanho = sizeof(array) / sizeof(array[0]);

    int elemento = 10;
    int indice = buscaBinaria(array, 0, tamanho - 1, elemento);

    if (indice != -1)
        printf("Elemento encontrado na posição %d.\n", indice);
    else
        printf("Elemento não encontrado.\n");

    return 0;
}
