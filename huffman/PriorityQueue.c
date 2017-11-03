#include "PriorityQueue.h"
#include "utils.h"
#include "List.h"
#include "HuffmanTree.h"
#include <stdlib.h>
#include <stdio.h>

#define DEBUG if(0)

PriorityQueue* newPriorityQueue() {
	PriorityQueue* queue = (PriorityQueue*) malloc(sizeof(PriorityQueue));
	queue->head = newList();
	return queue;
}

int isEmpty(PriorityQueue* queue) {
	return queue->head == NULL;
}

//enqueue(queue, newHuffmanTree(byte, frequency))
void enqueue(PriorityQueue* queue, HuffmanTree* tree) {
	List* node = newNode(tree);
	if(isEmpty(queue) || (tree->frequency < queue->head->tree->frequency)) {
		node->next = queue->head;
		queue->head = node;
	} else {
		List* it = queue->head;
		while((it->next != NULL) && (it->next->tree->frequency < tree->frequency)) 
			it = it->next;
		node->next = it->next;
		it->next = node;
	}
}

HuffmanTree* dequeue(PriorityQueue* queue) {
	if(isEmpty(queue)) {
		printf("Empty queue\n");
		return NULL; 
	} 
	List* node = queue->head;
	queue->head = queue->head->next;
	node->next = NULL;
	//return node;
	return node->tree;
}
