#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#define ERR -1

/**
 *	Priority Queue without heap
 *	Filosophy: item with biggest priority is inserted at the head of the list
 *	Big O of main functions:
 *		Enqueue: O(n)
 *		Dequeue: O(1)
 */

typedef struct Node 
{
	int item;
	int priority;
	struct Node *next;
} Node;

typedef struct PriorityQueue
{
	int size;
	Node *head;
} PriorityQueue;

/**
 * It constructs and returns a priority queue 
 * implemented using linked lists.
 *
 * @return a PriorityQueue object
 */
PriorityQueue *createPriorityQueue();

/**
 * It works as a destructor of a PriorityQueue 
 * object.
 *
 * @param a PriorityQueue to destroy
 */
void destroyPriorityQueue(PriorityQueue *queue);

/**
 * It gets an integer value and its priority then puts it 
 * inside a priority queue.
 *
 * @param a PriorityQueue object
 * @param an integer
 * @param an integer
 */
void enqueue(PriorityQueue *queue, int item, int priority);

/**
 * It removes the element in the front of the priority queue and returns it.
 *
 * @param a PriorityQueue to get front element
 * @return top element 
 */
int dequeue(PriorityQueue *queue);

/**
 * It gets a PriorityQueue object and
 * check if it's empty or not.
 *
 * @param a PriorityQueue object
 * @return 1 if empty, 0 if not
 */
int isEmpty(PriorityQueue *queue);


/** 
 * It gets a PriorityQueue object and
 * returns its size.
 *
 * @param PriorityQueue object
 * @return its size
 */
int getSize(PriorityQueue *queue);

#endif