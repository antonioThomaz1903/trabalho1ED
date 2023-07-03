#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../src/hash.h"

char *pegar_chave(void *bucket){
    return (char*)bucket;
}

void testar_hash_inserir(){
    Hash h;
    assert(construir_hash(&h, 13, pegar_chave) == EXIT_SUCCESS);
    assert(inserir_hash(&h, "Antonio") == EXIT_SUCCESS);
    assert(inserir_hash(&h, "Antonio") == EXIT_SUCCESS);
    assert(inserir_hash(&h, "Antonio") == EXIT_SUCCESS);
    assert(inserir_hash(&h, "Antonio") == EXIT_SUCCESS);
    assert(inserir_hash(&h, "Antonio") == EXIT_SUCCESS);
    assert(inserir_hash(&h, "Antonio") == EXIT_SUCCESS);
    assert(inserir_hash(&h, "Antonio") == EXIT_SUCCESS);
    assert(inserir_hash(&h, "Antonio") == EXIT_SUCCESS);
    assert(inserir_hash(&h, "Antonio") == EXIT_SUCCESS);
    assert(inserir_hash(&h, "Antonio") == EXIT_SUCCESS);
    assert(inserir_hash(&h, "Antonio") == EXIT_SUCCESS);
    assert(inserir_hash(&h, "Antonio") == EXIT_SUCCESS);
    assert(inserir_hash(&h, "Antonio") == EXIT_SUCCESS);
    assert(inserir_hash(&h, "Antonio") == EXIT_FAILURE);
}

void testar_hash_busca(){
    Hash h;
    assert(construir_hash(&h, 3, pegar_chave) == EXIT_SUCCESS);
    assert(inserir_hash(&h, "Antonio") == EXIT_SUCCESS);
    assert(inserir_hash(&h, "Tiago") == EXIT_SUCCESS);
    assert(inserir_hash(&h, "Matheus") == EXIT_SUCCESS);
    void *busca = buscar_hash(&h, "Tiago");
    assert(strcmp("Tiago", (char*)busca) == 0);
}


int main(void)
{
    testar_hash_inserir();
    testar_hash_busca();
    return EXIT_SUCCESS;
}
