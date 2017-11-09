#ifndef ONDECOMPRESSUTIL_H
#define ONDECOMPRESSUTIL_H

#include "utils.h"
#include "PriorityQueue.h"
#include "HuffmanTree.h"
#include <stdlib.h>
#include <string.h>

/**
 * It gets a string with the input file to
 * be decompressed and checks if it's valid.
 *
 * @param a string with file name
 * @return 1 if valid, 0 if not
 */
int isValidFile(char* inputFileName);

/**
 * It gets a string, a starting and ending
 * point and returns a string with the 
 * chars inside this range.
 *
 * @param a string
 * @param begin
 * @param end
 * @return a substring
 */
char* substring(char* s, int begin, int end);

/**
 * It gets the first byte and returns the 
 * trash on file.
 *
 * @param first byte
 * @return trash
 */
int getTrash(byte firstByte);

/**
 * It gets first two bytes of file, put the first 3 bits
 * off and returns the size tree.
 *
 * @param first byte
 * @param second byte
 * @return tree size
 */
int retrieveTreeSize(byte firstByte, byte secondByte);

/**
 * It gets the reassembled tree, trash size, input and output file to
 * make a file with original resources.
 *
 * @param huffman tree
 * @param trash
 * @param trash size
 * @param input file
 * @param output file
 */
void rewriteOriginal(HuffmanTree* tree, int trash, FILE* inputFile, FILE* outputFile);

/**
 * It runs the input file and returns an array with 
 * tree bytes.
 * 
 * @param input file
 * @param size of tree
 * @return array with tree bytes
 */
byte* huffmanTreeBytes(FILE* inputFile, int treeSize);

/**
 * It gets the tree bytes and its size to build a huffman tree
 * and returns it.
 *
 * @param tree bytes
 * @param tree size
 * @return Huffman tree object
 */
HuffmanTree* reassembleHuffmanTree(byte* treeBytes, int sizeTree);

#endif
