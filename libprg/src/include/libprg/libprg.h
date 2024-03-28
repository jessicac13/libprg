#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

//#include <stdio.h>
//#include <stdlib.h>
#include<stdbool.h>
//#include <libprg/libprg.h>

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

int buscaLista(lista_t *lista, int alvo);
int busca_bin_i(lista_t *lista, int alvo);
int busca_bin_r(lista_t *lista, int inicio, int fim, int alvo);
void imprimir_indice_busca(int teste);

typedef struct fila_t fila_t;

fila_t* criarFila(int capacidade);

void enqueue(fila_t *fila, int elemento);
void imprimirFila(fila_t  *fila);
int dequeue(fila_t  *fila);
int getHead(fila_t  *fila);
int getTail(fila_t  *fila);
int getSize(fila_t  *fila);
bool isEmpty(fila_t  *fila);
bool isFull(fila_t  *fila);


#endif /* LIBPRG_H */




