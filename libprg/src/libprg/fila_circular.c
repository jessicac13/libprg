#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <libprg/libprg.h>

struct fila_t {
    int *elemento;
    int capacidade;
    int inicio;
    int fim;
    int tamanho;
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
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;

    fila->elemento = (int*)malloc(fila->capacidade * sizeof(int));
    if (fila->elemento == NULL)
    {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    return fila;
}

void enqueue(fila_t *fila, int elemento)
{
    if (fila->fim <= fila->capacidade)
    {
        fila->elemento[fila->fim] = elemento;
        fila->tamanho++;
        fila->fim++;
    }

    if (fila->fim > fila->capacidade && fila->inicio == fila->capacidade)
    {
        fila->fim = 0;
        fila->elemento[fila->fim] = elemento;
        fila->tamanho++;
        fila->fim++;
    }
    if (fila->fim > fila->capacidade && fila->inicio < fila->capacidade)
    {
        printf("\nNão há espaço para novas inserções\n");
    }
}

void imprimirFila(fila_t  *fila)
{
    printf("Fila de tamanho %d: ", fila->tamanho);
    for (int i = 0; i < fila->tamanho; i++)
    {
        printf("%d ", fila->elemento[i]);
    }
    printf("\n");
}


//enqueue();
//dequeue();
//head();
//tail();
//size();
//empty();
//full();