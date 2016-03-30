/*
########################################################
###       @Copyright Moreno Vera, Felipe Adrian      ###
###        Graph implementation                      ###
########################################################
*/

/*

  Graph funcionts pfor a set of point nulls

*/

#ifndef __GRAPH__H
  #define __GRAPH__H
#endif

#define GRAPH_NODE int

// Reserva memoria para la matriz de aristas
extern int** Create_edgesMatrix(int);

// Reserva memoria para la matriz de adjacencia
extern int** Create_adjMatrix(int);

// crea la matriz de adjacencia de un grafo
extern void Create_graph(int**,int**);

// Crea la matriz de adjacencia de un grafo dirigido
extern void Create_directedGraph(int**,int**);

// algoritmo de arbol generador minimo
extern void prim(int*,int*,int**,int**,int,int);

// distancias minimo de un vertice a otro
extern void floydWarshall(int**,int);

// Camino mas corto de grafos dirigidos
// con pesos negativos
extern void bellmanFord(int**,int);

// Camino mas corto de grafos dirigidos
// con pesos NO negativos
extern void dijkstra();

// funcion Main de grafos
extern int mainGraph(void);
