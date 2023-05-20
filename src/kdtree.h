#ifndef _KDTREE_
#define _KDTREE_
#define MAX 100
#define CIBGE 7
#define UF 2
#define CAPITAL 1
#define SIAFI 4
#define DDD 2
#define CPOSTAL 5

typedef struct _kdtree{
    void *item;
    struct _kdtree *pai;
    struct _kdtree *esq;
    struct _kdtree *dir;
    double x; //LATITUDE
    double y; //LONGITUDE
} Kdtree;

Kdtree* inserir(Kdtree* raiz, void* item, double x, double y);
Kdtree* destruirArvore(Kdtree **raiz);
Kdtree* predecessor(Kdtree *no);
Kdtree* sucessor(Kdtree* no);

#endif