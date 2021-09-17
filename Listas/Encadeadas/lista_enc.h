#ifndef _LISTA_ENCADEADA_H_
#define _LISTA_ENCADEADA_H_

//Esse tipo pode ser alterar para definir o tipo de elemento que a lista deve armazenar
typedef int Elemento; 

typedef struct no No;
typedef struct no Lista;

void lista_criar(No **lista);
No *lista_criar_no(Elemento info);
Elemento* lista_get(No *head, int indice);
int lista_inserir_no_inicio(No **head, Elemento info);
int lista_inserir_no_fim(No **head, Elemento info);
int lista_is_empty(No *head);
int lista_size(No *head);
int lista_exists(No *head, Elemento info);
void lista_clear(No **head);
int lista_remove(No **head, Elemento info);
int lista_remove_first(No **head);
int lista_remove_last(No **head);
int lista_remove_middle(No *head, int indice);

#endif