#ifndef _KDTREE_
#define _KDTREE_


typedef struct _kdtree{
    void *item;
    int nivel;
    struct _kdtree *pai;
    struct _kdtree *esq;
    struct _kdtree *dir;
    int (*compara)(const void *a, const void *b, int nivel);
} Kdtree;

Kdtree* inserir(Kdtree* raiz, void* item, int (*compara)(const void *a, const void *b, int nivel));
Kdtree* destruirArvore(Kdtree **raiz);
Kdtree* predecessor(Kdtree *no);
Kdtree* sucessor(Kdtree* no);
Kdtree* maisProximo(Kdtree *no, double (*calculaDistancia)(const void *a, const void *b));

#endif