#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "utils.h"

typedef struct huffmanTree {
	byte givenByte;
	unsigned int frequency;
	struct huffmanTree *left;
	struct huffmanTree *right;
} HuffmanTree;


/**
 * It creates a node of a Huffman Tree
 * and setup its fields: byte, frequency,
 * left subtree and right subtree.
 *
 * @param given byte
 * @param byte frequency
 * @param left subtree
 * @param right subtree
 * @return a huffman tree node
 */
HuffmanTree* newHuffmanTree(byte givenByte, 
			unsigned int frequency, 
			HuffmanTree* left, 
			HuffmanTree* right);

#endif
