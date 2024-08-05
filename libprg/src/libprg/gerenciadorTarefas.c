#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <libprg/libprg.h>

#define MAX_DESCRICAO 1001
#define MAX_PRIORIDADE 6
#define MAX_PRAZO 11
#define CAPACIDADE_INICIAL 10

struct tarefas {
    char descricao[MAX_DESCRICAO];
    char prioridade[MAX_PRIORIDADE];
    char prazo[MAX_PRAZO];
    int ID;
    char conclusao[MAX_PRAZO];

};

struct lista_t {
    struct tarefas *elemento;
    int tamanho;
    int capacidade;
};

lista_t* criarListaTarefas()
{

    lista_t *lista = (lista_t*)malloc(sizeof(lista_t));
    if (lista == NULL)
    {
        printf("Erro de alocação de memória\n");
        exit(1);
    }

    lista->tamanho = 0;
    lista->capacidade = CAPACIDADE_INICIAL;

    free(lista->elemento);
    lista->elemento = (struct tarefas*)malloc(lista->capacidade * sizeof(struct tarefas));
    if (lista->elemento == NULL)
    {
        printf("Erro de alocação de memória\n");
        exit(1);
    }

    return lista;
}

void inserirListaTarefas(lista_t *lista, char descricao[MAX_DESCRICAO], char prioridade[MAX_PRIORIDADE], char prazo[MAX_PRAZO])
{
    if (lista->tamanho >= lista->capacidade)
    {
        lista->capacidade *= 2;
        lista->elemento = (struct tarefas*)malloc(lista->capacidade * sizeof(struct tarefas));
        if (lista->elemento == NULL)
        {
            printf("Erro de realocação de memória\n");
            exit(1);
        }
    }
    strncpy(lista->elemento[lista->tamanho].descricao, descricao, MAX_DESCRICAO - 1);
    lista->elemento[lista->tamanho].descricao[MAX_DESCRICAO - 1] = '\0';

    strncpy(lista->elemento[lista->tamanho].prioridade, prioridade, MAX_PRIORIDADE - 1);
    lista->elemento[lista->tamanho].prioridade[MAX_PRIORIDADE - 1] = '\0';

    strncpy(lista->elemento[lista->tamanho].prazo, prazo, MAX_PRAZO- 1);
    lista->elemento[lista->tamanho].prazo[MAX_PRAZO - 1] = '\0';

    strcpy(lista->elemento[lista->tamanho].conclusao, "NÃO CONCLUÍDO!");

    if(lista->tamanho== 0)
    {
        lista->elemento[lista->tamanho].ID = 0;
    }
    if(lista->tamanho!= 0)
    {
        lista->elemento[lista->tamanho].ID = (lista->elemento[lista->tamanho-1].ID) +1;
    }
    lista->tamanho++;

}

int buscaListaTarefasDes(lista_t *lista, char alvo[MAX_DESCRICAO])
{
   for(int i=0; i<lista->tamanho; i++)
   {
       if(strcmp(alvo, lista->elemento[i].descricao) == 0)
       {
            return i;
       }
   }
   return -1;
}

void removerListaTarefas(lista_t *lista, char alvo[MAX_DESCRICAO])
{
    int indice = buscaListaTarefasDes(lista, alvo);

    if (indice < 0 || indice >= lista->tamanho)
    {
        printf("\nÍndice fora dos limites da lista\n");
        return;
    }

    strcpy(lista->elemento[indice].descricao, lista->elemento[lista->tamanho - 1].descricao);

    strcpy(lista->elemento[indice].prioridade, lista->elemento[lista->tamanho - 1].prioridade);

    strcpy(lista->elemento[indice].prazo, lista->elemento[lista->tamanho - 1].prazo);

    lista->elemento[indice].ID = lista->elemento[lista->tamanho - 1].ID;

    strcpy(lista->elemento[indice].conclusao, lista->elemento[lista->tamanho - 1].conclusao);

    lista->tamanho--;

}

void buscarTarefasDescricao(lista_t *lista, char descricao[MAX_DESCRICAO])
{
    int encontrados = 0;
    for (int i = 0; i < lista->tamanho; i++)
    {
        if (strstr(lista->elemento[i].descricao, descricao) != NULL)
        {
            printf("\nID: %d, Descrição: %s, Prioridade: %s, Prazo: %s\n, Conclusão: %s", lista->elemento[i].ID, lista->elemento[i].descricao, lista->elemento[i].prioridade, lista->elemento[i].prazo, lista->elemento[i].conclusao);
            encontrados++;
        }
    }
    if (encontrados == 0)
    {
        printf("Nenhuma tarefa encontrada para '%s'\n", descricao);
    }
}

