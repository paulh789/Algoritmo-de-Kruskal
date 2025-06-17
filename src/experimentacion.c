#include "tarea2.h"

Punto **generar_puntos(int N) {
    Punto **puntos = malloc(N * sizeof(Punto*));
    for (int i = 0; i < N; i++) {
        puntos[i] = malloc(sizeof(Punto));
        puntos[i]->x = (double)rand()/ RAND_MAX;
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
    printf("================================\n");
    printf("Experimentacion Algoritmo de Kruskal\n");
    printf("================================\n");
    FILE *archivo = fopen("tiempos_kruskal.csv", "w");
    if (!archivo) {
        perror("No se pudo crear el archivo");
        return 1;
    }

    fprintf(archivo, "Algoritmo,i,N,Tiempo\n");

    clock_t inicio, fin;
    int tiempo;
    int N;
    Punto **puntos;
    Grafo *g;
    Arista *T; //árbol cobertor mínimo del grafo g

    for (int i = 5; i <= 12; i++) {
        printf("================================\n");
        printf("Probando con i = %d...\n", i);
        N = pow(2, i);
        for (int j = 1; j <= 5; j++) {
            printf("================================\n");
            printf("Secuencia %d de 5...\n", j);
            srand(time(NULL) + j*i); //semilla distinta en cada iteración
            puntos = generar_puntos(N);

            // Kruskal 1
            g = crear_grafo(puntos, N);
            inicio = clock();
            T = kruskal_1(g);
            fin = clock();
            tiempo = 1000*(fin - inicio) / CLOCKS_PER_SEC;
            printf("Kruskal 1 con %d puntos: %d ms\n", N, tiempo);
            fprintf(archivo, "Kruskal_1,%d,%d,%d\n", i, N, tiempo);
            free(T);
            destruirGrafo(g);

            // Kruskal 2
            g = crear_grafo(puntos, N);
            inicio = clock();
            T = kruskal_2(g);
            fin = clock();
            tiempo = 1000*(fin - inicio) / CLOCKS_PER_SEC;
            printf("Kruskal 2 con %d puntos: %d ms\n", N, tiempo);
            fprintf(archivo, "Kruskal_2,%d,%d,%d\n", i, N, tiempo);
            free(T);
            destruirGrafo(g);

            // Kruskal 3
            g = crear_grafo(puntos, N);
            inicio = clock();
            T = kruskal_3(g);
            fin = clock();
            tiempo = 1000*(fin - inicio) / CLOCKS_PER_SEC;
            printf("Kruskal 3 con %d puntos: %d ms\n", N, tiempo);
            fprintf(archivo, "Kruskal_3,%d,%d,%d\n", i, N, tiempo);
            free(T);
            destruirGrafo(g);

            // Kruskal 4
            g = crear_grafo(puntos, N);
            inicio = clock();
            T = kruskal_4(g);
            fin = clock();
            tiempo = 1000*(fin - inicio) / CLOCKS_PER_SEC;
            printf("Kruskal 4 con %d puntos: %d ms\n", N, tiempo);
            fprintf(archivo, "Kruskal_4,%d,%d,%d\n", i, N, tiempo);
            free(T);
            destruirGrafo(g);

            destruir_puntos(puntos, N);
        }
        printf("================================\n");
    }
    printf("================================\n");
    fclose(archivo);
    printf("Resultados guardados en tiempos_kruskal.csv\n");
    return 0;
}
