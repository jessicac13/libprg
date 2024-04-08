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

int salvarArquivo(struct lista_t *lista, char diretorio[1000])
{
    FILE *arquivo = fopen(diretorio, "w");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    for (int i = 0; i < lista->tamanho; i++) {
        fprintf(arquivo, "%s,%s,%s\n", lista->elemento[i].nome, lista->elemento[i].telefone, lista->elemento[i].email);
    }

    fclose(arquivo);

    return 0;
}

void recarregarListaContatos(lista_t *lista, const char *nome_arquivo)
{
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return; // Encerra a função se não for possível abrir o arquivo
    }

    char linha[MAX_NOME + MAX_TELEFONE + MAX_EMAIL + 3]; // Tamanho máximo de uma linha

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char nome[MAX_NOME], telefone[MAX_TELEFONE], email[MAX_EMAIL];
        sscanf(linha, "%[^,],%[^,],%s", nome, telefone, email);
        inserirListaContatos(lista, nome, telefone, email);
    }

    fclose(arquivo); // Fecha o arquivo
}
