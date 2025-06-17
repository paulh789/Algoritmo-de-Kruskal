#include "tarea2.h"

double calcular_peso(Nodo* n1, Nodo* n2) {
    return (n1->x - n2->x)*(n1->x - n2->x) + (n1->y - n2->y)*(n1->y - n2->y);
}

Nodo* crear_nodo(double x, double y) {
    Nodo* nodo = malloc(sizeof(Nodo));
    nodo->x = x;
    nodo->y = y;
    nodo->padre = NULL;
    nodo->size = 1;
    return nodo;
}

Arista* crear_arista(Nodo* n1, Nodo* n2) {
    Arista* arista = malloc(sizeof(Arista));
    arista->nodo1 = n1;
    arista->nodo2 = n2;
    arista->peso = calcular_peso(n1, n2);
    return arista;
}

Grafo* crear_grafo(Punto **puntos, int n) {
    Grafo* g = malloc(sizeof(Grafo));
    g->n = n;
    int e = (n*(n-1))/2;
    g->e = e;

    Nodo **nodos = malloc(n * sizeof(Nodo*));
    Nodo *nodo;
    for (int i=0; i<n; i++) {
        nodo = crear_nodo(puntos[i]->x, puntos[i]->y);
        nodos[i] = nodo;
    }
    g->nodos = nodos;

    Arista **aristas = malloc(e * sizeof(Arista*));
    int contador = 0;
    Arista *arista;
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            arista = crear_arista(nodos[i], nodos[j]);
            aristas[contador] = arista;
            contador++;
        }
    }
    g->aristas = aristas;

    return g;
}

void destruirGrafo(Grafo *g) {
    for (int i=0; i<g->n; i++) {
        free((g->nodos)[i]);
    }
    for (int i=0; i<g->e; i++) {
        free((g->aristas)[i]);
    }
    free(g->nodos);
    free(g->aristas);
    free(g);
}
