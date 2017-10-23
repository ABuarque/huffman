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
 * It gets bytes frequency array to
 * build the tree and returns it.
 *
 * @param a bytes frequency array
 * @return a huffman tree
 */
HuffmanTree* buildHuffmanTree(int* bytesFrenquency);

/**
 * It gets a priority queue and help
 * to build huffman tree.
 *
 * @param a priority queue
 * @returna  huffman tree
 */
HuffmanTree* buildTreeFromQueue(PriorityQueue *pq);

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
 * @param a integer
 */
void buildPathsHandler(byte** tabela, HuffmanTree* bt, byte *string, int position);

/**
 * It's a helpfull function which handles process
 * of writing bytes on file.
 *
 * @param a huffman tree
 * @param a pointer to store tree size
 * @param a file too write the tree 
 */
void setupTreeOnFileHandler(HuffmanTree *root, int *size, FILE *header);


/**
 * It starts the process writing the tree on file. It's 
 * done by getting the huffman tree and file to write.
 *
 * @param a huffman tree
 * @param a pointer to store size
 * @param a file to write
 */
void setupTreeOnFile(HuffmanTree *huffman, int* treeSize, FILE *header);


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

HuffmanTree* buildHuffmanTree(int* bytesFrenquency) {
    PriorityQueue *queue = newPriorityQueue();
    int i;
    for(i = 0; i < ASCII; i++)
        if(bytesFrenquency[i])
            enqueue(queue, newHuffmanTree(i, bytesFrenquency[i]));
    return buildTreeFromQueue(queue);
}

byte** buildPaths(HuffmanTree* tree) {
    byte** paths = malloc(sizeof(byte*) * ASCII);
    int i;
    for(i = 0; i < ASCII; i++)
        paths[i] = malloc(sizeof(byte) * ASCII);
    byte arrayUtil[ASCII] = {0};
    buildPathsHandler(paths, tree, arrayUtil, 0);
    return paths;
}

/**
 * It's backtracking and string bytes array
 * is auxiliar and helps the backtracking process
 */
void buildPathsHandler(byte** tabela, HuffmanTree* bt,
                           byte *string, int position) {
    if(bt->left == NULL && bt->right == NULL) { //a leave was found
        string[position] = '\0';
        strncpy(tabela[bt->treeByte], string, position + 1); //it copies (position + 1) chars of string to tabela[bt->treeByte]
        return;
    }
    if(bt->left != NULL) {
        string[position] = '0';
        buildPathsHandler(tabela, bt->left, string, position + 1);
    }
    if(bt->right != NULL) {
        string[position] = '1';
        buildPathsHandler(tabela, bt->right, string, position + 1);
    }
}

void setupTreeOnFile(HuffmanTree *huffman, int* treeSize, FILE *header) {
    byte aux = 0;
    (*treeSize) = 0;
    fprintf(header, "%c", aux);
    fprintf(header, "%c", aux);
    setupTreeOnFileHandler(huffman, treeSize, header);
}

void setupTreeOnFileHandler(HuffmanTree *root, int *size, FILE *header) {
    if(root->left == NULL && root->right == NULL) {
        if(root->treeByte== '\\' || root->treeByte== '*') {
            byte aux = '\\';
            (*size)++;
            fprintf(header, "%c", aux);
        }
        (*size)++;
        fprintf(header, "%c", root->treeByte);
        return ;
    }
    (*size)++;
    fprintf(header, "%c", root->treeByte);
    if(root->left != NULL)
        setupTreeOnFileHandler(root->left, size, header);
    if(root->right != NULL)
        setupTreeOnFileHandler(root->right, size, header);
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
