#include <stdio.h>
#include <stdlib.h>
#include "toposort.h"
#include "graph.h"

int main(){
	int size = 8;

	Graph *graph = createGraph(size);

	addEdge(graph,0,2);
	addEdge(graph,2,5);
	addEdge(graph,1,3);
	addEdge(graph,3,5);
	addEdge(graph,5,6);
	addEdge(graph,5,7);
	addEdge(graph,6,7);
	addEdge(graph,4,7);

	topologicalSortIndegree(graph,size);

	//topologicalSortDFS(graph,size);

	return 0;
}