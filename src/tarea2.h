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
Grafo* crear_grafo(int n, int e, double* nodos, double* aristas);
double calcular_peso(Nodo* n1, Nodo* n2);


#endif // TAREA2_H