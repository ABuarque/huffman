#include <stdio.h>
#include <stdlib.h>
#include "PriorityQueue.h"

#define DEBUG if(0)

/****************************************************
				Auxiliar functions
	Client programmer doesn't need to take care
about them, due to that, they've been separated from
the interface.
*****************************************************/

/**
 * This function gets the item with the biggest priority and returns it.
 *
 * @param a PriorityQueue object
 * @return item at the front of the queue
 */
void *maximum(PriorityQueue *queue);

/**
 * This function prints all elements of a Priority Queue.
 *
 * @param a PriorityQueue object
 */
void printPriorityQueue(PriorityQueue *queue);

/**********************************************************
			Contract's functions imeplementation
***********************************************************/

PriorityQueue *createPriorityQueue(size_t dataTypeSize) {
	PriorityQueue *newQueue = malloc(sizeof(PriorityQueue));
	if(!newQueue) return NULL;
	newQueue->head = NULL;
	newQueue->size = 0;
	newQueue->dataTypeSize = dataTypeSize;
	return newQueue;
}

void enqueue(PriorityQueue *queue, void *item, int priority, int *comparison) {
	Node *newNode = malloc(sizeof(Node));
	newNode->item = malloc(queue->dataTypeSize);
	unsigned i;
	for(i = 0; i < queue->dataTypeSize; i++)
		*(char*)(newNode->item + i) = *(char*)(item + i);
	newNode->priority = priority;
	
	if ((isEmpty(queue)) || (priority > queue->head->priority)) {
		newNode->next = queue->head;
		queue->head = newNode;
		queue->size++;
		if(priority>queue->head->priority)
			(*comparison)++;
	}
	else {
		Node *current = queue->head;
		while ((current->next != NULL) && (current->next->priority > priority)) {
			current = current->next;
			(*comparison)++;
		}
		newNode->next = current->next;
		current->next = newNode;
		queue->size++;
	}
}

/*
void *dequeue(PriorityQueue *queue) {
	if (isEmpty(queue)) {
		printf("Priority Queue underflow");
		return NULL;
	} 
	else {
		Node *node = queue->head;
		void* item = node->item;
		queue->head = queue->head->next;
		queue->size--;
		node = NULL;
		free(node);
		return item;
	}
}*/

int isEmpty(PriorityQueue *queue) {
	return (queue->head == NULL);
}

int getSize(PriorityQueue *queue) {
	return queue->size;
}

/**********************************************************
			Auxiliar functions imeplementation
***********************************************************/

void *maximum(PriorityQueue *queue)
{
	if (isEmpty(queue)) {
		printf("Priority Queue underflow");
		return NULL;
	}
	else {
		return queue->head->item;
	}
}

void printPriorityQueue(PriorityQueue *queue) {
	PriorityQueue *aux = queue;

	while(aux->head) {
		printf("|%d| ", *((int*)aux->head->item));
		aux->head = aux->head->next;
	}
	printf("\n");
}
