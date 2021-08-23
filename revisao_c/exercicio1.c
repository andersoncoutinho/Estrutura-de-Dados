#include <stdio.h>

#define PI 3.1415

int main(void) {

    double raio, area;

    scanf("%lf", &raio);

    area = PI * raio*raio;
    printf("Area: %.2lf\n", area);

    return 0;
}