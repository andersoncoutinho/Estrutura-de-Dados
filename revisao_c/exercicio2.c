#include <stdio.h>

int main(void) {

    int numero;

    scanf("%d", &numero);

    if((numero % 2) == 0) {
        puts("Eh par!");
    } else {
        puts("Eh impar!");
    }

    return 0;
}