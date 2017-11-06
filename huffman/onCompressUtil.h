#ifndef ONCOMPRESSUTIL_H
#define ONCOMPRESSUTIL_H

#include "utils.h"
#include "PriorityQueue.h"
#include "HuffmanTree.h"
#include "Header.h"
#include <stdlib.h>
#include <string.h>

/**
 * It gets a file and returns an array with
 * its bytes and frequencies.
 *
 * @param input file
 * @return an array of bytes
 */
int* getBytesFrequency(FILE* inputFile);

/**
 * It gets bytes frequency array to
 * build the tree and returns the tree.
 *
 * @param a bytes frequency array
 * @return a huffman tree
 */
HuffmanTree* buildHuffmanTree(int* bytesFrequency);

/**
 * It gets a priority queue and helps
 * to build the huffman tree.
 *
 * @param a priority queue
 * @return a huffman tree
 */
HuffmanTree* buildTreeFromQueue(PriorityQueue *queue);

/**
 * It gets a huffman tree and returns a matrix
 * with the byte's paths.
 *
 * @param a huffman tree
 * @return a byte matrix
 */
byte** buildPaths(HuffmanTree* tree);

/**
 * It gets a byte matrix, a huffman tree, a byte array and
 * an integer which works as index that helps to build the path
 * of bytes.
 *
 * @param a byte matrix
 * @param a huffman tree
 * @param a byte array
 * @param an integer
 */
void buildPathsHandler(byte** matrix, HuffmanTree* tree, byte *string, int position);

/**
 * It's a helpful function which handles the
 * process of writing bytes on file.
 *
 * @param a huffman tree
 * @param a file to write the tree in
 */
void writeTree(HuffmanTree *tree, FILE *outputFile);

/**
 * It gets the util matrix, input file and output file
 * to write the matrix.
 * 
 * @param util matrix
 * @param input file
 * @param output file
 */
void writePaths(byte** matrix, FILE* inputFile, FILE* outputFile);

/**
 * It gets a byte and an integer,
 * sets the bit at the index and returns
 * the new byte.
 *
 * @param a byte
 * @param a bit position
 * @return a byte 
 */
byte setBitAt(byte currentByte, short int pos);

/**
 * It gets a Huffman tree and returns its size.
 *
 * @param a huffman tree
 * @return size
 */
int getTreeSize(HuffmanTree* tree);

/**
 * It helps to get the huffman tree.
 * 
 * @param a huffman tree
 * @param a pointer to store the size
 */
void getSizeUtil(HuffmanTree* tree, int* sizePointer);

/**
 * It gets the matrix handler, tree size and input file
 * and returns a header object with scrap and tree size.
 *
 * @param matrix handler
 * @param tree size
 * @param input file
 * @return a header file
 */
Header* getHeaderInfo(byte** matrix, int treeSize, FILE* inputFile);

/**
 * It gets the header, huffman tree, input file and matrix paths
 * to print it in the output file
 *
 * @param header with scrap and tree size
 * @param huffman tree
 * @param matrix handler
 * @param output file
 * @param input file
 */
void writeSources(Header* header, HuffmanTree* tree, byte** matrix, FILE* outputFile, FILE* inputFile);

#endif
