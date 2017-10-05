#ifndef LIST_H
#define LIST_H

#include "HuffmanTree.h"

typedef struct list {
	HuffmanTree *root;
	struct list *next;
} List;

/**
 * It creates a new list and returns it.
 */
List *newList();

/**
 * It gets a Huffman tree root, 
 * puts it inside a list node and returns new node.
 *
 * @param Huffman tree root
 * @return list node
 */
List *newListNode(HuffmanTree *root);

#endif
