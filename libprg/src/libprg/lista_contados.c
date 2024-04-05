#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <string.h>
#include <libprg/libprg.h>

struct contatos {
    char nome[100];
    char telefone[9];
    char email[100];
};

struct lista_t {
    struct contatos *elemento;
    int tamanho;
    int capacidade;
    bool ordenada;
};

lista_t* criarListaContatos(bool ordenada)
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

    lista->elemento = (struct contatos*)malloc(lista->capacidade * sizeof(struct contatos));
    if (lista->elemento == NULL)
    {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    return lista;
}

void inserirListaContatos(lista_t *lista, char nome[100], char telefone[9], char email[100]) {
    if (lista->tamanho >= lista->capacidade) {
        lista->capacidade *= 2;
        lista->elemento = (struct contatos*)malloc(lista->capacidade * sizeof(struct contatos));
        if (lista->elemento == NULL) {
            printf("Erro de realocação de memória\n");
            exit(1);
        }
    }
//    if(lista->ordenada == true)
//    {
//        int posicao = 0;
//        while (posicao < lista->tamanho && lista->elemento[posicao] < elemento)
//        {
//            posicao++;
//        }
//
//        for (int i = lista->tamanho; i > posicao; i--)
//        {
//            lista->elemento[i] = lista->elemento[i - 1];
//        }
//
//        lista->elemento[posicao] = elemento;
//        lista->tamanho++;
//    }
    if (lista->ordenada == false)
    {
        strncpy(lista->elemento[lista->tamanho].nome, nome, sizeof(lista->elemento[lista->tamanho].nome) - 1);
        lista->elemento[lista->tamanho].nome[sizeof(lista->elemento[lista->tamanho].nome) - 1] = '\0';

        strncpy(lista->elemento[lista->tamanho].telefone, telefone,
                sizeof(lista->elemento[lista->tamanho].telefone) - 1);
        lista->elemento[lista->tamanho].telefone[sizeof(lista->elemento[lista->tamanho].telefone) - 1] = '\0';

        strncpy(lista->elemento[lista->tamanho].email, email, sizeof(lista->elemento[lista->tamanho].email) - 1);
        lista->elemento[lista->tamanho].email[sizeof(lista->elemento[lista->tamanho].email) - 1] = '\0';

        lista->tamanho++;
    }
}

void imprimirListaContatos(lista_t *lista)
{
    printf("\nLista de Contatos:\n");

    for (int i = 0; i < lista->tamanho; i++)
    {
        printf("Contato %d:\n", i + 1);
        printf("Nome: %s\n", lista->elemento[i].nome);
        printf("Telefone: %s\n", lista->elemento[i].telefone);
        printf("Email: %s\n", lista->elemento[i].email);
        printf("\n");
    }
}
//
void removerListaContados(lista_t *lista, char alvo[100])
{
    int indice = buscaListaContatos(lista, alvo);

    if (indice < 0 || indice >= lista->tamanho)
    {
        printf("\nÍndice fora dos limites da lista\n");
        return;
    }

//    if(lista->ordenada == true)
//    {
//        for (int i = indice; i < lista->tamanho - 1; i++)
//        {
//            lista->elemento[i] = lista->elemento[i + 1];
//        }
//        lista->tamanho--;
//    }
    if(lista->ordenada == false)
    {

        strcpy(lista->elemento[indice].telefone, lista->elemento[lista->tamanho - 1].telefone);

        strcpy(lista->elemento[indice].nome, lista->elemento[lista->tamanho - 1].nome);

        strcpy(lista->elemento[indice].email, lista->elemento[lista->tamanho - 1].email);

        lista->tamanho--;
    }
}

int buscaListaContatos(lista_t *lista, char alvo[100])
{
    if (lista->ordenada == false)
    {
        for(int i=0; i<=lista->tamanho; i++)
        {
            if(strcmp(alvo, lista->elemento[i].nome) == 0)
            {
                return i;
            }
        }
        return -1;
    }

////    if (lista->ordenada == true)
////    {
////        int i = 0;
////        while (lista->elemento[i]< alvo)
////        {
////            i = i+1;
////        }
////        if(i == lista->tamanho || lista->elemento[i] != alvo)
////        {
////            return -1;
////        }
////        return i;
////    }
}
//
//
//int busca_bin_i(lista_t *lista, int alvo)
//{
//    int meio;
//    int inicio = 1;
//    int fim = lista->tamanho;
//    while (inicio <= fim)
//    {
//        meio = inicio + ((fim - inicio)/2);
//        if(lista->elemento[meio] == alvo)
//        {
//            return meio;
//        }
//        else if(lista->elemento[meio] < alvo)
//        {
//            inicio = meio + 1;
//        }
//        else   fim = meio -1;
//    }
//    return -1;
//}
//
//int busca_bin_r(lista_t *lista, int inicio, int fim, int alvo)
//{
//    int meio;
//    if (inicio <= fim)
//    {
//        meio = inicio + ((fim - inicio) / 2);
//        if (lista->elemento[meio] == alvo)
//        {
//
//            return meio;
//        }
//        if (lista->elemento[meio] > alvo)
//        {
//            return busca_bin_r(lista, inicio, meio - 1, alvo);
//        }
//        else
//        {
//            return busca_bin_r(lista, meio + 1, fim, alvo);
//        }
//
//    }
//    return -1;
//}
//
void imprimir_indice_busca_contatos(int teste)
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