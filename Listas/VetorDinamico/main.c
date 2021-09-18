#include <stdio.h>
#include "vetorDinamico.h"

// Código de teste:

int main(void) {

    VetorDinamico *vetor;
    // Vetor dinâmico.
    float inserir;
    // Valor a ser inserido.
    float aux;
    int aux2;
    // Variáveis auxiliares de acesso.
    int n;
    // Dimensão.
    int op_01, op_02;
    // Variáveis de opção.
    int tamanho_vetorV;
    // Tamanho do vetor.

    printf("Deseja um vetor de que dimensao: ");
    scanf("%d", &n);

    vetor = criaVetor(n);

    while(1) {
        printf("Escolha uma opcao: \n\n1- Inserir um valor\n2- Remover um valor\n3- Mostrar vetor + tamanho\n4- Redefinir tamanho da dimensao de realocacao\n5- Sair\n\n");
        scanf("%d", &op_02);
        printf("\n");

        if(op_02 == 5)
            break;
        
        if(op_02 == 1) {
            printf("Digite um valor: ");
            scanf("%f", &inserir);

            aux2 = insere_vetor(vetor, inserir);

            if(aux2 == 1) {
                printf("Inserido com sucesso!\n\n");
            }else {
                printf("Falha ao inserir elemento!\n\n");
            }
        }

        if(op_02 == 2) {
            aux2 = remove_vetor(vetor);

            if(aux2 == 1) {
                printf("Ultimo valor removido com sucesso!\n\n");
            }else {
                printf("Falha ao remover ultimo elemento!\n\n");
            }
        }

        if(op_02 == 3) {
            tamanho_vetorV = tamanho_vetor(vetor);


            if(tamanho_vetorV == -1) {
                printf("Falha ao calcular tamanho!\n");
            }else {
                printf("Tamanho: %d\n\n", tamanho_vetorV);
            }

            for(int i = 0; i< tamanho_vetorV; i++) {
                aux2 = acessa_vetor(vetor, i, &aux);

                if(aux2 == 1) {
                    printf("%.2f \n", aux);
                }else {
                    printf("Error\n");
                }
            }
            printf("\n");
        }

        if(op_02 == 4) {
            printf("Digite a nova dimensao de realocacao: ");
            scanf("%d", &n);

            aux2 = redefinir_dim_rlc(vetor, n);

            if(aux2 == 1) {
                printf("Dimensao de realocacao redefinida com sucesso!\n\n");
            }else {
                printf("Nao foi possivel redefinir a dimesao de realocacao do vetor!\n\n");
            }
        }
    }

    libera_vetor(vetor);

    return 0;
}
