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

void in/* sereA */resta(int v1, int v2, Peso peso, Grafo **grafo) {
    Apontador p;
    p = (Apontador) calloc(1, sizeof(Aresta));
    p->vdest = v2;
    p->peso = peso;
    p->prox = (*grafo)->listaAdj[v1];
    (*grafo)->listaAdj[v1] = p;
    (*grafo)->nroArestas++;
    printf("aresta %d - %d inserida\n", v1, v2);
}

Apontador proxListaAdj(int v, Grafo *grafo, Apontador atual) {
    return atual->prox;
}

void imprimeGrafo(Grafo* grafo) {
    printf("Graph:\n");
    for (int v = 0; v < grafo->nroVertices; v++) {
        Apontador atual = grafo->listaAdj[v];
        while (atual != NULL) {
            printf("(%d) -- %.1f -- (%d)\n", v, atual->peso, atual->vdest);
            atual = atual->prox;
        }
    }
}
/* void imprimeGrafo(Grafo *grafo) {

} */

