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
typedef struct {
    int *elemento;
    int tamanho;
    int capacidade;
    bool ordenada;
} lista_t;

void criarlista(lista_t *lista, int capacidade, bool ordenada);
void inserirlista(lista_t *lista, int elemento);
void imprimirlista(lista_t *lista);

#endif /* LIBPRG_H */

//int busca_lista_desodernada(struct lista_t lista, int alvo);
//int busca_lista_odernada(struct lista_t lista, int alvo);
//int busca_bin_i(struct lista_t lista, int alvo);
//int busca_bin_r(struct lista_t lista, int inicio, int fim, int alvo);


