#include <stdio.h>
#include "lista_enc.h"

int main(void) {

    No *lista;
    lista = NULL;
    
    
    printf("%d\n", ll_is_empty(lista));
    lista = ll_create_no(2);
    printf("%d\n", ll_is_empty(lista));
    ll_clear(&lista);
    printf("%d\n", ll_is_empty(lista));
    return 0;
}