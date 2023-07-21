#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    int vetor[tamanho];
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }
    
    int menor, aux, temp, troca;
    
    for (aux = 0; aux < tamanho-1; aux++) //percorre do inicio ate tamanho-1
    {
        menor = aux; //menor recebe a posiçao atual
        for(temp = aux + 1; temp < tamanho; temp++){ //percorre da posiçao aux+1 ate o final
            if(vetor[temp] < vetor[menor]) //testa se o valor da posicao atual é menor que o menor valor
                menor = temp; //menor recebe o indice do menor valor
        }
        if(aux != menor){ //se a posicao atual for diferente da posicao do menor valor, ocorre a troca
            troca = vetor[aux];
            vetor[aux] = vetor[menor];
            vetor[menor] = troca;
        }
    }

    printf("Vetor ordenado: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf(" %d", vetor[i]);
    }
    

    return 0;
}