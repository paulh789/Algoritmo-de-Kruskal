#include "tarea2.h"

double calcular_peso(Nodo_g* n1, Nodo_g* n2) {
    return (n1->x - n2->x)*(n1->x - n2->x) + (n1->y - n2->y)*(n1->y - n2->y);
}

// Función auxiliar para crear un nodo
Nodo_g* crear_nodo(double x, double y) {
    Nodo_g* nodo = malloc(sizeof(Nodo_g));
    nodo->x = x;
    nodo->y = y;
    return nodo;
}

// Función auxiliar para crear una arista
Arista* crear_arista(Nodo_g* n1, Nodo_g* n2) {
    Arista* arista = malloc(sizeof(Arista));
    arista->nodo1 = n1;
    arista->nodo2 = n2;
    arista->peso = calcular_peso(n1, n2);
    return arista;
}

Grafo* crear_grafo(int n, int e, Nodo_g** nodos, Arista** aristas) {
    Grafo* g = (Grafo*)malloc(sizeof(Grafo));
    g->n = n;
    g->e = e;
    g->nodos = nodos; // Cada nodo tiene dos coordenadas (x, y)
    g->aristas = aristas; // Cada arista tiene dos nodos y un peso
    return g;
}

