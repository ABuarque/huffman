#ifndef LIST_H
#define LIST_H

#include "HuffmanTree.h"

typedef struct list {
	HuffmanTree* tree;
	struct list* next;
} List;

/**
 * It works as constructor for a list.
 *
 */
List* newList();

/**
 * It gets a HuffmanTree object, insert
 * it into a list node and returns it;
 *
 * @param HuffmanTree object
 * @retunr a List node object
 */
List* newNode(HuffmanTree* tree);

#endif
