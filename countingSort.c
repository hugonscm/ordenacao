#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countingSort(int arr[], int n) {
    // Encontre o valor máximo no array
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Crie um array de contagem e inicialize com zeros
    int count[max + 1];
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Conte a ocorrência de cada elemento
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Imprima o array de contagem
    for (int i = 0; i <= max; i++) {
        printf("%d ", count[i]);
    }
    printf("\n");

    // Atualize o array de contagem com as posições corretas
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Crie um array temporário para armazenar os elementos ordenados
    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copie os elementos ordenados de volta para o array original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int capacity = 100; // Capacidade inicial do vetor
    int *arr = (int *)malloc(capacity * sizeof(int));
    
    char input[1001]; // Tamanho máximo da entrada
    fgets(input, sizeof(input), stdin);

    int n = 0; // Número de elementos inseridos até agora
    int value;

    char *token = strtok(input, " ");
    while (token != NULL) {
        sscanf(token, "%d", &value);

        if (n == capacity) {
            capacity *= 2;
            arr = (int *)realloc(arr, capacity * sizeof(int));
            if (arr == NULL) {
                printf("Erro na alocação de memória.\n");
                return 1;
            }
        }

        arr[n] = value;
        n++;

        token = strtok(NULL, " ");
    }

    countingSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
