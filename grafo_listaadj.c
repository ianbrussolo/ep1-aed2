#include <stdio.h>
#include <stdlib.h>
#include "grafo_listaadj.h"

void inicializaGrafo(Grafo *grafo, int nv) {
    int i;

    /* if (nv <= 0) {
        fprintf(stderr"erro: ")
    } */
     
    grafo->listaAdj = (Apontador*) calloc(nv+1, sizeof(Apontador));
    grafo->nroVertices = nv;
    grafo->nroArestas = 0;
    printf("grafo inicializado\n");
    //calloc ja inicializa as listas de adjacencia com zeros
    return;
}

void insereAresta(int v1, int v2, Peso peso, Grafo *grafo) {
    Apontador p;
    p = (Apontador) calloc(1, sizeof(Aresta));
    p->vdest = v2;
    p->peso = peso;
    p->prox = grafo->listaAdj[v1];
    grafo->listaAdj[v1] = p;
    grafo->nroArestas++;
    printf("aresta inserida\n");
}

int main(int argc, char const *argv[])
{   
    printf("pelo menos entrou na porra do main\n");
    FILE* fp = fopen(argv[1], "r");
    
    /* le primeira linha do arquivo de entrada */
    int numVertices, numArestas, numConsultas;
    fscanf(fp, "%d %d %d", &numVertices, &numArestas, &numConsultas);

    /* inicializa grafo */
    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
    inicializaGrafo(grafo, numVertices);

    /* le arestas */
    int v1, v2;
    float peso;
    int valuesRead;
    for (int i = 0; i < numArestas; i++) {
        printf("dentro do for loop\n");
        fscanf(fp, "%d %d %f", &v1, &v2, &peso);
        insereAresta(v1, v2, peso, grafo);
    }

    printf("leu e armazenou\n");
    /* depois de ler todo o arquivo não esqueça de fechá-lo */
    fclose(fp);
    return 0;
}
