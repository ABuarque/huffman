#include "PriorityQueue.h"
#include "utils.h"
#include "List.h"
#include "HuffmanTree.h"
#include <stdlib.h>
#include <stdio.h>

#define DEBUG if(1)

PriorityQueue *newPriorityQueue() {
	PriorityQueue *queue = malloc(sizeof(PriorityQueue));
	if(!queue) {
		printf("%s %s", LOG_ERROR, BAD_ALLOCATION);
		return NULL;
	}
	queue->head = queue->tail = NULL;
	return queue;
}

void enqueue(PriorityQueue *queue, HuffmanTree *tree) {
	queue->tail = pushBack(queue->tail, tree);
	if(queue->head == NULL) //was it empty?
		queue->head = queue->tail;
}

HuffmanTree *dequeue(PriorityQueue *queue) {
	if(isEmpty(queue)) {
		DEBUG printf("%s %s", LOG_ERROR, DATA_ESTRUCTURE_EMPTY);
		return NULL;
	}
	HuffmanTree *tree = queue->head->root;
	queue->head = removeFromHead(queue->head);
	if(queue->head == NULL) //is empty now?
		queue->tail = NULL;
	return tree;
}

int isEmpty(PriorityQueue *queue) {
	return queue->head == NULL;
}
