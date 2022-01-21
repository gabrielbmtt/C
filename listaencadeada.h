#ifndef listaencadeada_h
#define listaencadeada_h
#define MAXNOME 101
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct _chave{
    int matricula,telefone,ddd;
    char nome[MAXNOME],tipo[2];
}Chave;

typedef struct _no{
    Chave *contato;
    struct _no *prox;
}No;

typedef struct _lista{
    No *prim;
}Lista;

Lista *criarlista();

char imprime_menu();

void inserir(Lista *L);

void percorrer(Lista *L);

void carregar(Lista *L);

void salvar(Lista *L);

void exit();
#endif
