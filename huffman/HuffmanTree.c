#include "HuffmanTree.h"
#include "utils.h"
#include <stdlib.h>

HuffmanTree* newHuffmanTree(byte treeByte, int frequency) {
	HuffmanTree* tree = (HuffmanTree*) malloc(sizeof(HuffmanTree));
	tree->treeByte = treeByte;
	tree->frequency = frequency;
	tree->left = tree->right = NULL;
	return tree;
}