void buscarTarefasPrioridade(lista_t *lista, char prioridades[MAX_PRIORIDADE])
{
    int encontrados = 0;
    for (int i = 0; i < lista->tamanho; i++)
    {
        if (strstr(lista->elemento[i].prioridade, prioridades) != NULL)
        {
            printf("\nID: %d, Descrição: %s, Prioridade: %s, Prazo: %s\n, Conclusão: %s", lista->elemento[i].ID, lista->elemento[i].descricao, lista->elemento[i].prioridade, lista->elemento[i].prazo, lista->elemento[i].conclusao);
            encontrados++;
        }
    }
    if (encontrados == 0)
    {
        printf("Nenhuma tarefa encontrada para '%s'\n", prioridades);
    }
}

void buscarTarefasPrazo(lista_t *lista, char prazo[MAX_PRAZO])
{
    int encontrados = 0;
    for (int i = 0; i < lista->tamanho; i++)
    {
        if (strstr(lista->elemento[i].prazo, prazo) != NULL)
        {
            printf("\nID: %d, Descrição: %s, Prioridade: %s, Prazo: %s\n, Conclusão: %s", lista->elemento[i].ID, lista->elemento[i].descricao, lista->elemento[i].prioridade, lista->elemento[i].prazo, lista->elemento[i].conclusao);
            encontrados++;
        }
    }
    if (encontrados == 0)
    {
        printf("Nenhuma tarefa encontrada para '%s'\n", prazo);
    }
}

void buscarTarefasConclusao(lista_t *lista, char conclusao[MAX_PRAZO])
{
    int encontrados = 0;
    for (int i = 0; i < lista->tamanho; i++)
    {
        if (strstr(lista->elemento[i].conclusao, conclusao) != NULL)
        {
            printf("\nID: %d, Descrição: %s, Prioridade: %s, Prazo: %s\n, Conclusão: %s", lista->elemento[i].ID, lista->elemento[i].descricao, lista->elemento[i].prioridade, lista->elemento[i].prazo, lista->elemento[i].conclusao);
            encontrados++;
        }
    }
    if (encontrados == 0)
    {
        printf("Nenhuma tarefa encontrada para '%s'\n", conclusao);
    }
}

void editarDes(lista_t *lista, char descricao[MAX_DESCRICAO], char descricaoNova[MAX_DESCRICAO] )
{
    int indice = buscaListaTarefasDes(lista,descricao);
    if( indice < 0)
    {
        printf("\nNenhuma tarefa encontrada para '%s'\n", descricao);
        return;
    }
    else
    {
        strcpy(lista->elemento[indice].descricao, descricaoNova);
        printf("\nDescrição alterada!\n");
    }
}

void editarPrio(lista_t *lista, char descricao[MAX_DESCRICAO], char prioridade[MAX_PRIORIDADE])
{
    int indice = buscaListaTarefasDes(lista,descricao);
    if( indice < 0)
    {
        printf("\nNenhuma tarefa encontrada para '%s'\n", descricao);
        return;
    }
    else
    {
        strcpy(lista->elemento[indice].prioridade, prioridade);
        printf("\nPrioridade alterada!\n");
    }
}


void editarPrazo(lista_t *lista, char descricao[MAX_DESCRICAO], char prazo[MAX_PRIORIDADE] )
{
    int indice = buscaListaTarefasDes(lista,descricao);
    if( indice < 0)
    {
        printf("\nNenhuma tarefa encontrada para '%s'\n", descricao);
        return;
    }
    else
    {
        strcpy(lista->elemento[indice].prazo, prazo);
        printf("\nPrazo alterada!\n");
    }
}


void editarConclusao(lista_t *lista,char descricao[MAX_DESCRICAO], char conclusao[MAX_PRAZO])
{
    int indice = buscaListaTarefasDes(lista,descricao);
    if( indice < 0)
    {
        printf("\nNenhuma tarefa encontrada para '%s'\n", descricao);
        return;
    }
    else
    {
        strcpy(lista->elemento[indice].conclusao, conclusao);
        printf("\nConclusão alterada!\n");
    }
}


void destruirListaTarefas(lista_t *lista)
{
    free(lista->elemento);
    free(lista);
}

lista_t* insertionSortDescricao(lista_t * vetor, int tamanho, bool crescente)
{
    int j;
    lista_t chave;

    for (int i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;

        if (crescente)
        {
            while (j >= 0 && strcmp(vetor[j].elemento->descricao, chave.elemento->descricao) > 0)
            {
                vetor[j + 1] = vetor[j];
                j = j - 1;
            }
        } else
        {
            while (j >= 0 && strcmp(vetor[j].elemento->descricao, chave.elemento->descricao) < 0) {
                vetor[j + 1] = vetor[j];
                j = j - 1;
            }
        }
        vetor[j + 1] = chave;
    }
}

void ordenarListaTarefasPorDescricao(lista_t *lista, bool crescente)
{
    insertionSort(lista->elemento, lista->tamanho, crescente);
}