#include "tarea2.h"

double calcular_peso(Nodo_g* n1, Nodo_g* n2) {
    return (n1->x - n2->x)*(n1->x - n2->x) + (n1->y - n2->y)*(n1->y - n2->y);
}

Grafo* crear_grafo(int n, int e, double* nodos, double* aristas) {
    Grafo* g = (Grafo*)malloc(sizeof(Grafo));
    g->n = n;
    g->e = e;
    g->nodos = nodos; // Cada nodo tiene dos coordenadas (x, y)
    g->aristas = aristas; // Cada arista tiene dos nodos y un peso
    return g;
}

