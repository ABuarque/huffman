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
int maximum(PriorityQueue *queue);

/**
 * This function prints all elements of a Priority Queue.
 *
 * @param a PriorityQueue object
 */
void printPriorityQueue(PriorityQueue *queue);

/**********************************************************
			Contract's functions imeplementation
***********************************************************/

PriorityQueue *createPriorityQueue() {
	PriorityQueue *newQueue = malloc(sizeof(PriorityQueue));
	if(!newQueue) return NULL;
	newQueue->head = NULL;
	newQueue->size = 0;

	return newQueue;
}

void enqueue(PriorityQueue *queue, int item, int priority, int *comparison) {
	Node *newNode = malloc(sizeof(Node));
	newNode->item = item;
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

int dequeue(PriorityQueue *queue) {
	if (isEmpty(queue)) {
		printf("Priority Queue underflow");
		return ERR;
	} 
	else {
		Node *node = queue->head;
		int item = node->item;
		queue->head = queue->head->next;
		queue->size--;
		node = NULL;
		free(node);
		return item;
	}
}

int isEmpty(PriorityQueue *queue) {
	return (queue->head == NULL);
}

int getSize(PriorityQueue *queue) {
	return queue->size;
}

void destroyPriorityQueue(PriorityQueue *queue) {
	while(queue->head) {
		dequeue(queue);
	}
	free(queue);
}

/**********************************************************
			Auxiliar functions imeplementation
***********************************************************/

int maximum(PriorityQueue *queue)
{
	if (isEmpty(queue)) {
		printf("Priority Queue underflow");
		return ERR;
	}
	else {
		return queue->head->item;
	}
}

void printPriorityQueue(PriorityQueue *queue) {
	PriorityQueue *aux = queue;

	while(aux->head) {
		printf("|%d| ",aux->head->item);
		aux->head = aux->head->next;
	}
	printf("\n");
}
