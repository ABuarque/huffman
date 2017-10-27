#include "HuffmanHandler.h"
#include "HuffmanTree.h"
#include "List.h"
#include "utils.h"
#include "PriorityQueue.h"
#include "fileManipulation.h"
#include "onCompressUtil.h"
#include "onDecompressUtil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG if(1)

/**********************************************************
            Contract's functions implementation
***********************************************************/
void onCompress(char *inputPathFile, 
        char *outputPathFile, const char *alertMessage) {
    FILE* inputFile = fopen(inputPathFile, "rb");
    while(!inputFile) {
        printf("%s", alertMessage);
        scanf("%[^\n]", inputPathFile);
        getchar();
        DEBUG printf("%s\n", inputPathFile);
        inputFile = fopen(inputPathFile, "rb");
    }
    strcat(outputPathFile,VALID_EXTENSION);
    int* bytesFrenquency = getBytesFrenquency(inputFile);
    fseek(inputFile, 0, SEEK_SET); //because we've gone through the file, so get back to start
    HuffmanTree* tree = buildHuffmanTree(bytesFrenquency);
    byte** matrixPath = buildPaths(tree);
    FILE* outputFile = fopen(outputPathFile,"wb");
    int treeSize = getTreeSize(tree);
    //writeResources(scrap, sizeTree, Tree, Matrix);
    setupTreeOnFile(tree, outputFile);
    writePaths(matrixPath, inputFile, outputFile, treeSize);
    fclose(inputFile);
    fclose(outputFile); 
}

void onDecompress(char *inputPathFile, char *outputPathFile) {
    DEBUG printf("INSIDE DECOMPRESS\n");
    isValidFile(inputPathFile);
}
