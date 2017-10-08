#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "List.h"
#include "HuffmanTree.h"

typedef struct {
	List *head;
	List *tail;
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

/**
 * It retuens and remove the first element
 * on the priority queue.
 *
 * @param a PriorityQueue object
 * @return a HuffmanTree
 */
HuffmanTree dequeue(PriorityQueue *queue);

#endif
