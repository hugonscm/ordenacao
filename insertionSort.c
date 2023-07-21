#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    int vetor[tamanho];
    int chave, j;
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }

    for (int i = 1; i < tamanho; i++)
    {
        chave = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > chave)
        {
            vetor[j+1] = vetor[j];
            j = j-1;
        }
        vetor[j+1] = chave;
    }

    printf("Vetor ordenado: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf(" %d", vetor[i]);
    }
    
    return 0;
}