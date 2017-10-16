#include "HuffmanHandler.h"
#include "HuffmanTree.h"
#include "List.h"
#include "utils.h"
#include "PriorityQueue.h"
#include "fileManipulation.h"
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


/**********************************************************
			Contract's functions imeplementation
***********************************************************/
void compressFile(char *inputPathFile, 
		char *outputPathFile, const char *alertMessage) {
	FILE *inputFile = fopen(inputPathFile, "rb");
	//checking if correct type name was inserted
	while(inputFile == NULL) {
		printf("%s", alertMessage); //change it 
		scanf("%[^\n]", inputPathFile);
		getchar();
		DEBUG printf("%s\n", inputPathFile);
		inputFile = fopen(inputPathFile, "rb");
	}
	strcat(outputPathFile, ".huff");
	FILE *outputFile = fopen(outputPathFile, "wb");
	int bytesFrequencies[ASCII] = {0};
	bytesFrequency(inputFile, bytesFrequencies);
	//TODO build huffman tree and save it on file
	fclose(inputFile);
	fclose(outputFile);
}

void decompressFile(char *inputPathFile, char *outputPathFile) {
	DEBUG printf("INSIDE DECOMPRESS\n");
}

/**********************************************************
			Auxiliar functions implementation
**********************************************************/
