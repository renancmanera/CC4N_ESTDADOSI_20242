#include <stdio.h>
#include <stdlib.h>

// Definição do nó da árvore
typedef struct No {
    int valor;
    struct No *esquerda, *direita;
} No;

// Função para criar um novo nó
No* novoNo(int valor) {
    No* temp = (No*)malloc(sizeof(No));
    temp->valor = valor;
    temp->esquerda = temp->direita = NULL;
    return temp;
}

// Função para inserir um novo nó na árvore
No* inserir(No* no, int valor) {
    if (no == NULL) return novoNo(valor);

    if (valor < no->valor)
        no->esquerda = inserir(no->esquerda, valor);
    else if (valor > no->valor)
        no->direita = inserir(no->direita, valor);

    return no;
}

// Função para percorrer a árvore em ordem
void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        emOrdem(raiz->direita);
    }
}

// Função principal
int main() {
    No* raiz = NULL;
    raiz = inserir(raiz, 50);
    inserir(raiz, 30);
    inserir(raiz, 20);
    inserir(raiz, 40);
    inserir(raiz, 70);
    inserir(raiz, 60);
    inserir(raiz, 80);

    printf("Percurso em ordem: ");
    emOrdem(raiz);

    return 0;
}