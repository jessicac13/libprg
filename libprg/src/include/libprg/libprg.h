#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

#include<stdbool.h>

typedef struct {
    double value;
    int error;
} result_t;

typedef enum { SUM, SUB } operation_t;

result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);

typedef struct lista_t lista_t;

lista_t* criarLista(bool ordenada);
void inserirLista(lista_t *lista, int elemento);
void removerLista(lista_t *lista, int alvo);
void imprimirLista(lista_t *lista);
int buscaLista(lista_t *lista, int alvo);
int busca_bin_i(lista_t *lista, int alvo);
int busca_bin_r(lista_t *lista, int inicio, int fim, int alvo);
void imprimir_indice_busca(int teste);

typedef struct fila_t fila_t;

fila_t * criarFila(int capacidade);
void enqueue(fila_t *fila, int elemento);
void imprimirFila(fila_t *fila);
int dequeue(fila_t *fila);
int getHead(fila_t *fila);
int getTail(fila_t *fila);
int getSize(fila_t *fila);
bool isEmpty(fila_t *fila);
bool isFull(fila_t *fila);

#define MAX_NOME 100
#define MAX_TELEFONE 15
#define MAX_EMAIL 100

lista_t* criarListaContatos(bool ordenada);
void inserirListaContatos(lista_t *lista, char nome[MAX_NOME], char telefone[MAX_TELEFONE], char email[MAX_EMAIL]);
void removerListaContatos(lista_t *lista, char alvo[MAX_NOME]);
int buscaListaContatos(lista_t *lista, char alvo[MAX_NOME]);
void buscarContatos(lista_t *lista, char alvo[MAX_NOME]);
void editarContatoEmail(lista_t *lista, char alvo[MAX_NOME], char email[MAX_EMAIL]);
void editarContatoNome(lista_t *lista, char alvo[MAX_NOME], char nome[MAX_NOME]);
void editarContatoTel(lista_t *lista, char alvo[MAX_NOME], char telefone[MAX_TELEFONE]);



typedef struct pilha_t pilha_t;

pilha_t * criarPilha(int capacidade);
void empilhar(pilha_t *pilha, int elemento);
int desempilhar(pilha_t *pilha);
void imprimirPilha(pilha_t *pilha);
bool isEmptyPilha(pilha_t *pilha);
int getSizePilha(pilha_t *pilha);

typedef struct no no_t;

void adicionarListaEncadeada(no_t** inicio, int dado);
bool removerListaEncadeada(no_t** inicio, int dado);
void destruirListaEncadeada(no_t** inicio);
no_t* buscarListaEncadeada(no_t **inicio, int dado);
void imprimirListaEncadeada(no_t **inicio);

typedef struct noOrdenado noOrdenado_t;

void adicionarListaEncadeadaO(noOrdenado_t** inicioOrdenado, int dado);
void imprimirListaEncadeadaO(noOrdenado_t** inicioOrdenado);
bool removerListaEncadeadaO(noOrdenado_t** inicioOrdenado, int dado);
void destruirListaEncadeadaO(noOrdenado_t** inicioOrdenado);
noOrdenado_t* buscarListaEncadeadaO(noOrdenado_t** inicioOrdenado, int dado);

typedef struct noDuplo noDuplo_t;

void adicionarListaEncadeadaDuplo(noDuplo_t** inicioDuplo, int dado);
void imprimirListaEncadeadaDuplo(noDuplo_t **inicioDuplo);
bool removerListaEncadeadaDuplo(noDuplo_t** inicioDuplo, int dado);
noDuplo_t* buscarListaEncadeadaDuplo(noDuplo_t **inicioDuplo, int dado);

int* bubbleSort(int* vetor, int tamanho, bool crescente);
int* insertionSort(int* vetor, int tamanho, bool crescente);
int* selectionSort(int* vetor, int tamanho, bool crescente);
int* merge(int *vetor, int esquerda, int meio, int direita);
int* mergeSort(int* vetor, int esquerda, int direita);
int particiona(int* vetor, int inicio, int fim);
int* quickSort(int* vetor, int inicio, int fim);

typedef struct pessoa pessoa_t;
typedef struct no_hash no_hash_t;
typedef struct dicionario dicionario_t;

dicionario_t *criar_dicionario(int m);
void destruir_pessoa(pessoa_t *pessoa);
void destruir_no_hash(no_hash_t *no);
void destruir_dicionario(dicionario_t *d);
int hash(const char *chave, int m);
bool inserir_hash(dicionario_t *d, char *chave, pessoa_t *valor);
pessoa_t *buscar(dicionario_t *d, char *chave);
void imprimir_pessoa(dicionario_t *d, char *chave);

typedef struct no_arvore no_arvore_t;

no_arvore_t* criar_no_arvore(int valor);
void destruir_no_arvore(no_arvore_t *no_arvore);
no_arvore_t  *inserir_valor_arvore(no_arvore_t  *raiz, int valor);
bool busca_arvore(no_arvore_t  *raiz, int valor);
no_arvore_t *remover_valor_arvore(no_arvore_t *raiz, int valor);

#define MAX_DESCRICAO 1000
#define MAX_PRIORIDADE 5
#define MAX_PRAZO 10
#define CAPACIDADE_INICIAL 10

lista_t* criarListaTarefas();
void inserirListaTarefas(lista_t *lista, char descricao[MAX_DESCRICAO], char prioridade[MAX_PRIORIDADE], char prazo[MAX_PRAZO]);
int buscaListaTarefasDes(lista_t *lista, char alvo[MAX_DESCRICAO]);
int buscaListaTarefasPrio(lista_t *lista, char alvo[MAX_PRIORIDADE]);
int buscaListaTarefasPrazo(lista_t *lista, char alvo[MAX_PRAZO]);
int buscaListaTarefasConclusao(lista_t *lista, char alvo[MAX_PRAZO]);
void removerListaTarefas(lista_t *lista, char alvo[MAX_DESCRICAO]);
void buscarTarefasDescricao(lista_t *lista, char descricao[MAX_DESCRICAO]);
void buscarTarefasPrioridade(lista_t *lista, char prioridades[MAX_PRIORIDADE]);
void buscarTarefasPrazo(lista_t *lista, char prazo[MAX_PRAZO]);
void buscarTarefasConclusao(lista_t *lista, char conclusao[MAX_PRAZO]);
void editarDes(lista_t *lista, char descricao[MAX_DESCRICAO]);
void editaPrio(lista_t *lista, char prioridade[MAX_PRIORIDADE]);
void editarPrazo(lista_t *lista, char prazo[MAX_PRIORIDADE]);
void editarConclusao(lista_t *lista, char conclusao[MAX_PRAZO]);
void ordenarPorDescricao(lista_t *lista, bool crescente);
void ordenarPorPrioridade(lista_t *lista, bool crescente);
void ordenarPorPrazo(lista_t *lista, bool crescente);
void ordenarPorConclusao(lista_t *lista, bool crescente);
void listarListaTarefas(lista_t *lista);
void destruirListaTarefas(lista_t *lista);

#endif /* LIBPRG_H */





