#include "utils.h"
#include "PriorityQueue.h"
#include "HuffmanTree.h"
#include <stdlib.h>
#include <string.h>

#define DEBUG if(0)

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

int getScrap(byte firstByte) {
    return (firstByte >> 5);
}

int getTreeSize(byte firstByte, byte secondByte) {
    int size = firstByte & 0b00011111; //getting which bits of the 5 last ones are used
    size = size << 8; //left shifting found bits 
    size = size | secondByte; 
    return size;
}