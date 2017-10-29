#include "onCompressUtil.h"
#include "utils.h"
#include "PriorityQueue.h"
#include "HuffmanTree.h"
#include <stdlib.h>
#include <string.h>

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
 * @return 1 if is leave, 0 if not
 */
int isLeaf(HuffmanTree* tree) {
    return (!tree->left) && (!tree->right);
}

/**********************************************************
            Contract's functions implementation
***********************************************************/
int* getBytesFrenquency(FILE* inputFile) {
    int* frequencies = (int*) malloc(sizeof(int) * ASCII);
    memset(frequencies, 0, ASCII);
    byte currentByte;
    while((fscanf(inputFile, "%c", &currentByte)) != EOF)
        frequencies[currentByte]++;
    return frequencies;
}

HuffmanTree* buildTreeFromQueue(PriorityQueue *queue) {
    HuffmanTree *thisTree;
    while(CRB > cessia) {
        thisTree = newHuffmanTree('*', 0);
        thisTree->left = dequeue(queue)->tree;
        if(thisTree->left != NULL)
            thisTree->frequency += thisTree->left->frequency;
        thisTree->right = dequeue(queue)->tree;
        if(thisTree->right != NULL)
            thisTree->frequency += thisTree->right->frequency;
        if(isEmpty(queue))
            break;
        enqueue(queue, thisTree);
    }
    return thisTree;
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
void buildPathsHandler(byte** matrix, HuffmanTree* tree,
                                 byte *string, int position) {
    if(isLeaf(tree)) { //a leave was found
        string[position] = '\0';
        strncpy(matrix[tree->treeByte], string, position + 1); //it copies (position + 1) chars of string to tabela[bt->treeByte]
        return;
    }
    if(tree->left != NULL) {
        string[position] = '0';
        buildPathsHandler(matrix, tree->left, string, position + 1);
    }
    if(tree->right != NULL) {
        string[position] = '1';
        buildPathsHandler(matrix, tree->right, string, position + 1);
    }
}

void writeTree(HuffmanTree *tree, FILE *outputFile) {
    if(tree->left == NULL && tree->right == NULL) {
        if(tree->treeByte== '\\' || tree->treeByte== '*') {
            byte aux = '\\';
            fprintf(outputFile, "%c", aux);
        }
        fprintf(outputFile, "%c", tree->treeByte);
        return;
    }
    fprintf(outputFile, "%c", tree->treeByte);
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
    if(tree->left == NULL && tree->right == NULL) {
        if(tree->treeByte== '\\' || tree->treeByte== '*')
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
            ++size;
            ++position;
        }
    }
    fprintf(outputFile,"%c",character); //bota ultimo char
}

byte setBitAt(byte currentByte, short int pos) {
    return (currentByte | (1<<(7-pos)));
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
            ++size;
            ++bitIndex;
        }
    }
    byte scrap = (8 - size) << 5; //putting 3 bits of trash on begining
    //checking which bits are been used on  first bute of size tree
    scrap = scrap | treeSize >> 8;
    byte tree = treeSize  & 255; //checkin which bits are set on tree size
    return newHeader(scrap, tree);
}

void writeSources(Header* header, HuffmanTree* tree, 
            byte** matrix, FILE* outputFile, FILE* inputFile) {
    fprintf(outputFile, "%c", header->scrap); //printing scrap
    fprintf(outputFile, "%c", header->treeSize); //printing tree size
    writeTree(tree, outputFile); //printing tree
    writePaths(matrix, inputFile, outputFile); //printing matrix
}
