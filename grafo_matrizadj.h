#include <stdbool.h>

#define MAXNUMVERTICES 100
#define AN -1 //ausencia de aresta
#define VERTICE_INVALIDO -1 //vertice inexistente

typedef float Peso;
typedef struct {
    Peso mat[MAXNUMVERTICES + 1][MAXNUMVERTICES + 1];
    int nroVertices;
    int nroArestas;
} Grafo;
typedef int Apontador;

void inicializaGrafo(Grafo **grafo, int nv);
void insereAresta(int v1, int v2, Peso peso, Grafo **grafo);
void obterPesoEDestino(Grafo *grafo, int v1, int indiceAresta, int *dest, Peso *peso);
int obterNroArestas(Grafo *grafo, int v1);
Apontador proxListaAdj(int v, Grafo* grafo, Apontador atual);
void imprimeGrafo(Grafo *grafo);
