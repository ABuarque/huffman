#include "HuffmanHandler.h"
#include "HuffmanTree.h"
#include "List.h"
#include "utils.h"
#include "PriorityQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG if(1)

/****************************************************
				Auxiliar functions
	Client programmer doesn't need to take care
about them, due to that, they've been separated from
the interface.
*****************************************************/

/**
 * It gets a file and returns an array
 * with bytes frequency;
 *
 * @param a file reference
 * @return an array of frequencies
 */
int *getBytesFrequency(FILE *fileReference);

/**********************************************************
			Contract's functions imeplementation
***********************************************************/
void compressFile(char *inputPathFile, 
		char *outputPathFile, const char *alertMessage) {
	FILE *inputFile = fopen(inputPathFile, "r");
	//checking if correct type name was inserted
	while(inputFile == NULL) {
		printf("%s", alertMessage); //change it 
		scanf("%[^\n]", inputPathFile);
		getchar();
		DEBUG printf("%s\n", inputPathFile);
		inputFile = fopen(inputPathFile, "r");
	}
	strcat(outputPathFile, ".huff");
	FILE *outputFile = fopen(outputPathFile, "wb");
	int *bytesFrequencies = getBytesFrequencies(inputFile);
	//TODO build huffman tree and save it on file
	fclose(inputFile);
	fclose(outputFile);
}

void decompressFile(char *inputPathFile, char *outputPathFile) {
	DEBUG printf("INSIDE DECOMPRESS\n");
}

/**********************************************************
			Auxiliar functions imeplementation
**********************************************************/
int *getBytesFrequency(FILE *fileReference) { 
	int *frequencies = malloc(sizeof(int) * 256);
	memset(frequencies, 0, sizeof(frequencies));
	int i;
	byte b;
	while(fscanf(fileReference, "%c", &b) != EOF)
		frequencies[b]++;
	return frequencies;
}
