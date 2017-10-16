#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "List.h"
#include "utils.h"
#include "HuffmanTree.h"

typedef struct {
	List* head;
} PriorityQueue;

/**
 * It works as a contructor of a 
 * PriorityQueue object.
 */
PriorityQueue* newPriorityQueue();

/**
 * It gets a PriorityQueue object and checks
 * if is it empty or not.
 *
 * @param a PriorityQueue object
 * @return 1 if empty, 0 if not
 */
int isEmpty(PriorityQueue* queue);

/**
 * It gets a PriorityQueue object, a byte 
 * for the node and its frequency.
 *
 * @param a PriorityQueue object
 * @param a byte
 * @param a frequency
 */
void enqueue(PriorityQueue* queue, byte nodeByte, int frequency);

/** 
 * It gets a PriorityQueue object
 * and removes its element.
 * 
 * @param a PriorityQueue object
 * @return a List object
 */
List* dequeue(PriorityQueue* queue);

#endif
