#include "tarea2.h"

int main() {

    printf("================================\n");
    printf("Prueba sort y heap\n");
    //crear puntos
    Punto p1 = {0, 0};
    Punto p2 = {1, 5};
    Punto p3 = {3, 4};
    Punto p4 = {2, 3};

    Punto *puntos[] = {&p1, &p2, &p3, &p4};
    
    Grafo *g1 = crear_grafo(puntos, 4);

    //sort
    Arista **copia_aristas1 = malloc(g1->e * sizeof(Arista*));
    memcpy(copia_aristas1, g1->aristas, g1->e * sizeof(Arista*)); //copiar las aristas
    printf("Aristas desordenadas:\n");
    for (int i=0; i<g1->e; i++) {
        printf("Peso: %.2f\n", g1->aristas[i]->peso);
    }
    qsort(copia_aristas1, g1->e, sizeof(Arista*), comparar_aristas_ptr);
    printf("Aristas ordenadas por sort:\n");
    for (int i=0; i<g1->e; i++) {
        printf("Peso: %.2f\n", copia_aristas1[i]->peso);
    }
    
    // heap
    Arista **copia_aristas2 = malloc(g1->e * sizeof(Arista*));
    memcpy(copia_aristas2, g1->aristas, g1->e * sizeof(Arista*)); //copiar las aristas
    printf("Aristas desordenadas:\n");
    for (int i=0; i<g1->e; i++) {
        printf("Peso: %.2f\n", g1->aristas[i]->peso);
    }
    Heap* heap = heapifyArray((void**)copia_aristas2, g1->e, (Comparator)comparar_aristas);
    printf("Extrayendo aristas ordenadas por heap:\n");
    Arista* actual;
    while ((actual = (Arista*)extractMin(heap)) != NULL) {
        printf("Peso: %.2f\n", actual->peso);
    }

    destruirGrafo(g1);
    free(copia_aristas1);
    free(copia_aristas2);


    printf("================================\n");
    printf("Prueba arbol cobertor minimo\n");

    Punto A = {0, 0};
    Punto B = {1, 0};
    Punto C = {0, 2};
    Punto D = {1, 1};
    Punto E = {2, 0};
    Punto *puntos2[] = {&A, &B, &C, &D, &E};

    Grafo *g2;
    Arista *T;    

    g2 = crear_grafo(puntos2, 5);
    printf("Probando con un grafo completo de 5 nodos:\n");
    for (int i=0; i<5; i++) {
        printf("(%.0f, %.0f)", g2->nodos[i]->x, g2->nodos[i]->y);
        if (i < 4) {
            printf(", ");
        }
        else {
            printf("\n");
        }
    }
    printf("Arista [peso]\n");
    for (int i=0; i<g2->e; i++) {
        printf("(%.0f, %.0f)-(%.0f, %.0f) [%.0f]\n", g2->aristas[i]->nodo1->x, g2->aristas[i]->nodo1->y, g2->aristas[i]->nodo2->x, g2->aristas[i]->nodo2->y, g2->aristas[i]->peso);
    }
    printf(" \n");

    // Kruskal 1
    T = kruskal_1(g2);
    printf("Resultado Kruskal 1\n");
    for (int i=0; i<4; i++) {
        printf("Arista %d: (%.0f, %.0f)-(%.0f, %.0f)\n", i+1, T[i].nodo1->x, T[i].nodo1->y, T[i].nodo2->x, T[i].nodo2->y);
    }
    free(g2);
    free(T);
    printf(" \n");

    // Kruskal 2
    g2 = crear_grafo(puntos2, 5);
    T = kruskal_2(g2);
    printf("Resultado Kruskal 2\n");
    for (int i=0; i<4; i++) {
        printf("Arista %d: (%.0f, %.0f)-(%.0f, %.0f)\n", i+1, T[i].nodo1->x, T[i].nodo1->y, T[i].nodo2->x, T[i].nodo2->y);
    }
    free(g2);
    free(T);
    printf(" \n");

    // Kruskal 3
    g2 = crear_grafo(puntos2, 5);
    T = kruskal_3(g2);
    printf("Resultado Kruskal 3\n");
    for (int i=0; i<4; i++) {
        printf("Arista %d: (%.0f, %.0f)-(%.0f, %.0f)\n", i+1, T[i].nodo1->x, T[i].nodo1->y, T[i].nodo2->x, T[i].nodo2->y);
    }
    free(g2);
    free(T);
    printf(" \n");

    // Kruskal 4
    g2 = crear_grafo(puntos2, 5);
    T = kruskal_4(g2);
    printf("Resultado Kruskal 4\n");
    for (int i=0; i<4; i++) {
        printf("Arista %d: (%.0f, %.0f)-(%.0f, %.0f)\n", i+1, T[i].nodo1->x, T[i].nodo1->y, T[i].nodo2->x, T[i].nodo2->y);
    }
    free(g2);
    free(T);

    return 0;
}

