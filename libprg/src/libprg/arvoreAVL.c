#include <libprg/libprg.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct no_avl
{
    int valor;
    int altura; // altura da subárvore
    struct no_avl *esquerda;
    struct no_avl *direita;
} no_avl_t;

no_avl_t* criar_no_avl(int valor)
{
    no_avl_t *no_avl = (no_avl_t*) malloc(sizeof(no_avl_t));
    if (no_avl == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para o nó AVL.\n");
        exit(EXIT_FAILURE);
    }
    no_avl->valor = valor;
    no_avl->esquerda = no_avl->direita = NULL;
    no_avl->altura = 1; // Inicializa a altura como 1
    return no_avl;
}

int altura(no_avl_t *v)
{
    return v ? v->altura : 0;
}

int fatorBalanceamento(no_avl_t *v)
{
    return v ? altura(v->esquerda) - altura(v->direita) : 0;
}

#define max(a,b) (((a) > (b)) ? (a) : (b))

no_avl_t *rotacaoEsquerda(no_avl_t *v)
{
    no_avl_t *u = v->direita;
    v->direita = u->esquerda;
    u->esquerda = v;
    v->altura = 1 + max(altura(v->esquerda), altura(v->direita));
    u->altura = 1 + max(altura(u->esquerda), altura(u->direita));
    return u;
}

no_avl_t *rotacaoDireita(no_avl_t *v)
{
    no_avl_t *u = v->esquerda;
    v->esquerda = u->direita;
    u->direita = v;
    v->altura = 1 + max(altura(v->direita), altura(v->esquerda));
    u->altura = 1 + max(altura(u->direita), altura(u->esquerda));
    return u;
}

no_avl_t *rotacaoDuplaEsquerda(no_avl_t *v)
{
    v->direita = rotacaoDireita(v->direita);
    return rotacaoEsquerda(v);
}

no_avl_t *rotacaoDuplaDireita(no_avl_t *v)
{
    v->esquerda = rotacaoEsquerda(v->esquerda);
    return rotacaoDireita(v);
}

no_avl_t *balancear(no_avl_t *v)
{
    int fb = fatorBalanceamento(v);
    if (fb > 1)
    {
        if (fatorBalanceamento(v->esquerda) > 0)
        {
            return rotacaoDireita(v);
        }
        else
        {
            return rotacaoDuplaDireita(v);
        }
    }
    else if (fb < -1)
    {
        if (fatorBalanceamento(v->direita) < 0)
        {
            return rotacaoEsquerda(v);
        }
        else
        {
            return rotacaoDuplaEsquerda(v);
        }
    }
    return v;
}

no_avl_t *inserirAVL(no_avl_t *v, int valor)
{
    if (v == NULL)
    {
        v = criar_no_avl(valor);
    }
    else if (valor < v->valor)
    {
        v->esquerda = inserirAVL(v->esquerda, valor);
    }
    else if (valor > v->valor)
    {
        v->direita = inserirAVL(v->direita, valor);
    }
    v->altura = 1 + max(altura(v->esquerda), altura(v->direita));
    v = balancear(v);
    return v;
}

no_avl_t *removerAvl(no_avl_t *v, int valor)
{
    if (v == NULL)
    {
        return NULL;
    }
    else if (valor < v->valor)
    {
        v->esquerda = removerAvl(v->esquerda, valor);
    }
    else if (valor > v->valor)
    {
        v->direita = removerAvl(v->direita, valor);
    }
    else
    {
        if (v->esquerda == NULL || v->direita == NULL)
        {
            no_avl_t *temp = v->esquerda ? v->esquerda : v->direita;
            if (temp == NULL)
            {
                free(v);
                v = NULL;
            }
            else
            {
                *v = *temp;
                free(temp);
            }
        }
        else
        {
            no_avl_t *temp = v->esquerda;
            while (temp->direita != NULL)
            {
                temp = temp->direita;
            }
            v->valor = temp->valor;
            v->esquerda = removerAvl(v->esquerda, temp->valor);
        }
    }
    if (v != NULL)
    {
        v->altura = 1 + max(altura(v->esquerda), altura(v->direita));
        v = balancear(v);
    }
    return v;
}

void travessiaPreOrderAVL(no_avl_t *x)
{
    if(x != NULL)
    {
        if(x->esquerda != NULL)
            printf("%d -- %d\n", x->valor, x->esquerda->valor);
        if(x->direita != NULL)
            printf("%d -- %d\n", x->valor, x->direita->valor);

        travessiaPreOrderAVL(x->esquerda);
        travessiaPreOrderAVL(x->direita);
    }
}