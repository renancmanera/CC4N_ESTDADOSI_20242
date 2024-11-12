#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar valores entre duas posições
void troca(int *x, int *y) {
    int aux = *x;
    *x = *y;
    *y = aux;
}

// Função para particionar o array e definir a posição do pivô
int particionar(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim];  // Escolhe o último elemento como pivô
    int menor_indice = inicio - 1;  // Índice para menores que o pivô

    for (int atual = inicio; atual < fim; atual++) {
        if (vetor[atual] < pivo) {
            troca(&vetor[++menor_indice], &vetor[atual]);
        }
    }
    troca(&vetor[menor_indice + 1], &vetor[fim]);
    return menor_indice + 1;  // Retorna a nova posição do pivô
}

// Implementação do QuickSort com chamadas recursivas
void quicksort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int posicao_pivo = particionar(vetor, inicio, fim);
        quicksort(vetor, inicio, posicao_pivo - 1);
        quicksort(vetor, posicao_pivo + 1, fim);
    }
}

// Função para gerar valores aleatórios no array
void gerarVetorAleatorio(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 1000;
    }
}

// Função para imprimir os elementos do array
void exibirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Função para calcular o tempo de execução do algoritmo
void calcularTempoExecucao(void (*algoritmo)(int[], int, int), int vetor[], int tamanho, const char *nome) {
    clock_t inicio = clock();
    algoritmo(vetor, 0, tamanho - 1);  // Chama a função de ordenação
    clock_t fim = clock();
    double duracao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\n%s: Tempo de execucao: %f segundos\n", nome, duracao);
}

int main() {
    int tamanho = 100;
    srand((unsigned int)time(NULL));
    int vetor[tamanho];

    gerarVetorAleatorio(vetor, tamanho);

    printf("Vetor original:\n");
    exibirVetor(vetor, tamanho);

    calcularTempoExecucao(quicksort, vetor, tamanho, "Quicksort com vetor aleatorio");

    printf("\nVetor ordenado:\n");
    exibirVetor(vetor, tamanho);

    return 0;
}
