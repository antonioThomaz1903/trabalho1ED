#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"kdtree.h"
#include"cidade.h"
#include"fastfood.h"
#include"leitura.h"


void imprimirArvoreCidade(Kdtree *raiz, FILE *saida){
    if(raiz == NULL) return;
    Cidade *atual = (Cidade*)raiz->item;
    fprintf(saida, "--------------\nNome da cidade: %s\n", atual->nome);
    fprintf(saida, "LAT, LONG: (%.4lf, %.4lf)\n", atual->lat, atual->lon);
    fprintf(saida, "CAPITAL: %s\nFUSO: %s\nESTADO: %s\nSIAFI: %s\nIBGE: %s\n\n", atual->capital, atual->fuso, atual->codigo_uf, atual->siafi, atual->codigo_ibge);
    imprimirArvoreCidade(raiz->esq, saida);
    imprimirArvoreCidade(raiz->dir, saida);
}

void imprimirArvoreFastfood(Kdtree *raiz, FILE *saida){
    if(raiz == NULL) return;
    Fastfood *atual = (Fastfood*)raiz->item;
    fprintf(saida, "--------------\nNome do Fastfood: %s\n", atual->nome);
    fprintf(saida, "LAT, LONG: (%.4lf, %.4lf)\n", atual->lat, atual->lon);
    fprintf(saida, "ENDERECO: %s\nPAIS: %s\nID: %s\nCODIGO POSTAL: %s\nCIDADE: %s\n\n", atual->endereco, atual->pais, atual->id, atual->codigo_postal, atual->cidade);
    imprimirArvoreFastfood(raiz->esq, saida);
    imprimirArvoreFastfood(raiz->dir, saida);
}

void imprimirVetorC(Kdtree **vetor, int i){
    for(int j=0; j<i; j++){
        printf("\nCIDADE: %s\n", ((Cidade*)vetor[j]->item)->nome);
    }
}

void imprimirVetorF(Kdtree **vetor, int i){
    for(int j=0; j<i; j++){
        printf("\nFASTFOOD: %s\n", ((Fastfood*)vetor[j]->item)->nome);
    }
}

int main(void)
{
    Kdtree *arvoreC = NULL;
    Kdtree *arvoreF = NULL;


    FILE *saidaC = fopen("data/saidaCidade.txt", "w");
    FILE *saidaF = fopen("data/saidaFastfood.txt", "w");

    arvoreC = lerCidades("data/municipios.txt");
    arvoreF = lerFastfoods("data/fastfoods.txt");


    imprimirArvoreCidade(arvoreC, saidaC);
    imprimirArvoreFastfood(arvoreF, saidaF);

    fclose(saidaC);
    fclose(saidaF);

    Kdtree *prox = maisProximo(arvoreC, calcularDistanciaCidade);
    printf("\nCIDADE MAIS PROXIMA DE: %s\n", ((Cidade*)arvoreC->item)->nome);

    printf("CIDADE: %s\n\n", ((Cidade*)prox->item)->nome);

    printf("-------------------------\n");

    printf("OS 5 FASTFOODS MAIS PROXIMOS DE: %s\n", ((Fastfood*)arvoreF->item)->nome);
    Kdtree **proxs = maisProximos(arvoreF, 5);
    imprimirVetorF(proxs, 5);

    return EXIT_SUCCESS;
}
