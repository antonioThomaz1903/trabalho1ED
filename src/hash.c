#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include"hash.h"

uint32_t hashf(const char *str, uint32_t h){
    for (; *str; ++str) {
            h ^= *str;
            h *= 0x5bd1e995;
            h ^= h >> 15;
        }
        return h;
}

uint32_t hashf2(uint32_t hash1){
    return 1 + hash1;
}

int inserir_hash(Hash *h, void *bucket){
    if(h->max == h->tamanho+1){
        return EXIT_FAILURE;
    }
    uint32_t hash = hashf(h->chave(bucket), SEED);
    int pos = hash % h->max;
    int inc = hashf2(hash)/h->max % (h->max - 1);
    while(h->tabela[pos] != 0){
        if(h->tabela[pos] == h->del)
            break;
        pos += inc; 
    }
    h->tabela[pos] = bucket;
    h->tamanho++;
    return EXIT_SUCCESS;
}

int construir_hash(Hash *h, int n_buckets, char *( *chave)(void *bucket)){
    int max = n_buckets + 1;
    h->tabela = (uintptr_t)calloc(max, sizeof(uintptr_t));
    if(h->tabela == NULL)
        return EXIT_FAILURE;
    h->max = max;
    h->tamanho = 0;
    h->del = (uintptr_t) &(h->tamanho);
    h->chave = chave;
    return EXIT_SUCCESS;
}

void *buscar_hash(Hash *h, const char *chave){
    uint32_t hash = hashf(chave, SEED);
    int pos = hash % h->max;
    int inc = hashf2(hash)/h->max % (h->max - 1);
    while(h->tabela[pos] != 0){
        if(strcmp(h->chave(h->tabela[pos]), chave) == 0)
            return (void *)h->tabela[pos];
        pos += inc;
    }
    return NULL;
}

int remover_hash(Hash *h, const char *chave){
    uint32_t hash = hashf(chave, SEED);
    int pos = hash% h->max;
    int inc = hashf2(hash)/h->max % (h->max - 1);
    while(h->tabela[pos]!=0){
        if(strcmp(h->chave(h->tabela[pos]), chave) == 0){
            free((void*)h->tabela[pos]);
            h->tabela[pos] = h->del;
            h->tamanho--;
            return EXIT_SUCCESS;
        }
        pos += inc;
    }
    return EXIT_FAILURE;
}

void apagar_hash(Hash *h){
    int pos;
    for(pos=0; pos < h->max; pos++){
        if(h->tabela[pos] !=0 && h->tabela[pos] != h->del){
            free((void *)h->tabela[pos]);
        }
    }
    free(h->tabela);
}
