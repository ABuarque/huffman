#include <stdio.h>
#include <stdlib.h>
#include "adjacency.h"

AdjList* createAdjList(int item){
	AdjList* newAdjList = malloc(sizeof(AdjList));
	newAdjList->item = item;
	newAdjList->next = NULL;
	return newAdjList;
}

void destructAdjList(AdjList *list){
	while(list != NULL){
		AdjList *current = list;
		list = list->next;
		free(current);
	}
}

int isEmptyAdjList(AdjList *list){
	return (list == NULL);
}