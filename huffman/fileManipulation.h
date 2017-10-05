#ifndef FILEMANIPULATION_H
#define FILEMANIPULATION_H

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define ASCII_TABLE 256

/**
 * The way this works is that we take advantage of the position of
 * each char in the ASCII table , and use it as the index for a array of ints.
 * this function takes a empty array of ints and fills it with the frequency
 * of the chars in the read file.
 * Ex: freq[97] = 3;
 *		This would mean that there is 3 'a' characters in the read file.
 *
 * @param a pointer to a file to be read
 * @param a array to receive the frequency of each char contained in the opened file.
 */
void charsFrequency(FILE *file, int *freq);

/**
 * It gets a array with the frequency of all ASCII table chars and prints it
 * unprintable characters are printed with the help of the ctype lib and do not come between ' '.
 *
 * @param a array of ints
 */
void printFreq(int *freq);

#endif