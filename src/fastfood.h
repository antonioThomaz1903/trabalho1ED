#ifndef _FASTFOODH_
#define _FASTFOODH_
#include"cidade.h"

typedef struct _fastfood{
    char endereco[MAX+1];
    char id[5];
    char categoria[MAX+1];
    char cidade[MAX+1];
    char pais[3];
    char nome[MAX+1];
    char codigo_postal[CPOSTAL+1];
    char sites[2000];
    char provincia[3];
    double lat;
    double lon;
} Fastfood;

double comparaFastfood(const void *a, const void *b, int nivel);
double calculaDistanciaFastfood(const void *a, const void *b);

#endif