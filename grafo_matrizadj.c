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
    
    return;
}

void insereAresta(int v1, int v2, Peso peso, Grafo **grafo) {

}