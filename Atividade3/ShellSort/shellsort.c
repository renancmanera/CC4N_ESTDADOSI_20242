#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para ordenação utilizando Shell Sort
void ordenarShell(int vetor[], int tamanho) {
    for (int intervalo = tamanho / 2; intervalo > 0; intervalo /= 2) {
        for (int i = intervalo; i < tamanho; i++) {
            int valorAtual = vetor[i];
            int j = i;
            while (j >= intervalo && vetor[j - intervalo] > valorAtual) {
                vetor[j] = vetor[j - intervalo];
                j -= intervalo;
            }
            vetor[j] = valorAtual;
        }
    }
}

// Função para gerar um vetor com valores aleatórios
void gerarVetorAleatorio(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 1000;
    }
}

// Função para exibir o vetor
void exibirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Função para medir o tempo de execução de um método de ordenação
void medirTempoExecucao(void (*metodoOrdenacao)(int[], int), int vetor[], int tamanho) {
    clock_t inicio = clock();
    metodoOrdenacao(vetor, tamanho);
    clock_t fim = clock();
    double duracao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    
    printf("\nVetor ordenado:\n");
    exibirVetor(vetor, tamanho);
    printf("Tempo de execução: %f segundos\n", duracao);
}

int main() {
    int tamanho = 100;
    int vetor[tamanho];
    
    srand((unsigned int)time(NULL));
    
    gerarVetorAleatorio(vetor, tamanho);

    printf("Vetor original:\n");
    exibirVetor(vetor, tamanho);
    
    medirTempoExecucao(ordenarShell, vetor, tamanho);
    
    return 0;
}
