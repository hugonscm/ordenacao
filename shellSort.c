#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void shellSort(int *v, int n) {
    int i, j, h = 1, aux;

    while (h < n/3)
        h = 3 * h + 1;
    
    while (h > 0) {
        for(i = h; i < n; i++){
            aux = v[i];
            j = i;

            while (j >= h && aux < v[j-h]) {
                v[j] = v[j-h];
                j = j - h;
            }
            v[j] = aux;
        }
        h = (h-1)/3;
    }
}

int main(){
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    int vetor[tamanho];
    for (int i = 0; i < tamanho; i++)
        scanf("%d", &vetor[i]);

    shellSort(vetor, tamanho);

    printf("Vetor ordenado: ");
    for (int i = 0; i < tamanho; i++)
        printf(" %d", vetor[i]);
    
    return 0;
}
