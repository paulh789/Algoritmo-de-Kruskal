#ifndef TAREA2_H
#define TAREA2_H

//Librerías
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

//Funciones

//==================
// sort.c
//==================
/**
 * @brief Compara dos aristas según su peso para ordenación.
 * 
 * Esta función compara dos punteros a Arista y devuelve un valor
 * negativo, cero o positivo según el peso de la primera arista sea menor,
 * igual o mayor que el de la segunda.
 * 
 * @param a: puntero a la primera arista (void*).
 * @param b: puntero a la segunda arista (void*).
 * @return int: -1 si a < b, 1 si a > b, 0 si son iguales.
 */

int comparar_aristas(void* a, void* b);
/**
 * @brief Compara dos punteros a aristas según su peso para ordenación.
 * 
 * Esta función compara dos punteros a punteros de Arista (const void*),
 * usada típicamente con funciones estándar como qsort para ordenar arreglos
 * de punteros a Arista.
 * 
 * @param a: puntero a puntero a Arista (const void*).
 * @param b: puntero a puntero a Arista (const void*).
 * @return int: -1 si *a < *b, 1 si *a > *b, 0 si son iguales.
 */
int comparar_aristas_ptr(const void* a, const void* b);

//==================
// heap.c
//==================

// Adaptado de https://www.geeksforgeeks.org/c/heap-in-c/
/**
 * @typedef Comparator
 * @brief Puntero a función para comparar dos elementos genéricos.
 *
 * Esta función debe retornar un valor negativo si el primer elemento es menor,
 * cero si son iguales, y un valor positivo si el primero es mayor.
 *
 * @param a Puntero al primer elemento a comparar.
 * @param b Puntero al segundo elemento a comparar.
 * @return int Resultado de la comparación (<0, 0, >0).
 */
typedef int (*Comparator)(void*, void*);

/**
 * @struct Heap
 * @brief Estructura que representa un heap genérico.
 *
 * El heap almacena punteros genéricos a elementos y mantiene su tamaño,
 * capacidad máxima y la función de comparación para mantener la propiedad del heap.
 */
typedef struct Heap {
    void** array;
    int size;
    int capacity;
    Comparator cmp;
} Heap;

/**
 * @brief Crea un nuevo heap con una capacidad y función de comparación dadas.
 *
 * Reserva memoria para el heap y su arreglo interno, inicializando su tamaño a 0.
 *
 * @param capacity Capacidad máxima del heap.
 * @param cmp Función de comparación para mantener la propiedad del heap.
 * @return Heap* Puntero al heap creado (memoria asignada dinámicamente).
 */
Heap* createHeap(int capacity, Comparator cmp);

/**
 * @brief Intercambia dos punteros en el arreglo del heap.
 *
 * @param a Puntero al primer puntero a intercambiar.
 * @param b Puntero al segundo puntero a intercambiar.
 */
void swap(void** a, void** b) ;

/**
 * @brief Reestablece la propiedad de min-heap en el índice dado.
 *
 * Compara el nodo en índice i con sus hijos y, si es necesario, intercambia con el menor hijo
 * y continúa el proceso recursivamente.
 *
 * @param heap Puntero al heap.
 * @param i Índice en el arreglo donde se reestablecerá la propiedad.
 */
void heapify(Heap* heap, int i);

/**
 * @brief Inserta un nuevo elemento en el heap.
 *
 * Inserta el elemento al final y ajusta hacia arriba para mantener la propiedad de min-heap.
 * Si el heap está lleno, imprime un mensaje de error y no inserta.
 *
 * @param heap Puntero al heap.
 * @param value Puntero al elemento a insertar.
 */
void insertHeap(Heap* heap, void* value);

/**
 * @brief Extrae el elemento mínimo (raíz) del heap.
 *
 * Reemplaza la raíz con el último elemento, reduce el tamaño y reestablece la propiedad de heap.
 *
 * @param heap Puntero al heap.
 * @return void* Puntero al elemento mínimo extraído, o NULL si el heap está vacío.
 */
void* extractMin(Heap* heap);

/**
 * @brief Libera la memoria usada por el heap.
 *
 * Libera el arreglo interno y la estructura heap.
 *
 * @param heap Puntero al heap a liberar.
 */
void freeHeap(Heap* heap);

/**
 * @brief Construye un heap válido a partir del arreglo actual.
 *
 * Aplica heapify en los nodos internos desde la mitad hacia la raíz.
 *
 * @param heap Puntero al heap.
 */
