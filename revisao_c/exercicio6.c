#include <stdio.h>

int main(void) {

    int inicial, final, soma = 0;
    scanf("%d%d", &inicial, &final);

    while(inicial <= final) {
        soma += inicial;
        inicial++;
    }
    printf("%d\n", soma);

    return 0;
}