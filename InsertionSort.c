#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;

        /* Move os elementos do arr[0..i-1], que são
           maiores que a chave, para uma posição à frente
           de sua posição atual */
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
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
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Array ordenado:\n");
    printArray(arr, n);
    return 0;
}
