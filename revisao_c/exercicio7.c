#include <stdio.h>
#include <math.h>

int ehPrimo(int numero) {
    int i;

    if(numero == 1 || (numero % 2 == 0 && numero != 2)) {
        return 0;
    }

    for(i = 3; i < sqrt(numero); i+=2) {
        if(numero % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main(void) {
    
    int numero;
    
    scanf("%i", &numero);

    if(ehPrimo(numero)) {
        puts("Prime");
    } else {
        puts("Not Prime");
    }

    return 0;
}