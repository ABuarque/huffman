#include "onCompressUtil.h"
#include "utils.h"
#include "PriorityQueue.h"
#include "HuffmanTree.h"
#include <stdlib.h>
#include <string.h>

#define DEBUG if(0)

/****************************************************
                Auxiliar functions
    Client programmer doesn't need to take care
about them, due to that, they've been separated from
the interface.
*****************************************************/

/**
 * It gets a Huffman tree node and
 * checks if its left and right subtree
 * are NULL;
 *
 * @param a huffman tree
 * @return 1 if is leaf, 0 if not
 */
int isLeaf(HuffmanTree* tree) {
    return (!tree->left) && (!tree->right);
}

/**********************************************************
            Contract's functions implementation
***********************************************************/
int* getBytesFrequency(FILE* inputFile) {
    int* frequencies = (int*) calloc(ASCII, sizeof(int));
    byte currentByte;  
    while((fscanf(inputFile, "%c", &currentByte)) != EOF)
        frequencies[currentByte]++;
    return frequencies;
}

HuffmanTree* buildTreeFromQueue(PriorityQueue *queue) {
    HuffmanTree *thisTree;
    int run = 1;
    while(run) {
        byte markByte = '*';
        thisTree = newHuffmanTree(sizeof(byte), &markByte, 0);
        thisTree->left = dequeue(queue);
        if(thisTree->left != NULL)
            thisTree->frequency += thisTree->left->frequency;
        thisTree->right = dequeue(queue);
        if(thisTree->right != NULL) 
            thisTree->frequency += thisTree->right->frequency;
        if(isEmpty(queue))
            run = 0;
        enqueue(queue, thisTree);
    }
    return thisTree;
}

HuffmanTree* buildHuffmanTree(int* bytesFrequency) {
    PriorityQueue *queue = newPriorityQueue();
    int i;
    for(i = 0; i < ASCII; i++)
        if(bytesFrequency[i])
            enqueue(queue, newHuffmanTree(sizeof(byte), &i, bytesFrequency[i]));
    return buildTreeFromQueue(queue);
}

byte** buildPaths(HuffmanTree* tree) {
    byte** paths = malloc(sizeof(byte*) * ASCII);
    int i;
    for(i = 0; i < ASCII; i++)
        paths[i] = calloc(ASCII, sizeof(byte));
    byte arrayUtil[ASCII] = {0};
    buildPathsHandler(paths, tree, arrayUtil, 0);
    return paths;
}

/**
 * It's backtracking and the bytes array
 * is auxiliar and helps the backtracking process
 */
void buildPathsHandler(byte** matrix, HuffmanTree* tree,
                                 byte *utilArray, int position) {
    if(isLeaf(tree)) { //a leaf was found
        utilArray[position] = '\0';
        strncpy(matrix[*(byte*)(tree->treeByte)], utilArray, position + 1); //it copies (position + 1) chars of string to tabela[bt->treeByte]
        return;
    }
    if(tree->left != NULL) {
        utilArray[position] = '0';
        buildPathsHandler(matrix, tree->left, utilArray, position + 1);
    }
    if(tree->right != NULL) {
        utilArray[position] = '1';
        buildPathsHandler(matrix, tree->right, utilArray, position + 1);
    }
}

void writeTree(HuffmanTree *tree, FILE *outputFile) {
    if(isLeaf(tree)) {
        if(*(byte*)(tree->treeByte) == '*' || *(byte*)(tree->treeByte) == '\\') {
            byte aux = '\\';
            fprintf(outputFile, "%c", aux);
        }
        fprintf(outputFile, "%c", *(byte*)(tree->treeByte));
        return;
    }
    fprintf(outputFile, "%c", *(byte*)(tree->treeByte));
    if(tree->left != NULL)
        writeTree(tree->left, outputFile);
    if(tree->right != NULL)
        writeTree(tree->right, outputFile);
}

int getTreeSize(HuffmanTree* tree) {
    int size = 0;
    getSizeUtil(tree, &size);
    return size;
}

void getSizeUtil(HuffmanTree* tree, int* sizePointer) {
    if(isLeaf(tree)) {
        if(*(byte*)(tree->treeByte) == '\\' || *(byte*)(tree->treeByte) == '*')
            (*sizePointer)++;
        (*sizePointer)++;
        return;
    }
    (*sizePointer)++;
    if(tree->left != NULL)
        getSizeUtil(tree->left, sizePointer);
    if(tree->right != NULL)
        getSizeUtil(tree->right, sizePointer);
}

void writePaths(byte** matrix, FILE* inputFile, FILE* outputFile) {
    byte aux, character = 0;
    short int size = 0,position = 0;
    while((fscanf(inputFile,"%c",&aux)) != EOF) {
        position = 0;
        while(matrix[aux][position] != '\0') {
            if(size == 8){
                fprintf(outputFile,"%c",character);
                size = 0;
                character = 0;
            }
            if(matrix[aux][position] & 1) //compare with last (1: odd, 0: even)
                character = setBitAt(character,size);
            size++;
            position++;
        }
    }
    fprintf(outputFile,"%c",character); 
}

byte setBitAt(byte currentByte, short int pos) {
    return (currentByte | (1 << (7 - pos)));
}

Header* getHeaderInfo(byte** matrix, int treeSize, 
                FILE* inputFile) {
    byte inputByte, byteToWrite = 0;
    short int size = 0, bitIndex = 0;
    while((fscanf(inputFile,"%c",&inputByte)) != EOF) {
        bitIndex = 0;
        while(matrix[inputByte][bitIndex] != '\0') {
            if(size == 8)
                size = byteToWrite = 0;
            if(matrix[inputByte][bitIndex] & 1) //compare with last (1: odd, 0: even)
                byteToWrite = setBitAt(byteToWrite,size);
            size++;
            bitIndex++;
        }
    }
    byte trash = (8 - size) << 5; //putting 3 bits of trash on begining
    //checking which bits are been used on  first byte of size tree
    trash |= treeSize >> 8;
    byte tree = treeSize  & 255; //checking which bits are set on tree size
    return newHeader(trash, tree);
}

void writeSources(Header* header, HuffmanTree* tree, 
            byte** matrix, FILE* outputFile, FILE* inputFile) {
    fprintf(outputFile, "%c", header->trash); //printing scrap
    fprintf(outputFile, "%c", header->treeSize); //printing tree size
    writeTree(tree, outputFile); //printing tree
    writePaths(matrix, inputFile, outputFile); //printing matrix
}
