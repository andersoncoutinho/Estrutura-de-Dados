#include "lista_enc.h"
#include <stddef.h>
#include <stdlib.h>

struct no {
    Elemento info;
    No *proximo;
};

// cria uma lista vazia
void lista_criar(No **lista) {
    *lista = NULL;
}

// retorna o endereço de memória do nó criado em caso de sucesso e NULL caso contrário
No *lista_criar_no(int info) {
    No *no = (No*) malloc(sizeof(No));

    if(no) {
        no->info = info;
        no->proximo = NULL;
    }

    return no;
}

// retorna 1 em caso de sucesso e 0 caso contrário
int lista_inserir_no_inicio(No **head, Elemento info) {

    No *novo = lista_criar_no(info);
    
    if(novo == NULL) return 0;
    //faz o atributo ponteiro do nó criado apontar para o antigo primeiro elemento
    novo->proximo = *head;
    //faz que o novo elemento seja o primeiro item da lista
    *head = novo;
    return 1;

}

// retorna 1 em caso de sucesso e 0 caso contrário
int lista_inserir_no_fim(No **head, Elemento info) {
    No *novo = lista_criar_no(info);
    if(novo == NULL) {
        return 0;
    }

    // se a lista estiver vazia, então o nó inserido será o único elemento da lista
    if(lista_is_empty(*head)) {
        *head = novo;
        return 1;
    }

    // caso a lista não esteja vazia, procura-se o último nó da lista, que pode ser identificado através
    // de seu atributo ponteiro que armazena o valor NULL
    No *aux = *head;
    while(aux->proximo != NULL){
        aux = aux->proximo;
    }
    // o atributo ponteiro do ultimo no que antes era NULL passa agora a apontar para o nó inserido
    aux->proximo = novo;
    return 1;
}

// retornar, como ponteiro, o valor de um elemento de um índice da lista caso ele exista, caso contrário retorna NULL
Elemento* lista_get(No *head, int indice) {
    int i;
    // o indice passado deve ser maior igual a 0 e menor que o tamanho da lista
    if(indice >= 0 && indice < lista_size(head)) {
        for(i = 0; i <= indice; i++) {
            if(i == indice) {
                Elemento *info = (Elemento*) malloc(sizeof(Elemento));
                *info = head->info;
                return info;
            }
            head = head->proximo;
        }
    }

    return NULL;
}
//retorna 1 caso a lista esteja vazia e 0 caso contrário
int lista_is_empty(No *head) {
    // head nulo significa que a lista não possui nenhum elemento
    return head == NULL ? 1 : 0;
}

// retorna o tamanho da lista
int lista_size(No *head) {
    int size;
    // soma-se a quantidade de elementos até chegar no último nó
    for(size = 0;  head != NULL; size++) {
        head = head->proximo;
    }
    return size;
}

// retorna 1 caso o elemento passado exista na lista e 0 caso contrário
int lista_exists(No *head, Elemento info) {
    // se a lista está vazia o elemento não existe
    if(lista_is_empty(head)) {
        return 0;
    }

    // percorre-se a lista até chegar no último elemento
    while(head != NULL) {
        //caso o elemento seja encontrado retorna-se 1
        if(head->info == info) {
            return 1;
        }
        head = head->proximo;
    }

    return 0;

}

// remove todos os elementos da lista
void lista_clear(No **head) {
    No *prox = NULL;
    No *aux = *head;
    
    // se a lista já está vazia nada precisa ser feito
    if(lista_is_empty(*head))
        return;
    
    // percorre elemento a elemento
    while(aux != NULL) {
        //salva o endereço do proximo nó antes de liberar o espaço em memória do nó atual
        prox = aux->proximo;
        //libera o espaço do nó atual
        free(aux);
        aux = prox;
    }

    *head = NULL;
}

// remove um elemento específico da lista
int lista_remove(No **head, Elemento info) {
    No *anterior = NULL;
    No *aux = *head;
    int found = 0;

    // procura pelo elemento na lista inteira
    while(aux != NULL) {
        if(aux->info == info) {
            found = 1;
            break;
        }
        anterior = aux;
        aux = aux->proximo;
    }

    
    if(found) {
        // se o elemento anterior é NULL isso significa que o primeiro elemento da lista será removido e portanto
        // o head deve agora apontar para o segundo elemento
        if(anterior==NULL) {
            *head = aux->proximo;
            free(aux);
            return 1;
        }
        // caso contrário o atributo ponteiro do nó anterior ao nó removido deve agora apontar para o endereço do nó que vem após o nó removido
        anterior->proximo = aux->proximo;
        free(aux);
        return 1;
    }
    return 0;
}

// retorna 1 caso o primeiro no seja removido e 0 caso a lista esteja vazia
int lista_remove_first(No **head) {
    if(*head != NULL) {
        No *aux = *head;
        *head = aux->proximo;
        free(aux);
        return 1;
    }
    return 0;
}

// retorna 1 caso o primeiro no seja removido e 0 caso a lista esteja vazia
int lista_remove_last(No **head) {
    // se a lista estã vazia não há o que fazer
    if(*head == NULL) return 0;

    No *aux = *head;
    No *anterior = NULL;
    while(aux->proximo != NULL) {
        anterior = aux;
        aux = anterior->proximo;
    }

    // se anterior é nulo significa que a lista só possui um no
    if(anterior == NULL) {
        free(aux);
        *head = NULL;
        return 1;
    }

    anterior->proximo = NULL;
    free(aux);
    return 1;

}

int lista_remove_middle(No *head, int indice) {
    int i;
    if(indice > 0 && indice < lista_size(head)-1) {
        No *aux = NULL;
        for(i = 0; i < indice; i++) {
            aux = head;
            head = head->proximo;
        }
        aux->proximo = head->proximo;
        free(head);
        return 1;
    }
    return 0;
}