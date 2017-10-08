#ifndef HUFFMANHANDLER_H
#define HUFFMANHANDLER_H

#include "HuffmanTree.h"
#include "List.h"
#include "utils.h"
#include "PriorityQueue.h"
#include <stdio.h>
#include <stdlib.h>

/****************************************************
 This source file actually handles Huffman'a algorithm.
 It calls the necessary data structures and aply the 
 below processes: 

-> get byte frequency
-> build huffman tree
-> destroy huffman tree
-> compress
-> decrompress
*****************************************************/

/**
 * This function gets two strings, whose are
 * the input and output path file, and them
 * apply Huffman`s algorithm to compress file.
 *
 * @param input file
 * @param output file
 */
void compressFile(char *inputPathFile, char *outputPathFile);

/**
 * This function gets two strings, whose are
 * the input and output path file, and them
 * apply decompress the input file
 *
 * @param input file
 * @param output file
 */
void decompressFile(char *inputPathFile, char *outputPathFile);

#endif
