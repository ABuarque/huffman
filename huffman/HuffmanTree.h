#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "utils.h"

typedef struct huffmanTree {
	byte treeByte;
	int frequency;
	struct huffmanTree* left;
	struct huffmanTree* right;
} HuffmanTree;


/**
 * It creates a node of a Huffman Tree
 * and setup its fields: byte, frequency;
 *
 * @param given byte
 * @param byte frequency
 * @return a huffman tree node
 */
HuffmanTree* newHuffmanTree(byte treeByte, int frequency);

/**
 * It just returns a referece for HuffmanTree objects
 *
 * @param a HuffmanTree reference
 */
HuffmanTree* newHuffmanHandle();

#endif
