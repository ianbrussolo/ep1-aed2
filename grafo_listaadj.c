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

void obterPesoEDestino(Grafo *grafo, int v1, int indiceAresta, int *dest, Peso *peso) {
	if((v1 < 0) || (v1 > grafo->nroVertices)) return;
	/* if((indiceAresta < 0) || (indiceAresta > grafo->listaAdj[v1].edges)) return; */
	if(g->nodeList[nodeI].edges == 0) {
		*dest = -1;
		*weight = -1;
		return;
	};
	Link *temp = g->nodeList[nodeI].head;
	for(int i = 0; i < LinkIndex; i++) {
		temp = temp->next;
	}
	*dest = temp->dest;
	*weight = temp->weight;
}

/* int obterNroArestas(Grafo *grafo, int v1) {
	if((v1 < 0) || (v1 > grafo->nroVertices)) return -1;
	return grafo->listaAdj[v1].;
} */

Peso pesoAresta(int v1, int v2, Grafo *grafo) {
    Apontador q;
    if (!(verificaVertice(v1, grafo) && verificaVertice(v2, grafo)))
        return -1; // return -1 to indicate an error

    q = grafo->listaAdj[v1];
    while ((q != NULL) && (q->vdest != v2))
        q = q->prox;
    if (q != NULL)
    {
        return q->peso; // return the weight of the edge
    }
    return AN; // return -1 to indicate that the edge doesn't exist
}
