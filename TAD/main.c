#include <stdio.h>

#include "ponto.h"
#define _N_ 15
int main(void)
{
    Ponto * p[_N_];
    int i;
    for(i=0; i < _N_; i++)
        p[i] = cria_ponto(i/10.0f, (i+1)/10.0f);
    
    for(i=0; i < _N_; i++)
        mostra(p[i]);
    
    for(i=0; i < _N_; i++)
        libera_ponto(p[i]);
    
/*    Ponto * p = cria_ponto(2.0f, 1.0f);
    Ponto * q = cria_ponto(3.4f, 2.1f);
    
    float d = calcula_distancia(p,q);
    if(d >= 0)
        printf("Distancia entre pontos : %f\n", d);
    else
        printf("Falha na memória : %f\n", d);
    
    libera_ponto(p);
    libera_ponto(q);*/
}
