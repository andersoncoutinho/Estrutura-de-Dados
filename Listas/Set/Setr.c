#include "Setr.h"
#include <stddef.h>

struct no {
    Elemento info;
    Setr *proximo;
};

Setr* setr_criar(Elemento info) {
    Setr *novo = (Setr*) malloc(sizeof (Setr*));
    if(novo == NULL) {
        return NULL;
    }
    novo->info = info;
    novo->proximo = NULL;
    return novo;
}

int setr_isEmpty(Setr *head) {
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
    Setr *novo = (Setr*) malloc(sizeof (Setr));
    if(novo == NULL) {
        return 0;
    }

    novo->info = info;
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

int setr_remove(Setr **head, Elemento info) {
    int i;
    for(i = 0; head != NULL; i++) {
        if(head->info == info) {
            return 1;
        }
        head = head->proximo;
    }
    return 0;
}

