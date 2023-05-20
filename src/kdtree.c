#include<stdio.h>
#include<stdlib.h>
#include"kdtree.h"

Kdtree* criarKD(void* item, double x, double y, Kdtree *pai){
    Kdtree* raiz = (Kdtree*)calloc(1, sizeof(Kdtree));
    
    raiz->item = item;
    raiz->dir = NULL;
    raiz->esq = NULL;
    raiz->pai = pai;
    raiz->x = x;
    raiz->y = y;
    
    return raiz;
}

Kdtree* inserirAux(Kdtree* raiz, void* item, double x, double y, int nivel, Kdtree *pai){

    if(raiz == NULL) return criarKD(item, x, y, pai);

    nivel = nivel % 2;
    Kdtree *atual = raiz;

    if(nivel == 0){
        if(x < raiz->x){
            raiz->esq = inserirAux(raiz->esq, item, x, y, nivel+1, atual);
        }
        else{
            raiz->dir = inserirAux(raiz->dir, item, x, y, nivel+1, atual);
        }
    }
    else{
        if(y < raiz->y){
            raiz->esq = inserirAux(raiz->esq, item, x, y, nivel+1, atual);
        }
        else{
            raiz->dir = inserirAux(raiz->dir, item, x, y, nivel+1, atual);
        }
    }

    return raiz;
}

Kdtree* inserir(Kdtree* raiz, void* item, double x, double y){
    return inserirAux(raiz, item, x, y, 0, NULL);
}

void destruirArvore(Kdtree **raiz){
    if(*raiz != NULL){
        destruirArvore(&(*raiz)->dir);
        destruirArvore(&(*raiz)->esq);
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
        (*raiz)->pai = NULL;
        free(&(*raiz)->item);
        free(&*raiz);
    }
}


Kdtree* predecessorAux(Kdtree* filho_esquerdo){
    if(filho_esquerdo->dir == NULL){
        return filho_esquerdo;
    }
    return predecessorAux(filho_esquerdo->dir);
}

Kdtree* predecessor(Kdtree *no){
    if(no->esq != NULL)
        return predecessorAux(no->esq);
    return no->pai;
}

Kdtree* sucessorAux(Kdtree* filho_direito){
    if(filho_direito->esq == NULL){
        return filho_direito;
    }
    return sucessorAux(filho_direito->esq);
}

Kdtree* sucessor(Kdtree* no){
    if(no->dir != NULL)
        return sucessorAux(no->dir);
    return no->pai;
}











