#ifndef _VETORDINAMICO_C_
#define _VETORDINAMICO_C_
#include <stdio.h>
#include <stdlib.h>
#include "vetorDinamico.h"
#define DIM_RLC 10

struct vetorDinamico {
    int n; // Indice do vetor dinâmico.
    int dim; // Dimensão total do vetor dinâmico.
    int dim_rlc; // Dimensão de realocação.
    float *v; // Ponteiro para armazenar o endereço de memória do vetor dinâmico.
};

// Funcionalidade: Cria vetor
VetorDinamico *criaVetor(int dim) {

        VetorDinamico *vetor =  (VetorDinamico *) malloc(sizeof(VetorDinamico));
        // Alocação do vetor dinâmico.

        if(vetor == NULL) {
            return NULL;
        }
        vetor->v = (float *) malloc(dim * sizeof(float));
        // Alocação do vetor.

        if(vetor->v == NULL) {
            return NULL;
        }

        vetor->n = 0;
        // Iniciando indice como "0".
        vetor->dim = dim;
        // Iniciando dimensão.
        vetor->dim_rlc = DIM_RLC;
        // Iniciando dimensão de realocação com valor padrão "10".

        return vetor;
}

// Funcionalidade: Inserir um valor na próxima posição vazia do vetor dinâmico. 
// Em caso de memória não alocada é realizada uma realocação automática, no qual 
// a nova dimensão do vetor vai ser igual a dimensão anterior incrementada com a
// dimensão de realocação.
int insere_vetor(VetorDinamico *vetor, float v) {
    if(vetor) {
        // Se o vetor existir execute as instruções abaixo.
        if(vetor->n == vetor->dim) {
            // Quando for necessário realocar espaços na memória execute as instruções abaixo.

            // Será necessário realocar espaços na memória quando a próxima posição que vai receber o valor for igual
            // a dimensão total momentânea do vetor dinâmico.

            vetor->v = (float*) realloc(vetor->v, (vetor->dim+vetor->dim_rlc)*sizeof(float));

            if(vetor->v) {
                // Verificar se a operação de realocação foi realizada com sucesso.
                vetor->dim = vetor->dim+vetor->dim_rlc;
                // Nova dimensão do vetor: dimensão anterior + dimensão constante de realocação.

                vetor->v[vetor->n] = v;
                vetor->n++;
                // Adicionar valor na próxima posição vazia e incrementar o indice.
        
                return 1;
            }
            return -1;
        }

        vetor->v[vetor->n] = v;
        vetor->n++;
        // Se não for necessário realocar, adicionar valor na próxima posição vazia e incrementar o indice.

        return 1;
    }
    
    return -1;
}

// Funcionalidade: Remover elemento da última posição.
int remove_vetor(VetorDinamico *vetor) {
    if(vetor && vetor->n > 0) {
        // Se existir e tiver mais de um elemento, execute as instruções abaixo.
        vetor->v = (float*) realloc(vetor->v, (vetor->dim-1)*sizeof(float));

        if(vetor->v) {
            // Verificar se a operação de realocação foi realizada com sucesso.
            if(vetor->n == vetor->dim)
                vetor->n--;
            // Correção do indice, caso esteja na última posição.
            
            vetor->v[vetor->dim] = 0;
            vetor->dim--;
            // Nova dimensão do vetor: dimensão anterior - 1.


            return 1;
        }

        return -1;
    }

    return -1;
}

// Funcionalidade: Acessar o valor da posição "i" do vetor dinâmico.
int acessa_vetor(VetorDinamico *vetor, int i, float *v) {
    if(vetor &&  (0 <= i <= vetor->dim)) {
        // Se o vetor existir e a posição desejada estiver entre 0 e o tamanho do vetor dinâmico
        // execute as instruções abaixo. 
        *v = vetor->v[i];

        return 1;
    }

    return -1;
}

// Funcionalidade: Retornar o tamanho do vetor dinâmico.
int tamanho_vetor(VetorDinamico *vetor) {
    if(vetor) {
        // Se o vetor existir execute as instruções abaixo.
        return vetor->dim;
    }
    return -1;
}

// Funcionalidade: Redefinir dimensão de realocação.
int redefinir_dim_rlc(VetorDinamico *vetor, int dim_rlc) {
    if(vetor && dim_rlc > 0) {
        // Se existir e a dimensão informada for maior que zero, execute as instruções abaixo.
        vetor->dim_rlc = dim_rlc;

        return 1;
    }
    
    return -1;
}

// Funcionalidade: Liberar o vetor dinâmico da memória.
void libera_vetor(VetorDinamico *vetor) {
    if(vetor) {
        // Se o vetor existir execute as instruções abaixo.
        
        free(vetor->v);
        free(vetor);
        // Liberar vetor dinâmico.
    }
}

#endif