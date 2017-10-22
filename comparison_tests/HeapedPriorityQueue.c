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
HeapedPriorityQueue *newHeapedPriorityQueue(size_t dataTypeSize) {
	HeapedPriorityQueue *queue = (HeapedPriorityQueue*) malloc(
						sizeof(HeapedPriorityQueue));
	queue->dataTypeSize = dataTypeSize;
	queue->size = 0;
	queue->elements = malloc(sizeof(void*) * MAX);
	return queue;
}

void destroyHeapedPriorityQueue(HeapedPriorityQueue *queue) {
	free(queue);
}

void enqueueHPQ(HeapedPriorityQueue *queue, void *value, int *comparison) {
	if(isFullHPQ(queue))
		printf("Log Error:: Heap Overflow!\n");
	else {
		//allocating space to place given value
		queue->elements[++queue->size] = malloc(queue->dataTypeSize);
		//puttin given value on the right index
		unsigned i;
		for(i = 0; i < queue->dataTypeSize; i++) 
			*(char*)(queue->elements[queue->size] + i) = *(char*)(value + i);
		int indexHandler = queue->size;
		int parentIndex = getParentIndex(getQueueSize(queue));
		while(parentIndex >= 1 && 
				*((int*)queue->elements[indexHandler]) > *((int*) queue->elements[parentIndex])) {
			swap((int*) queue->elements[indexHandler], (int*) queue->elements[parentIndex]);
			indexHandler = parentIndex;
			parentIndex = getParentIndex(indexHandler);
			(*comparison)++;
		}
	}
}

void *dequeueHPQ(HeapedPriorityQueue *queue) {
	if(isEmptyHPQ(queue))
		return NULL;
	void *topElement = queue->elements[1];
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
**********************************************************/

void maxHeapify(HeapedPriorityQueue *queue, int index) {
	int leftIndex = getLeftIndex(index);
	int rightIndex = getRightIndex(index);
	int largerstIndex;
	int queueSize = getQueueSize(queue);
	if(leftIndex < queueSize && 
			*((int*) queue->elements[leftIndex]) > *((int*) queue->elements[index])) 
		largerstIndex = leftIndex;
	else
		largerstIndex = index;
	if(rightIndex < queueSize && 
			*((int*) queue->elements[rightIndex]) > *((int*) queue->elements[largerstIndex]))
		largerstIndex = rightIndex;
	if((*(int*) queue->elements[index]) != *((int*) queue->elements[largerstIndex])) {
		swap((int*) queue->elements[index], (int*) queue->elements[largerstIndex]);
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
		printf("%d ", *((int*) queue->elements[i]));
	printf("\n");
}
