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
    if (fila->tamanho < fila->capacidade)
    {
//        if (fila->fim <= fila->capacidade)
//        {
            fila->elemento[fila->fim] = elemento;
            fila->tamanho++;
            fila->fim = (fila->fim + 1) % fila->capacidade;
//        }

        //if (fila->fim > fila->capacidade && fila->inicio == fila->capacidade)
//        if (fila->inicio == fila->capacidade)
//        {
//            fila->elemento[fila->fim] = elemento;
//            fila->tamanho++;
//            fila->fim = (fila->fim + 1) % fila->capacidade;
//        }

    }
    else
    {
        printf("\nNão há espaço para novas inserções\n");

    }
}

void imprimirFila(fila_t  *fila)
{
    if (fila->tamanho == 0)
    {
        printf("Fila vazia\n");
        return;
    }

    int i = fila->inicio;
    printf("Elementos da fila: ");
    for (int contador = 0; contador < fila->tamanho; contador++)
    {
        printf("%d ", fila->elemento[i]);
        i = (i + 1) % fila->capacidade; // Avançando para o próximo índice circularmente
    }
    printf("\n");

}

int dequeue(fila_t *fila)
{
    if (fila->tamanho == 0)
    {
        printf("Erro: Fila vazia\n");

    }

    int elementoRemovido = fila->elemento[fila->inicio];

    fila->inicio = (fila->inicio + 1) % fila->capacidade;

    fila->tamanho--;
    printf("\nO elemento removido da fila foi: %d\n", elementoRemovido) ;
    return elementoRemovido;

}

int getHead(fila_t  *fila)
{
    int inicio = fila->elemento[fila->inicio];
    printf("\nO elemento no início da fila é: %d\n", inicio) ;
    return inicio;
}

int getTail(fila_t  *fila)
{
    int fim = fila->elemento[(fila->inicio + (fila->tamanho-1)) % fila->capacidade];
    printf("\nO elemento no início da fila é: %d\n", fim) ;
    return fim;
}

int getSize(fila_t  *fila)
{
    int tamanho = fila->tamanho;
    printf("\nO tamanho da fila é: %d\n", tamanho) ;
    return tamanho;
}

bool isEmpty(fila_t  *fila)
{
    if(fila->tamanho == 0)
    {
        printf("\nA fila se encontra vazia!\n");
        return true;
    }
    else
    {
        printf("\nA fila não se encontra vazia!\n");
        return false;
    }
}
bool isFull(fila_t *fila)
{
    if(fila->tamanho == fila->capacidade)
    {
        printf("\nA fila se encontra cheia!\n");
        return true;
    }
    else
    {
        printf("\nA fila não se encontra cheia!\n");
        return false;
    }

};