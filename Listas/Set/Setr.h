#ifndef _SETR_H_
#define _SETR_H_

typedef float Elemento; 

typedef struct no Setr;

Setr* setr_criar(float info);
int setr_isEmpty(Setr *head);
int setr_size(Setr *head);
int setr_insert(Setr **head, Elemento info);

int setr_exists(Setr *head, Elemento info);

void setr_clear(Setr **head);
int setr_remove(Setr **head, Elemento info);
int ll_insert_sorted(Setr ** head, Elemento info);

#endif