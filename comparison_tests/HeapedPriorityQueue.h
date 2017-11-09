#ifndef HEAPEDPRIORITYQUEUE_H
#define HEAPEDPRIORITYQUEUE_H

#include <stdlib.h>

#define MAX 100000

typedef struct heapedPriorityQueue {
	size_t dataTypeSize;
	int size;
	void **elements;
} HeapedPriorityQueue;

/**
 * It constructs and returns a priority queue 
 * implemented using heap.
 *
 * @param size of data type
 * @return a HeapedPriorityQueue object
 */
HeapedPriorityQueue *newHeapedPriorityQueue(size_t dataTypeSize);

/**
 * It gets a pointer to some type and puts it 
 * inside a priority queue.
 *
 * @param a HeapedPriorityQueue object
 * @param a pointer to some data type
 */
void enqueueHPQ(HeapedPriorityQueue *queue, void *value, int *comparison);

/**
 * It returns the element in the front.
 *
 * @param a HeapedPriorityQueue to get front element
 * @return top element 
 */
//void *dequeueHPQ(HeapedPriorityQueue *queue);

/**
 * It gets a HeapedPriorityQueue object and
 * check if it's empty or not.
 *
 * @param a HeapedPriorityQueue object
 * @return 1 if empty, 0 if not
 */
int isEmptyHPQ(HeapedPriorityQueue *queue);

/**
 * It gets HeapedPriorityQueue the check if
 * it's full or not.
 *
 * @param a HeapedPriorityQueue object
 * @return 1 if full, 0 if not
 */
int isFullHPQ(HeapedPriorityQueue *queue);

/** 
 * It gets a HeapedPriorityQueue object and
 * returns its size.
 *
 * @param HeapedPriorityQueue object
 * @return its size
 */
int getQueueSize(HeapedPriorityQueue *queue);

/**
 * It gets a HeapedPriorityQueue object
 * and prints its state.
 *
 * @param a queue
 */
void printHeap(HeapedPriorityQueue *queue);

#endif
