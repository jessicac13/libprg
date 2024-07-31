#include <libprg/libprg.h>
#include <malloc.h>

typedef struct no_arvore {
    int valor;
    struct no_arvore *esquerda;
    struct no_arvore *direita;
} no_arvore_t;

no_arvore_t* criar_no_arvore(int valor)
{
    no_arvore_t *no_arvore = (no_arvore_t*) malloc(sizeof(no_arvore_t));
    no_arvore->valor = valor;
    no_arvore->esquerda = no_arvore->direita = NULL;
    return no_arvore;
}

void destruir_no_arvore(no_arvore_t *no_arvore)
{
    if (no_arvore != NULL)
    {
        destruir_no_arvore(no_arvore->esquerda);
        destruir_no_arvore(no_arvore->direita);
        free(no_arvore);
    }
}

// todo nó é raiz de uma subárvore
no_arvore_t  *inserir_valor_arvore(no_arvore_t  *raiz, int valor)
{
    if (raiz == NULL)
    {
        return criar_no_arvore(valor);
    }
    else if (valor < raiz->valor)
    {
        raiz->esquerda = inserir_valor_arvore(raiz->esquerda, valor);
    }
    else if (valor > raiz->valor)
    {
        raiz->direita = inserir_valor_arvore(raiz->direita, valor);
    }
    return raiz;
}

bool busca_arvore(no_arvore_t  *raiz, int valor)
{
    if (raiz == NULL)
    {
        return false;
    }
    if (valor == raiz->valor)
    {
        return true;
    }
    if (valor < raiz->valor)
    {
        return busca_arvore(raiz->esquerda, valor);
    }
    return busca_arvore(raiz->direita, valor);
}

no_arvore_t *remover_valor_arvore(no_arvore_t *raiz, int valor)
{
    if (raiz == NULL)
    {
        return raiz;
    }
    if (valor < raiz->valor)
    {
        raiz->esquerda = remover_valor_arvore(raiz, valor);
    } else if (valor > raiz->valor)
    {
         raiz->direita = remover_valor_arvore(raiz, valor);
    } else
    {
    // IF nó folha ou nó com um filho
    // ELSE nó com dois filhos

    }
    return raiz;
}