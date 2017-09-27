#ifndef QUEUE_H
#define QUEUE_H

#include "adjacency.h"

typedef struct queue{
	Node *head;
	Node *tail;
	int size;
}Queue;

Queue* createQueue();
void enqueue(Queue *queue, int item);
int isEmptyQueue(Queue *queue);
void printQueue(Queue *queue);

#endif