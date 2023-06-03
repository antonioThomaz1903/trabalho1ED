#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"kdtree.h"
#include"cidade.h"
#include"fastfood.h"
#include"leitura.h"


void imprimirArvore(Kdtree *raiz, FILE *saida){
    if(raiz == NULL) return;
    Cidade *atual = (Cidade*)raiz->item;
    fprintf(saida, "--------------\nNome da cidade: %s\n", atual->nome);
    fprintf(saida, "LAT, LONG: (%.4lf, %.4lf)\n", atual->lat, atual->lon);
    fprintf(saida, "CAPITAL: %s\nFUSO: %s\nESTADO: %s\nSIAFI: %s\nIBGE: %s\n\n", atual->capital, atual->fuso, atual->codigo_uf, atual->siafi, atual->codigo_ibge);
    imprimirArvore(raiz->dir, saida);
    imprimirArvore(raiz->esq, saida);
}

int main(void)
{
    Kdtree *arvore = NULL;
    FILE *saida = fopen("data/saida.txt", "w");
    arvore = lerCidades("data/municipios.txt");
    imprimirArvore(arvore, saida);
    
    char nomeAux[101] = "Abadia de Goiás";
    printf("\n\n%.12lf\n\n", ((Cidade*)arvore->item)->lat);
    printf("\n\n%d\n\n", strcmp(((Cidade*)arvore->item)->nome, nomeAux));
    fclose(saida);

    return EXIT_SUCCESS;
}
