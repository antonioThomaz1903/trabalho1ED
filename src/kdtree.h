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

Kdtree* inserir(Kdtree* raiz, void* item, double x, double y);
void destruirArvore(Kdtree *raiz);
Kdtree* predecessor(Kdtree *no);
Kdtree* sucessor(Kdtree* no);

#endif