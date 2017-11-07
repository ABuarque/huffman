#include "HuffmanTree.h"
#include "utils.h"
#include <stdlib.h>

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
