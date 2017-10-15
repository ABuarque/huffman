#ifndef FILEMANIPULATION_H
#define FILEMANIPULATION_H

#include <stdlib.h>
#include <stdio.h>

/**
 * The way this works is that we take advantage of the position of
 * each char in the ASCII table , and use it as the index for a array of ints.
 * this function takes a empty array of ints and fills it with the frequency
 * of the bytes in the read file.
 *
 * @param a pointer to a file to be read
 * @param a array to receive the frequency of each byte contained in the opened file.
 */
void bytesFrequency(FILE *file, int *freq);

#endif