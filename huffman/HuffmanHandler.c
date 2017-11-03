#include "HuffmanHandler.h"
#include "HuffmanTree.h"
#include "List.h"
#include "utils.h"
#include "PriorityQueue.h"
#include "onCompressUtil.h"
#include "onDecompressUtil.h"
#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG if(1)

/**********************************************************
            Contract's functions implementation
***********************************************************/
void onCompress(char *inputPathFile, 
        char *outputPathFile, const char *alertMessage) {
    FILE* inputFile = fopen(inputPathFile, "rb"); //opening inputfile
    while(!inputFile) { //if there's something wrong on opening...
        printf("%s", COLOR_RED);
        printf("%s", alertMessage); //say to user type name again
         printf("%s", COLOR_CYAN);
        scanf("%[^\n]", inputPathFile); //get given path
        getchar(); //clean buffer
        DEBUG printf("%s\n", inputPathFile); 
        inputFile = fopen(inputPathFile, "rb"); //try to open file again
    }
    int* bytesFrenquency = getBytesFrenquency(inputFile); //getting bytes frenquency
    fseek(inputFile, 0, SEEK_SET); //because we've gone through the file, so get back to start
    HuffmanTree* tree = buildHuffmanTree(bytesFrenquency); //building huffman tree
    byte** matrixPath = buildPaths(tree); //building the matrix that helps to handle bytes
    strcat(outputPathFile,VALID_EXTENSION); //appending .huff to given output name
    FILE* outputFile = fopen(outputPathFile,"wb"); //opening output file 
    int treeSize = getTreeSize(tree); //getting tree size
    Header* header = getHeaderInfo(matrixPath, treeSize, inputFile); //creating the header
    fseek(inputFile, 0, SEEK_SET); //because we've gone through the file, so get back to start
    writeSources(header, tree, matrixPath, outputFile, inputFile); //writes header, tree, and matrix
    fclose(inputFile);
    fclose(outputFile); 
}

void onDecompress(char* inputPathFile, char* outputPathFile,
             const char* alertMessage, const char* alertMessage1) {
    DEBUG printf("INSIDE DECOMPRESS\n");
    while(!isValidFile(inputPathFile)) {
        printf("%s", COLOR_RED);
        printf("%s", alertMessage1);
        printf("%s", COLOR_CYAN); 
        scanf("%[^\n]", inputPathFile);
        getchar();
        DEBUG printf("%s\n", inputPathFile);
    }
    FILE* inputFile = fopen(inputPathFile, "rb");
    while(!inputFile) {
        printf("%s", COLOR_RED);
        printf("%s", alertMessage);
        printf("%s", COLOR_CYAN);
        scanf("%[^\n]", inputPathFile);
        getchar();
        DEBUG printf("%s\n", inputPathFile);
        inputFile = fopen(inputPathFile, "rb");
    }
    //getting first byte
    byte firstByte;
    fscanf(inputFile, "%c", &firstByte);
    //getting trash
    int trash = getTrash(firstByte);
    //getting second byte
    byte secondByte;
    fscanf(inputFile, "%c", &secondByte);
    //get size tree
    int treeSize = retrieveTreeSize(firstByte, secondByte);
    //build tree from file
    HuffmanTree* tree = buildTreeFromFile(inputFile, treeSize);
    //creating output file
    FILE* outputFile = fopen(outputPathFile, "wb");
    rewriteOriginal(tree, trash, inputFile, outputFile);
    //rewrite the file
    fclose(inputFile);
    fclose(outputFile);
}
