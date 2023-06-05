#include <stdio.h>
#include <stdlib.h>
#include "grafo_listaadj.h"

void inicializaGrafo(Grafo **grafo, int nv) {
    int i;

    /* if (nv <= 0) {
        fprintf(stderr"erro: ")
    } */
     
    (*grafo)->listaAdj = (Apontador*) calloc(nv+1, sizeof(Apontador));
    (*grafo)->nroVertices = nv;
    (*grafo)->nroArestas = 0;
    printf("grafo inicializado\n");
    //calloc ja inicializa as listas de adjacencia com zeros
    return;
}

void insereAresta(int v1, int v2, Peso peso, Grafo **grafo) {
    Apontador p;
    p = (Apontador) calloc(1, sizeof(Aresta));
    p->vdest = v2;
    p->peso = peso;
    p->prox = (*grafo)->listaAdj[v1];
    (*grafo)->listaAdj[v1] = p;
    (*grafo)->nroArestas++;
    printf("aresta inserida\n");
}

Apontador proxListaAdj(int v, Grafo *grafo, Apontador atual) {
    return atual->prox;
}

/* void imprimeGrafo(Grafo *grafo) {

} */

