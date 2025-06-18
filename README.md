# Algoritmo-de-Kruskal
Tarea 2 del ramo CC4102 - Diseño y Análisis de Algoritmos

## Contenido
Para esta tarea, la organización del trabajo sigue el siguiente formato:

- `src/`: Código fuente
  - `tarea2.h`: librerías, estructuras y encabezados de funciones.
  - `grafo.c`: funciones para crear y destruir intancias de grafos.
  - `sort.c`: funciones para comparar aristas en estructuras de datos.
  - `heap.c`: implementación de estructura Min-Heap genérica.
  - `union_find.c`: implementación de estructura Union-Find con y sin optimización de find.
  - `kruskal.c`: implementación de las cuatro variantes del algoritmo de kruskal.
  - `prueba.c`: código para probar el funcionamiento correcto del sort y heap genéricos, y de las variantes del algoritmo.
  - `experimentacion.c`: código para comparar el tiempo de ejecución de las variantes del algoritmo para distintos inputs de diferentes tamaños. 


- `bin/`: Archivos ejecutables
  - `prueba`: ejecutable para verificar el correcto funcionamiento de sort, heap y las variantes del algoritmo de Kruskal.
  - `experimentacion`: ejecutable para comparar el rendimiento de las variantes en función del tamaño del input. 


## Instrucciones para correr el código
### Compilación
Para compilar los ejecutables se deben correr los siguientes comandos:
- prueba
  ```bash
  gcc src/grafo.c src/sort.c src/heap.c src/union_find.c src/kruskal.c src/prueba.c -o bin/prueba
  ```
- experimentacion:
  ```bash
  gcc src/grafo.c src/sort.c src/heap.c src/union_find.c src/kruskal.c src/experimentacion.c -o bin/experimentacion
  ```

### Uso
Para correr cada programa se deben correr los siguientes comandos:
- prueba:
  ```bash
  ./bin/prueba
  ```
- experimentacion:
  ```bash
  ./bin/experimentacion
  ```
