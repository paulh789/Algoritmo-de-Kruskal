#include "tarea2.h"

// Crea un nuevo heap con capacidad y función de comparación
Heap* createHeap(int capacity, Comparator cmp) {
    Heap* heap = malloc(sizeof(Heap));
    heap->array = malloc(capacity * sizeof(void*));
    heap->size = 0;
    heap->capacity = capacity;
    heap->cmp = cmp;
    return heap;
}

// Intercambia dos elementos del arreglo
void swap(void** a, void** b) {
    void* temp = *a;
    *a = *b;
    *b = temp;
}

// Reestablece propiedad de minHeap en el índice dado
void heapify(Heap* heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->cmp(heap->array[left], heap->array[smallest]) < 0)
        smallest = left;

    if (right < heap->size && heap->cmp(heap->array[right], heap->array[smallest]) < 0)
        smallest = right;

    if (smallest != i) {
        swap(&heap->array[i], &heap->array[smallest]);
        heapify(heap, smallest);
    }
}

// Inserta un nuevo elemento al heap
void insertHeap(Heap* heap, void* value) {
    if (heap->size == heap->capacity) {
        printf("Heap overflow\n");
        return;
    }

    int i = heap->size++;
    heap->array[i] = value;

    // Corrige posición hacia arriba
    while (i != 0 && heap->cmp(heap->array[i], heap->array[(i - 1) / 2]) < 0) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Extrae el mínimo (raíz)
void* extractMin(Heap* heap) {
    if (heap->size <= 0)
        return NULL;
    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }

    void* root = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    heapify(heap, 0);
    return root;
}


// Libera el heap
void freeHeap(Heap* heap) {
    free(heap->array);
    free(heap);
}

// Construir heap
void buildHeap(Heap* heap) {
    for (int i = (heap->size - 1) / 2; i >= 0; i--) {
        heapify(heap, i);
    }
}

// Heapify
Heap* heapifyArray(void** elems, int n, Comparator cmp) {
    Heap* heap = malloc(sizeof(Heap));
    heap->array = elems;
    heap->size = n;
    heap->capacity = n;
    heap->cmp = cmp;

    buildHeap(heap);
    return heap;
}
