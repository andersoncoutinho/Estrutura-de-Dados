#include <stdio.h>
#include <stdlib.h>

int* gerarVetorInvertido(int *vetor, int n) {

    int *novoVetor = malloc((sizeof (int)) * n);
    if(novoVetor == NULL) {
        puts("Memória Insuficiente");
        exit(1);
    }
    int i;
    for(i = 0; i < n; i++) {
        novoVetor[n-(i+1)] = vetor[i];
    }
    
    return novoVetor;
}


int main(void) {

    int n = 20, i;
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 4,1,6,6,9,4,3,2};
    
    int *novoVetor;
    novoVetor = gerarVetorInvertido(vetor, n);

    for(i = 0; i < n; i++) {
        printf("%d ", novoVetor[i]);
    }
    putchar('\n');
    free(novoVetor);

    return 0;
}