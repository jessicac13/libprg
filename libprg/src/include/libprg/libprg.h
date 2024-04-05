#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

#include<stdbool.h>

typedef struct {
    double value;
    int error;
} result_t;

typedef enum { SUM, SUB } operation_t;

result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);

typedef struct lista_t lista_t;

lista_t* criarLista(bool ordenada);
void inserirLista(lista_t *lista, int elemento);
void removerLista(lista_t *lista, int alvo);
void imprimirLista(lista_t *lista);
int buscaLista(lista_t *lista, int alvo);
int busca_bin_i(lista_t *lista, int alvo);
int busca_bin_r(lista_t *lista, int inicio, int fim, int alvo);
void imprimir_indice_busca(int teste);

typedef struct fila_t fila_t;

fila_t * criarFila(int capacidade);
void enqueue(fila_t *fila, int elemento);
void imprimirFila(fila_t *fila);
int dequeue(fila_t *fila);
int getHead(fila_t *fila);
int getTail(fila_t *fila);
int getSize(fila_t *fila);
bool isEmpty(fila_t *fila);
bool isFull(fila_t *fila);

lista_t* criarListaContatos(bool ordenada);
void inserirListaContatos(lista_t *lista, char nome[100], char telefone[9], char email[100]);
void imprimirListaContatos(lista_t *lista);
void removerListaContatos(lista_t *lista, char alvo[100]);
int buscaListaContatos(lista_t *lista, char alvo[100]);
void imprimir_indice_busca_contatos(int teste);
void buscarContatos(lista_t *lista, char alvo[100]);

typedef struct pilha_t pilha_t;

pilha_t * criarPilha(int capacidade);
void empilhar(pilha_t *pilha, int elemento);
int desempilhar(pilha_t *pilha);
void imprimirPilha(pilha_t *pilha);
bool isEmptyPilha(pilha_t *pilha);
int getSizePilha(pilha_t *pilha);

#endif /* LIBPRG_H */





