#ifndef _VETORDINAMICO_H_
#define _VETORDINAMICO_H_

typedef struct vetorDinamico VetorDinamico;
VetorDinamico *criaVetor(int dim);
int insere_vetor(VetorDinamico *vetor, float v);
int remove_vetor(VetorDinamico *vetor);
int tamanho_vetor(VetorDinamico *vetor);
int redefinir_dim_rlc(VetorDinamico *vetor, int dim_rlc);
int acessa_vetor(VetorDinamico *vetor, int i, float *v);
void libera_vetor(VetorDinamico *vetor);

#endif