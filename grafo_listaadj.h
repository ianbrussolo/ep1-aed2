#include <stdbool.h>

#define AN -1 //ausencia de aresta
#define VERTICE_INVALIDO NULL    //vertice inexistente   

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

void inicializaGrafo(Grafo **grafo, int nv);
void insereAresta(int v1, int v2, Peso peso, Grafo **grafo);
void obterPesoEDestino(Grafo *grafo, int v1, int indiceAresta, int *dest, Peso *peso);
int obterNroArestas(Grafo *grafo, int v1);
int primeiroListaAdj(int v, Grafo *grafo);
Apontador proxListaAdj(int v, Grafo *grafo, Apontador atual);
void imprimeGrafo(Grafo *grafo);