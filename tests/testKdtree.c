#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../src/kdtree.h"

typedef struct _cidade{
    char codigo_ibge[CIBGE+1];
    char nome[MAX+1];
    char codigo_uf[UF+1];
    char capital[CAPITAL+1];
    char regiao[MAX+1];
    char siafi[SIAFI+1];
    char ddd[DDD+1];
    char fuso[MAX+1];
} Cidade;

typedef struct _fastfood{
    char endereco[MAX+1];
    char categoria[MAX+1];
    char cidade[MAX+1];
    char pais[3];
    char nome[MAX+1];
    char codigo_postal[CPOSTAL+1];
    char provincia[3];
} Fastfood;

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
        printf("5- Destruir arvore\n");
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
                printf("Latitude, Longitude = (%.1lf, %.1lf)", pred->x, pred->y);
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

        else if(op == 5){
            arvore = destruirArvore(&arvore);
            printf("\nARVORE DESTRUIDA\n");
        }

        else if(op < 0 || op > 5){
            printf("\nOPCAO INVALIDA");
        }
    }

    arvore = destruirArvore(&arvore);
    free(arvore);

    printf("\nFIM DO TESTE\n");
    
}

int main(void){
    testarKD();
    return 0;
}
