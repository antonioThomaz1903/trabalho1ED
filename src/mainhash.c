#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
#include "hash.h"
#include "cidade.h"

char *get_chave_cidade(void *bucket){
    return ((Cidade*)bucket)->codigo_ibge;
}

int main()
{
    Hash h;
    construir_hash(&h, 5, get_chave_cidade);

    Cidade c1;
    strcpy(c1.nome, "Campo Grande");
    strcpy(c1.codigo_ibge, "1234");

    inserir_hash(&h, &c1);

    Cidade c2;
    strcpy(c2.nome, "Dourados");
    strcpy(c2.codigo_ibge, "5678");

    inserir_hash(&h, &c2);

    Cidade c3;
    strcpy(c3.nome, "Sao Paulo");
    strcpy(c3.codigo_ibge, "9123");

    inserir_hash(&h, &c3);

    void *busca = buscar_hash(&h, "1234");
    printf("\nCIDADE 1234: %s\n", ((Cidade*)busca)->nome);

    busca = buscar_hash(&h, "5678");
    printf("\nCIDADE 5678: %s\n", ((Cidade*)busca)->nome);

    busca = buscar_hash(&h, "9123");
    printf("\nCIDADE 9123: %s\n", ((Cidade*)busca)->nome);

    return 0;
}

