#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct noduloLista{ 
    char valor;
    struct noduloLista *anterior;
    struct noduloLista *proximo; 

};
typedef struct noduloLista NODLISTA;
typedef NODLISTA *LISTA; // Ponteiro "Lista" que sera usado...

/* insere um nó no início da lista */
LISTA* cria_Lista(){
     ///////////////////////////////////////////////////////////////
    /// Aloca um espaco // 
   ///////////////////////////////////////////////////////////////
    LISTA* viagra = (LISTA*) malloc(sizeof(LISTA));
    if(viagra != NULL)
        *viagra = NULL;
    
    return viagra;
}

int listInserInicio(LISTA* inicio, int valor){
     
     LISTA novo;
     
     novo = (NODLISTA*) malloc(sizeof(NODLISTA)); /* aloca memória para o novo nó */
     
     if(novo == NULL) // Verifica se foi possivel alocar.
         return 1;     
     
    /*  Caso a lista esteja fazia o proximo e o anterior serao NULL.
        O novo NO se torna o primeiro elemento da lista.*/
     if(*inicio == NULL){    
         novo->valor = valor;
         novo->proximo = novo->anterior = NULL; 
         *inicio = novo; 
     }else{ // Caso ja exite um  NO na lista...  
         novo->valor = valor; 
         novo->anterior = NULL; 
         novo->proximo = *inicio;
         (*inicio)->anterior = novo; // Agora o início aponta para o novo NO 
         *inicio = novo; // o novo NO passa a ser o primeiro da lista */
     }
     return 0;
}

int listInseriFinal(LISTA *inicio, int valor){
     
     //////////////////////////////////////////////////////////////
    ///Aloca um espaco para reunir tufos de provas para processo//
   //////////////////////////////////////////////////////////////
    LISTA novo = (NODLISTA*) malloc(sizeof(NODLISTA));
    LISTA viagra;//auxiliar
     
     if(novo == NULL)
         return 1;
     
     /*  Caso a lista esteja fazia o proximo e o anterior serao NULL.
        O novo NO se torna o primeiro elemento da lista.*/
     if(*inicio == NULL){
         novo->valor = valor;
         novo->proximo = novo->anterior = NULL;
         *inicio = novo;
    }else{ // Caso ja exite um  NO na lista...  
        viagra = *inicio;
        while(viagra->proximo != NULL) /* enquanto o  viagra nao for o ultimo */
            viagra = viagra->proximo;
        
        
        novo->valor = valor;
        novo->anterior = viagra;  
        novo->proximo = NULL; 
        viagra->proximo = novo; 
     }
     return 0;
}   

/* deleta um NO do inicio da lista */
char listaIniRemov(LISTA *inicio){
    LISTA auxiliar;
    char c;
    auxiliar = *inicio; 
    c = (*inicio)->valor; 
    *inicio = (*inicio)->proximo; 
    free(auxiliar); 
    
    return c;
}

int listaRemov(LISTA *inicio, int valor){
    
    LISTA viagra;
    LISTA picaAuxiliar; 
    
    if(*inicio == NULL) 
        return 1; /* retorna 0 caso a lista esteja vazia */
    
    viagra = *inicio;
    
    if((*inicio)->valor == valor) /* Se o NO for o do inicio*/
        *inicio = (*inicio)->proximo; /* o nó inicial passa a ser o próximo da lista */
    
    while(viagra != NULL && viagra->valor != valor) /*Equanto o valor do viagra nao for o desejado*/
        viagra = viagra->proximo; 
    
    if(viagra == NULL)/*Caso o valor do viagra nao stenha sido encontrado*/
        return 1; 
    else{
        picaAuxiliar = viagra; /*Caso o valor tenha sido encontrado a picaAuxliar recebe */
        
        /* Verifica se ha um NO anterior e faz o anterior apontar para o sucessor do que sera eliminado*/
        if(viagra->anterior != NULL)
            viagra->anterior->proximo = viagra->proximo; 
        
        ///////////////////////////////////////////////////
        /* Verifica se ha a PORRA de um NO no PROXIMO!.
         Caso tenha, o proximo do viagra apontar para o anterior ao que sera eliminado*/
        if(viagra->proximo != NULL) 
            viagra->proximo->anterior = viagra->anterior; 
        
        free(picaAuxiliar);/* remove a picaAuxiliar deixando livre para quem quiser alocar a coitada*/
        // :) Use sempre camisinha 8===D
    }
    
    return 1;
}

int listaVazia(LISTA *inicio){
    return inicio == NULL;
}

int listaDeletar(LISTA *inicio){
    while(!listaVazia(inicio)){ 
        listaIniRemov(inicio);
    }
    return 0;
}


void listaPrintInverso(LISTA inicio){
     if(listaVazia(inicio))
         printf("\nLISTA VAZIA\n");
     else{
         while(inicio->proximo != NULL) /* Chegar no ultimo no*/
             inicio = inicio->proximo;   
         while(inicio != NULL){
             printf(" %i", inicio->valor);
             inicio = inicio->anterior;
         }
     }
     
}

int listaPrintComeco(LISTA inicio){
     if(listaVazia(inicio)){
         printf("\nLISTA VAZIA!!\n");
         return 1;
     }else{
         while(inicio != NULL){
             printf("%i\n", inicio->valor);
             inicio = inicio->proximo;
        }
     }
    return 0;
}

void menu(){

     printf("\n\n1 - Inserir inicio da lista\n");
     printf("2 - Inserir  final\n");
     printf("3 - Remover um elemento \n");
     printf("4 - Remover elemento do inicio \n");
     printf("5 - Imprimir comeco\n");
     printf("6 - Imprimir inverso\n");
     printf("7 - sair\n\n\n\n");
     
}


 
         
         
     
     
 