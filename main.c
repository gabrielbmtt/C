#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./listaencadeada.h"
int main(int narg, char *argv[]){
    Lista *L;
    int loop=1;
    char resp;
    L=criarlista();
    while(loop!=0){
        resp=imprime_menu();
        if(resp=='I' || resp=='i'){
            inserir(L);
        }
        else if(resp=='P'||resp=='p'){
            percorrer(L);
        }
        else if(resp=='C'|| resp=='c'){
            carregar(L);
        }
        else if(resp=='S'|| resp=='s'){
            //depois fazer pensando como seria com uma lista vazia
            //salvar(L);
            printf("\nLista salva!");
        }
        else if(resp=='E'|| resp=='e'){
            printf("\nFim do programa.");
            loop=0;
        }
    }            
  return EXIT_SUCCESS;
    
}