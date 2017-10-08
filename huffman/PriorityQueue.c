#include "PriorityQueue.h"
#include "utils.h"
#include "List.h"
#include "HuffmanTree.h"
#include <stdlib.h>
#include <stdio.h>

PriorityQueue *newPriorityQueue() {
	PriorityQueue *queue = malloc(sizeof(PriorityQueue));
	if(!queue) {
		printf("%s %s", LOG_ERROR, BAD_ALLOCATION);
		return NULL;
	}
	queue->head = q->tail = NULL;
	return queue;
}
