#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <libprg/libprg.h>

struct lista_t {
    int *elemento;
    int tamanho;
    int capacidade;
    bool ordenada;
};

lista_t* criarLista(bool ordenada)
{
    lista_t *lista = (lista_t*)malloc(sizeof(lista_t));
    if (lista == NULL)
    {
        printf("Erro de alocação de memória\n");
        exit(1);
    }

    lista->tamanho = 0;
    lista->capacidade = 10;
    lista->ordenada = ordenada;

    lista->elemento = (int*)malloc(lista->capacidade * sizeof(int));
    if (lista->elemento == NULL)
    {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    return lista;
}

void inserirLista(lista_t *lista, int elemento)
{
    if (lista->tamanho >= lista->capacidade)
    {
        lista->capacidade *= 2;
        lista->elemento = (int*)realloc(lista->elemento, lista->capacidade * sizeof(int));
        if (lista->elemento == NULL)
        {
            printf("Erro de realocação de memória\n");
            exit(1);
        }
    }
    if(lista->ordenada == true)
    {
        int posicao = 0;
        while (posicao < lista->tamanho && lista->elemento[posicao] < elemento)
        {
            posicao++;
        }

        for (int i = lista->tamanho; i > posicao; i--)
        {
            lista->elemento[i] = lista->elemento[i - 1];
        }

        lista->elemento[posicao] = elemento;
        lista->tamanho++;
    }
    if(lista->ordenada == false)
    {
        lista->elemento[lista->tamanho] = elemento;
        lista->tamanho++;

    }
}

void removerLista(lista_t *lista, int alvo)
{
    int indice = buscaLista(lista, alvo);
    if (indice < 0 || indice >= lista->tamanho)
    {
        printf("\nÍndice fora dos limites da lista\n");
        return;
    }

    if(lista->ordenada == true)
    {
        for (int i = indice; i < lista->tamanho - 1; i++)
        {
            lista->elemento[i] = lista->elemento[i + 1];
        }
        lista->tamanho--;
    }
    if(lista->ordenada == false)
    {
        lista->elemento[indice] = lista->elemento[lista->tamanho - 1];
        lista->tamanho--;
    }
}

void imprimirLista(lista_t *lista)
{
    printf("\nLista de tamanho %d: ", lista->tamanho);
    for (int i = 0; i < lista->tamanho; i++)
    {
        printf("%d ", lista->elemento[i]);
    }
    printf("\n");
}

int buscaLista(lista_t *lista, int alvo)
{
    if (lista->ordenada == false)
    {
        for(int i=0; i<=lista->tamanho; i++)
        {
            if(alvo == lista->elemento[i])
            {
                return i;
            }
        }
        return -1;
    }
    if (lista->ordenada == true)
    {
        int i = 0;
        while (lista->elemento[i]< alvo)
        {
            i = i+1;
        }
        if(i == lista->tamanho || lista->elemento[i] != alvo)
        {
            return -1;
        }
        return i;
    }
}


int busca_bin_i(lista_t *lista, int alvo)
{
    int meio;
    int inicio = 1;
    int fim = lista->tamanho;
    while (inicio <= fim)
    {
        meio = inicio + ((fim - inicio)/2);
        if(lista->elemento[meio] == alvo)
        {
            return meio;
        }
        else if(lista->elemento[meio] < alvo)
        {
            inicio = meio + 1;
        }
        else   fim = meio -1;
    }
    return -1;
}

int busca_bin_r(lista_t *lista, int inicio, int fim, int alvo)
{
    int meio;
    if (inicio <= fim)
    {
        meio = inicio + ((fim - inicio) / 2);
        if (lista->elemento[meio] == alvo)
        {

            return meio;
        }
        if (lista->elemento[meio] > alvo)
        {
            return busca_bin_r(lista, inicio, meio - 1, alvo);
        }
        else
        {
            return busca_bin_r(lista, meio + 1, fim, alvo);
        }

    }
    return -1;
}

void imprimir_indice_busca(int teste)
{
    if (teste > -1)
    {
        printf("\nIndice do elemento de busca: %d\n", teste);
    }
    else
    {
        printf("\nElemento não se encontra na lista\n");
    }
}