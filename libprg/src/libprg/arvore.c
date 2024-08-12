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
        raiz->esquerda = remover_valor_arvore(raiz->esquerda, valor);
    } else if (valor > raiz->valor)
    {
         raiz->direita = remover_valor_arvore(raiz->direita, valor);
    } else
    {
        // IF nó folha ou nó com um filho
        // ELSE nó com dois filhos
        if (raiz->direita || raiz->esquerda == NULL)
        {
            if(raiz->esquerda == NULL)
            {
                remover_valor_arvore(raiz->direita, valor);
            }
            if (raiz->direita == NULL)
            {
                remover_valor_arvore(raiz->esquerda, valor);
            }

        }
        else
        {
            remover_valor_arvore(raiz->direita, valor);
            remover_valor_arvore(raiz->esquerda, valor);
        }

    }
    return raiz;
}

void travessiaInOrder(no_arvore_t *x)
{
   if(x!=NULL)
   {
       travessiaInOrder(x->esquerda);
       printf("%d, ",x->valor);
       travessiaInOrder(x->direita);
   }
}

void travessiaPreOrder(no_arvore_t *x)
{
    if(x!=NULL)
    {
        printf("%d, ",x->valor);
        travessiaPreOrder(x->esquerda);
        travessiaPreOrder(x->direita);
    }
}

void travessiaPosOrder(no_arvore_t *x)
{
    if(x!=NULL)
    {
        travessiaPosOrder(x->esquerda);
        travessiaPosOrder(x->direita);
        printf("%d, ",x->valor);
    }
}

void percursoLargura(no_arvore_t* x)
{
    fila_t *fila;
    fila = criarFila(4);

    while (x!=NULL)
    {
        printf("%d, ",x->valor);
        if(x->esquerda!=NULL)
        {
            enqueue(fila, x->esquerda->valor);
        }
        if(x->direita!=NULL)
        {
            enqueue(fila, x->direita->valor);
        }
        x->valor = dequeue(fila);
    }
}