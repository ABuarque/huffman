#include "List.h"
#include "HuffmanTree.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

List* newList() {
	return NULL;
}

List* newListNode(HuffmanTree* root) {
	List* node = malloc(sizeof(List));
	node->root = root;
	node->next = NULL;
	return node;
}
