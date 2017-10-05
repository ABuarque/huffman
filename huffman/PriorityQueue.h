#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "List.h"

typedef struct {
	List *head;
	int queueSize;
} PriorityQueue;

/**
 * It creates a priority queue and returns it;
 * 
 * @return priority queue object
 */
PriorityQueue *newPriorityQueue();

/**
 * It gets a list and enqueue it into a given
 * priority queue.
 *
 * @param priority queue
 * @param a list head
 */
void enqueue(PriorityQueue *queue, List *list);

#endif
