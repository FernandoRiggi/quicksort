/*
 * Trabalho Prático 03 - QuickSort não recursivo
 *
 * Discussão sobre a estratégia da pilha (O(log n) stack size):
 * A estratégia iterativa do algoritmo Quicksort oferece uma vantagem ao estabelecer limites para o tamanho da pilha.
 * Em contraste com a abordagem recursiva, que insere duas partições na pilha de execução em ordem arbitrária,
 * a versão iterativa verifica os tamanhos das partições antes de adicionar à pilha.
 * Além disso, ao adotar uma política que prioriza a inserção dos índices da partição maior do vetor antes
 * dos índices da partição menor, permite que o lado menor seja processado antes do lado maior.
 * Como resultado, o tamanho da pilha é da ordem de O(log(n)).
 *
 * Status da implementação da estratégia:
 * A estratégia de empilhar a partição maior antes da menor para otimizar o tamanho da pilha para O(log n)
 * foi implementada na função 'quicksort_iterative' no arquivo 'quicksort.c'.
 * Após cada partição, os tamanhos das duas sub-partições são calculados. A sub-partição maior tem seus
 * limites empilhados primeiro na pilha, seguida pela sub-partição menor. Isso garante que a sub-partição
 * menor seja a próxima a ser desempilhada e processada, minimizando a profundidade máxima da pilha.
 */

#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h" 
#include "stack.h"     

int main() {
    int N;

    if (scanf("%d", &N) != 1) {
        fprintf(stderr, "Erro ao ler a quantidade de elementos N.\n");
        return EXIT_FAILURE;
    }

    if (N <= 0) {
        printf("\n");  
        return EXIT_SUCCESS;
    }

    int* arr = (int*) malloc(N * sizeof(int));
    if (arr == NULL) {
        perror("Erro ao alocar memória para o vetor");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < N; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Erro ao ler o elemento %d do vetor.\n", i);
            free(arr);
            return EXIT_FAILURE;
        }
    }

    quicksort_iterative(arr, N);

    for (int i = 0; i < N; i++) {
        printf("%d%s", arr[i], (i == N - 1) ? "" : " ");
    }
    printf("\n");

    free(arr);

    return EXIT_SUCCESS;
}