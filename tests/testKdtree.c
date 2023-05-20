#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../src/kdtree.h"

void imprimirArvore(Kdtree *raiz){
    if(raiz == NULL) return;
    printf("Nome da cidade: %s\n", (*(Cidade*)raiz->item).nome);
    printf("LAT, LONG: (%.1lf, %.1lf)\n\n", raiz->x, raiz->y);
    imprimirArvore(raiz->dir);
    imprimirArvore(raiz->esq);
}

void testarKD(){
    Kdtree *arvore = NULL;
    int op;

    while(op!=0){
        printf("\n\n----TESTE-KD-TREE----\n");
        printf("1- Inserir Elemento\n");
        printf("2- Predecessor\n");
        printf("3- Sucessor\n");
        printf("4- Imprimir arvore\n");
        printf("0- Sair\nOpcao: ");
        scanf("%d", &op);

        if(op == 1){
            Cidade *adicionar = (Cidade*)calloc(1, sizeof(Cidade));
            double lat, lon;
            printf("\nINSERIR CIDADE:\n");
            printf("Digite o nome da cidade: ");
            scanf(" %[^\n]", adicionar->nome);
            printf("Digite a latitude da cidade: ");
            scanf("%lf", &lat);
            printf("Digite a longitude da cidade: ");
            scanf("%lf", &lon);
            arvore = inserir(arvore, adicionar, lat, lon);
            if(arvore!=NULL){
                printf("\nCIDADE ADICIONADA COM SUCESSO, voltando ao menu...");
            }
            else{
                printf("\nERRO AO ADICIONAR CIDADE, voltando ao menu...");
            }
        }

        else if(op == 2){
            Kdtree *pred = predecessor(arvore);
            if(pred != NULL){
                printf("\nPredecessor da raiz: %s\n", ((Cidade*)pred->item)->nome);
                printf("Latitude, Longitude = (%.1lf, %,1lf)", pred->x, pred->y);
            }
            else{
                printf("\nNao ha predecessor\n");
            }
        }

        else if(op == 3){
            Kdtree *suce = sucessor(arvore);
            if(suce != NULL){
                printf("\nSucessor da raiz: %s\n", ((Cidade*)suce->item)->nome);
                printf("Latitude, Longitude = (%.1lf, %.1lf)", suce->x, suce->y);
            }
            else{
                printf("\nNao ha sucessor");
            }
        }
        
        else if(op == 4){
            printf("\n\n");
            imprimirArvore(arvore);
        }

        else if(op < 0 || op > 4){
            printf("\nOPCAO INVALIDA");
        }
    }

    destruirArvore(&arvore);
    
}

int main(void){
    testarKD();
    return 0;
}
