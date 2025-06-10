#include "tarea2.h"

int comparar_aristas(const void* a, const void* b) {
    const Arista* aristaA = *(const Arista**)a;
    const Arista* aristaB = *(const Arista**)b;

    if (aristaA->peso < aristaB->peso) return -1;
    if (aristaA->peso > aristaB->peso) return 1;
    return 0;
}


int comparar_aristas_directo(void* a, void* b) {
    Arista* aristaA = (Arista*)a;
    Arista* aristaB = (Arista*)b;

    if (aristaA->peso < aristaB->peso) return -1;
    if (aristaA->peso > aristaB->peso) return 1;
    return 0;
}



void sort_aristas(Arista** aristas, int n) {
    qsort(aristas, n, sizeof(Arista*), comparar_aristas);
}


