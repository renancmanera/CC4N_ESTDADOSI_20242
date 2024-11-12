#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para mesclar as divisões do Merge Sort
void mesclar(int vetor[], int inicio, int meio, int fim) {
    int tamanhoEsquerdo = meio - inicio + 1;
    int tamanhoDireito = fim - meio;
    int tempEsquerdo[tamanhoEsquerdo], tempDireito[tamanhoDireito];
    
    // Preenche os subarrays temporários tempEsquerdo[] e tempDireito[]
    for (int x = 0; x < tamanhoEsquerdo; x++) tempEsquerdo[x] = vetor[inicio + x];
    for (int y = 0; y < tamanhoDireito; y++) tempDireito[y] = vetor[meio + 1 + y];
    
    int i = 0, j = 0, k = inicio;
    
    // Mescla os subarrays temporários de volta no vetor original
    while (i < tamanhoEsquerdo && j < tamanhoDireito) {
        if (tempEsquerdo[i] <= tempDireito[j]) vetor[k++] = tempEsquerdo[i++];
        else vetor[k++] = tempDireito[j++];
    }
    
    // Copia os elementos restantes de tempEsquerdo[], se houver
    while (i < tamanhoEsquerdo) vetor[k++] = tempEsquerdo[i++];
    
    // Copia os elementos restantes de tempDireito[], se houver
    while (j < tamanhoDireito) vetor[k++] = tempDireito[j++];
}

// Função recursiva para ordenar o vetor
void ordenarMerge(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        ordenarMerge(vetor, inicio, meio);  // Ordena a primeira metade
        ordenarMerge(vetor, meio + 1, fim);  // Ordena a segunda metade
        mesclar(vetor, inicio, meio, fim);  // Mescla as duas metades
    }
}

// Função para gerar valores aleatórios no vetor
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

// Função para calcular o tempo de execução do método de ordenação
void calcularTempoExecucao(void (*funcaoOrdenacao)(int[], int, int), int vetor[], int tamanho, const char *descricao) {
    clock_t inicio = clock();
    funcaoOrdenacao(vetor, 0, tamanho - 1);
    clock_t fim = clock();
    double tempoDecorrido = (double)(fim - inicio) / CLOCKS_PER_SEC;
    
    printf("%s: Tempo de execução: %f segundos\n", descricao, tempoDecorrido);
}

int main() {
    int tamanho = 100;
    int vetor[tamanho];
    srand((unsigned int)time(NULL));
  
    gerarVetorAleatorio(vetor, tamanho);
    
    printf("Vetor original:\n");
    exibirVetor(vetor, tamanho);

    calcularTempoExecucao(ordenarMerge, vetor, tamanho, "Mergesort com vetor aleatório");

    printf("\nVetor ordenado:\n");
    exibirVetor(vetor, tamanho);
    
    return 0;
}
