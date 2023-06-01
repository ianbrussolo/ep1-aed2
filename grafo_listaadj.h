#include <stdbool.h>

typedef float Peso; 

typedef struct str_aresta {
    int vdest;
    Peso peso;
    struct str_aresta * prox;
} Aresta;
typedef Aresta* Apontador;

typedef struct {
    Apontador* listaAdj;
    int nroVertices;
    int nroArestas;
} Grafo;

void inicializaGrafo(Grafo *grafo, int nv);
void insereAresta(int v1, int v2, Peso peso, Grafo *grafo);
bool existeAresta(int v1, int v2, Grafo *grafo);
void removeAresta(int v1, int v2, Peso *peso, Grafo *grafo);
bool listaAdjVazia(int v, Grafo *grafo);
int primeiroListaAdj(int v, Grafo *grafo);
int proxListaAdj(int v, Grafo *grafo, int prox);
void imprimeGrafo(Grafo *grafo);