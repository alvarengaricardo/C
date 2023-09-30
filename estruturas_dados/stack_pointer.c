#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dado;
    struct Node* proximo;
};

struct Pilha {
    struct Node* topo;
};

// Função para inicializar a pilha vazia
void inicializarPilha(struct Pilha *pilha) {
    pilha->topo = NULL;
}

// Função para verificar se a pilha está vazia
int estaVazia(struct Pilha *pilha) {
    return (pilha->topo == NULL);
}

// Função para empilhar um elemento
void push(struct Pilha *pilha, int elemento) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    if (novoNo == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        exit(1); // Encerrar o programa em caso de falha na alocação de memória.
    }
    novoNo->dado = elemento;
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
    printf("Elemento %d empilhado com sucesso.\n", elemento);
}

// Função para desempilhar um elemento
int pop(struct Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("Erro: Pilha vazia, não é possível desempilhar.\n");
        exit(1); // Encerrar o programa em caso de erro.
    }
    struct Node* temp = pilha->topo;
    int elemento = temp->dado;
    pilha->topo = temp->proximo;
    free(temp);
    return elemento;
}

// Função para obter o elemento do topo da pilha sem removê-lo
int topo(struct Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("Erro: Pilha vazia, não é possível obter o topo.\n");
        exit(1); // Encerrar o programa em caso de erro.
    }
    return pilha->topo->dado;
}

// Função para liberar a memória alocada para a pilha
void liberarPilha(struct Pilha *pilha) {
    while (!estaVazia(pilha)) {
        pop(pilha);
    }
}

int main() {
    struct Pilha minhaPilha;
    inicializarPilha(&minhaPilha);

    push(&minhaPilha, 10);
    push(&minhaPilha, 20);
    push(&minhaPilha, 30);

    printf("Topo da pilha: %d\n", topo(&minhaPilha));

    printf("Desempilhando: %d\n", pop(&minhaPilha));
    printf("Desempilhando: %d\n", pop(&minhaPilha));
    printf("Topo da pilha: %d\n", topo(&minhaPilha));

    liberarPilha(&minhaPilha);

    return 0;
}
