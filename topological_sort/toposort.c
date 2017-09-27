#include <stdio.h>
#include <stdlib.h>
#include "toposort.h"

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