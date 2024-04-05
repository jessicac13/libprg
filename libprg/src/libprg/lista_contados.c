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
    if(lista->ordenada == true)
    {
        int posicao = 0;
        while (posicao < lista->tamanho && strcmp(lista->elemento[posicao].nome, nome) < 0)
        {
            posicao++;
        }

        for (int i = lista->tamanho; i > posicao; i--)
        {
            strcpy(lista->elemento[i].nome, lista->elemento[i - 1].nome);
            strcpy(lista->elemento[i].telefone, lista->elemento[i - 1].telefone);
            strcpy(lista->elemento[i].email, lista->elemento[i - 1].email);
        }

        strcpy(lista->elemento[posicao].nome, nome);
        lista->elemento[posicao].nome[sizeof(lista->elemento[posicao].nome) - 1] = '\0';

        strcpy(lista->elemento[posicao].telefone, telefone);
        lista->elemento[posicao].telefone[sizeof(lista->elemento[posicao].telefone) - 1] = '\0';

        strcpy(lista->elemento[posicao].email, email);

        lista->tamanho++;
    }
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

void removerListaContatos(lista_t *lista, char alvo[100])
{
    int indice = buscaListaContatos(lista, alvo);

    if (indice < 0 || indice >= lista->tamanho)
    {
        printf("\nÍndice fora dos limites da lista\n");
        return;
    }

    if(lista->ordenada == true)
    {
        for (int i = indice; i < lista->tamanho - 1; i++)
        {
            strcpy(lista->elemento[i].nome, lista->elemento[i + 1].nome);
            strcpy(lista->elemento[i].telefone, lista->elemento[i + 1].telefone);
            strcpy(lista->elemento[i].email, lista->elemento[i + 1].email);
        }
        lista->tamanho--;
    }
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

    if (lista->ordenada == true)
    {
        int i = 0;
        while (strcmp(lista->elemento[i].nome,alvo) < 0)
        {
            i = i+1;
        }
        if(i == lista->tamanho || strcmp(lista->elemento[i].nome, alvo) != 0)
        {
            return -1;
        }
        return i;
    }
}

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

void buscarContatos(lista_t *lista, char alvo[100])
{
    int encontrados = 0;
    for (int i = 0; i < lista->tamanho; i++)
    {
        if (strstr(lista->elemento[i].nome, alvo) != NULL)
        {
            printf("\nNome: %s, Telefone: %s, Email: %s\n", lista->elemento[i].nome, lista->elemento[i].telefone, lista->elemento[i].email);
            encontrados++;
        }
    }
    if (encontrados == 0)
    {
        printf("Nenhum contato encontrado para '%s'\n", alvo);
    }
}

void editarContatoTel(lista_t *lista, char alvo[100], char telefone[9])
{
    int indice = buscaListaContatos(lista,alvo);
    strcpy(lista->elemento[indice].telefone, telefone);
    lista->elemento[indice].telefone[sizeof(lista->elemento[indice].telefone) - 1] = '\0';
}

void editarContatoEmail(lista_t *lista, char alvo[100], char email[9])
{
    int indice = buscaListaContatos(lista,alvo);
    strcpy(lista->elemento[indice].email, email);
    lista->elemento[indice].email[sizeof(lista->elemento[indice].email) - 1] = '\0';
}

void editarContatoNome(lista_t *lista, char alvo[100], char nome[100])
{
    int indice = buscaListaContatos(lista,alvo);
    strcpy(lista->elemento[indice].nome, nome);
    lista->elemento[indice].nome[sizeof(lista->elemento[indice].nome) - 1] = '\0';
}