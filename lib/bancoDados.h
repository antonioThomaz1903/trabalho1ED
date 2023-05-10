#include<stdio.h>
#include<stdlib.h>

FILE *BD = NULL;

typedef struct bancoDados
{
    int codigo_ibge;
    char nome[101];
    double latitude;
    double longitude;
    int capital;
    int cofigo_uf;
    char siafi_id[5];
    int ddd;
    char fuso_horario[33];
    bancoDados *prox;
}bancoDados;

int carregarBancoDados(char *nome);
int lerBancoDados(bancoDados *tabela);
void adicionarLinha(bancoDados *tabela, bancoDados adicionar);

