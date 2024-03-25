#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <libprg/libprg.h>
struct fila_t {
    int *elemento;
    int capacidade;

};

fila_t* criarFila(int capacidade)

{
    fila_t *fila = (fila_t*)malloc(sizeof(fila_t));
    if (fila == NULL)
    {
        printf("Erro de alocação de memória\n");
        exit(1);
    }

    fila->capacidade = capacidade;

    fila->elemento = (int*)malloc(fila->capacidade * sizeof(int));
    if (fila->elemento == NULL)
    {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    return fila;
}

//enqueue();
//dequeue();
//head();
//tail();
//size();
//empty();
//full();