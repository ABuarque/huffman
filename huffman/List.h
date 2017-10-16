#ifndef LIST_H
#define LIST_H

#include "HuffmanTree.h"
#include "utils.h"

typedef struct list {
	int frequency;
	byte nodeByte;
	struct list* next;
} List;

/**
 * It works as constructor for a list.
 *
 */
List* newList();

/**
 * It gets an integer as frequency and a byte
 * with byte value;
 *
 * @param frequency;
 * @param a byte
 * @retunr a List node object
 */
List* newNode(int frequency, byte nodeByte);

#endif
