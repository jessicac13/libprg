#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libprg/libprg.h>

typedef struct pessoa{
    char *cpf;
    char *nome;
    char *email;
} pessoa_t;

typedef struct no_hash {
    char *chave;
    pessoa_t *valor;
    struct no_hash *prox;
} no_hash_t;

typedef struct dicionario {
    int tamanho; // tamanho do vetor
    no_hash_t **vetor;
} dicionario_t;

dicionario_t *criar_dicionario(int m)
{
    dicionario_t *d = NULL;
    if (m < 1) {
        return NULL;
    }
    if ((d = (dicionario_t *)malloc(sizeof(dicionario_t))) == NULL) {
        return NULL;
    }
    d->tamanho = m;
    if ((d->vetor = calloc(m, sizeof(no_hash_t *))) == NULL) {
        return NULL;
    }
// O calloc já deve colocar NULL, mas deixo aqui de forma explícita
    for (int i = 0; i < m; ++i) {
        d->vetor[i] = NULL;
    }
    return d;
}

void destruir_pessoa(pessoa_t *pessoa)
{
    if (pessoa->cpf != NULL)
    {
        free(pessoa->cpf);
    }
    if (pessoa->nome != NULL)
    {
         free(pessoa->nome);
    }
    if (pessoa->email != NULL)
    {
        free(pessoa->email);
    }
    free(pessoa);
}

void destruir_no_hash(no_hash_t  *no_hash)
{
    if (no_hash != NULL)
    {
        free(no_hash->chave);
        destruir_pessoa(no_hash->valor);
        free(no_hash);
    }
}

void destruir_dicionario(dicionario_t *d)
{
    if (d != NULL)
    {
        for (int i = 0; i < d->tamanho; ++i)
        {
            // TODO destruir lista encadeada
            destruir_no_hash(d->vetor[i]);
        }
        free(d->vetor);
        free(d);
    }
}

// método por divisão com chave alfanumérica
int hash(const char *chave, int m)
{
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++)
    {
        soma += (i + 1) * chave[i];
    }
return soma % m;
}

bool inserir_hash(dicionario_t *d, char *chave, pessoa_t *valor)
{
    int indice = hash(chave, d->tamanho);
    no_hash_t *no_hash = malloc(sizeof(no_hash_t));
    if (no_hash == NULL)
    {
        return false;
    }

    // strdup reserva memória para fazer a cópia da string. Presente em string.h padrão
    // C23 https://en.cppreference.com/w/c/string/byte/strdup
    no_hash->chave = strdup(chave);
    if (no_hash->chave == NULL)
    {
        free(no_hash);
        return false;
    }
    no_hash->valor = valor;
    // TODO não está tratando colisões
    // se houver colisão é necessário usar uma lista encadeada
    no_hash->prox = NULL;
    // libera a memória se existir um nó anterior na posição
    destruir_no_hash(d->vetor[indice]);
    d->vetor[indice] = no_hash;
    return true;
}

pessoa_t *buscar(dicionario_t *d, char *chave)
{
    int indice = hash(chave, d->tamanho);
    if (d->vetor[indice] != NULL)
    {
        // TODO Abaixo só pega o primeiro elemento da lista encadeada
        // é necessário percorrer a lista encadeada e não apenas o primeiro
        // elemento
        if (strcmp(d->vetor[indice]->chave, chave) == 0)
        {
            return d->vetor[indice]->valor;
        }
    }
    return NULL;
}

void imprimir_pessoa(dicionario_t *d, char *chave)
{
    pessoa_t *p = buscar(d, chave);
    if (p != NULL)
    {
        printf("CPF: %s\tNome: %s\tEmail: %s\n", p->cpf, p->nome, p->email);
    }
    else
    {
        printf("Pessoa com CPF %s não encontrada\n", chave);
    }
}