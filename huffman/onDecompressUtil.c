#include "utils.h"
#include "PriorityQueue.h"
#include "HuffmanTree.h"
#include <stdlib.h>
#include <string.h>

#define DEBUG if(0)

int foundLeaf(HuffmanTree* tree) {
    return (!tree->left) && (!tree->right);
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
    DEBUG printf("Given inputFileName: %s\n", inputFileName);
    int stringSize = strlen(inputFileName);
    char* extension = substring(inputFileName, stringSize - 5, stringSize);
    DEBUG printf("%s\n", extension);
    return strcmp(extension, VALID_EXTENSION) == 0;
}

int getTrash(byte firstByte) {
    return (firstByte >> 5); //clear all the first 5 bits and get 3 first
}

int retrieveTreeSize(byte firstByte, byte secondByte) {
    int size = firstByte & 0b00011111; //getting which bits of the 5 last ones are used
    size = size << 8; //left shifting found bits 
    size = size | secondByte; //comparing bits of second byte to see what should use
    return size;
}

void rewriteOriginal(HuffmanTree* tree, int trash, 
                    FILE* inputFile, FILE* outputFile) {
    byte currentByte;
    fscanf(inputFile, "%c", &currentByte);
    byte utilByte = currentByte;
    HuffmanTree* utilTree = tree; //prev tree node
    int i;
    while(fscanf(inputFile, "%c", &currentByte) != EOF) { //read a byte
        for(i = 7; i >= 0; i--) { //for each bit on read byte
            if(foundLeaf(utilTree)) { //if prev node is a leaf
                fprintf(outputFile,"%c", utilTree->treeByte); //print byte
                utilTree = tree; //prev tree = current
            }
            if(utilByte & 1<<i) //
                utilTree = utilTree->right;
            else
                utilTree = utilTree->left;
        }
        utilByte = currentByte;
    }
    for(i = 7; trash <= 8; trash++, i--) {
        if(foundLeaf(utilTree)) {
            fprintf(outputFile,"%c", utilTree->treeByte);
            utilTree = tree;
        }
        if(utilByte & 1<<i)
            utilTree = utilTree->right;
        else
            utilTree = utilTree->left;
    }
}

HuffmanTree* buildTreeFromFileUtil(FILE* inputFile) {
    int specialByte = 0;
    byte currentByte;
    fscanf(inputFile, "%c", &currentByte);
    if(currentByte != '*')
        specialByte = 1;
    if(currentByte == '\\') {
        fscanf(inputFile, "%c", &currentByte);
        specialByte = 1;
    }
    HuffmanTree* toReturn = newHuffmanTree(currentByte, 0);
    if(!specialByte) {
        toReturn->left = buildTreeFromFileUtil(inputFile);
        toReturn->right = buildTreeFromFileUtil(inputFile);
    }
    return toReturn;
}

HuffmanTree* buildTreeFromFile(FILE* inputFile, int sizeTree) {
    HuffmanTree* toReturn = NULL;
    if(sizeTree == 2) {
        byte currentByte;
        fscanf(inputFile, "%c", &currentByte);
        toReturn = newHuffmanTree(currentByte, 0);
        fscanf(inputFile, "%c", &currentByte);
        if(currentByte == '\\') 
            fscanf(inputFile, "%c", &currentByte);
        toReturn->left = newHuffmanTree(currentByte, 0);
    } else {
       toReturn = buildTreeFromFileUtil(inputFile);
    }
    return toReturn;
}
