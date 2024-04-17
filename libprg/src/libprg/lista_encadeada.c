#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <libprg/libprg.h>

typedef struct no{
    int dado;
    struct no* proximo;
} no_t;

void adicionarListaEncadeada(no_t** inicio, int dado)
{
    no_t* novo = (no_t*) malloc(sizeof (no_t));
    novo->dado = dado;
    novo->proximo = *inicio;
    *inicio = novo;
}

bool removerListaEncadeada(no_t** inicio, int dado)
{
    no_t* atual = *inicio;
    no_t* anterior = NULL;
    while(atual != NULL)
    {
        if (atual->dado == dado)
        {
            if (anterior == NULL)
            {
                *inicio = atual->proximo;
            }
            else
            {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return true;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return false;
}

void destruirListaEncadeada(no_t** inicio)
{
    no_t* atual = *inicio;
    no_t* prox;
    while(atual != NULL)
    {
        prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    *inicio = NULL;
}
no_t* buscarListaEncadeada(no_t **inicio, int dado)
{
    no_t *atual = *inicio;
    no_t *anterior = NULL;
    while (atual != NULL) {
        if (atual->dado == dado) {
            if (anterior == NULL) {
                *inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            return atual;
        }
        anterior = atual;
        atual = atual->proximo;

    }
}
void imprimirListaEncadeada(no_t **inicio)
{
    no_t *atual = *inicio;

    while(atual != NULL)
    {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }

}
