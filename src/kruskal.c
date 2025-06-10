#include "tarea2.h"

// (1) Sin optimización de find y usando arreglo de aristas
Arista *kruskal_1(Grafo* g) {
    Nodo_uf **nodos_uf = crear_uf(g->nodos, g->n); // Crear estructura de unión-find
    Arista **E = g->aristas;
    sort_aristas(E,g->e);
    Arista *T= malloc((g->n - 1)* sizeof(Arista)); // Árbol de expansión mínima
    int contador = 0;// contador de aristas de arbol T
    
    while (contador < g->n - 1) {
        for (int i = 0; i < g->e; i++) {
            Arista *a = E[i];
            Nodo_uf *u;
            Nodo_uf *v;
            for(int j = 0; j<g->n; j++){
                if(nodos_uf[j]->info == a->nodo1){
                    u= nodos_uf[j];
                }
                if(nodos_uf[j]->info == a->nodo2){
                    v = nodos_uf[j];
                }
            }
            Nodo_g *x=find_normal(u);
            Nodo_g *y=find_normal(v);
            if (x!=y){ 
                T[contador] = *a; // Añadir arista al árbol T
                contador++;
                union_uf(x, y); // Unir los nodos
            }
        }
    }
    return T;
}

// (2) Sin optimización de find y usando heap
Arista *kruskal_2(Grafo* g) {
    Nodo_uf **nodos_uf = crear_uf(g->nodos, g->n); // Crear estructura de unión-find
    Heap **E = heapifyFromArray(g->aristas, g->e, comparar_aristas_directo);
    Arista *T= malloc((g->n - 1)* sizeof(Arista)); // Árbol de expansión mínima
    int contador = 0;// contador de aristas de arbol T

    while (contador < g->n - 1) {
        Arista *a = extractMin(E); // Extraer la arista con menor peso
        Nodo_uf *u;
        Nodo_uf *v;
        for(int j = 0; j<g->n; j++){
            if(nodos_uf[j]->info == a->nodo1){
                u= nodos_uf[j];
            }
            if(nodos_uf[j]->info == a->nodo2){
                v = nodos_uf[j];
            }
        }
        Nodo_g *x=find_normal(u);
        Nodo_g *y=find_normal(v);
        if (x!=y){ 
            T[contador] = *a; // Añadir arista al árbol T
            contador++;
            union_uf(x, y); // Unir los nodos
        }
        
    }
    return T;

}


// (3) Con optimización de find y usando arreglo de aristas
Arista *kruskal_3(Grafo* g) {
    Nodo_uf **nodos_uf = crear_uf(g->nodos, g->n); // Crear estructura de unión-find
    Arista **E = g->aristas;
    sort_aristas(E,g->e);
    Arista *T= malloc((g->n - 1)* sizeof(Arista)); // Árbol de expansión mínima
    int contador = 0;// contador de aristas de arbol T
    
    while (contador < g->n - 1) {
        for (int i = 0; i < g->e; i++) {
            Arista *a = E[i];
            Nodo_uf *u;
            Nodo_uf *v;
            for(int j = 0; j<g->n; j++){
                if(nodos_uf[j]->info == a->nodo1){
                    u= nodos_uf[j];
                }
                if(nodos_uf[j]->info == a->nodo2){
                    v = nodos_uf[j];
                }
            }
            Nodo_g *x=find_opti(u);
            Nodo_g *y=find_opti(v);
            if (x!=y){ 
                T[contador] = *a; // Añadir arista al árbol T
                contador++;
                union_uf(x, y); // Unir los nodos
            }
        }
    }
    return T;
}

// (4) Con optimización de find y usando heap
Arista *kruskal_4(Grafo* g) {
    Nodo_uf **nodos_uf = crear_uf(g->nodos, g->n); // Crear estructura de unión-find
    Heap **E = heapifyFromArray(g->aristas, g->e, comparar_aristas_directo);
    Arista *T= malloc((g->n - 1)* sizeof(Arista)); // Árbol de expansión mínima
    int contador = 0;// contador de aristas de arbol T

    while (contador < g->n - 1) {
        Arista *a = extractMin(E); // Extraer la arista con menor peso
        Nodo_uf *u;
        Nodo_uf *v;
        for(int j = 0; j<g->n; j++){
            if(nodos_uf[j]->info == a->nodo1){
                u= nodos_uf[j];
            }
            if(nodos_uf[j]->info == a->nodo2){
                v = nodos_uf[j];
            }
        }
        Nodo_g *x=find_opti(u);
        Nodo_g *y=find_opti(v);
        if (x!=y){ 
            T[contador] = *a; // Añadir arista al árbol T
            contador++;
            union_uf(x, y); // Unir los nodos
        }
        
    }
    return T;

}