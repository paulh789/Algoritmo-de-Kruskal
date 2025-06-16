#ifndef TAREA2_H
#define TAREA2_H

//Librerías
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Funciones

//==================
// sort.c
//==================

int comparar_aristas(void* a, void* b);
int comparar_aristas_ptr(const void* a, const void* b);

//==================
// heap.c
//==================
// Adaptado de https://www.geeksforgeeks.org/c/heap-in-c/

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
Heap* heapifyArray(void** elems, int n, Comparator cmp);
 

//==================
// grafo.c
//==================

typedef struct punto {
    double x;
    double y;
} Punto;

typedef struct nodo {
    double x;
    double y;
    struct Nodo *padre;
    int size;
} Nodo;

typedef struct arista {
    Nodo *nodo1;
    Nodo *nodo2;
    double peso;
} Arista;

typedef struct grafo {
    int n ; //Número de nodos
    Nodo **nodos;
    int e; //Número de aristas
    Arista **aristas;
} Grafo;

double calcular_peso(Nodo* n1, Nodo* n2);
Nodo* crear_nodo(double x, double y);
Arista* crear_arista(Nodo* n1, Nodo* n2);
Grafo* crear_grafo(Punto **puntos, int n);
void destruirGrafo(Grafo *g);

//==================
// union_find.c
//==================

void union_(Nodo *x, Nodo *y);
Nodo *find_normal(Nodo *x);
Nodo *find_opti(Nodo *x);


//==================
// kruskal.c
//==================

//(1) Sin optimización de find y usando arreglo de aristas
Arista *kruskal_1(Grafo* g);

//(2) Sin optimización de find y usando heap
Arista *kruskal_2(Grafo* g);

//(3) Con optimización de find y usando arreglo de aristas
Arista *kruskal_3(Grafo* g);

//(4) Con optimización de find y usando heap
Arista *kruskal_4(Grafo* g);

#endif // TAREA2_H