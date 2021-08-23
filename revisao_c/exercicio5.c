#include <stdio.h>

int main(void) {

    int inicial, final, i;
    scanf("%d%d", &inicial, &final);

    i = inicial;
    while(i < final) {
        printf("%d ", i);
        i++;
    }
    printf("%d\n", i);
    
    i = inicial;
    do {
        printf("%d ", i);
        i++;
    } while(i < final);
    printf("%d\n", i);

    for(i = inicial; i < final; i++) {
        printf("%d ", i);
    }
    printf("%d\n", i);

    return 0;
}