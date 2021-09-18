#include "Setr.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
struct no {
    Elemento info;
    Setr *proximo;
};

void setr_criar(Setr **setr) {
    *setr = NULL;
}

Setr* setr_criar_elemento(Elemento info) {
    Setr *novo = (Setr*) malloc(sizeof (Setr*));
    if(novo == NULL) {
        return NULL;
    }
    novo->info = info;
    novo->proximo = NULL;
    return novo;
}

int setr_is_empty(Setr *head) {
    return head == NULL ? 1 : 0;
}

int setr_size(Setr *head) {
    int size;
    for(size = 0; head != NULL; size++) {
        head = head->proximo;
    }

    return size;
}

int setr_insert(Setr **head, Elemento info) {
    if(setr_exists(*head, info)) {
        return 0;
    }
    
    Setr *novo = setr_criar_elemento(info);
    if(novo == NULL) {
        return 0;
    }

    novo->proximo = *head;
    *head = novo;
    
    return 1;
}

int setr_exists(Setr *head, Elemento info) {
    int i;
        
    for(i = 0; head != NULL; i++) {
        if(head->info == info) {
            return 1;
        }
        head = head->proximo;
    }
    return 0;
}

int setr_is_equal(Setr *first, Setr *second) {
    if(setr_size(first) != setr_size(second)) {
        return 0;
    }
    int i;
    for(i = 0; i < setr_size(first); i++) {
        Elemento elemento = *setr_get(first, i);
        if(!setr_exists(second, elemento)) {
            return 0;
        }
    }
    return 1;
}

Elemento* setr_get(Setr *head, int indice) {
    int i;
    // o indice passado deve ser maior igual a 0 e menor que o tamanho da setr
    if(indice >= 0 && indice < setr_size(head)) {
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

Setr* setr_get_interseccao(Setr *first, Setr *second) {
    Setr *novo = NULL;
    int i;
    for(i = 0; i < setr_size(first); i++) {
        Elemento elemento = *setr_get(first, i);
        if(setr_exists(second, elemento)) {
            setr_insert(&novo, elemento);
        }
    }
    return novo;
}

Setr* setr_get_uniao(Setr *first, Setr *second) {
    Setr *novo;
    setr_criar(&novo);

    int i;

    for(i = 0; i < setr_size(first); i++) {
        Elemento elemento = *setr_get(first, i);
        setr_insert(&novo, elemento);
    }

    for(i = 0; i < setr_size(second); i++) {
        Elemento elemento = *setr_get(second, i);
        setr_insert(&novo, elemento);
    }
    return novo;
}



int setr_remove(Setr **head, Elemento info) {
    Setr *anterior = NULL;
    Setr *aux = *head;
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

void setr_clear(Setr **head) {
    Setr *prox = NULL;
    Setr *aux = *head;
    
    if(setr_is_empty(*head))
        return;
    
    while(aux != NULL) {
        prox = aux->proximo;
        free(aux);
        aux = prox;
    }

    *head = NULL;
}

