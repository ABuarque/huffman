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

/**
 * It appends new HuffmanTree object into a list
 * 
 * @param end of a list
 * @param a HuffmanTree tree
 * @return the list with new object
 */
List *pushBack(List *listEnd, HuffmanTree *tree);

#endif
