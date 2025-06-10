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
typedef int (*PriComparator)(void*, void*);
typedef struct priqueue PriQueue;
PriQueue makePriQueue(void);
double priBest(PriQueue* q);
void* priPeek(PriQueue* q);
void* priGet(PriQueue* q);
void priPut(PriQueue* q, void* elem, double pri);
int priDel(PriQueue* q, void* elem);

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
Grafo* crear_grafo(int n, int e, double* nodos, double* aristas);
double calcular_peso(Nodo_g* n1, Nodo_g* n2);

//mergesort.c
void merge(Arista* arr, Arista* aux, int inicio, int medio, int fin);
void mergesort_RAM(Arista* arreglo, Arista* aux, int inicio, int fin);

//union_find.c
typedef struct nodo_uf {
    Nodo_g *info;
    //struct Nodo_uf** hijos;
    //int num_hijos;
    Nodo_uf *padre;
    int size;
} Nodo_uf;


#endif // TAREA2_H