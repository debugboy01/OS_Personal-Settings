/*
########################################################
###       @Copyright Moreno Vera, Felipe Adrian      ###
###        Graph implementation                      ###
########################################################
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//#include "graph.h"

#define GRAPH_NODE int

void Create_graph(int**edges,int**adj,int numVertices,int numEdges)
{
  int i,j,k;    // contadores
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
  if(numEdges!=0) {
    printf("Ingrese las aristas y su peso (v1, v2, weight): \n");
    for(i = 0; i < numEdges; i++)
    {
      scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
      adj[edges[i][0]][edges[i][1]] = edges[i][2];
      adj[edges[i][1]][edges[i][0]] = edges[i][2];
    }
  }
  // muestra la nueva matriz de adjacencia
  printf("\n\nMatriz de adjacencia:\n\n");
  for(i = 0; i < numVertices; i++){
    for(j = 0; j < numVertices; j++){
      printf("%d ",adj[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
}

void Create_directedGraph(int**edges,int**adj,int numVertices,int numEdges)
{
  int i,j,k;    // contadores
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
  for(i = 0; i < numVertices; i++){
    for(j = 0; j < numVertices; j++){
      printf("%p ",&adj[i][j]);
    }
    printf("\n");
  }
  int v1, v2, weight;
  for( i=0;i<numEdges;i++){
    printf("%p ",&edges[i][0]);
    printf("%p ",&edges[i][1]);
    printf("%p\n",&edges[i][2]);
  }
  printf("\n");
  // arista de vertice a vertice y con peso (grafo dirigido)
  if(numEdges>0) {
    printf("Ingrese las aristas y su peso (v1, v2, weight): \n");
    for(i = 0; i < numEdges; i++)
    {
      scanf("%d %d %d", &v1, &v2, &weight);
      edges[i][0] = v1;
      //edges[i][1] = v2;
      //edges[i][2] = weight;
      //adj[edges[i][0]][edges[i][1]] = edges[i][2];
      adj[v1][v2] = weight;
    }
  }
  // muestra la nueva matriz de adjacencia
  printf("\n\nMatriz de adjacencia:\n\n");
  for(i = 0; i < numVertices; i++){
    for(j = 0; j < numVertices; j++){
      printf("%d ",adj[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
}

void prim(int*key,int*parent,int**edges,int**adj,int numVertices,int root)
{
  int i,j;
  // construccion del arbol minimo generado
  // iniciados con pesos infinitos (INT_MAX)
  // y -1 indica padre es NULL o nil
  for(i = 0; i < numVertices; i++){
      key[i] = INT_MAX;
      parent[i] = -1;
  }
  key[root] = 0;
  //The queue should be a priority queue, however, for brevity,
  // Reserva memoria para el array de vertices que seran usados
  int * used = (int *) malloc(sizeof(int)*numVertices);
  int numUnused = numVertices;
  for(i = 0; i < numVertices; i++)
    used[i] = 0;
  int u = root;
  int closestIdx = root;    // indice del vertice mas cercano
  int closestVal = INT_MAX; // valor del vertice mas cercano

  while(numUnused > 0){
    closestVal = INT_MAX;
    // Encuentra la arista con menor peso
    for(i = 0; i < numVertices; i++){
      if(used[i] == 0 && key[i] < closestVal){
        closestIdx = i;
        closestVal = key[i];
      }
    }
    printf("vertice visitado actual es %d\n", u);
    u = closestIdx;
    // marca como visitado
    used[u] = 1;
    // decrementa el numero de vertices
    numUnused--;
    // para cada vertice i adjacente al vertice u
    for(i = 0; i < numVertices; i++){
      if(used[i] == 0 && adj[u][i] > 0 && adj[u][i] < key[i]){
        parent[i] = u;
        key[i] = adj[u][i];
        printf("key[%d] is %d\n", i, adj[u][i]);
      }
    }
  }

  for(i = 0; i < numVertices; i++)
    printf("vertice: %d parent: %d\n", i, parent[i]);
}

void floydWarshall(int**adj,int numVertices){
  int i,j,k;
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

int** Create_adjMatrix(int numVertices){
  int i;
  int** adj;
  // Reservamos memoria para la matriz de adjacencia
  adj = (int **) malloc(sizeof(int *)*numVertices);
  adj[0] = (int *)malloc(numVertices*sizeof(int));
  for(i = 0; i < numVertices; i++)
    adj[i] = &adj[0][numVertices*i];
    //adj[i] = (int *) malloc(sizeof(int)*numVertices);
  return adj;
}

int** Create_edgesMatrix(int numEdges){
  int i;
  int** edges;
  // aristas
  edges = (int **)malloc(sizeof(int*)*numEdges);
  edges[0] = (int *)malloc(sizeof(int)*3);
  // reservamos memoria para los caminos
  for(i = 0; i < numEdges; i++)
    edges[i] = &edges[0][numEdges*i];
    //edges[i] = (int *) malloc(sizeof(int)*3);
  return edges;
}

int mainGraph(void){
  int* key,     // Valores de cada nodo del arbol generado minimo
    * parent; // nodo padre de cada nodo del arbol generado minimo
  int** adj,  // matriz de adjacencia
    ** edges;  // matriz de caminos y/o aristas
  int numVertices; // numero de vertices del grafo
  int numEdges;   // numero de aristas del grafo
  int i;
  printf("Ingrese numero de vertices: ");
  scanf("%d",&numVertices);
  printf("Ingrese numero de aristas: ");
  scanf("%d", &numEdges);
  // valores de cada nodo del arbol generado, son los pesos
  key = (int *) malloc(sizeof(int)*numVertices);
  // padres, del arbol generado
  parent = (int *) malloc(sizeof(int)*numVertices);
  
  if(numVertices == 0){
    printf("Numero de vertices 0\nGrafo Nulo\n");
    return 1;
  }else if(numVertices < 0){
    printf("Numero de vertices erroneo\n");
    return -1;
  }
  if(numEdges < 0){
    printf("Numero de aristas Incorrecto!!\n");
    return -1;
  }else if(numEdges == 0){
    printf("Numero de aristas 0\n");
  }
  adj = Create_adjMatrix(numVertices);
  edges = Create_edgesMatrix(numEdges);
  int j;
  for(i = 0; i < numVertices; i++){
    for(j = 0; j < numVertices; j++){
      printf("%p ",&adj[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for( i=0;i<numEdges;i++){
    printf("%p ",&edges[i][0]);
    printf("%p ",&edges[i][1]);
    printf("%p\n",&edges[i][2]);
  }
  printf("\n");
  Create_directedGraph(edges,adj,numVertices,numEdges);
  return 0;
}

int main(int argc,char*argv){
  int retorno;
  retorno = mainGraph();
  GRAPH_NODE a=1.2;
  printf("%i\t%ld\n",a,sizeof(a));
  return 0;
}
