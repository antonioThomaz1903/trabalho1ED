#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"kdtree.h"

Kdtree* criarKD(void* item, Kdtree *pai, int nivel,  int (*compara)(const void *a, const void *b, int nivel)){
    Kdtree* raiz = (Kdtree*)calloc(1, sizeof(Kdtree));
    
    raiz->item = item;
    raiz->dir = NULL;
    raiz->esq = NULL;
    raiz->pai = pai;
    raiz->nivel = nivel;
    raiz->compara = compara;
    return raiz;
}

Kdtree* inserirAux(Kdtree* raiz, void* item, int nivel, Kdtree *pai, int (*compara)(const void *a, const void *b, int nivel)){

    if(raiz == NULL) return criarKD(item, pai, nivel, compara);
    Kdtree *atual = raiz;

    if(raiz->compara(raiz->item, item, nivel)){
        raiz->esq = inserirAux(raiz->esq, item, nivel+1, atual, compara);
    }
    else{
        raiz->dir = inserirAux(raiz->dir, item, nivel+1, atual, compara);
    }

    return raiz;
}

Kdtree* inserir(Kdtree* raiz, void* item, int (*compara)(const void *a, const void *b, int nivel)){
    return inserirAux(raiz, item, 0, NULL, compara);
}

Kdtree* destruirArvore(Kdtree **raiz){
    if(*raiz != NULL){
        destruirArvore(&(*raiz)->dir);
        destruirArvore(&(*raiz)->esq);
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
        (*raiz)->pai = NULL;
        free(&(*raiz)->item);
        free(&*raiz);
    }
    return *raiz = NULL;
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

    if(no->pai != NULL){
        if(no == no->pai->esq){
            return no->pai->pai;
        }
        return no->pai;
    }
    return NULL;
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
    
    if(no->pai != NULL){
        if(no->pai->dir != NULL && no == no->pai->dir)
            return no->pai->pai;
        
        return no->pai;    
    }
    return NULL;
}

Kdtree* maisProximo(Kdtree *no, double (*calculaDistancia)(const void *a, const void *b)){
    Kdtree *suc, *pred;
    suc = sucessor(no);
    pred = predecessor(no);

    if(suc == NULL && pred == NULL){
        return NULL;
    }
    else if(suc == NULL){
        return pred;
    }
    else if(pred == NULL){
        return suc;
    }

    if(calculaDistancia(no->item, suc->item) <= calculaDistancia(no->item, pred->item)){
        return suc;
    }
    else{
        return pred;
    }

}

Kdtree* maisProximosAux(Kdtree *no, Kdtree *aux, Kdtree *ultS, int i, int k, Kdtree** vetor, int fs, int voltar){
    if(i == k || no == NULL){
        return vetor;
    }
    

    if((i <= k/2 && !fs) || (voltar && i < k)){
        Kdtree *suc;
        suc = sucessor(no);
        if(suc != NULL){
            vetor[i] = suc;
            maisProximosAux(suc, aux, suc, i+1, k, vetor, 0, 0);
        }
        else{
            maisProximosAux(no, aux, suc, i, k, vetor, 1, 0);
        }
    }
    else{
        no = aux;
        Kdtree *pred;
        pred = predecessor(no);
        if(pred != NULL){
            vetor[i] = pred;
            if(!fs){
                maisProximosAux(pred, pred, ultS, i+1, k, vetor, 0, 0);
            }
            else{
                maisProximosAux(pred, pred, ultS, i+1, k, vetor, 1, 0);
            }
        }
        else{
            if(!fs){
                maisProximosAux(ultS, NULL, ultS, i, k, vetor, 0, 1);
            }
            else{
                maisProximosAux(NULL, NULL, ultS, i, k, vetor, 1, 0);
            }
        }
    }

}

Kdtree** maisProximos(Kdtree *no, int k){
    Kdtree **vetor = (Kdtree*)calloc(k, sizeof(Kdtree));
    return maisProximosAux(no, no, NULL, 0, k, vetor, 0, 0);
}


Kdtree* buscarNoNome(Kdtree* arvore, char *nome, int (*igualaNo)(const void *a, const char *nome)){
    if(arvore == NULL){
        return NULL;
    }

    else if(igualaNo(arvore->item, nome)){
        return arvore;
    }

    buscarNoNome(arvore->esq, nome, igualaNo);
    buscarNoNome(arvore->dir, nome, igualaNo);

}








