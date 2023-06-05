#include<stdio.h>
#include<stdlib.h>
#include"leitura.h"
#include"kdtree.h"
#include"cidade.h"
#include"fastfood.h"

Kdtree *lerCidades(char *nomeArquivo){
    FILE *arq = fopen(nomeArquivo, "r");

    if(arq == NULL){
        printf("\nERRO AO ABRIR O ARQUIVO");
        return NULL;
    }

    Cidade *cidadeAux;
    Kdtree *arvore = NULL;
    
    while(!feof(arq)){
        cidadeAux = (Cidade*)calloc(1, sizeof(Cidade));
        fscanf(arq, " %[^,],", cidadeAux->codigo_ibge);
        fscanf(arq, " %[^,],", cidadeAux->nome);
        fscanf(arq, " %lf,", &cidadeAux->lat);
        fscanf(arq, " %lf,", &cidadeAux->lon);
        fscanf(arq, " %[^,],", cidadeAux->capital);
        fscanf(arq, " %[^,],", cidadeAux->codigo_uf);
        fscanf(arq, " %[^,],", cidadeAux->siafi);
        fscanf(arq, " %[^,],", cidadeAux->ddd);
        fscanf(arq, " %[^\n]\n", cidadeAux->fuso);
        arvore = inserir(arvore, cidadeAux, comparaCidade);
    }
    return arvore;
}

Kdtree *lerFastfoods(char *nomeArquivo){
    FILE *arq = fopen(nomeArquivo, "r");

    if(arq==NULL){
        printf("\nDEU ERRO NO ARQUIVO");
        return NULL;
    }

    Fastfood *fastAux;
    Kdtree *arvore = NULL;

    while(!feof(arq)){
        fastAux = (Fastfood*)calloc(1, sizeof(Fastfood));
        fscanf(arq, " %[^,],", fastAux->id);
        fscanf(arq, " %[^,],", fastAux->endereco);
        fscanf(arq, " %[^,],", fastAux->cidade);
        fscanf(arq, " %[^,],", fastAux->pais);
        fscanf(arq, " %lf,", &fastAux->lat);
        fscanf(arq, " %lf,", &fastAux->lon);
        fscanf(arq, " %[^,],", fastAux->nome);
        fscanf(arq, " %[^,],", fastAux->codigo_postal);
        fscanf(arq, " %[^,],", fastAux->provincia);
        fscanf(arq, " %[^\n]\n", fastAux->sites);
        arvore = inserir(arvore, fastAux, comparaFastfood);
    }
    return arvore;
}
