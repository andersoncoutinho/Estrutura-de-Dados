#include <stdio.h>
#include "lista_enc.h"

int main(void) {

    No *lista;
    lista_criar(&lista);
    printf("Esta vazia: %d\nTamanho: %d\n\n", lista_is_empty(lista), lista_size(lista));

    lista_inserir_no_fim(&lista, 15);
    lista_inserir_no_fim(&lista, 13);
    lista_inserir_no_inicio(&lista, 7);
    lista_inserir_no_inicio(&lista, 2); 
    puts("Quatro elementos inseridos");
    printf("Esta vazia: %d\nTamanho: %d\n", lista_is_empty(lista), lista_size(lista));
    for(int i = 0; i < lista_size(lista); i++) {
        printf("Elemento %d: %d\n", i, *lista_get(lista, i));
    }

    puts("\nRemovendo ultimo");
    lista_remove_last(&lista);
    for(int i = 0; i < lista_size(lista); i++) {
        printf("Elemento %d: %d\n", i, *lista_get(lista, i));
    }
    puts("\nRemovendo ultimo");
    lista_remove_last(&lista);
    for(int i = 0; i < lista_size(lista); i++) {
        printf("Elemento %d: %d\n", i, *lista_get(lista, i));
    }
    puts("\nRemovendo primeiro");
    lista_remove_first(&lista);
    for(int i = 0; i < lista_size(lista); i++) {
        printf("Elemento %d: %d\n", i, *lista_get(lista, i));
    }
    printf("Existe o elemento 7? %d\n", lista_exists(lista, 7));
    printf("Existe o elemento 14? %d\n", lista_exists(lista, 14));

    puts("Adicionando 2 no inicio, depois 3 no fim, depois 1 no inicio");
    lista_inserir_no_inicio(&lista, 2);
    lista_inserir_no_fim(&lista, 3);
    lista_inserir_no_inicio(&lista, 1);
    puts("\nRemovendo o elemento 7...");
    lista_remove(&lista, 7);
    for(int i = 0; i < lista_size(lista); i++) {
        printf("Elemento %d: %d\n", i, *lista_get(lista, i));
    }

    lista_clear(&lista);
    puts("\nClear...");
    printf("Esta vazia: %d\nTamanho: %d\n", lista_is_empty(lista), lista_size(lista));

    lista_inserir_no_fim(&lista, 15);
    lista_inserir_no_fim(&lista, 13);
    lista_inserir_no_inicio(&lista, 7);
    lista_inserir_no_inicio(&lista, 2); 

    for(int i = 0; i < lista_size(lista); i++) {
        printf("Elemento %d: %d\n", i, *lista_get(lista, i));
    }
    lista_remove_middle(lista, 1);
    for(int i = 0; i < lista_size(lista); i++) {
        printf("Elemento %d: %d\n", i, *lista_get(lista, i));
    }
    
    return 0;
}