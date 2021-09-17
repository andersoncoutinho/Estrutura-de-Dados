#include "lista_enc.h"
#include <stddef.h>
#include <stdlib.h>

//para alterar o tipo de lista basta modificar o tipo int pelo desejado

struct no {
    Elemento info;
    No *proximo;
};

void criar_lista(No **lista) {
    *lista = NULL;
}

No *ll_create_no(int info) {
    No *no = (No*) malloc(sizeof(No));

    if(no) {
        no->info = info;
        no->proximo = NULL;
    }

    return no;
}

int ll_is_empty(No *lhead) {
    return lhead == NULL ? 1 : 0;
}

int ll_size(No *lhead) {
    int size;

    for(size = 0;  lhead != NULL; size++) {
        lhead = lhead->proximo;
    }
    return size;
}

// retorna 1 em caso de sucesso e 0 caso contrário
int ll_insert_first(No **lhead, int info) {
    // cria um nó auxiliar a ser inserido na lista com a informação fornecida
    No *aux = ll_create_no(info);

    //verifica se o nó foi de fato criado
    if(aux == NULL)
        return 0;
    
    // faz o atributo próximo do nó criado apontar para o nó que antes era o primeiro da lista;
    aux->proximo = *lhead;
    //faz o nó inicial receber o endereço do nó criado, tornado-o o primeiro nó da lista
    *lhead = aux;
    return 1;
}

int ll_insert_last(No **lhead, int info) {
    
    //tratamento caso a lista esteja vazia


    No *aux = ll_create_no(info);
    if(aux == NULL) {
        return 0;
    }

    No *ultimo = *lhead;
    while(ultimo->proximo != NULL) {
        ultimo = ultimo->proximo;
    }


    ultimo->proximo = aux;
    aux->proximo = NULL;

    return 1;
}

int ll_exists(No *lhead, int info) {

    if(ll_is_empty(lhead)) {
        return 0;
    }

    while(lhead != NULL) {
        if(lhead->info == info) {
            return 1;
        }
        lhead = lhead->proximo;
    }

    return 0;

}

void ll_clear(No **lhead) {
    No *prox = NULL;
    No *aux = *lhead;
    
    if(ll_is_empty(*lhead))
        return;
    
    while(aux != NULL) {
        prox = aux->proximo;
        free(aux);
        aux = prox;
    }

    *lhead = NULL;
}

int ll_remove(No **lhead, int info) {
    No *anterior = NULL;
    No *aux = *lhead;
    int found = 0;

    while(aux != NULL) {
        if(aux->info == info) {
            found = 1;
            break;
        }
        anterior = aux;
        aux = aux->proximo;
    }

    if(found) {
        if(anterior==NULL) {
            *lhead = aux->proximo;
            free(aux);
            return 1;
        }
        anterior->proximo = aux->proximo;
        free(aux);
        return 1;
    }
    return 0;
}

int ll_insert_sorted(No **lhead, int info) {
    if(ll_is_empty(*lhead)) {
        return ll_insert_first(lhead,info);
    }

    No *new = ll_create_no(info);

    if(new == NULL) {
        return 0;
    }

    No *anterior = NULL;
    No *aux = *lhead;
    while(aux != NULL && aux->info < info) {
        anterior = aux;
        aux = aux->proximo;
    }

    if(anterior == NULL) {
        new->proximo = *lhead;
        *lhead = new;
        return 1;
    }

    new->proximo = anterior->proximo;
    anterior->proximo = new;
}
