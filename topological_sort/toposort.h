#ifndef TOPOSORT_H
#define TOPOSORT_H

#include "graph.h"
#include "stack.h"

void topologicalSortDFS(Graph *graph, int size);
void topologicalSortIndegree(Graph *graph, int size);

#endif