#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* createQueue(){
	Queue *newQueue = malloc(sizeof(Queue));
	newQueue->head = NULL;
	newQueue->tail = NULL;
	newQueue->size = 0;
	return newQueue;
}

void enqueue(Queue *queue, int item){
	Node* newNode = malloc(sizeof(Node));
	newNode->item = item;
	newNode->next = NULL;

	if(isEmptyQueue(queue)){
		queue->head = newNode;
		queue->tail = newNode;
		queue->size++;
		return;
	}

	queue->tail->next = newNode;
	queue->tail = newNode;
	queue->size++;
}

int isEmptyQueue(Queue *queue){
	return (queue->size == 0);
}

void printQueue(Queue *queue){
	while(queue->head != NULL){
		printf("%d\n",queue->head->item);
		queue->head = queue->head->next;
	}
}