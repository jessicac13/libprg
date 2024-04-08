#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <libprg/libprg.h>

#define MAX_NOME 100
#define MAX_TELEFONE 15
#define MAX_EMAIL 100
#define CAPACIDADE_INICIAL 10

struct contatos {
    char nome[MAX_NOME];
    char telefone[MAX_TELEFONE];
    char email[MAX_EMAIL];
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
    lista->capacidade = CAPACIDADE_INICIAL;
    lista->ordenada = ordenada;

    lista->elemento = (struct contatos*)malloc(lista->capacidade * sizeof(struct contatos));
    if (lista->elemento == NULL)
    {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    return lista;
}

void inserirListaContatos(lista_t *lista, char nome[MAX_NOME], char telefone[MAX_TELEFONE], char email[MAX_EMAIL]) {
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
        lista->elemento[posicao].nome[MAX_NOME - 1] = '\0';

        strcpy(lista->elemento[posicao].telefone, telefone);
        lista->elemento[posicao].telefone[MAX_TELEFONE - 1] = '\0';

        strcpy(lista->elemento[posicao].email, email);

        lista->tamanho++;
    }
    if (lista->ordenada == false)
    {
        strncpy(lista->elemento[lista->tamanho].nome, nome, MAX_NOME - 1);
        lista->elemento[lista->tamanho].nome[MAX_NOME - 1] = '\0';

        strncpy(lista->elemento[lista->tamanho].telefone, telefone, MAX_TELEFONE - 1);
        lista->elemento[lista->tamanho].telefone[MAX_TELEFONE - 1] = '\0';

        strncpy(lista->elemento[lista->tamanho].email, email, MAX_EMAIL - 1);
        lista->elemento[lista->tamanho].email[MAX_EMAIL - 1] = '\0';

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

void removerListaContatos(lista_t *lista, char alvo[MAX_NOME])
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

int buscaListaContatos(lista_t *lista, char alvo[MAX_NOME])
{
    if (lista->ordenada == false)
    {
        for(int i=0; i<lista->tamanho; i++)
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

void buscarContatos(lista_t *lista, char alvo[MAX_NOME])
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

void editarContatoTel(lista_t *lista, char alvo[MAX_NOME], char telefone[MAX_TELEFONE])
{
    int indice = buscaListaContatos(lista,alvo);
    strcpy(lista->elemento[indice].telefone, telefone);
    lista->elemento[indice].telefone[MAX_TELEFONE - 1] = '\0';
    if( indice == -1)
    {
        printf("\nNenhum contato encontrado para '%s'\n", alvo);
    }
}

void editarContatoEmail(lista_t *lista, char alvo[MAX_NOME], char email[MAX_EMAIL])
{
    int indice = buscaListaContatos(lista,alvo);
    strcpy(lista->elemento[indice].email, email);
    lista->elemento[indice].email[MAX_EMAIL - 1] = '\0';
    if( indice == -1)
    {
        printf("\nNenhum contato encontrado para '%s'\n", alvo);
    }
}

void editarContatoNome(lista_t *lista, char alvo[MAX_NOME], char nome[MAX_NOME])
{
    int indice = buscaListaContatos(lista,alvo);
    strcpy(lista->elemento[indice].nome, nome);
    lista->elemento[indice].nome[MAX_NOME - 1] = '\0';
    if( indice == -1)
    {
        printf("\nNenhum contato encontrado para '%s'\n", alvo);
    }
}


int salvarArquivo(struct lista_t *lista, char diretorio[1000])
{
    FILE *arquivo = fopen(diretorio, "wb");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    fwrite(&(lista->tamanho), sizeof(int), 1, arquivo);

    fwrite(lista->elemento, sizeof(struct contatos), lista->tamanho, arquivo);

    fclose(arquivo);

    return 0;
}

void recarregarListaContatos(lista_t *lista, const char *nome_arquivo)
{
    FILE *arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return; // Encerra a função se não for possível abrir o arquivo
    }

    while (true) {
        char nome[MAX_NOME], telefone[MAX_TELEFONE], email[MAX_EMAIL];

        // Lê um contato do arquivo
        if (fread(nome, sizeof(char), MAX_NOME, arquivo) != MAX_NOME) {
            if (feof(arquivo)) {
                // Fim do arquivo alcançado
                break;
            } else {
                // Erro de leitura
                fprintf(stderr, "Erro ao ler o nome do arquivo\n");
                fclose(arquivo);
                return;
            }
        }
        nome[MAX_NOME - 1] = '\0'; // Garante que o nome seja terminado corretamente

        if (fread(telefone, sizeof(char), MAX_TELEFONE, arquivo) != MAX_TELEFONE) {
            fprintf(stderr, "Erro ao ler o telefone do arquivo\n");
            fclose(arquivo);
            return;
        }
        telefone[MAX_TELEFONE - 1] = '\0';

        if (fread(email, sizeof(char), MAX_EMAIL, arquivo) != MAX_EMAIL) {
            fprintf(stderr, "Erro ao ler o email do arquivo\n");
            fclose(arquivo);
            return;
        }
        email[MAX_EMAIL - 1] = '\0';

        // Insere o contato na lista
        inserirListaContatos(lista, nome, telefone, email);
    }

    fclose(arquivo); // Fecha o arquivo
}
