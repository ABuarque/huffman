#include "List.h"
#include "HuffmanTree.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

List* newList() {
	return NULL;
}

List* newNode(HuffmanTree* tree) {
	List* node = (List*) malloc(sizeof(List));
	node->tree = tree;
	node->next = NULL;
	return node;
}
