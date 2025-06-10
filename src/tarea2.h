#ifndef TAREA2_H
#define TAREA2_H

//Librerías
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

//Funciones

//heap.c
typedef int (*Comparator)(void*, void*);
typedef struct Heap {
    void** array;
    int size;
    int capacity;
    Comparator cmp;
} Heap;

Heap* createHeap(int capacity, Comparator cmp);
void swap(void** a, void** b) ;
void heapify(Heap* heap, int i);
void insertHeap(Heap* heap, void* value);
void* extractMin(Heap* heap);
void freeHeap(Heap* heap);
void buildHeap(Heap* heap);
Heap* heapifyFromArray(void** elems, int n, Comparator cmp);
 

//grafo.c
typedef struct nodo_g{
    double x;
    double y;
} Nodo_g;

typedef struct arista{
    Nodo_g *nodo1;
    Nodo_g *nodo2;
    double peso;
    //(nodo1->x-nodo2->x)*(nodo1->x-nodo2->x) + (nodo1->y+nodo2->y)*(nodo1->y-nodo2->y)
} Arista;

typedef struct grafo{
    int n ; // Número de nodos
    Nodo_g **nodos;
    int e; // Número de aristas
    Arista **aristas;
} Grafo;

typedef struct grafo Grafo; 
Grafo* crear_grafo(int n, int e, Nodo_g** nodos, Arista** aristas);
double calcular_peso(Nodo_g* n1, Nodo_g* n2);
Nodo_g* crear_nodo(double x, double y);
Arista* crear_arista(Nodo_g* n1, Nodo_g* n2);

//mergesort.c
void merge(Arista** arr, Arista** aux, int inicio, int medio, int fin);
void mergesort_RAM(Arista** arreglo, Arista** aux, int inicio, int fin);

//union_find.c
typedef struct nodo_uf {
    Nodo_g *info;
    //struct Nodo_uf** hijos;
    //int num_hijos;
    struct Nodo_uf *padre;
    int size;
} Nodo_uf;

//sort.c
int comparar_aristas(const void* a, const void* b);
void sort_aristas(Arista** aristas, int n);
int comparar_aristas_directo(void* a, void* b);


#endif // TAREA2_H