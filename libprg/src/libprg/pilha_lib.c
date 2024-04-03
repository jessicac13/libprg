#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <libprg/libprg.h>

struct pilha_t {
    int *elemento;
    int capacidade;
    int fim;
    int tamanho;
};

pilha_t * criarPilha(int capacidade)

{
    pilha_t *pilha = (pilha_t*)malloc(sizeof(pilha_t));
    if (pilha == NULL)
    {
        printf("Erro de alocação de memória\n");
        exit(1);
    }

    pilha->capacidade = capacidade;
    pilha->fim = 0;
    pilha->tamanho = 0;

    pilha->elemento = (int*)malloc(pilha->capacidade * sizeof(int));
    if (pilha->elemento == NULL)
    {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    return pilha;
}

void empilhar(pilha_t *pilha, int elemento)
{
    if (pilha->tamanho < pilha->capacidade)
    {
        pilha->elemento[pilha->fim] = elemento;
        pilha->tamanho++;
        pilha->fim++;
    }
    else
    {
        printf("\nNão há espaço para novas inserções\n");

    }
}

int desempilhar(pilha_t *pilha)
{
    int topo = pilha->elemento[(pilha->tamanho) - 1];
    (pilha->tamanho)- 1;
    return topo;

}

void imprimirPilha(pilha_t *pilha)
{
    printf("\nPilha de tamanho %d: ", pilha->tamanho);
    for (int i = 0; i < pilha->tamanho; i++)
    {
        printf("%d ", pilha->elemento[i]);
    }
    printf("\n");
}

int getSizePilha(pilha_t *pilha)
{
    int tamanho = pilha->tamanho;
    printf("\nO tamanho da fila é: %d\n", tamanho) ;
    return tamanho;
}


bool isEmptyPilha(pilha_t *pilha)
{
    if(pilha->tamanho == 0)
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

