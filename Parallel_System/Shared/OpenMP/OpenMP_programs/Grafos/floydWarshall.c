#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//#include "graph.h"

void floydWarshall(){
  int numVertices; // numero de vertices del grafo
  int numEdges;   // numero de aristas del grafo
  int root = 0;   // vertice inicial
  int i,j,k;    // contadores
  int* key,* parent;
  int** adj,**edges;
  printf("Ingrese numero de vertices: ");
  scanf("%d", &numVertices);
  printf("Ingrese numero de aristas: ");
  scanf("%d", &numEdges);
  // valores de cada nodo del arbol generado, son los pesos
  key = (int *) malloc(sizeof(int)*numVertices);
  // padres, del arbol generado
  parent = (int *) malloc(sizeof(int)*numVertices);
  // aristas
  edges = (int **)malloc(sizeof(int*)*numEdges);
  // reservamos memoria para los caminos
  for(i = 0; i < numEdges; i++)
    edges[i] = (int *) malloc(sizeof(int)*3);
  // Reservamos memoria para la matriz de adjacencia
  adj = (int **) malloc(sizeof(int *)*numVertices);
  for(i = 0; i < numVertices; i++)
    adj[i] = (int *) malloc(sizeof(int)*numVertices);
  // Matriz de adjacencia
  // donde se considera INT_MAX camino infinito
  for(i = 0; i < numVertices; i++){
    for(j = 0; j < numVertices; j++){
      if(i == j)
        adj[i][j] = 0;
      else
        adj[i][j] = INT_MAX;
    }
  }
  // arista de vertice a vertice y con peso (grafo dirigido)
  printf("Ingrese las aristas y su peso (v1, v2, weight): \n");
  for(i = 0; i < numEdges; i++)
  {
    scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    adj[edges[i][0]][edges[i][1]] = edges[i][2];
    adj[edges[i][1]][edges[i][0]] = edges[i][2];
  }  
  // muestra la nueva matriz de adjacencia
  for(i = 0; i < numVertices; i++){
    for(j = 0; j < numVertices; j++){
      printf("%d ",adj[i][j]);
    }
    printf("\n");
  }
  for(k = 0; k < numVertices; k++){
    for(i = 0; i < numVertices; i++){
      for(j = 0; j < numVertices; j++){
        if(adj[i][j] > ( (adj[i][k] == INT_MAX || adj[k][j] == INT_MAX) ? INT_MAX : (adj[i][k] + adj[k][j]) ) ){
          adj[i][j] = adj[i][k] + adj[k][j];
        }
      }
    }
  }
  printf("\n\nNueva matriz de adjacencia con distancias minimas:\n\n");
  for(i = 0; i < numVertices; i++){
    for(j = 0; j < numVertices; j++)
      printf("%d ", adj[i][j]);
    printf("\n");
  }
}

int main(int argc, char* argv){
  floydWarshall();
  return 0;
}
