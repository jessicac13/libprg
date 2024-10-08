#include <libprg/libprg.h>
#include <malloc.h>

typedef struct no_avl
{
    int valor;
    int altura; // altura da subárvore
    struct no_avl *esquerda;
    struct no_avl *direita;
} no_avl_t;

int contagemRotacoes = 0;

no_avl_t* criarNoAVL(int valor)
{
    no_avl_t *no_avl = (no_avl_t*) malloc(sizeof(no_avl_t));
    no_avl->valor = valor;
    no_avl->esquerda = no_avl->direita = NULL;
    no_avl->altura= 0;

    return no_avl;
}

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

    contagemRotacoes++;

    return u;
}

no_avl_t *rotacaoDireita(no_avl_t *v)
{
    no_avl_t *u = v->esquerda;

    v->esquerda = u->direita;

    u->direita = v;

    v->altura = max(altura(v->esquerda), altura(v->direita)) + 1;

    u->altura = max(altura(u->esquerda), altura(u->direita)) + 1;

    contagemRotacoes++;

    return u;
}

no_avl_t *rotacaoDuplaDireita(no_avl_t *v)
{
    v->esquerda = rotacaoEsquerda(v->esquerda);

    return rotacaoDireita(v);
}

no_avl_t *rotacaoDuplaEsquerda(no_avl_t *v)
{
    v->direita = rotacaoDireita(v->direita);

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

no_avl_t *inserirAVL(no_avl_t *v, int valor)
{
    if (v == NULL)
    {
        v = criarNoAVL(valor);
    }
    else if (valor < v->valor)
    {
        v->esquerda = inserirAVL(v->esquerda, valor);
    }
    else if (valor > v->valor)
    {
        v->direita = inserirAVL(v->direita, valor);
    }
    v->altura= max(altura(v->esquerda), altura(v->direita)) + 1;
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
            no_avl_t *temp = (v->esquerda != NULL) ? v->esquerda : v->direita;
            if (temp == NULL)
            {
                temp = v;
                v = NULL;
            }
            else
            {
                *v = *temp;
            }
            free(temp);
        }
        else
        {
            no_avl_t *aux = v->esquerda;
            while (aux->direita != NULL)
            {
                aux = aux->direita;
            }
            v->valor = aux->valor;
            v->esquerda = removerAvl(v->esquerda, aux->valor);
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

void imprimirTextoGrafo(no_avl_t *raiz)
{
    printf("\n");
    printf("strict graph{\n");
    printf("label=\"Árvore de busca binária\";\n");
    printf("node [shape=\"oval\", color=\"#339966\", style=\"filled\", fontcolor=\"black\"\n");
    printf("\tfixedsize=true];\n");
    travessiaPreOrderAVL(raiz);
    printf("}\n");
}

int contagemRotacao()
{
    return contagemRotacoes;
}

int resetcontagemRotacao()
{
    return contagemRotacoes = 0;
}


bool buscaAVL(no_avl_t  *raiz, int valor)
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
        return buscaAVL(raiz->esquerda, valor);
    }
    return buscaAVL(raiz->direita, valor);
}