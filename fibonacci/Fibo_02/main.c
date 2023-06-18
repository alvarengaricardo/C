#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Tamanho máximo da tabela de memoization
#define MAX_SIZE 51

// Tabela de memoization
long long memo[MAX_SIZE];

// Função para calcular o valor de Fibonacci usando recursão e memoization
long long fibonacci(int n) {
    if (n <= 1)
        return n;

    // Verifica se o valor já foi calculado antes
    if (memo[n] != -1)
        return memo[n];

    // Caso contrário, calcula o valor e o armazena na tabela de memoization
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main() {
    int posicao;
    long long resultado;
    char opcao;
    clock_t inicio, fim;
    double tempo_gasto;

    // Inicializa a tabela de memoization com valores iniciais
    for (int i = 0; i < MAX_SIZE; i++)
        memo[i] = -1;

    do {
        // Solicita a posição desejada ao usuário
        printf("Digite a posicao de Fibonacci desejada: ");
        scanf("%d", &posicao);

        // Verifica se a posição é válida
        if (posicao < 0 || posicao >= MAX_SIZE) {
            printf("Posicao invalida!\n");
            continue;
        }

        // Calcula o valor de Fibonacci e registra o tempo inicial
        inicio = clock();
        resultado = fibonacci(posicao);
        fim = clock();

        // Exibe o resultado e o tempo gasto
        printf("O valor da posicao %d de Fibonacci eh: %lld\n", posicao, resultado);
        tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Tempo gasto: %.6f segundos\n", tempo_gasto);

        // Pergunta ao usuário se deseja calcular outro valor ou sair
        printf("Deseja calcular outro valor? (S/N): ");
        scanf(" %c", &opcao);
    } while (opcao == 'S' || opcao == 's');

    return 0;
}
