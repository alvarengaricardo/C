#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long fibonacci(int n);

int main() {
    int posicao;
    char opcao;
    double tempo_gasto;
    clock_t inicio, fim;

    do {
        printf("001-Digite a posicao de Fibonacci desejada: ");
        scanf("%d", &posicao);

        inicio = clock();
        long resultado = fibonacci(posicao);
        fim = clock();

        tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

        printf("O valor da posicao %d de Fibonacci eh: %ld\n", posicao, resultado);
        printf("Tempo gasto para calcular: %.6f segundos\n\n", tempo_gasto);
        printf("%d\n", inicio);
        printf("%d\n", fim);

        printf("Deseja calcular outro valor? (S/N): ");
        scanf(" %c", &opcao);

    } while (opcao == 'S' || opcao == 's');

    return 0;
}

long fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
