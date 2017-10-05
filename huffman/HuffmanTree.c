#include "HuffmanTree.h"
#include "utils.h"
#include <stdlib.h>

HuffmanTree* newHuffmanTree(byte givenByte, unsigned int frequency,
		 HuffmanTree* left, HuffmanTree* right) {
	HuffmanTree* tree = malloc(sizeof(HuffmanTree));
	if(!tree) {
		printf("%s %s\n", LOG_ERROR, BAD_ALLOCATION);
		return NULL;
	}
	tree->givenByte = givenByte;
	tree->frequency = frequency;
	tree->left = left;
	tree->right = right;
	return tree;
}
