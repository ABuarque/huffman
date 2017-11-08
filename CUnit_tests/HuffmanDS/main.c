#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define unsgined char byte 

typedef struct huffmanTree {
	void* treeByte;
	size_t dataTypeSize;
	int frequency;
	struct huffmanTree* left;
	struct huffmanTree* right;
} HuffmanTree;

HuffmanTree* newHuffmanTree(size_t dataTypeSize, void* treeByte, int frequency) {
	HuffmanTree* tree = (HuffmanTree*) malloc(sizeof(HuffmanTree));
	tree->dataTypeSize = dataTypeSize;
	tree->treeByte = malloc(dataTypeSize);
	unsigned i;
	for(i = 0; i < dataTypeSize; i++)
		*(char*)(tree->treeByte + i) = *(char*)(treeByte + i);
	tree->frequency = frequency;
	tree->left = tree->right = NULL;
	return tree;
}

HuffmanTree* newHuffmanHandle(size_t dataTypeSize) {
    HuffmanTree* tree = (HuffmanTree*) malloc(sizeof(HuffmanTree));
    tree->dataTypeSize = dataTypeSize;
    tree->treeByte = malloc(dataTypeSize);
    return tree;
}

typedef struct list {
	HuffmanTree* tree;
	struct list* next;
} List;

HuffmanTree* newHuffmanTree(size_t dataTypeSize, void* treeByte, int frequency);

HuffmanTree* newHuffmanHandle(size_t dataTypeSize);

List* newList();

List* newNode(HuffmanTree* tree);

/////////////////////////////////////////////////////////////////////////


List* newList() {
	return NULL;
}

List* newNode(HuffmanTree* tree) {
	List* node = (List*) malloc(sizeof(List));
	node->tree = tree;
	node->next = NULL;
	return node;
}

////////////////////////////////////////////////////////////////////////////////

typedef struct {
	List* head;
} PriorityQueue;

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

int main(int argc, char** argv) {
    
    
    
    return (EXIT_SUCCESS);
}

