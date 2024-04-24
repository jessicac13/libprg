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

typedef struct noDuplo{
    int dado;
    struct noDuplo* proximo;
    struct noDuplo* anterior;
} noDuplo_t;

typedef struct noOrdenado{
    int dado;
    struct noOrdenado* proximo;
} noOrdenado_t;

void adicionarListaEncadeada(no_t** inicio, int dado)
{

    no_t* novo = (no_t*) malloc(sizeof(no_t));
    novo->dado = dado;

    if (*inicio == NULL)
    {
        novo->proximo = novo;
    }
    else
    {
        novo->proximo = *inicio;
        no_t* ultimo = *inicio;
        while (ultimo->proximo != *inicio)
        {
            ultimo = ultimo->proximo;
        }
        ultimo->proximo = novo;
    }
        *inicio = novo;
}

void adicionarListaEncadeadaDuplo(noDuplo_t** inicioDuplo, int dado)
{
    noDuplo_t* novo = (noDuplo_t*) malloc(sizeof (noDuplo_t));
    novo->dado = dado;
    novo->proximo = *inicioDuplo;
    novo->anterior = NULL;

    if (*inicioDuplo != NULL)
    {
        (*inicioDuplo)->anterior = novo;
    }

    *inicioDuplo = novo;

}

void adicionarListaEncadeadaO(noOrdenado_t** inicioOrdenado, int dado)
{
    noOrdenado_t *novo = (noOrdenado_t *) malloc(sizeof(noOrdenado_t));
    novo->dado = dado;

    if (*inicioOrdenado == NULL || dado < (*inicioOrdenado)->dado)
    {
        novo->proximo = *inicioOrdenado;
        *inicioOrdenado = novo;

        if (*inicioOrdenado != NULL) {
            noOrdenado_t *ultimo = *inicioOrdenado;
            while (ultimo->proximo != NULL) {
                ultimo = ultimo->proximo;
            }
            ultimo->proximo = *inicioOrdenado;
        }
        return;
    }

    noOrdenado_t *atual = *inicioOrdenado;
    while (atual->proximo != *inicioOrdenado && dado >= atual->proximo->dado)
    {
        atual = atual->proximo;
    }
    novo->proximo = atual->proximo;
    atual->proximo = novo;

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


bool removerListaEncadeadaDuplo(noDuplo_t** inicioDuplo, int dado)
{
    noDuplo_t* atual = *inicioDuplo;
    noDuplo_t* anterior = NULL;
    while(atual != NULL)
    {
        if (atual->dado == dado)
        {
            if (anterior == NULL)
            {
                *inicioDuplo = atual->proximo;
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

bool removerListaEncadeadaO(noOrdenado_t** inicioOrdendo, int dado)
{
    noOrdenado_t* atual = *inicioOrdendo;
    noOrdenado_t* anterior = NULL;
    while(atual != NULL)
    {
        if (atual->dado == dado)
        {
            if (anterior == NULL)
            {
                *inicioOrdendo = atual->proximo;
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


void destruirListaEncadeadaDuplo(noDuplo_t** inicioDuplo)
{
    noDuplo_t* atual = *inicioDuplo;
    no_t* prox;
    while(atual != NULL)
    {
        prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    *inicioDuplo = NULL;
}

void destruirListaEncadeadaO(noOrdenado_t** inicioOrdenado)
{
    noOrdenado_t* atual = *inicioOrdenado;
    noOrdenado_t* prox;
    while(atual != NULL)
    {
        prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    *inicioOrdenado = NULL;
}

no_t* buscarListaEncadeada(no_t **inicio, int dado)
{
    no_t *atual = *inicio;
    no_t *anterior = NULL;
    while (atual != NULL)
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
            return atual;
        }
        anterior = atual;
        atual = atual->proximo;

    }
    return NULL;
}

noOrdenado_t* buscarListaEncadeadaO(noOrdenado_t **inicioOrdenado, int dado)
{
    noOrdenado_t  *atual = *inicioOrdenado;
    noOrdenado_t  *anterior = NULL;
    while (atual != NULL)
    {
        if (atual->dado == dado)
        {
            if (anterior == NULL)
            {
                *inicioOrdenado = atual->proximo;
            }
            else
            {
                anterior->proximo = atual->proximo;
            }
            return atual;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return NULL;
}


noDuplo_t* buscarListaEncadeadaDuplo(noDuplo_t **inicioDuplo, int dado)
{
    noDuplo_t *atual = *inicioDuplo;
    noDuplo_t *anterior = NULL;
    while (atual != NULL)
    {
        if (atual->dado == dado)
        {
            if (anterior == NULL)
            {
                *inicioDuplo = atual->proximo;
            }
            else
            {
                anterior->proximo = atual->proximo;
            }
            return atual;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return NULL;
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

void imprimirListaEncadeadaDuplo(noDuplo_t **inicioDuplo)
{
    noDuplo_t *atual = *inicioDuplo;

    while(atual != NULL)
    {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
}

void imprimirListaEncadeadaO(noOrdenado_t **inicioOrdenado)
{
    noOrdenado_t *atual = *inicioOrdenado;

    while(atual != NULL)
    {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }

}


