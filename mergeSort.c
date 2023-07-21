#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void merge(int *lista, int *esquerda, int contadorEsquerda, int *direita, int contadorDireita){
    int i = 0, j = 0, k = 0; 
    //i = contador da subLista esquerda
    //j = contador da subLista direita
    //k = contador da subLista agrupada
    while (i<contadorEsquerda && j<contadorDireita){
        if (esquerda[i] < direita[j])
            lista[k++] = esquerda[i++];
        else
            lista[k++] = direita[j++];
    }
    while (i < contadorEsquerda)
        lista[k++] = esquerda[i++];
    
    while (j < contadorDireita)
        lista[k++] = direita[j++];
    
}

void mergeSort(int *lista, int tamanho){
    int meio, i, *esquerda, *direita;
    
    if(tamanho < 2)
        return;
    
    meio = tamanho/2;

    //criando subListas esquerda e direita
    esquerda = (int*)malloc(meio*sizeof(int));
    direita = (int*)malloc((tamanho - meio)*sizeof(int));

    for (i = 0; i < meio; i++)
        esquerda[i] = lista[i];
    for (i = meio; i < tamanho; i++)
        direita[i-meio] = lista[i];
    
    mergeSort(esquerda, meio);
    mergeSort(direita, tamanho-meio);
    merge(lista, esquerda, meio, direita, tamanho-meio);

    free(esquerda);
    free(direita);
}

int main() {
    
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    int vetor[tamanho];

    for (int i = 0; i < tamanho; i++)
        scanf("%d", &vetor[i]);

    mergeSort(vetor, tamanho);
    for (int i = 0; i < tamanho; i++)
        printf("%d ", vetor[i]);

    return 0;

}