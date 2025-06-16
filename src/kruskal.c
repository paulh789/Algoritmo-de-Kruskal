#include "tarea2.h"

// (1) Sin optimización de find y usando arreglo de aristas
Arista *kruskal_1(Grafo* g) {
    Arista **E = g->aristas;
    qsort(E, g->e, sizeof(Arista*), comparar_aristas_ptr); //ordenar aristas con quicksort
    Arista *T = malloc((g->n - 1) * sizeof(Arista)); //árbol cobertor mínimo
    int contador = 0; //contador de aristas del árbol T
    int i = 0;
    while (i < g->e && contador < g->n - 1) {
        Arista *arista = E[i]; //obtener arista
        //find de los nodos de la arista
        Nodo *x = find_normal(arista->nodo1);
        Nodo *y = find_normal(arista->nodo2);
        if (x != y) { 
            T[contador] = *arista; //añadir arista al árbol T
            contador++;
            union_(x, y); //hacer union de los nodos representantes
        }
        i++;
    }
    return T;
}

// (2) Sin optimización de find y usando heap
Arista *kruskal_2(Grafo* g) {
    Heap *E = heapifyArray((void**)g->aristas, g->e, (Comparator)comparar_aristas); //heapify del arreglo de aristas
    Arista *T = malloc((g->n - 1) * sizeof(Arista)); //árbol cobertor mínimo
    int contador = 0; //contador de aristas de árbol T

    while (contador < g->n - 1) {
        Arista *arista = extractMin(E); //extraer la arista con menor peso
        //find de los nodos de la arista
        Nodo *x = find_normal(arista->nodo1);
        Nodo *y = find_normal(arista->nodo2);
        if (x != y) { 
            T[contador] = *arista; //añadir arista al árbol T
            contador++;
            union_(x, y); //hacer union de los nodos representantes
        }
    }
    free(E);
    return T;
}


// (3) Con optimización de find y usando arreglo de aristas
Arista *kruskal_3(Grafo* g) {
    Arista **E = g->aristas;
    qsort(E, g->e, sizeof(Arista*), comparar_aristas_ptr); //ordenar aristas con quicksort
    Arista *T = malloc((g->n - 1) * sizeof(Arista)); //árbol cobertor mínimo
    int contador = 0; //contador de aristas de árbol T
    int i = 0;
    
    while (i < g->e && contador < g->n - 1) {
        Arista *arista = E[i];
        //find optimizado de los nodos de la arista
        Nodo *x = find_opti(arista->nodo1);
        Nodo *y = find_opti(arista->nodo2);
        if (x != y) { 
            T[contador] = *arista; //añadir arista al árbol T
            contador++;
            union_(x, y); //hacer union de los nodos representantes
        }
    }
    return T;
}

// (4) Con optimización de find y usando heap
Arista *kruskal_4(Grafo* g) {
    Heap *E = heapifyArray((void**)g->aristas, g->e, (Comparator)comparar_aristas); //heapify del arreglo de aristas
    Arista *T = malloc((g->n - 1) * sizeof(Arista)); //árbol cobertor mínimo
    int contador = 0; //contador de aristas de arbol T

    while (contador < g->n - 1) {
        Arista *arista = extractMin(E); //extraer la arista con menor peso
        //find optimizado de los nodos de la arista
        Nodo *x = find_opti(arista->nodo1);
        Nodo *y = find_opti(arista->nodo2);
        if (x != y) { 
            T[contador] = *arista; //añadir arista al árbol T
            contador++;
            union_(x, y); //hacer union de los nodos representantes
        }
    }
    free(E);
    return T;
}