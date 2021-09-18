#include <stdio.h>
#include "Setr.h"

int main(void) {
    
    Setr *set, *set2, *set3, *intersect, *uniao;
    int i;
    setr_criar(&set);
    setr_criar(&set2);
    setr_criar(&set3);
    setr_criar(&intersect);
    setr_criar(&uniao);

    setr_insert(&set, 1);
    setr_insert(&set, 2);
    setr_insert(&set, 1);
    setr_insert(&set, 3);
    setr_insert(&set, 4);
    setr_insert(&set, 15);
    setr_insert(&set, 23);
    setr_insert(&set, 15);
    setr_insert(&set, 1);

    setr_insert(&set2, 100);
    setr_insert(&set2, 99);
    setr_insert(&set2, 98);
    setr_insert(&set2, 15);
    setr_insert(&set2, 23);
    setr_insert(&set2, 100);
    setr_insert(&set2, 98);
    setr_insert(&set2, 100);

    setr_insert(&set3, 15);
    setr_insert(&set3, 98);
    setr_insert(&set3, 100);
    setr_insert(&set3, 23);
    setr_insert(&set3, 99);

    intersect = setr_get_interseccao(set, set2);

    puts("Set 1:");
    for(i = 0; i < setr_size(set); i++) {
        printf("Indice %d: %.2f\n", i, *setr_get(set, i));
    }

    puts("\nSet 2:");
    for(i = 0; i < setr_size(set2); i++) {
        printf("Indice %d: %.2f\n", i, *setr_get(set2, i));
    }

    puts("\nSet 3:");
    for(i = 0; i < setr_size(set3); i++) {
        printf("Indice %d: %.2f\n", i, *setr_get(set3, i));
    }

    puts("\nRemovendo elemento 1 do set 1...");
    setr_remove(&set, 1);
    puts("\nSet 1:");
    for(i = 0; i < setr_size(set); i++) {
        printf("Indice %d: %.2f\n", i, *setr_get(set, i));
    }

    uniao = setr_get_uniao(set, set2);
    puts("\nUniao Set 1 e Set 2");
    for(i = 0; i < setr_size(uniao); i++) {
        printf("Indice %d: %.2f\n", i, *setr_get(uniao, i));
    }
    
    puts("\nInters. Set 1 e Set 2");
    for(i = 0; i < setr_size(intersect); i++) {
        printf("Indice %d: %.2f\n", i, *setr_get(intersect, i));
    }

    puts("\nTeste se valor 3 existe do Set 1:");
    printf("Existe? %d\n", setr_exists(set, 3));

    puts("\nTeste se valor 3 existe do Set 2:");
    printf("Existe? %d\n", setr_exists(set2, 3));

    puts("\nVerificar se Set 1 e 2 são iguais");
    printf("São iguais? %d\n", setr_is_equal(set, set2));

    puts("\nVerificar se Set 2 e 3 são iguais");
    printf("São iguais? %d\n", setr_is_equal(set2, set3));

    puts("\nTamanho dos sets");
    printf("Set 1: %d\n", setr_size(set));
    printf("Set 2: %d\n", setr_size(set2));
    printf("Set 3: %d\n", setr_size(set3));
    printf("Set interseccao: %d\n", setr_size(intersect));
    printf("Set uniao: %d\n", setr_size(uniao));
    
    puts("\nTestando se Sets sao vazios");
    printf("Set 1: %d\n", setr_is_empty(set));
    printf("Set 2: %d\n", setr_is_empty(set2));
    printf("Set 3: %d\n", setr_is_empty(set3));
    printf("Set interseccao: %d\n", setr_is_empty(intersect));
    printf("Set uniao: %d\n", setr_is_empty(uniao));

    puts("\nLimpando set uniao...");
    setr_clear(&uniao);
    printf("Set uniao esta vazio? %d\n", setr_is_empty(uniao));

    return 0;
}