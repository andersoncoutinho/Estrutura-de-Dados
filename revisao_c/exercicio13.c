#include <stdio.h>
#include <ctype.h>

#define QTD_LETRAS 26

int main(void) {
    
    int n = 11;
    char *string = "Hello World";
    int letras[QTD_LETRAS];

    int i;
    for(i = 0; i < QTD_LETRAS; i++) {
        letras[i] = 0;
        int j;
        for(j = 0; j < n; j++) {
            if(tolower(string[j]) == 'a' + i) {
                letras[i]++;
            }
        }
    }

    for(i = 0; i < QTD_LETRAS; i++) {
        if(letras[i] != 0) {
            printf("%c aparece %d vez(es) na string \"%s\"\n", 'A' + i, letras[i], string);
        }
    }





    return 0;
}