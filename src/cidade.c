#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include"cidade.h"


int comparaCidade(const void *a, const void *b, int nivel){
    Cidade *c1 = (Cidade*)a;
    Cidade *c2 = (Cidade*)b;
    if(nivel % 2==0){
        if(c1->lat >= c2->lat){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        if(c1->lon >= c2->lon){
            return 1;
        }
        else{
            return 0;
        }
    }
}

double calcularDistanciaCidade(const void *a, const void *b){
    Cidade *cA = (Cidade*)a;
    Cidade *cB = (Cidade*)b;
    double deltaLat, deltaLong, distancia, aux;
    deltaLat = cA->lat - cB->lat;
    deltaLong = cA->lon - cB->lon;
    aux = (deltaLat * deltaLat) + (deltaLong * deltaLong);
    distancia = sqrt(aux);
    return distancia;
}
