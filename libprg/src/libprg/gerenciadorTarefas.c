#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <libprg/libprg.h>

#define MAX_DESCRICAO 1001
#define MAX_PRIORIDADE 10
#define MAX_PRAZO 20
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

    strcpy(lista->elemento[lista->tamanho].conclusao, "99/99/99");

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



int compararDes(char* p1, char* p2, bool crescente)
{
    if (crescente)
    {
        return strcmp(p1, p2);
    }
    else
    {
        return strcmp(p2, p1);
    }
}


void insertionSortDes(lista_t* lista, bool crescente)
{
    int j;
    struct tarefas chave;

    for (int i = 1; i < lista->tamanho; i++) {
        chave = lista->elemento[i];
        j = i - 1;

        while (j >= 0 && compararDes(lista->elemento[j].descricao, chave.descricao, crescente) > 0) {
            lista->elemento[j + 1] = lista->elemento[j];
            j = j - 1;
        }
        lista->elemento[j + 1] = chave;
    }
}

int compararPrioridade(char* p1, char* p2, bool crescente) {
    int peso1, peso2;

    if (strcmp(p1, "Alta") == 0) peso1 = 3;
    else if (strcmp(p1, "Média") == 0) peso1 = 2;
    else if (strcmp(p1, "Baixa") == 0) peso1 = 1;
    else peso1 = 0;

    if (strcmp(p2, "Alta") == 0) peso2 = 3;
    else if (strcmp(p2, "Média") == 0) peso2 = 2;
    else if (strcmp(p2, "Baixa") == 0) peso2 = 1;
    else peso2 = 0;

    return crescente ? (peso1 - peso2) : (peso2 - peso1);
}


void insertionSortPrio(lista_t* lista, bool crescente)
{
    int j;
    struct tarefas chave;

    for (int i = 1; i < lista->tamanho; i++)
    {
        chave = lista->elemento[i];
        j = i - 1;

        while (j >= 0 && compararPrioridade(lista->elemento[j].prioridade, chave.prioridade, crescente) > 0) {
            lista->elemento[j + 1] = lista->elemento[j];
            j = j - 1;
        }
        lista->elemento[j + 1] = chave;
    }
}


// Função para converter data "dd/mm/aa" em um número inteiro "aammdd" para comparação
int converterData(const char* data) {
    int dia, mes, ano;
    sscanf(data, "%d/%d/%d", &dia, &mes, &ano);
    // Ajusta ano para um valor de 4 dígitos
    if (ano < 100) {
        ano += 2000;
    }
    return (ano * 10000) + (mes * 100) + dia;
}

// Função de comparação para datas
int compararData(const char* d1, const char* d2, bool crescente) {
    int data1 = converterData(d1);
    int data2 = converterData(d2);
    return crescente ? (data1 - data2) : (data2 - data1);
}

void insertionSortPrazo(lista_t* lista, bool crescente)
{
    int j;
    struct tarefas chave;

    for (int i = 1; i < lista->tamanho; i++) {
        chave = lista->elemento[i];
        j = i - 1;

        while (j >= 0 && compararData(lista->elemento[j].prazo, chave.prazo, crescente) > 0) {
            lista->elemento[j + 1] = lista->elemento[j];
            j = j - 1;
        }
        lista->elemento[j + 1] = chave;
    }
}

void insertionSortConclusao(lista_t* lista, bool crescente)
{
    int j;
    struct tarefas chave;

    for (int i = 1; i < lista->tamanho; i++) {
        chave = lista->elemento[i];
        j = i - 1;

        while (j >= 0 && compararData(lista->elemento[j].conclusao, chave.conclusao, crescente) > 0) {
            lista->elemento[j + 1] = lista->elemento[j];
            j = j - 1;
        }
        lista->elemento[j + 1] = chave;
    }
}

void buscarTarefaPrazo(const lista_t* lista, const char* data, const char* criterio)
{
    int dataBusca = converterData(data);
    bool encontrou = false;

    for (int i = 0; i < lista->tamanho; i++)
    {
        int dataTarefa = converterData(lista->elemento[i].prazo);
        bool exibir = false;

        if (strcmp(criterio, "antes") == 0 && dataTarefa < dataBusca)
        {
            exibir = true;
        }
        else if (strcmp(criterio, "depois") == 0 && dataTarefa > dataBusca)
        {
            exibir = true;
        }
        else if (strcmp(criterio, "exatamente") == 0 && dataTarefa == dataBusca)
        {
            exibir = true;
        }

        if (exibir)
        {   encontrou= true;
            printf("\nID: %d, Descrição: %s, Prioridade: %s, Prazo: %s\n, Conclusão: %s", lista->elemento[i].ID, lista->elemento[i].descricao, lista->elemento[i].prioridade, lista->elemento[i].prazo, lista->elemento[i].conclusao);
        }

        if (!encontrou)
        {
            printf("\nNenhuma tarefa encontrada para o critério de busca fornecido.\n");
        }

    }
}

void buscarTarefaConclusao(const lista_t* lista, const char* data, const char* criterio)
{
    int dataBusca = converterData(data);
    bool encontrou = false;

    for (int i = 0; i < lista->tamanho; i++)
    {
        int dataTarefa = converterData(lista->elemento[i].conclusao);
        bool exibir = false;

        if (strcmp(criterio, "antes") == 0 && dataTarefa < dataBusca)
        {
            exibir = true;
        }
        else if (strcmp(criterio, "depois") == 0 && dataTarefa > dataBusca)
        {
            exibir = true;
        }
        else if (strcmp(criterio, "exatamente") == 0 && dataTarefa == dataBusca)
        {
            exibir = true;
        }

        if (exibir)
        {
            encontrou = true;
            printf("\nID: %d, Descrição: %s, Prioridade: %s, Prazo: %s\n, Conclusão: %s", lista->elemento[i].ID, lista->elemento[i].descricao, lista->elemento[i].prioridade, lista->elemento[i].prazo, lista->elemento[i].conclusao);

        }

        if (!encontrou)
        {
            printf("\nNenhuma tarefa encontrada para o critério de busca fornecido.\n");
        }

    }
}