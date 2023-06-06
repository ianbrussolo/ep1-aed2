#include <stdio.h>
#include "grafo_matrizadj.h"

void inicializaGrafo(Grafo **grafo, int nv) {
    int i, j;

    (*grafo)->nroVertices = nv;
    (*grafo)->nroArestas = 0;
    for (i = 0; i < (*grafo)->nroVertices; i++) {
        for (j = 0; j < (*grafo)->nroVertices; j++) {
            (*grafo)->mat[i][j] = AN;
        }
    }
    printf("grafo inicializado\n");
    return;
}

void insereAresta(int v1, int v2, Peso peso, Grafo **grafo) {
    (*grafo)->mat[v1][v2] = peso;
    (*grafo)->nroArestas++;
    printf("aresta %d - %d inserida\n", v1, v2);
    return;
}

void imprimeGrafo(Grafo* grafo) {
    printf("Graph:\n");
    for (int i = 0; i < grafo->nroVertices; i++) {
        for (int j = 0; j < grafo->nroVertices; j++) {
            if (i != j && grafo->mat[i][j] != -1) {
                printf("(%d) -- %.1f -- (%d)\n", i, grafo->mat[i][j], j);
            }
        }
    }
}