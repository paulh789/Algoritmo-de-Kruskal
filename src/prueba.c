#include "tarea2.h"

int main() {
    //crear puntos
    Punto p1 = {0, 0};
    Punto p2 = {1, 5};
    Punto p3 = {3, 4};
    Punto p4 = {2, 3};

    Punto *puntos[] = {&p1, &p2, &p3, &p4};
    
    Grafo *g1 = crear_grafo(puntos, 4);

    printf("Aristas desordenadas:\n");
    for (int i=0; i<g1->e; i++) {
        printf("Peso: %.2f\n", g1->aristas[i]->peso);
    }

    qsort(g1->aristas, g1->e, sizeof(Arista*), comparar_aristas_ptr);
    printf("Aristas ordenadas por sort:\n");
    for (int i=0; i<g1->e; i++) {
        printf("Peso: %.2f\n", g1->aristas[i]->peso);
    }

    Grafo *g2 = crear_grafo(puntos, 4);

    printf("Aristas desordenadas:\n");
    for (int i=0; i<g2->e; i++) {
        printf("Peso: %.2f\n", g2->aristas[i]->peso);
    }

    Heap* heap = heapifyArray((void**)g2->aristas, g2->e, (Comparator)comparar_aristas);
    printf("Extrayendo aristas ordenadas por heap:\n");
    Arista* actual;
    while ((actual = (Arista*)extractMin(heap)) != NULL) {
        printf("Peso: %.2f\n", actual->peso);
    }

    //liberar memoria
    destruirGrafo(g1);
    destruirGrafo(g2);

    return 0;
}

