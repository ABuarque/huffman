#include <stdio.h>
#include <stdlib.h>
#define DEBUG if(0)
#define ERR -1

/*
	Priority Queue without heap
	Filosophy: item with biggest priority is inserted at the head of the list
	Big O of main functions:
		Enqueue: O(n)
		Dequeue: O(1)
	Input: A Number n of tests, followed by n pairs of a item and its priority, in that order
*/

typedef struct Node 
{
	int item;
	int priority;
	struct Node *next;
}Node;

typedef struct priorityQueue
{
	Node *head;
}priorityQueue;

priorityQueue *createPQ();

void enqueue(priorityQueue *pq, int item, int priority);

Node* dequeue(priorityQueue *pq);

int maximum(priorityQueue *pq);

int isEmpty(priorityQueue *pq);

void printPriorityQueue(priorityQueue *pq);

int main(int argc,char *argv[])
{
	priorityQueue *pq = createPQ();

	int i;
	int tests,item,priority;
	scanf("%d",&tests);						// reads number of tests to be done
	for(i = 0; i < tests; i++)
	{
		scanf("%d %d",&item,&priority);		// reads an item and its priority in the queue
		enqueue(pq,item,priority);			// insert the item into the queue
	}	
	printPriorityQueue(pq);					// after inserting all the item into the queue, the queue is printed 

	return 0;
}

priorityQueue *createPQ()
{
	priorityQueue *newPQ = malloc(sizeof(priorityQueue));
	if(!newPQ) return NULL;
	newPQ->head = NULL;

	return newPQ;
}

void enqueue(priorityQueue *pq, int item, int priority)
{
	Node *newNode = malloc(sizeof(Node));
	newNode->item = item;
	newNode->priority = priority;
	
	if ((isEmpty(pq)) || (priority > pq->head->priority))
	{
		newNode->next = pq->head;
		pq->head = newNode;
	}
	else
	{
		Node *current = pq->head;
		while ((current->next != NULL) && (current->next->priority > priority))
		{
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}

Node *dequeue(priorityQueue *pq)
{
	if (isEmpty(pq)) 
	{
		printf("Priority Queue underflow");
		return NULL;
	} 
	else
	{
		Node *node = pq->head;
		pq->head = pq->head->next;
		node->next = NULL;
		return node;
	}
}

int maximum(priorityQueue *pq)
{
	if (isEmpty(pq)) 
	{
		printf("Priority Queue underflow");
		return ERR;
	}
	else
	{
		return pq->head->item;
	}
}

int isEmpty(priorityQueue *pq)
{
	return (pq->head == NULL);
}

void printPriorityQueue(priorityQueue *pq)
{
	priorityQueue *aux = pq;

	while(aux->head)
	{
		printf("|%d| ",aux->head->item);
		aux->head = aux->head->next;
	}
	printf("\n");
}
