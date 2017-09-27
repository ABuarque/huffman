#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph* createGraph(int size){
	int i;


	Graph* newGraph = malloc(sizeof(Graph));
	AdjList** newList = malloc(sizeof(AdjList) * size);
	newGraph->vertices = newList;
	newGraph->visited = calloc(size,sizeof(int));

	for(i=0;i<size;i++){
		newGraph->vertices[i] = NULL;
	}
	return newGraph;
}

void addEdge(Graph *graph, int vertex1, int vertex2){
	AdjList* vertex = createAdjList(vertex2);

	if(graph->vertices[vertex1] == NULL || graph->vertices[vertex1]->item > vertex2){
		vertex->next = graph->vertices[vertex1];
		graph->vertices[vertex1] = vertex;
		return;
	}

	AdjList* current = graph->vertices[vertex1];

	while(current->next != NULL && current->next->item < vertex2)
		current = current->next;

	vertex->next = current->next;
	current->next = vertex;
}

void resetVisited(Graph *graph, int size){
	int i;
	for(i=0;i<size;i++) 
		graph->visited[i] = 0;
}

void destructGraph(Graph *graph, int size){
	int i;

	for(i=0;i<size;i++){
		destructAdjList(graph->vertices[i]);
	}

	free(graph);
}

void dfs(Graph *graph, int source, Stack *stack){
	graph->visited[source] = 1;
	AdjList *adjList = graph->vertices[source];

	while (adjList != NULL) {
		if (!graph->visited[adjList->item]){
			dfs(graph, adjList->item,stack);
		}
		adjList = adjList->next;
	}

	push(stack,source);
}