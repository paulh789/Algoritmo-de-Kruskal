#include "tarea2.h"

int main() {
    // Crear nodos
    Nodo_g* n1 = crear_nodo(0, 0);
    Nodo_g* n2 = crear_nodo(1, 5);
    Nodo_g* n3 = crear_nodo(6, 24);
    Nodo_g* n4 = crear_nodo(6, 2);

    // Crear aristas con distintos pesos
    Arista* a1 = crear_arista(n1, n2);
    Arista* a2 = crear_arista(n2, n3);
    Arista* a3 = crear_arista(n3, n4);
    Arista* a4 = crear_arista(n1, n4);

    Arista* aristas[]= {a1, a2, a3, a4};
    int e = sizeof(aristas) / sizeof(aristas[0]);

    Heap* heap = heapifyFromArray((void**)aristas, e, (Comparator)comparar_aristas_directo);

    // Extraer en orden e imprimir pesos
    printf("Extrayendo aristas ordenadas por peso:\n");
    Arista* actual;
    while ((actual = (Arista*)extractMin(heap)) != NULL) {
        printf("Peso: %.2f\n", actual->peso);
    }

    // Liberar memoria
    free(n1); free(n2); free(n3); free(n4);
    free(a1); free(a2); free(a3); free(a4);

    return 0;
}

