#include "tarea2.h"


Punto ** generar_puntos(int n) {
    Punto **puntos = malloc(n * sizeof(Punto*));
    for (int i = 0; i < n; i++) {
        puntos[i] = malloc(sizeof(Punto));
        puntos[i]->x = (double)rand()/ RAND_MAX; // Genera coordenadas aleatorias
        puntos[i]->y = (double)rand()/ RAND_MAX;
    }
    return puntos;
}

void destruir_puntos(Punto **puntos, int n) {
    for (int i = 0; i < n; i++) {
        free(puntos[i]);
    }
    free(puntos);
}

int main() {
    FILE *archivo = fopen("tiempos_kruskal.csv", "w");
    if (!archivo) {
        perror("No se pudo crear el archivo");
        return 1;
    }

    // Encabezado CSV
    fprintf(archivo, "Algoritmo,N_puntos,Tiempo_segundos\n");

    time_t inicio, fin;
    int tiempo;
    int N;
    Grafo *g;
    Arista *T;
    for (int i = 5; i < 13; i++) {
        N = pow(2, i);
        for (int j = 0; j < 5; j++) {
            srand((unsigned int)time(NULL) + j); // semilla un poco distinta en cada iteración
            Punto **puntos = generar_puntos(N);
            
            g = crear_grafo(puntos, N);

            // Kruskal 1
            time(&inicio);
            T =kruskal_1(g);
            time(&fin);
            free(T);
            tiempo = difftime(fin, inicio);
            printf("Kruskal 1 con %d puntos: %d segundos\n", N, tiempo);
            fprintf(archivo, "Kruskal_1,%d,%d\n", N, tiempo);
            destruirGrafo(g);

            
            g = crear_grafo(puntos, N);
            // Kruskal 2
            time(&inicio);
            T =kruskal_2(g);
            time(&fin);
            free(T);
            tiempo = difftime(fin, inicio);
            printf("Kruskal 2 con %d puntos: %d segundos\n", N, tiempo);
            fprintf(archivo, "Kruskal_2,%d,%d\n", N, tiempo);
            destruirGrafo(g);

            
            g = crear_grafo(puntos, N);
            // Kruskal 3
            time(&inicio);
            T =kruskal_3(g);
            time(&fin);
            free(T);
            tiempo = difftime(fin, inicio);
            printf("Kruskal 3 con %d puntos: %d segundos\n", N, tiempo);
            fprintf(archivo, "Kruskal_3,%d,%d\n", N, tiempo);
            destruirGrafo(g);

            
            g = crear_grafo(puntos, N);
            // Kruskal 4
            time(&inicio);
            T =kruskal_4(g);
            time(&fin);
            free(T);
            tiempo = difftime(fin, inicio);
            printf("Kruskal 4 con %d puntos: %d segundos\n", N, tiempo);
            fprintf(archivo, "Kruskal_4,%d,%d\n", N, tiempo);
            destruirGrafo(g);

            destruir_puntos(puntos, N);
        }
    }

    fclose(archivo);
    printf("Resultados guardados en tiempos_kruskal.csv\n");
    return 0;
}
