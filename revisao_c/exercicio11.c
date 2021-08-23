#include <stdio.h>

int main(void) {
    
    int n = 14;
    int vetor[] = {7, 3, 2, 12, 5, 13, 230, 12, 540, 10, 12, 23, 18, 29};

    int menor, maior;
    menor = vetor[0];
    maior = vetor[0];
    for(int i = 1; i < n; i++) {
        menor = vetor[i] < menor ? vetor[i] : menor;
        maior = vetor[i] > maior ? vetor[i] : maior;
    }

    printf("Menor: %d\nMaior: %d\n", menor, maior);

    return 0;
}