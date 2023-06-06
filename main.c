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

typedef struct {
    int v;
    int peso;
} VerticePeso;

VerticePeso* prim(int origem, GrafoMatrix* grafo) {
    int numVertices = grafo->nroVertices;
    bool* visitado = (bool*)calloc(numVertices, sizeof(bool));
    VerticePeso* resultado = (VerticePeso*)malloc(numVertices * sizeof(VerticePeso));

    for (int i = 0; i < numVertices; i++) {
        resultado[i].v = -1;
        resultado[i].peso = -1;
    }

    resultado[origem].v = origem;
    resultado[origem].peso = 0;

    for (int count = 0; count < numVertices - 1; count++) {
        int u = -1;
        int minPeso = __INT_MAX__;

        for (int v = 0; v < numVertices; v++) {
            if (!visitado[v] && resultado[v].peso != -1 && resultado[v].peso < minPeso) {
                u = v;
                minPeso = resultado[v].peso;
            }
        }

        if (u == -1)
            break;

        visitado[u] = true;

        for (int v = 0; v < numVertices; v++) {
            if (!visitado[v] && grafo->matriz[u][v] != 0 && grafo->matriz[u][v] > resultado[v].peso) {
                resultado[v].v = u;
                resultado[v].peso = grafo->matriz[u][v];
            }
        }
    }

    free(visitado);
    return resultado;
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