void buildHeap(Heap* heap);

/**
 * @brief Crea un heap a partir de un arreglo dado, aplicando buildHeap.
 *
 * Usa el arreglo proporcionado (no lo copia) y crea una estructura heap que lo administre.
 *
 * @param elems Arreglo de punteros a elementos.
 * @param n Número de elementos en el arreglo.
 * @param cmp Función de comparación para el heap.
 * @return Heap* Puntero al heap creado.
 */
Heap* heapifyArray(void** elems, int n, Comparator cmp);


//==================
// grafo.c
//==================

/**
 * @struct Punto
 * @brief Representa un punto en el plano 2D.
 *
 * Contiene las coordenadas x e y del punto.
 */
typedef struct punto {
    double x;
    double y;
} Punto;


/**
 * @struct Nodo
 * @brief Representa un nodo para el algoritmo de Kruskal.
 *
 * Contiene coordenadas x e y, un puntero al padre para la estructura de conjuntos disjuntos,
 * y un entero size que representa el tamaño del conjunto.
 */
typedef struct nodo {
    double x;
    double y;
    struct nodo *padre;
    int size;
} Nodo;

/**
 * @struct Arista
 * @brief Representa una arista entre dos nodos en el grafo.
 *
 * Contiene punteros a los dos nodos que conecta y el peso de la arista.
 */
typedef struct arista {
    Nodo *nodo1;
    Nodo *nodo2;
    double peso;
} Arista;

/**
 * @struct Grafo
 * @brief Representa al grafo que recibe kruskal.
 *
 * Contiene el número de nodos y aristas, así como arreglos de punteros a nodos y aristas.
 */
typedef struct grafo {
    int n ; //Número de nodos
    Nodo **nodos;
    int e; //Número de aristas
    Arista **aristas;
} Grafo;

/**
 * @brief Calcula el peso (distancia al cuadrado) entre dos nodos.
 *
 * Esta función retorna el peso de la arista entre dos nodos, que es la
 * distancia euclidiana al cuadrado entre sus coordenadas.
 *
 * @param n1 Puntero al primer nodo.
 * @param n2 Puntero al segundo nodo.
 * @return double Peso (distancia al cuadrado) entre n1 y n2.
 */
double calcular_peso(Nodo* n1, Nodo* n2);

/**
 * @brief Crea un nuevo nodo con coordenadas dadas.
 *
 * Esta función reserva memoria para un nodo, inicializa sus coordenadas
 * con los valores dados, y establece padre en NULL y size en 1.
 *
 * @param x Coordenada x del nodo.
 * @param y Coordenada y del nodo.
 * @return Nodo* Puntero al nodo creado (reservado con malloc).
 * @throws Termina el programa si no puede asignar memoria.
 */
Nodo* crear_nodo(double x, double y);

/**
 * @brief Crea una nueva arista entre dos nodos.
 *
 * Esta función reserva memoria para una arista y la inicializa con los nodos
 * dados y el peso calculado con `calcular_peso`.
 *
 * @param n1 Puntero al primer nodo.
 * @param n2 Puntero al segundo nodo.
 * @return Arista* Puntero a la arista creada (reservada con malloc).
 * @throw Termina el programa si no puede asignar memoria.
 */
Arista* crear_arista(Nodo* n1, Nodo* n2);

/**
 * @brief Crea un grafo completo a partir de un arreglo de puntos.
 *
 * Esta función crea un grafo completo con `n` nodos, donde cada nodo corresponde
 * a un punto dado y cada par de nodos está conectado con una arista cuyo peso
 * es la distancia al cuadrado entre ellos.
 *
 * @param puntos Arreglo de punteros a puntos.
 * @param n Cantidad de puntos (y nodos).
 * @return Grafo* Puntero al grafo creado (reservado con malloc).
 * @throw Termina el programa si no puede asignar memoria.
 */
Grafo* crear_grafo(Punto **puntos, int n);


/**
 * @brief Libera la memoria asociada a un grafo.
 *
 * Esta función libera toda la memoria reservada para los nodos, aristas y el
 * propio grafo.
 *
 * @param g Puntero al grafo a destruir.
 */
void destruirGrafo(Grafo *g);

//==================
// union_find.c
//==================

/**
 * @brief Une dos conjuntos representados por nodos usando unión por tamaño.
 *
 * Esta función une los conjuntos que contienen a los nodos `x` y `y`.
 * El padre del conjunto más pequeño apunta al padre del conjunto más grande,
 * y se actualiza el tamaño del conjunto resultante.
 *
 * @param x Puntero al nodo representante del primer conjunto.
 * @param y Puntero al nodo representante del segundo conjunto.
 */
