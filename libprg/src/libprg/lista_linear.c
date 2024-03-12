#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <libprg/libprg.h>

//struct lista_t {
//    int *elemento;
//    int tamanho;
//    int capacidade;
//    bool ordenada;
//};
void criarlista(lista_t *lista, int capacidade, bool ordenada)
{
    lista->elemento = (int*)malloc(capacidade * sizeof(int));
    if (lista->elemento == NULL)
    {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    lista->tamanho = 0;
    lista->capacidade = capacidade;
    lista->ordenada = ordenada;
}

void inserirlista(lista_t *lista, int elemento)
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
    else
    {
        lista->elemento[lista->tamanho] = elemento;
        lista->tamanho++;
        lista->ordenada = false;
    }

}

void remover(lista_t *lista, int indice)
{
    if(lista->ordenada == true)
    {
        if (indice < 0 || indice >= lista->tamanho)
        {
            printf("Índice fora dos limites da lista\n");
            return;
        }

        for (int i = indice; i < lista->tamanho - 1; i++)
        {
            lista->elemento[i] = lista->elemento[i + 1];
        }
        lista->tamanho--;
    }
    else
    {
        if (indice < 0 || indice >= lista->tamanho)
        {
            printf("Índice fora dos limites da lista\n");
            return;
        }

        lista->elemento[indice] = lista->elemento[lista->tamanho - 1];
        lista->tamanho--;
    }
}

void imprimirlista(lista_t *lista)
{
    printf("Lista de tamanho %d: ", lista->tamanho);
    for (int i = 0; i < lista->tamanho; i++)
    {
        printf("%d ", lista->elemento[i]);
    }
    printf("\n");
}

//int busca_lista_desodernada(struct lista_t lista, int alvo)
//{
//    for(int i=1; i<lista.tamanho; i++)
//    {
//        if(alvo == lista.elemento[i])
//        {
//            lista.ordenada = true;
//            return lista.ordenada;
//        }
//    }
//    lista.ordenada = true;
//    return lista.ordenada;
//}
//
//int busca_lista_odernada(struct lista_t lista, int alvo)
//{
//    int i = 1;
//    while (lista.elemento[i]< alvo)
//    {
//        i = i+1;
//    }
//    if(i == lista.tamanho || lista.elemento[i] != alvo)
//    {
//        lista.ordenada = true;
//        return lista.ordenada;
//    }
//    lista.ordenada = false;
//    return lista.ordenada;;
//}
//
//int busca_bin_i(struct lista_t lista, int alvo)
//{
//    int meio;
//    int inicio = 1;
//    int fim = lista.tamanho;
//    while (inicio <= fim)
//    {
//        meio = inicio + ((fim - inicio)/2);
//        if(lista.elemento[meio] == alvo)
//        {
//            lista.ordenada = true;
//            return lista.ordenada;
//        }
//        else if(lista.elemento[meio] < alvo)
//        {
//            inicio = meio + 1;
//        }
//        else   fim = meio -1;
//    }
//    lista.ordenada = false;
//    return lista.ordenada;
//}
//
//int busca_bin_r(struct lista_t lista, int inicio, int fim, int alvo)
//{
//    int meio;
//    if (inicio <= fim)
//    {
//        meio = inicio + ((fim - inicio) / 2);
//        if (lista.elemento[meio] == alvo)
//        {
//            lista.ordenada = true;
//            return lista.ordenada;
//        }
//        if (lista.elemento[meio] > alvo)
//        {
//            busca_bin_r(lista, inicio, meio - 1, alvo);
//        }
//        return busca_bin_r(lista, meio + 1, fim, alvo);
//    }
//    lista.ordenada = false;
//    return lista.ordenada;
//}
//
////void inserir_desordenado(int **lista, int *tamanho_lista, int valor) {
////
////    (*tamanho_lista)++;
////
////    *lista = (int *)realloc(*lista, (*tamanho_lista) * sizeof(int));
////    if (*lista == NULL) {
////        printf("Erro ao realocar memória.\n");
////        exit(1);
////    }
////
////    // Adiciona o novo valor ao final da lista
////    (*lista)[(*tamanho_lista) - 1] = valor;
////}
//
