#ifndef _SETR_H_
#define _SETR_H_

typedef float Elemento; 

typedef struct no Setr;

void setr_criar(Setr **setr);
Setr* setr_criar_elemento(Elemento info);
int setr_insert(Setr **head, Elemento info);
int setr_exists(Setr *head, Elemento info);
int setr_is_equal(Setr *first, Setr *second);
int setr_size(Setr *head);
int setr_is_empty(Setr *head);
int setr_remove(Setr **head, Elemento info);
void setr_clear(Setr **head);
Elemento* setr_get(Setr *head, int indice);
Setr* setr_get_interseccao(Setr *first, Setr *second);
Setr* setr_get_uniao(Setr *first, Setr *second);

#endif