void union_(Nodo *x, Nodo *y);

/**
 * @brief Encuentra el representante del conjunto de un nodo.
 *
 * Esta función retorna el representante de la clase de equivalencia del conjunto al que pertenece
 * el nodo `x`, usando búsqueda recursiva sin optimización.
 *
 * @param x Puntero al nodo.
 * @return Nodo* Puntero al nodo representante del conjunto.
 */
Nodo *find_normal(Nodo *x);

/**
 * @brief Encuentra el representante del conjunto de un nodo con compresión de caminos.
 *
 * Esta función retorna el nodo raíz (representante) del conjunto al que pertenece
 * el nodo `x`, aplicando compresión de caminos para optimizar búsquedas futuras.
 *
 * @param x Puntero al nodo.
 * @return Nodo* Puntero al nodo representante del conjunto.
 */
Nodo *find_opti(Nodo *x);


//==================
// kruskal.c
//==================

//(1) Sin optimización de find y usando arreglo de aristas
/**
 * @brief Calcula el árbol de expansión mínima con Kruskal sin optimización y usando arreglo de aristas.
 *
 * Esta función copia las aristas del grafo, las ordena con qsort y aplica el algoritmo
 * de Kruskal sin optimización en la función find (búsqueda simple), usando un arreglo para las aristas.
 *
 * @param g Puntero al grafo.
 * @return Arista* Arreglo dinámico con las aristas del árbol de expansión mínima.
 *                 El tamaño del arreglo es (g->n - 1).
 */
Arista *kruskal_1(Grafo* g);

//(2) Sin optimización de find y usando heap
/**
 * @brief Calcula el árbol de expansión mínima con Kruskal sin optimización y usando heap.
 *
 * Esta función copia las aristas del grafo, construye un heap para obtener la arista mínima,
 * y aplica el algoritmo de Kruskal sin optimización en la función find (búsqueda simple).
 *
 * @param g Puntero al grafo.
 * @return Arista* Arreglo dinámico con las aristas del árbol de expansión mínima.
 *                 El tamaño del arreglo es (g->n - 1).
 */
Arista *kruskal_2(Grafo* g);

//(3) Con optimización de find y usando arreglo de aristas
/**
 * @brief Calcula el árbol de expansión mínima con Kruskal con optimización y usando arreglo de aristas.
 *
 * Esta función copia las aristas del grafo, las ordena con qsort y aplica el algoritmo
 * de Kruskal usando la versión optimizada de find (con compresión de caminos),
 * usando un arreglo para las aristas.
 *
 * @param g Puntero al grafo.
 * @return Arista* Arreglo dinámico con las aristas del árbol de expansión mínima.
 *                 El tamaño del arreglo es (g->n - 1).
 */
Arista *kruskal_3(Grafo* g);

//(4) Con optimización de find y usando heap
/**
 * @brief Calcula el árbol de expansión mínima con Kruskal con optimización y usando heap.
 *
 * Esta función copia las aristas del grafo, construye un heap para obtener la arista mínima,
 * y aplica el algoritmo de Kruskal usando la versión optimizada de find (con compresión de caminos).
 *
 * @param g Puntero al grafo.
 * @return Arista* Arreglo dinámico con las aristas del árbol de expansión mínima.
 *                 El tamaño del arreglo es (g->n - 1).
 */
Arista *kruskal_4(Grafo* g);

//==================
// experimentacion.c
//==================

/**
 * @brief Genera un arreglo de puntos aleatorios en el plano.
 *
 * Esta función genera un arreglo de `N` punteros a estructuras `Punto`,
 * donde cada punto tiene coordenadas `x` e `y` aleatorias en el intervalo [0, 1].
 *
 * @param N Número de puntos a generar.
 * @return Punto** Arreglo de punteros a estructuras `Punto`.
 * @note La memoria asignada debe ser liberada utilizando `destruir_puntos`.
 */
Punto **generar_puntos(int N);


/**
 * @brief Libera la memoria de un arreglo de puntos.
 *
 * Esta función libera la memoria utilizada por cada `Punto` en el arreglo
 * y luego libera el arreglo de punteros.
 *
 * @param puntos Arreglo de punteros a estructuras `Punto`.
 * @param n Número de puntos en el arreglo.
 */
void destruir_puntos(Punto **puntos, int n) ;


#endif // TAREA2_H
