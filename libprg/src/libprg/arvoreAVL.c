#include <libprg/libprg.h>
#include <malloc.h>

typedef struct no_avl
{
    int valor;
    int altura; // altura da subárvore
    struct no *esquerda;
    struct no *direita;
} no_avl_t;

int altura(no_avl_t *v)
{
    if (v == NULL)
    {
        return 0;
    }
    else
    {
        return v->altura;
    }
}

int fatorBalanceamento(no_avl_t *v)
{
    if (v == NULL)
    {
        return 0;
    }
    else
    {
        return altura(v->esquerda) - altura(v->direita);
    }
}

#define max(a,b) (((a) > (b)) ? (a) : (b))

no_avl_t *rotacaoEsquerda(no_avl_t *v)
{
    no_avl_t *u = v->direita;

    v->direita = u->esquerda;

    u->esquerda = v;

    v->altura = max(altura(v->esquerda), altura(v->direita)) + 1;

    u->altura = max(altura(u->esquerda), altura(u->direita)) + 1;

    return u;
}

no_avl_t *rotacaoDireita(no_avl_t *v)
{
    no_avl_t *u = v->esquerda;

    v->esquerda = u->direita;

    u->direita = v;

    v->altura = max(altura(v->direita), altura(v->esquerda)) + 1;

    u->altura = max(altura(u->direita), altura(u->esquerda)) + 1;

    return u;
}

no_avl_t *rotacaoDuplaDireita(no_avl_t *v)
{
    v->esquerda = rotacaoEsquerda(v->esquerda);

    return rotacaoDireita(v);
}

no_avl_t *rotacaoDuplaEsquerda(no_avl_t *v)
{
    v->direita = rotacaoEsquerda(v->direita);

    return rotacaoEsquerda(v);
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