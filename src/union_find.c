#include "tarea2.h"

void union_(Nodo *x, Nodo *y) {
    if (x->size < y->size) {
        x->padre = y;
        y->size += x->size;
    }
    else {
        y->padre = x;
        x->size += y->size;
    }
}

Nodo *find_normal(Nodo *x) {
    if (x->padre == NULL) {
        return x;
    }
    return find_normal(x->padre);
}

Nodo *find_opti(Nodo *x) {
    if (x->padre == NULL) {
        return x;
    }
    Nodo *raiz = find_opti(x->padre);
    x->padre = raiz;
    return raiz;
}
