#ifndef _CIDADE_
#define _CIDADE_
#define MAX 100
#define CIBGE 7
#define UF 2
#define CAPITAL 1
#define SIAFI 4
#define DDD 2
#define CPOSTAL 5

typedef struct _cidade{
    char codigo_ibge[CIBGE+1];
    char nome[MAX+1];
    char codigo_uf[UF+1];
    char capital[CAPITAL+1];
    char siafi[SIAFI+1];
    char ddd[DDD+1];
    char fuso[MAX+1];
    double lat;
    double lon;
} Cidade;

int comparaCidade(const void *a, const void *b, int nivel);
double calcularDistanciaCidade(const void *a, const void *b);


#endif