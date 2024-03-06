#include <stdio.h>
#include <stdlib.h>
#include <libprg/libprg.h>


int busca_lista_desodernada(int lista[], int tamanho_lista, int alvo)
{
    for(int i=1; i<tamanho_lista; i++)
    {
        if(alvo == lista[i])
        {
            return 1;
        }
    }
    return 0;
}

int busca_lista_odernada(int lista[], int tamanho_lista, int alvo)
{
    int i = 1;
    while (lista[i]< alvo)
    {
        i = i+1;
    }
    if(i == tamanho_lista || lista[i] != alvo)
    {
        return 0;
    }
    return 1;
}

int busca_bin_i(int lista[], int tamanho_lista, int alvo)
{
    int meio;
    int inicio = 1;
    int fim = tamanho_lista;
    while (inicio <= fim)
    {
        meio = inicio + ((fim - inicio)/2);
        if(lista[meio] == alvo)
        {
            return 1;
        }
        else if(lista[meio] < alvo)
        {
            inicio = meio + 1;
        }
        else   fim = meio -1;
    }
    return 0;
}

int busca_bin_r(int lista[], int inicio, int fim, int alvo)
{
    int meio;
    if (inicio <= fim)
    {
        meio = inicio + ((fim - inicio) / 2);
        if (lista[meio] == alvo)
        {
            return 1;
        }
        if (lista[meio] > alvo)
        {
            busca_bin_r(lista, inicio, meio - 1, alvo);
        }
        return busca_bin_r(lista, meio + 1, fim, alvo);
    }
    return 0;
}

//int *inserir_ordenada(int lista[], int x)
//{
//    int *lista = (int*) calloc( sizeof (int));
//}