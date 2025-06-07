#include "tarea2.h"

typedef struct nodo{
    double x;
    double y;
} Nodo;

double calcular_peso(Nodo* n1, Nodo* n2) {
    return (n1->x - n2->x)*(n1->x - n2->x) + (n1->y - n2->y)*(n1->y - n2->y);
}

typedef struct arista{
    Nodo *nodo1;
    Nodo *nodo2;
    double peso;
    //(nodo1->x-nodo2->x)*(nodo1->x-nodo2->x) + (nodo1->y+nodo2->y)*(nodo1->y-nodo2->y)
} Arista;

typedef struct grafo{
    int n ; // Número de nodos
    double *nodos;
    int e; // Número de aristas
    double *aristas;
} Grafo;

Grafo* crear_grafo(int n, int e, double* nodos, double* aristas) {
    Grafo* g = (Grafo*)malloc(sizeof(Grafo));
    g->n = n;
    g->e = e;
    g->nodos = nodos; // Cada nodo tiene dos coordenadas (x, y)
    g->aristas = aristas; // Cada arista tiene dos nodos y un peso
    return g;
}



