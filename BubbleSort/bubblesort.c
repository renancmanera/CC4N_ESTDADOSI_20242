#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }

    printf("Antes de ordenar:\n");
    printArray(arr, SIZE);

    bubbleSort(arr, SIZE);

    printf("Depois de ordenar:\n");
    printArray(arr, SIZE);

    return 0;
}