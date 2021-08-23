#include <stdio.h>

int main(void) {

    double nota1, nota2, nota3, media;

    scanf("%lf%lf%lf", &nota1, &nota2, &nota3);

    media = (nota1 + nota2 + nota3) / 3;

    if(media >= 7) {
        puts("Aprovado!");
    } else if (media >= 4) {
        puts("Recuperacao");
    } else {
        puts("Reprovado");
    }

    return 0;
}