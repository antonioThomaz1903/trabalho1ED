#ifndef _HASH_H_
#define _HASH_H_
#define SEED 0x12345678
#include<stdint.h>

typedef struct {
    uintptr_t * tabela;
    int tamanho;
    int max;
    uintptr_t del;
    char *( *chave)(void *bucket);
}Hash;

uint32_t hashf(const char *str, uint32_t h);
uint32_t hashf2(uint32_t hash1);
int inserir_hash(Hash *h, void *bucket);
int construir_hash(Hash *h, int n_buckets, char *( *chave)(void *bucket));
void *buscar_hash(Hash *h, const char *chave);
int remover_hash(Hash *h, const char *chave);
void apagar_hash(Hash *h);

#endif