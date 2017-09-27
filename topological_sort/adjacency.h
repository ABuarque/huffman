#ifndef ADJACENCY_H
#define ADJACENCY_H

typedef struct adjList{
	int item;
	struct adjList *next;
}AdjList;

typedef struct node{
	int item;
	struct node *next;
}Node;

/*
	Creating a adjacency list to add all related vertices 
*/
AdjList* createAdjList(int item);

void destructAdjList(AdjList *list);

int isEmptyAdjList(AdjList *list);

#endif