#include "PriorityQueue.h"
#include "utils.h"
#include "List.h"

PriorityQueue *newPriorityQueue() {
	PriorityQueue *queue = malloc(sizeof(PriorityQueue));
	if(!queue) {
		printf("%s %s", LOG_ERROR, BAD_ALLOCATION);
		return NULL;
	}
	queue->queueSize = 0;
	queue->head = newList();
}
