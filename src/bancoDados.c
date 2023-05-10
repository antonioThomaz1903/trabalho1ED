#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lib/bancoDados.h"

int carregarBancoDados(char *nome){
    BD = fopen(nome, "r");
    if(BD == NULL){
        return EXIT_FAILURE;
    }
    else{
        return EXIT_SUCCESS;
    }
}

int lerBancoDados(bancoDados* tabela){

}

void adicionarLinha(bancoDados *tabela, bancoDados adicionar){
    bancoDados *novo = (bancoDados*)calloc(1, sizeof(bancoDados));
    novo->codigo_ibge = adicionar.codigo_ibge;
    novo->capital = adicionar.capital;
    novo->cofigo_uf = adicionar.cofigo_uf;
    novo->ddd = adicionar.ddd;
    novo->latitude = adicionar.latitude;
    novo->longitude = adicionar.longitude;
    strcpy(novo->nome, adicionar.nome);
    strcpy(novo->fuso_horario, adicionar.fuso_horario);
    strcpy(novo->siafi_id, adicionar.siafi_id);

    if(tabela == NULL){
        tabela = novo;
    }
    else{
        
    }

}