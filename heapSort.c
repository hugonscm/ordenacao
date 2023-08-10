#include <stdio.h>

// Função para ajustar um heap máximo
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        maxHeapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Construindo o heap máximo
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        maxHeapify(arr, i, 0);
    }
}

int main() {
    
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    int vetor[tamanho];
    for (int i = 0; i < tamanho; i++)
        scanf("%d", &vetor[i]);

    heapSort(vetor, tamanho);

    printf("Vetor ordenado: ");
    for (int i = 0; i < tamanho; i++)
        printf(" %d", vetor[i]);

    return 0;
}
