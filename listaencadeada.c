#include "listaencadeada.h"

Lista *criarlista(){
    Lista *L;
    printf("Criando lista vazia!");
    L=malloc(sizeof(Lista));
    L->prim=NULL;
    return L;
}

char imprime_menu(){
    char resp;
    printf("\n----------MENU---------");
    printf("\nInserir novo registro: (I)");
    printf("\nPrintar contatos: (P)");
    printf("\nCarregar contatos: (C)");
    printf("\nSalvar: (S)");
    printf("\nSair do programa: (E)");
    printf("\nR: ");
    scanf(" %c",&resp);
    return resp;
}

void inserir(Lista *L){
    No *aux,*novo;
    novo=malloc(sizeof(No));
    printf("Insira as informações do contato:");
    printf("\nMatrícula: ");
    scanf("%d",&novo->contato->matricula);
    printf("\nNome: ");
    scanf("%s",novo->contato->nome);
    printf("\nQual o numero do DDD? :");
    scanf("%d",&novo->contato->ddd);
    printf("\nQual o numero de telefone? :");
    scanf("%d",&novo->contato->telefone);
    printf("\nTelefone fixo(F) ou celular(C)? :");
    scanf("%s",novo->contato->tipo); 
    aux=L->prim;
    if(aux==NULL){
        L->prim=novo;
        novo->prox=NULL;
        printf("\nContato adicionado.");
        return;
    }
    while(aux->prox!=NULL){
        aux=aux->prox;
    }
    aux->prox=novo;
    novo->prox=NULL;
}

void percorrer(Lista *L){
    No *no;
    int i=1;
    no=L->prim;
    if(no==NULL){
        printf("Lista vazia.");
        return;
    }
    do{
        printf("--------CONTATOS--------");
        printf("\n\n-----CONTATO %d-----",i);
        printf("\nMATRICULA:%d",no->contato->matricula);
        printf("\nNOME:%s",no->contato->nome);
        printf("\nDDD:%d",no->contato->ddd);
        printf("\nTELEFONE:%d",no->contato->telefone);
        printf("\nTIPO:%s",no->contato->tipo);
        no=no->prox;
    } while (no->prox!=NULL);
    
    
}

void carregar(Lista *L){
    FILE *file;
    No *no;
    file=fopen("agenda.txt","rt");
    if(file==NULL){
        printf("\nErro na abertura do arquivo/arquivo inexistente.\n");
        fclose(file);
    }else{
      printf("--------ARQUIVO ABERTO COM SUCESSO!--------\n");
      no=L->prim;
      while(!feof(file)){
        no=malloc(sizeof(No));
        fscanf(file,"%d",&no->contato->matricula);
        fscanf(file,"%s",no->contato->nome);
        fscanf(file,"%d",&no->contato->ddd);
        fscanf(file,"%d",&no->contato->telefone);
        fscanf(file,"%s",no->contato->tipo);
        no=no->prox;
      }
      no->prox=NULL;
      fclose(file);
    }
}

/*void salvar(Lista *L){
    FILE *file;
    No *no;
    file=fopen("agenda.txt","wt");
    if(file==NULL){
        printf("\nErro na abertura do arquivo/arquivo inexistente.\n");
        fclose(file);
    }
    else{
      printf("--------ARQUIVO ABERTO COM SUCESSO!--------\n");
      no=L->prim;
      do{
        fprintf("%d\n",no->contato->matricula);
        fprintf("%s\n",no->contato->nome);
        fprintf("%d\n",no->contato->ddd);
        fprintf("%d\n",no->contato->telefone);
        fprintf("%s\n",no->contato->tipo);
        no=no->prox;
    } while (no->prox!=NULL);
      fclose(file);
    }
}*/

