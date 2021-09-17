/* TAD: Ponto (x,y) */

#ifndef _PONTO_H_
#define _PONTO_H_

typedef struct ponto Ponto;
Ponto * cria_ponto(float x, float y);
void libera_ponto(Ponto *p);
int pega_ponto(Ponto *p, float *x, float *y);
int seta_ponto(Ponto *p, float x, float y);
float calcula_distancia(Ponto *p, Ponto *q);
void mostra(Ponto *p);

#endif
