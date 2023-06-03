#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"fastfood.h"

double comparaFastfood(const void *a, const void *b, int nivel){
    Fastfood *f1 = (Fastfood*)a;
    Fastfood *f2 = (Fastfood*)b;
    if(nivel % 2==0){
        if(f1->lat >= f2->lat){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        if(f1->lon >= f2->lon){
            return 1;
        }
        else{
            return 0;
        }
    }
}

double calcularDistanciaFastfood(const void *a, const void *b){
    Fastfood *fA = (Fastfood*)a;
    Fastfood *fB = (Fastfood*)b;
    double deltaLat, deltaLong, distancia, aux;
    deltaLat = fA->lat - fB->lat;
    deltaLong = fA->lon - fB->lon;
    aux = (deltaLat * deltaLat) + (deltaLong * deltaLong);
    distancia = sqrt(aux);
    return distancia;
}

