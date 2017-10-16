#include "List.h"
#include "HuffmanTree.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

List* newList() {
	return NULL;
}

List* newNode(int frequency, byte nodeByte) {
	List* node = (List*) malloc(sizeof(List));
	node->frequency = frequency;
	node->nodeByte = nodeByte;
	return node;
}
