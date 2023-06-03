#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include"../src/cidade.h"
#include"../src/fastfood.h"
#include"../src/kdtree.h"
#include"../src/leitura.h"


void testarKD(){
    Kdtree *arvore = NULL;
    Cidade aux1;
    aux1.lat = 10;
    aux1.lon = 10;
    arvore = inserir(arvore, &aux1, comparaCidade);
    
    assert(arvore->nivel == 0);
    assert(((Cidade*)arvore->item)->lat == 10);
    assert(((Cidade*)arvore->item)->lon == 10);

    Cidade aux2;
    aux2.lat = 15;
    aux2.lon = 15;
    arvore = inserir(arvore, &aux2, comparaCidade);

    assert(arvore->dir->nivel == 1);
    assert(((Cidade*)arvore->dir->item)->lat == 15);
    assert(((Cidade*)arvore->dir->item)->lon == 15);

    Cidade aux3;
    aux3.lat = 5;
    aux3.lon = 5;
    arvore = inserir(arvore, &aux3, comparaCidade);

    assert(arvore->esq->nivel == 1);
    assert(((Cidade*)arvore->esq->item)->lat == 5);
    assert(((Cidade*)arvore->esq->item)->lon == 5);
}

int main(void){
    testarKD();
    return EXIT_SUCCESS;
}