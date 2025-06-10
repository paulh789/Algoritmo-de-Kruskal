#include "tarea2.h"

void merge(Arista **arr, Arista **aux, int inicio, int medio, int fin) {
    int i = inicio;
    int j = medio + 1;
    int k = inicio;
    while (i <= medio && j <= fin) {
        if (arr[i]->peso <= arr[j]->peso) {
            aux[k++] = arr[i++];
        } else {
            aux[k++] = arr[j++];
        }
    }
    while (i <= medio) {
        aux[k++] = arr[i++];
    }
    while (j <= fin) {
        aux[k++] = arr[j++];
    }
    for (int l = inicio; l <= fin; l++) {
        arr[l] = aux[l];
    }
}


void mergesort_RAM(Arista **arreglo, Arista **aux, int inicio, int fin) {
    if (inicio >= fin) return;
    int medio = (inicio + fin) / 2;
    mergesort_RAM(arreglo, aux, inicio, medio);
    mergesort_RAM(arreglo, aux, medio + 1, fin);
    merge(arreglo, aux, inicio, medio, fin);
}