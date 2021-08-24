#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int n, i;
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &n);

    int *vetor;
    vetor = malloc(sizeof(int) * n);
    if(vetor == NULL) {
        puts("Memória Insuficiente");
        exit(1);
    }

    for(i = 0; i < n; i++) {
        printf("Informe o valor do indice %d: ", i);
        scanf("%d", &vetor[i]);
    }

    for(i = 0; i < n; i++) {
        printf("Valor no indice %d: %d\n", i, vetor[i]);
    }

    free(vetor);

    return 0;
}