#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Fila {
    int itens[MAX_SIZE];
    int frente, traseira;
};

// Função para inicializar a fila
void inicializarFila(struct Fila *fila) {
    fila->frente = -1;
    fila->traseira = -1;
}

// Função para verificar se a fila está vazia
int estaVazia(struct Fila *fila) {
    return (fila->frente == -1);
}

// Função para verificar se a fila está cheia
int estaCheia(struct Fila *fila) {
    return ((fila->traseira + 1) % MAX_SIZE == fila->frente);
}

// Função para enfileirar (adicionar) um elemento
void enfileirar(struct Fila *fila, int elemento) {
    if (estaCheia(fila)) {
        printf("Erro: Fila cheia, não é possível enfileirar.\n");
        return;
    }
    if (estaVazia(fila)) {
        fila->frente = 0;
    }
    fila->traseira = (fila->traseira + 1) % MAX_SIZE;
    fila->itens[fila->traseira] = elemento;
    printf("Elemento %d enfileirado com sucesso.\n", elemento);
}

// Função para desenfileirar (remover) um elemento
int desenfileirar(struct Fila *fila) {
    if (estaVazia(fila)) {
        printf("Erro: Fila vazia, não é possível desenfileirar.\n");
        return -1;
    }
    int elemento = fila->itens[fila->frente];
    if (fila->frente == fila->traseira) {
        fila->frente = -1;
        fila->traseira = -1;
    } else {
        fila->frente = (fila->frente + 1) % MAX_SIZE;
    }
    return elemento;
}

int main() {
    struct Fila minhaFila;
    inicializarFila(&minhaFila);

    enfileirar(&minhaFila, 10);
    enfileirar(&minhaFila, 20);
    enfileirar(&minhaFila, 30);

    printf("Desenfileirando: %d\n", desenfileirar(&minhaFila));
    printf("Desenfileirando: %d\n", desenfileirar(&minhaFila));

    enfileirar(&minhaFila, 40);

    printf("Desenfileirando: %d\n", desenfileirar(&minhaFila));

    return 0;
}
