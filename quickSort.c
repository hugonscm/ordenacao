#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int particiona(int *lista, int inicio, int fim){
    int esquerda, direita, pivo, aux;
    esquerda = inicio;
    direita = fim;
    pivo = lista[inicio];
    while (esquerda < direita){
        while (esquerda <= fim && lista[esquerda] <= pivo)
            esquerda++;
        while (direita >= 0 && lista[direita] > pivo)
            direita--;
        if (esquerda < direita){
            aux = lista[esquerda];
            lista[esquerda] = lista[direita];
            lista[direita] = aux;
        }
    }
    lista[inicio] = lista[direita];
    lista[direita] = pivo;

    return direita;
}

void quickSort(int *lista, int esquerda, int direita){
    int pivo;
    if(direita > esquerda){
        pivo = particiona(lista, esquerda, direita);
        quickSort(lista, esquerda, pivo-1);
        quickSort(lista, pivo+1, direita);
    }
}

int main() {
    
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    int *vetor = (int*)malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++)
        scanf("%d", &vetor[i]);

    quickSort(vetor, 0, tamanho - 1);

    for (int i = 0; i < tamanho; i++)
        printf("%d ", vetor[i]);

    free(vetor);
    return 0;

}