#ifndef _FASTFOODH_
#define _FASTFOODH_
#include"cidade.h"

typedef struct _fastfood{
    char endereco[MAX+10];
    char id[10];
    char cidade[MAX+100];
    char pais[8];
    char nome[MAX+100];
    char codigo_postal[CPOSTAL+10];
    char sites[2000];
    char provincia[8];
    double lat;
    double lon;
} Fastfood;

double comparaFastfood(const void *a, const void *b, int nivel);
double calculaDistanciaFastfood(const void *a, const void *b);
int igualaFastfood(const void *a, const char *nome);

#endif