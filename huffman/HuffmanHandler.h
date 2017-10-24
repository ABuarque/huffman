#ifndef HUFFMANHANDLER_H
#define HUFFMANHANDLER_H

#include "HuffmanTree.h"
#include "List.h"
#include "utils.h"
#include "PriorityQueue.h"
#include <stdio.h>
#include <stdlib.h>

/****************************************************
 This source file actually handles Huffman's algorithm.
 It calls the necessary data structures and applies the 
 below processes: 

-> get byte frequency
-> build huffman tree
-> destroy huffman tree
-> compress
-> decompress
*****************************************************/

/**
 * This function gets three strings, which are
 * the input, output path file and a proper error message, and then
 * applies Huffman`s algorithm to compress file.
 *
 * @param input file
 * @param output file
 * @param an alert message
 */
void onCompress(char *inputPathFile, char *outputPathFile, const char *alertMessage);

/**
 * This function gets two strings, which are
 * the input and output path file, and then,
 *  decompress the input file
 *
 * @param input file
 * @param output file
 */
void onDecompress(char *inputPathFile, char *outputPathFile);

#endif
