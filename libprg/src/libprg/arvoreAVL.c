#include <libprg/libprg.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no_avl
{
    int valor;
    int altura; // altura da subárvore
    struct no_avl *esquerda;
    struct no_avl *direita;
} no_avl_t;

// Cria um novo nó AVL
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
    no_avl->altura = 1; // A altura inicial de um nó folha é 1
    return no_avl;
}

// Retorna a altura de um nó
int altura(no_avl_t *v)
{
    return (v == NULL) ? 0 : v->altura;
}

// Calcula o fator de balanceamento
int fatorBalanceamento(no_avl_t *v)
{
    return (v == NULL) ? 0 : altura(v->esquerda) - altura(v->direita);
}

// Função para obter o máximo de dois valores
#define max(a, b) (((a) > (b)) ? (a) : (b))

// Rotação simples à esquerda
no_avl_t *rotacaoEsquerda(no_avl_t *v)
{
    no_avl_t *u = v->direita;
    v->direita = u->esquerda;
    u->esquerda = v;

    // Atualiza a altura dos nós
    v->altura = max(altura(v->esquerda), altura(v->direita)) + 1;
    u->altura = max(altura(u->esquerda), altura(u->direita)) + 1;

    return u;
}

// Rotação simples à direita
no_avl_t *rotacaoDireita(no_avl_t *v)
{
    no_avl_t *u = v->esquerda;
    v->esquerda = u->direita;
    u->direita = v;

    // Atualiza a altura dos nós
    v->altura = max(altura(v->esquerda), altura(v->direita)) + 1;
    u->altura = max(altura(u->esquerda), altura(u->direita)) + 1;

    return u;
}

// Rotação dupla à direita
no_avl_t *rotacaoDuplaDireita(no_avl_t *v)
{
    v->esquerda = rotacaoEsquerda(v->esquerda);
    return rotacaoDireita(v);
}

// Rotação dupla à esquerda
no_avl_t *rotacaoDuplaEsquerda(no_avl_t *v)
{
    v->direita = rotacaoDireita(v->direita);
    return rotacaoEsquerda(v);
}

// Balanceia um nó
no_avl_t *balancear(no_avl_t *v)
{
    int fb = fatorBalanceamento(v);
    if (fb > 1)
    {
        if (fatorBalanceamento(v->esquerda) >= 0)
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
        if (fatorBalanceamento(v->direita) <= 0)
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

// Insere um novo valor na árvore AVL
no_avl_t *inserirAVL(no_avl_t *v, int valor)
{
    if (v == NULL)
    {
        return criar_no_avl(valor);
    }
    if (valor < v->valor)
    {
        v->esquerda = inserirAVL(v->esquerda, valor);
    }
    else if (valor > v->valor)
    {
        v->direita = inserirAVL(v->direita, valor);
    }
    else
    {
        return v; // Valor já existe na árvore
    }

    // Atualiza a altura do nó atual
    v->altura = 1 + max(altura(v->esquerda), altura(v->direita));

    // Balanceia o nó atual
    return balancear(v);
}

// Remove um valor da árvore AVL
no_avl_t *removerAvl(no_avl_t *v, int valor)
{
    if (v == NULL)
    {
        return NULL;
    }
    if (valor < v->valor)
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
            free(v);
            return temp;
        }
        no_avl_t *temp = v->esquerda;
        while (temp->direita != NULL)
        {
            temp = temp->direita;
        }
        v->valor = temp->valor;
        v->esquerda = removerAvl(v->esquerda, temp->valor);
    }

    if (v == NULL)
    {
        return NULL;
    }

    // Atualiza a altura do nó atual
    v->altura = 1 + max(altura(v->esquerda), altura(v->direita));

    // Balanceia o nó atual
    return balancear(v);
}

// Função para travessia em pré-ordem
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
