#include "listaencadeada.h"

Lista *criarlista(){
    Lista *L;
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
    No *aux,*x;
    x=malloc(sizeof(No));
    printf("\nInsira as informações do contato:\n");
    printf("\nMatrícula: ");
    scanf("%d",&x->matricula);
    printf("\nNome: ");
    scanf("%s",x->nome);
    printf("\nDDD :");
    scanf("%d",&x->ddd);
    printf("\nTelefone :");
    scanf("%d",&x->telefone);
    printf("\nTelefone fixo(F) ou celular(C)? :");
    scanf("%s",x->tipo); 
    if(L->prim==NULL){
        x->prox=L->prim;
        L->prim=x;
    }
    else{
      aux=L->prim;
      x->prox=NULL;
      while(aux->prox!=NULL){
        aux=aux->prox;
      }
      aux->prox=x;
      printf("\nContato adicionado.\n");
    }
}

void percorrer(Lista *L){
    No *no;
    int i=1;
    no=L->prim;
    if(no==NULL){
        printf("Lista vazia.");
    }
    else{
      printf("--------CONTATOS--------");
      while(no!=NULL){
        printf("\n\n-----CONTATO %d-----",i);
        printf("\nMATRICULA:%d",no->matricula);
        printf("\nNOME:%s",no->nome);
        printf("\nDDD:%d",no->ddd);
        printf("\nTELEFONE:%d",no->telefone);
        printf("\nTIPO:%s",no->tipo);
        no=no->prox;
        i++;
      } 
    }
    
    
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
        fscanf(file,"%d",&no->matricula);
        fscanf(file,"%s",no->nome);
        fscanf(file,"%d",&no->ddd);
        fscanf(file,"%d",&no->telefone);
        fscanf(file,"%s",no->tipo);
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
        fprintf("%d\n",no->matricula);
        fprintf("%s\n",no->nome);
        fprintf("%d\n",no->ddd);
        fprintf("%d\n",no->telefone);
        fprintf("%s\n",no->tipo);
        no=no->prox;
    } while (no->prox!=NULL);
      fclose(file);
    }
}*/

