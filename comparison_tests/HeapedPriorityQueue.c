#include "HeapedPriorityQueue.h"
#include <stdlib.h>
#include <stdio.h>

#define DEBUG if(0)

/****************************************************
				Auxiliar functions
	Client programmer doesn't need to take care
about them, due to that, they've been separated from
the interface.
*****************************************************/

/**
 * This function keeps the max heap property.
 *
 * @param a HeapedPriorityQueue object
 * @param the auxiliar index of
 */
void maxHeapify(HeapedPriorityQueue *queue, int index);

/**
 * It gets two integers and swap
 * their values to each other.
 *
 * @param an integer pointer a
 * @param an integer pointer b
 */
void swap(int *a, int *b);

/**
 * It gets an index and returns the 
 * index of its parent.
 * 
 * @param an index
 * @return index of parent
 */
int getParentIndex(int index);

/**
 * It gets an index and returns the index
 * of its left element.
 *
 * @param an index
 * @return index of left element
 */
int getLeftIndex(int index);

/**
 * It gets and index and returns the 
 * index of its right element.
 *
 * @param an index
 * @return right element
 */
int getRightIndex(int index);

/**********************************************************
			Contract's functions imeplementation
***********************************************************/
HeapedPriorityQueue *newHeapedPriorityQueue() {
	HeapedPriorityQueue *queue = (HeapedPriorityQueue*) malloc(
						sizeof(HeapedPriorityQueue));
	queue->size = 0;
	return queue;
}

void destroyHeapedPriorityQueue(HeapedPriorityQueue *queue) {
	free(queue);
}

void enqueueHPQ(HeapedPriorityQueue *queue, int value, int *comparison) {
	if(isFullHPQ(queue))
		printf("Log Error:: Heap Overflow!\n");
	else {
		queue->elements[++queue->size] = value;
		int indexHandler = queue->size;
		int parentIndex = getParentIndex(getQueueSize(queue));
		while(parentIndex >= 1 && 
				queue->elements[indexHandler] > queue->elements[parentIndex]) {
			swap(&queue->elements[indexHandler], &queue->elements[parentIndex]);
			indexHandler = parentIndex;
			parentIndex = getParentIndex(indexHandler);
			(*comparison)++;
		}
	}
}

int dequeueHPQ(HeapedPriorityQueue *queue) {
	if(isEmptyHPQ(queue))
		return -1;
	int topElement = queue->elements[1];
	queue->elements[1] = queue->elements[queue->size];
	queue->size--;
	maxHeapify(queue, 1);
	return topElement;
}

int isEmptyHPQ(HeapedPriorityQueue *queue) {
	return queue->size == 0;
}

int isFullHPQ(HeapedPriorityQueue *queue) {
	return queue->size >= MAX;
}

int getQueueSize(HeapedPriorityQueue *queue) {
	return queue->size;
}

/**********************************************************
			Auxiliar functions imeplementation
***********************************************************/

void maxHeapify(HeapedPriorityQueue *queue, int index) {
	int leftIndex = getLeftIndex(index);
	int rightIndex = getRightIndex(index);
	int largerstIndex;
	int queueSize = getQueueSize(queue);
	if(leftIndex < queueSize && 
			queue->elements[leftIndex] > queue->elements[index]) 
		largerstIndex = leftIndex;
	else
		largerstIndex = index;
	if(rightIndex < queueSize && 
			queue->elements[rightIndex] > queue->elements[largerstIndex])
		largerstIndex = rightIndex;
	if(queue->elements[index] != queue->elements[largerstIndex]) {
		swap(&queue->elements[index], &queue->elements[largerstIndex]);
		maxHeapify(queue, largerstIndex);
	}
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int getParentIndex(int index) {
	return index >> 1;
}

int getLeftIndex(int index) {
	return index << 1;
}

int getRightIndex(int index) {
	return (index << 1) + 1;
}

void printHeap(HeapedPriorityQueue *queue) {
	int i;
	for(i = 1; i <= getQueueSize(queue); i++)
		printf("%d ", queue->elements[i]);
	printf("\n");
}
