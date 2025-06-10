#include "tarea2.h"

Nodo_uf **crear_uf(Nodo_g **nodos_grafo, int n) {
    Nodo_uf **nodos_uf = malloc(sizeof(Nodo_uf*) * n);
    for (int i=0; i<n; i++) {
        nodos_uf[i]->info = nodos_grafo[i];
        //nodos_uf[i]->hijos = NULL;
        //nodos_uf[i]->num_hijos = 0;
        nodos_uf[i]->padre = NULL;
        nodos_uf[i]->size = 1;
    }
    return nodos_uf;
}

void union_uf(Nodo_uf *x, Nodo_uf *y) {
    if (x->size < y->size) {
        x->padre = y;
        y->size += x->size;
    }
    else {
        y->padre = x;
        x->size += y->size;
    }
}

Nodo_uf *find_normal(Nodo_uf *x) {
    if (x->padre == NULL) {
        return x;
    }
    return find_normal(x->padre);
}

Nodo_uf *find_opti(Nodo_uf *x) {
    if (x->padre == NULL) {
        return x;
    }
    Nodo_uf *raiz = find_opti(x->padre);
    x->padre = raiz;
    return raiz;
}
