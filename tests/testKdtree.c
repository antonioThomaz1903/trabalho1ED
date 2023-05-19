#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../src/kdtree.h"

void imprimirArvore(Kdtree *raiz){
    if(raiz == NULL){
        return;
    }
    imprimirArvore(raiz->dir);
    imprimirArvore(raiz->esq);
    printf("Nome da cidade: %s\n", (*(Cidade*)raiz->item).nome);
    printf("LAT, LONG: (%.2lf, %.2lf)\n\n", raiz->x, raiz->y);
}

void testarKD(){
    Kdtree *arvore;

    Cidade *cidade1 = (Cidade*)calloc(1, sizeof(Cidade));
    strcpy(cidade1->nome, "Campo Grande");
    arvore = inserir(arvore, cidade1, 15.2, 17.9);

    Cidade *cidade2 = (Cidade*)calloc(1, sizeof(Cidade));
    strcpy(cidade2->nome, "Dourados");
    arvore = inserir(arvore, cidade2, 3.2, 13.1);

    Cidade *cidade3 = (Cidade*)calloc(1, sizeof(Cidade));
    strcpy(cidade3->nome, "Sao paulo");
    arvore = inserir(arvore, cidade3,  2.7, 8);

    imprimirArvore(arvore);
}

int main(void){
    testarKD();
    return 0;
}
