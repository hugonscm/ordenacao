#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    int vetor[tamanho];
    int aux;
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < tamanho-1; i++)
    {
        for (int i = 0; i < tamanho-1; i++)
        {
            if (vetor[i] > vetor[i+1])
            {
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
            }
            
        }
        
    }

    printf("Vetor ordenado: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf(" %d", vetor[i]);
    }
    
    return 0;
}