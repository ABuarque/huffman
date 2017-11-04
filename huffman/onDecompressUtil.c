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
 * It's a helpfull function to build the tree using an
 * array with bytes and the tree size.
 * An iterator will iterate through the bytes array checking
 * chars inside of it and will put them propperly on the tree.
 * 
 * @param tree bytes array
 * @param tree size
 * @param an integer to iterate through the array
 * @param a HuffmanTree object handle
 * @return a huffam tree
 */
HuffmanTree* reassemblyHuffmanTreeHandler(byte* treeBytes, int size,
                                 int* utilIterator, HuffmanTree* node) {
    if(*utilIterator < size) {
        if(treeBytes[*utilIterator] == '\\') {
            node->treeByte = treeBytes[++*(utilIterator)];
            ++*(utilIterator);
            node->left = node->right = NULL;
            return node;
        } else if (treeBytes[*utilIterator] != '*') {
            node->treeByte = treeBytes[*utilIterator];
            ++*(utilIterator);
            node->left = node->right = NULL;
            return node;
        } else {
            node->treeByte = treeBytes[*utilIterator];
            ++*(utilIterator);
            node->left = reassemblyHuffmanTreeHandler(treeBytes, size, utilIterator, newHuffmanHandle());
            node->right = reassemblyHuffmanTreeHandler(treeBytes, size, utilIterator, newHuffmanHandle());
            return node;
        }
    }
    return NULL;
}

/**
 * It gets a byte and an integer which is the bit index
 * and check if this bit is set or not.
 * 
 * @param a byte
 * @param bit index
 * @return 1 if is set, 0 if not
 */
int isBitSetAt(byte currentByte, int bitIndex) {
    return currentByte & (1 << bitIndex);
}

/**********************************************************
            Contract's functions implementation
***********************************************************/
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
            if(isBitSetAt(utilByte, i)) //
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
        if(isBitSetAt(utilByte, i))
            utilTree = utilTree->right;
        else
            utilTree = utilTree->left;
    }
}

byte* huffmanTreeBytes(FILE* inputFile, int treeSize) {
	byte* treeBytes = (byte*) malloc(sizeof(byte) * (treeSize + 1));
	int i;
    byte currentByte;
	for(i = 0; i < treeSize; i++) {
        fread(&currentByte, 1, 1, inputFile);
        treeBytes[i] = currentByte;
    }
    treeBytes[i] = '\0';
    return treeBytes;
}

HuffmanTree* reassemblyHuffmanTree(byte* treeBytes, int sizeTree) {
    int utilIterator = 0;
    return reassemblyHuffmanTreeHandler(treeBytes, sizeTree, &utilIterator, newHuffmanHandle());
}
