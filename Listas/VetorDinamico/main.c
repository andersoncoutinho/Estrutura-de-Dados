#include <stdio.h>
#include "vetorDinamico.h"

// Código de teste:

void imprime_vetor(VetorDinamico *vetor) {
    int tamanhoVetor;
    float aux;

    tamanhoVetor = tamanho_vetor(vetor);
    printf("Tamanho: %d\n", tamanhoVetor);
    for(int i = 0; i < tamanhoVetor; i++) {
        acessa_vetor(vetor, i, &aux);
        printf("%.2f ", aux);
    }
    printf("\n\n");
}

int main(void) {

    VetorDinamico *vetor;

    printf("Criando vetor: \n\n");
    vetor = criaVetor(5);
    imprime_vetor(vetor);

    printf("Inserindo dados: \n\n");
    insere_vetor(vetor, 1);
    insere_vetor(vetor, 2);
    insere_vetor(vetor, 3);
    insere_vetor(vetor, 4);
    imprime_vetor(vetor);

    printf("Removendo ultimo elemento: \n\n");
    remove_vetor(vetor);
    imprime_vetor(vetor);

    printf("Usando a dimensao de realocao padrao, 10...\n");
    printf("Inserindo novo elemento e aumentando vetor: \n\n");
    insere_vetor(vetor, 5);
    imprime_vetor(vetor);

    printf("Redefinindo dimensao de realocao para 4...\n");
    printf("Inserindo elementos ate novo aumento do vetor: \n\n");
    redefinir_dim_rlc(vetor, 4);
    for(int i = 6; i < 16; i++) {
        insere_vetor(vetor, i);
    }
    imprime_vetor(vetor);

    libera_vetor(vetor);

    return 0;
}
