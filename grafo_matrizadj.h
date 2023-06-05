#include <stdbool.h>

#define MAXNUMVERTICES 100
#define AN -1 //ausencia de aresta
#define VERTICE_INVALIDO -1 //vertice inexistente

typedef int Peso;
typedef struct {
    Peso mat[MAXNUMVERTICES + 1][MAXNUMVERTICES + 1];
    int nroVertices;
    int nroArestas;
} Grafo;
typedef int Apontador;

void inicializaGrafo(Grafo **grafo, int nv);
void insereAresta(int v1, int v2, Peso peso, Grafo **grafo);
bool existeAresta(int v1, int v2, Grafo *grafo);
void removeAresta(int v1, int v2, Peso *peso, Grafo *grafo);
Apontador proxListaAdj(int v, Grafo* grafo, Apontador atual);
void imprimeGrafo(Grafo *grafo);
