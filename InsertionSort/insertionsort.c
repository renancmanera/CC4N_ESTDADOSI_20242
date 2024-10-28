#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[SIZE];
    srand(time(0));

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    printf("Antes de ordenar:\n");
    printArray(arr, SIZE);

    insertionSort(arr, SIZE);

    printf("Depois de ordenar:\n");
    printArray(arr, SIZE);

    return 0;
}