#ifndef GRAPH_H
#define GRAPH_H

#include "adjacency.h"
#include "stack.h"

typedef struct graph{
	AdjList **vertices;
	short *visited;
}Graph;

Graph* createGraph(int size);
void addEdge(Graph *graph, int vertex1, int vertex2);

//Set all vertices visited to 0.
void resetVisited(Graph *graph, int size);

void destructGraph(Graph *graph, int size);
void dfs(Graph *graph, int source, Stack *stack);

#endif