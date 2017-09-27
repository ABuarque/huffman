#include <stdio.h>
#include <stdlib.h>
#include "toposort.h"
#include "queue.h"

void topologicalSortDFS(Graph *graph, int size){
	Stack *stack = createStack();
	int i;

	for(i=0;i<size;i++){
		if(!graph->visited[i]){
			dfs(graph,i,stack);
		}
	}

	printStack(stack);
}

void topologicalSortIndegree(Graph *graph, int size){
	int* indegree = calloc(size,sizeof(int));
	int i;
	Stack *stack = createStack();
	Queue *result = createQueue();
	AdjList *adjList;

	for(i=0;i<size;i++){
		adjList = graph->vertices[i];
		while(adjList != NULL){
			indegree[adjList->item]++;
			adjList = adjList->next;
		}
	}

	for(i=0;i<size;i++){
		if(!indegree[i]) push(stack,i);
	}

	while(!isEmptyStack(stack)){
		int value = pop(stack);
		enqueue(result,value);
		adjList = graph->vertices[value];

		while(adjList != NULL){
			if(--indegree[adjList->item] == 0){
				push(stack,adjList->item);
			}
			adjList = adjList->next;
		}
	}

	printQueue(result);
}