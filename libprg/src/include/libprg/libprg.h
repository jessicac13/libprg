#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

typedef struct {
    double value;
    int error;
} result_t;

typedef enum { SUM, SUB } operation_t;

result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);

int busca_lista_desodernada(int lista[], int tamanho_lista, int alvo);
int busca_lista_odernada(int lista[], int tamanho_lista, int alvo);
int busca_bin_i(int lista[], int tamanho_lista, int alvo);
int busca_bin_r(int lista[], int inicio, int fim, int alvo);

#endif
