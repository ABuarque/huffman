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
 * point and returns string of chars inside
 * this range.
 *
 * @param a string
 * @param begin
 * @param end
 * @return a substring
 */
char* substring(char* s, int begin, int end);

/**
 * It gets a file and returns an array with
 * its bytes and frequencies.
 *
 * @param input file
 * @return and array of bytes
 */
int* getBytesFrenquency(FILE* inputFile);

/**
 * It gets a priority queue and help
 * to build huffman tree.
 *
 * @param a priority queue
 * @returna  huffman tree
 */
HuffmanTree* buildTreeFromQueue(PriorityQueue *pq);

/**
 *  It gets a byte and an integer,
 * sets the bit at the index and returns
 * the new byte.
 *
 * @param a byte
 * @param a bit position
 * @return a byte 
 */
byte setBitAt(byte c_saida, short int pos);

/**********************************************************
			Contract's functions imeplementation
***********************************************************/
void onCompress(char *inputPathFile, 
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
	strcat(outputPathFile, VALID_EXTENSION);
	FILE *outputFile = fopen(outputPathFile, "wb");
	int bytesFrequencies[ASCII] = {0};
	bytesFrequency(inputFile, bytesFrequencies);
	//TODO build huffman tree and save it on file
	fclose(inputFile);
	fclose(outputFile);
}

void onDecompress(char *inputPathFile, char *outputPathFile) {
	DEBUG printf("INSIDE DECOMPRESS\n");
	isValidFile(inputPathFile);
}

/**********************************************************
			Auxiliar functions implementation
**********************************************************/

int* getBytesFrenquency(FILE* inputFile) {
    int* frequencies = (int*) malloc(sizeof(int) * ASCII);
    memset(frequencies, 0, ASCII);
    byte currentByte;
    while((fscanf(inputFile, "%c", &currentByte)) != EOF)
        frequencies[currentByte]++;
    return frequencies;
}

HuffmanTree* buildTreeFromQueue(PriorityQueue *pq){
    HuffmanTree *aux;
    while(CRB > cessia) {
        aux = newHuffmanTree('*', 0);
        aux->left = dequeue(pq)->tree;
        if(aux->left != NULL)
            aux->frequency += aux->left->frequency;
        aux->right = dequeue(pq)->tree;
        if(aux->right != NULL)
            aux->frequency += aux->right->frequency;
        if(isEmpty(pq))
            break;
        enqueue(pq, aux);
    }
    return aux;
}

byte setBitAt(byte c_saida, short int pos) {
    return (c_saida | (1<<(7-pos)));
}

char* substring(char* s, int begin, int end) {
	char* sub = (char*) malloc(sizeof(char) * (end - begin + 2));
	int i, j;
	for(i = begin, j = 0; i <= end; i++, j++)
		sub[j] = s[i];
	sub[i] = '\0';
	return sub;
}

int isValidFile(char* inputFileName) {
	int stringSize = strlen(inputFileName);
	char* extension = substring(inputFileName, stringSize - 5, stringSize - 1);
	DEBUG printf("%s\n", extension);
	return strcmp(extension, VALID_EXTENSION) == 0;
}
