
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "ListaEncadeada.h"
 
// ----------------TESTANDO...----------------------
int main(void)
{
   LISTA* lista = cria_Lista();
    int opcao;
    char valor;
    FILE *arquivo;
    arquivo = fopen("C:\\Users\\Sterfanno\\Desktop\\arq.txt","r");
    
 
        

       
        do{
            fread(&valor, sizeof(valor), 1, arquivo);
            listInserInicio(lista, valor);
        }while(!feof(arquivo));
         
         
         
        /* while(valor = getc(arquivo)!=EOF){
            listInserInicio(lista, valor);
         }
         
        */
        
        
    
        
    listaPrintComeco(*lista);
    listaPrintInverso(*lista);
    fclose(arquivo);
    /*
       menu();
    printf("Escolha uma opcoe: ");
    scanf("%d", &opcao);
    
    while(opcao != 7){
        
        switch(opcao){
            
            case 1:
                 printf("\nDigite um novo item para o INICIO: ");
                 scanf("\n%c", &valor);
                 listInserInicio(lista, valor);
                 system("cls");
                 break;
            
            case 2:
                 printf("\nDigite um novo item para o FINAL: ");
                 scanf("\n%c", &valor);
                 listInseriFinal(lista, valor);
                 system("cls");
                 break;
            
            case 3:
                 printf("\nDigite o item a ser RETIRADO: ");
                 scanf("\n%c", &valor);
                 if(! listaRemov(lista, valor)){
                     printf("\nO item NAO EXISTE!\n\n");
                     getch();
                 }else printf("\n%c - Removido da lista!\n", valor);
                 system("cls");
                 break;
            
            case 4:
                 printf("\nRemover cabeca da Lista: ");
                 if(!listaIniRemov(lista)){
                     printf("\nLista VAZIA!\n\n");
                     getch();
                 }else printf("\nCabeca da lista REMOVIDA!\n");
                 getch();
                 system("cls");
                 break;
            
            case 5:
                 listaPrintComeco(*lista);
                 getch();
                 system("cls");
                 break;
            
            case 6:
                 listaPrintInverso(*lista);
                 getch();
                 system("cls");
                 break;
            
            default:
                 printf("\nOpcao invalida!!!\n\n");
                 getch();
                 system("cls");
                 break;
        }
        menu();
        printf("Escolha uma opcoe: ");
        scanf("%d", &opcao);
    }
    */
   
    listaDeletar(*lista);
    printf("\nLista DELETADA!!!\n");
    getch(); 
    
    return 0;
}
 
