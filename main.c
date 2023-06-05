#include <stdio.h>
#include <stdlib.h>
#include "grafo_listaadj.h"
/* #include "grafo_matrizadj.h" */

/* void trataResultadosBusca(Apontador aresta) {
  for(int i = 0; i <= aresta->size; i++) {
    if(aresta-> >= 450) aresta->listaAdj[i].weight = 450;
    else if(aresta->listaAdj[i].weight >= 400) aresta->listaAdj[i].weight = 400;
    else if(aresta->listaAdj[i].weight >= 350) aresta->listaAdj[i].weight = 350;
    else if(aresta->listaAdj[i].weight >= 300) aresta->listaAdj[i].weight = 300;
    else if(aresta->listaAdj[i].weight >= 250) aresta->listaAdj[i].weight = 250;
    else aresta->listaAdj[i].weight = -1;
  }
} */
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

int main(int argc, char const *argv[])
{   
    FILE* fp = fopen(argv[1], "r");
    
    /* le primeira linha do arquivo de entrada */
    int numVertices, numArestas, numConsultas;
    fscanf(fp, "%d %d %d", &numVertices, &numArestas, &numConsultas);

    /* inicializa grafo */
    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
    inicializaGrafo(&grafo, numVertices);

    /* le arestas */
    int v1, v2;
    float peso;
    for (int i = 0; i < numArestas; i++) {
        printf("dentro do for loop\n");
        fscanf(fp, "%d %d %f", &v1, &v2, &peso);
        insereAresta(v1, v2, peso, &grafo);
    }
    printf("leu e armazenou no grafo\n");

    for (int i = 0; i < numConsultas; i++) {
        fscanf(fp, "%d %d\n", &v1, &v2);
        // Process the query data here
    }
    /* depois de ler todo o arquivo não esqueça de fechá-lo */
    fclose(fp);

    imprimeGrafo(grafo);

    return 0;
}