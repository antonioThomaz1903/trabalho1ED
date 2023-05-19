#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../src/kdtree.h"

void imprimirArvore(Kdtree *raiz){
    if(raiz == NULL) return;
    printf("Nome da cidade: %s\n", (*(Cidade*)raiz->item).nome);
    printf("LAT, LONG: (%.2lf, %.2lf)\n\n", raiz->x, raiz->y);
    imprimirArvore(raiz->dir);
    imprimirArvore(raiz->esq);
}

void testarKD(){
    Kdtree *arvore = NULL;

    Cidade *cidade1 = (Cidade*)calloc(1, sizeof(Cidade));
    strcpy(cidade1->nome, "Campo Grande");
    arvore = inserir(arvore, cidade1, 15.2, 17.9);

    Cidade *cidade2 = (Cidade*)calloc(1, sizeof(Cidade));
    strcpy(cidade2->nome, "Dourados");
    arvore = inserir(arvore, cidade2, 3.2, 13.1);

    Cidade *cidade3 = (Cidade*)calloc(1, sizeof(Cidade));
    strcpy(cidade3->nome, "Sao paulo");
    arvore = inserir(arvore, cidade3,  2.7, 8);

    Cidade *cidade4 = (Cidade*)calloc(1, sizeof(Cidade));
    strcpy(cidade4->nome, "Rio de Janeiro");
    arvore = inserir(arvore, cidade4,  28.7, 86);

    
    imprimirArvore(arvore);

    Kdtree *no_sucessor = sucessor(arvore);
    Kdtree *no_predecessor = predecessor(arvore);
    printf("\n--------------------\n");
    if(no_sucessor != NULL)
        printf("SUCESSOR: %s\n", (*(Cidade*)no_sucessor->item).nome);
    else 
        printf("SUCESSOR NULO\n");

    if(no_predecessor != NULL)
        printf("PREDECESSOR: %s\n", (*(Cidade*)no_predecessor->item).nome);
    else
        printf("PREDECESSOR NULO\n");
}

int main(void){
    testarKD();
    return 0;
}
