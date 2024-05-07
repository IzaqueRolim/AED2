#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void heapify(int arr[], int n, int i) {
    int maior = i; 
    int esq = 2 * i + 1;
    int dir = 2 * i + 2; 

    if (esq < n && arr[esq] > arr[maior])
        maior = esq;

    if (dir < n && arr[dir] > arr[maior])
        maior = dir;

    // Se o maior não é a raiz
    if (maior != i) {
        trocar(&arr[i], &arr[maior]);
        // Recursivamente heapify a subárvore afetada
        heapify(arr, n, maior);
    }
}

// Função principal para classificar um array de tamanho n
void heapSort(int arr[], int n) {
    // Constrói heap (reorganiza array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extrai um por um dos elementos do heap
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual para o final
        trocar(&arr[0], &arr[i]);
        // chama max heapify na heap reduzida
        heapify(arr, i, 0);
    }
}

// Função para imprimir array de tamanho n
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função de teste
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Array ordenado:\n");
    printArray(arr, n);
    return 0;
}
