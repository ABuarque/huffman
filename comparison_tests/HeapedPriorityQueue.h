#ifndef HEAPEDPRIORITYQUEUE_H
#define HEAPEDPRIORITYQUEUE_H

#define MAX 100000

typedef struct heapedPriorityQueue {
	int size;
	int elements[MAX];
} HeapedPriorityQueue;

/**
 * It constructs and returns a priority queue 
 * implemented using heap.
 *
 * @return a HeapedPriorityQueue object
 */
HeapedPriorityQueue *newHeapedPriorityQueue();

/**
 * It works as a destructor of a HeapedPriorityQueue 
 * object.
 *
 * @param a HeapedPriorityQueue to destroy
 */
void destroyHeapedPriorityQueue(HeapedPriorityQueue *queue);

/**
 * It gets an integer value and puts it 
 * inside a priority queue.
 *
 * @param a HeapedPriorityQueue object
 * @param an integer
 */
void enqueueHPQ(HeapedPriorityQueue *queue, int value, int *comparison);

/**
 * It returns the element in the front.
 *
 * @param a HeapedPriorityQueue to get front element
 * @return top element 
 */
int dequeueHPQ(HeapedPriorityQueue *queue);

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

#endif
