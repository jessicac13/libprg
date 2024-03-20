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

// Definição da estrutura lista_t
typedef struct lista_t lista_t;

void criarLista(lista_t *lista, int capacidade, bool ordenada);
void inserirLista(lista_t *lista, int elemento);
void imprimirLista(lista_t *lista);
void removerLista(lista_t *lista, int alvo);



int buscaLista(lista_t *lista, int alvo);
int busca_bin_i(lista_t *lista, int alvo);
int busca_bin_r(lista_t *lista, int inicio, int fim, int alvo);

void imprimir_indice_busca(int teste);

#endif /* LIBPRG_H */




