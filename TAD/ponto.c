#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "ponto.h"
#ifndef _PONTO_C_
#define _PONTO_C_

struct ponto{
    float x;
    float y;
    };
/*    
struct ponto{
    float c[2];
};
*/

Ponto* cria_ponto(float x, float y)
{
    Ponto *p = (Ponto*) malloc(sizeof(Ponto));
    if(p) // p != NULL
    {
        p->x = x;
        p->y = y;
    }
   
   return p;
}

void libera_ponto(Ponto *p)
{
    free(p);
}

int pega_ponto(Ponto *p, float *x, float *y)
{
    if(p)
    {
        *x = p->x;
        *y = p->y;
        return 1;
    }
    
    return 0;
}

int seta_ponto(Ponto *p, float x, float y)
{
    if(p)
    {
        p->x = x;
        p->y = y;
        return 1;
    }
    
    return 0;    
}

float calcula_distancia(Ponto *p, Ponto *q)
{
    if(p && q)
        return (sqrt(pow(p->x-q->x,2)+pow(p->y-q->y,2)));
        
    return -1.0f;
}

void mostra(Ponto *p)
{
    if(p)
        printf("(%.2f,%.2f)\n", p->x, p->y);
}

#endif
