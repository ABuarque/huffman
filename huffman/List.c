#include "List.h"
#include "HuffmanTree.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

List *newList() {
	return NULL;
}

List *newListNode(HuffmanTree *root) {
	List *node = malloc(sizeof(List));
	node->root = root;
	node->next = NULL;
	return node;
}

List *pushBack(List *listEnd, HuffmanTree *tree) {
	List *node = (List*) malloc(sizeof(List));
	node->root = tree;
	node->next = NULL;
	if(listEnd != NULL)
		listEnd->next = node;
	return node;
}


