#include <stdio.h>
#include "grafo_listaadj.h"

void inicializaGrafo(Grafo *grafo, int nv) {
    int i;

    /* if (nv <= 0) {
        fprintf(stderr"erro: ")
    } */

    grafo->nroVertices = nv;
    grafo->listaAdj = (Apontador*) calloc(nv+1, sizeof(Apontador));
    grafo->nroArestas = 0;
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
}

int main(int argc, char const *argv[])
{   
    if (argc != 2) {
        /* mensagem explicando o erro e sai */
    }
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        /* mensagem explicando o erro e sai */
    }
    
    /* le primeira linha do arquivo de entrada */
    int numVertices, numArestas, numConsultas;
    fscanf(fp, "%d %d %d", &numVertices, &numArestas, &numConsultas);

    /* inicializa grafo */
    Grafo grafo;
    inicializaGrafo(grafo, numVertices);

    while (fscanf(fp) != EOF) {
        int v1, v2;
        float peso;
        fscanf(fp, "%d %d %f", &v1, &v2, &peso);
        insereAresta(v1, v2, peso, grafo);
    }
    
    /* depois de ler todo o arquivo não esqueça de fechá-lo */
    fclose(fp);
    return 0;
}
