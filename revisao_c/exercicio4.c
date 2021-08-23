#include <stdio.h>
#include <math.h>

typedef struct {
    double x1;
    double x2;
} tRaizes;

double calcularDelta(double a, double b, double c) {
    double delta;

    delta = b*b - 4*a*c;

    return delta;
}

tRaizes calcularRaizes(double a, double b, double c, double delta) {
    tRaizes raizes;

    raizes.x1 = (-b + sqrt(delta)) / 2*a;
    raizes.x2 = (-b - sqrt(delta)) / 2*a;

    return raizes;
}

int main(void) {

    double a, b, c, delta;
    
    scanf("%lf%lf%lf", &a, &b, &c);

    delta = calcularDelta(a, b, c);

    if(delta < 0) {
        puts("Nao existem raizes reais");
    } else {
        tRaizes raizes = calcularRaizes(a, b, c, delta);

        printf("x1 = %lf\nx2 = %lf\n", raizes.x1, raizes.x2);
    }

    return 0;
}