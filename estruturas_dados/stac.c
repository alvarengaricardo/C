#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Pilha {
    int itens[MAX_SIZE];
    int topo;
};

// Função para inicializar a pilha
void inicializarPilha(struct Pilha *pilha) {
    pilha->topo = -1;
}

// Função para verificar se a pilha está vazia
int estaVazia(struct Pilha *pilha) {
    return (pilha->topo == -1);
}

// Função para verificar se a pilha está cheia
int estaCheia(struct Pilha *pilha) {
    return (pilha->topo == MAX_SIZE - 1);
}

// Função para empilhar um elemento
void push(struct Pilha *pilha, int elemento) {
    if (estaCheia(pilha)) {
        printf("Erro: Pilha cheia, não é possível empilhar.\n");
        return;
    }
    pilha->itens[++pilha->topo] = elemento;
    printf("Elemento %d empilhado com sucesso.\n", elemento);
}

// Função para desempilhar um elemento
int pop(struct Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("Erro: Pilha vazia, não é possível desempilhar.\n");
        return -1;
    }
    return pilha->itens[pilha->topo--];
}

// Função para obter o elemento do topo da pilha sem removê-lo
int topo(struct Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("Erro: Pilha vazia, não é possível obter o topo.\n");
        return -1;
    }
    return pilha->itens[pilha->topo];
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

    return 0;
}
