#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int m, n, i, j;
    printf("Informe o tamanho do vetor: ");
    scanf("%d%d", &m, &n);

    
    int **matriz;
    matriz = malloc((sizeof (int*)) * m);
    for(i = 0; i < m; i++) {
        matriz[i] = malloc((sizeof (int)) * n);
    }
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        putchar('\n');
    }

    for(i = 0; i < m; i++) {
        free(matriz[i]);
    }
    free(matriz);


    return 0;
}