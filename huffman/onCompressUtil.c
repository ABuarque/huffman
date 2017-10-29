#include "onCompressUtil.h"
#include "utils.h"
#include "PriorityQueue.h"
#include "HuffmanTree.h"
#include <stdlib.h>
#include <string.h>

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
void buildPathsHandler(byte** matrix, HuffmanTree* bt,
                           byte *string, int position) {
    if(bt->left == NULL && bt->right == NULL) { //a leave was found
        string[position] = '\0';
        strncpy(matrix[bt->treeByte], string, position + 1); //it copies (position + 1) chars of string to tabela[bt->treeByte]
        return;
    }
    if(bt->left != NULL) {
        string[position] = '0';
        buildPathsHandler(matrix, bt->left, string, position + 1);
    }
    if(bt->right != NULL) {
        string[position] = '1';
        buildPathsHandler(matrix, bt->right, string, position + 1);
    }
}

void setupTreeOnFile(HuffmanTree *huffman, FILE *header) {
    byte aux = 0;
    fprintf(header, "%c", aux);
    fprintf(header, "%c", aux);
    setupTreeOnFileHandler(huffman, header);
}

void setupTreeOnFileHandler(HuffmanTree *root, FILE *header) {
    if(root->left == NULL && root->right == NULL) {
        if(root->treeByte== '\\' || root->treeByte== '*') {
            byte aux = '\\';
            fprintf(header, "%c", aux);
        }
        fprintf(header, "%c", root->treeByte);
        return;
    }
    fprintf(header, "%c", root->treeByte);
    if(root->left != NULL)
        setupTreeOnFileHandler(root->left, header);
    if(root->right != NULL)
        setupTreeOnFileHandler(root->right, header);
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

void writePaths(byte** matrix, FILE* arquivo, 
                            FILE* saida, int tree_size) {
    byte aux, character = 0;
    short int size = 0,position = 0;
    while((fscanf(arquivo,"%c",&aux)) != EOF) {
        position = 0;
        while(matrix[aux][position] != '\0') {
            if(size == 8){
                fprintf(saida,"%c",character);
                size = 0;
                character = 0;
            }
            if(matrix[aux][position] & 1) //compare with last (1: odd, 0: even)
                character = setBitAt(character,size);
            ++size;
            ++position;
        }
    }
    fprintf(saida,"%c",character); //bota ultimo char
    fseek(saida,0,SEEK_SET); //volta pro comeco
    byte lixo = (8 - size) << 5; //putting 3 bits of trash on begining
    //checking which bits are been used on  first bute of size tree
    lixo = lixo | tree_size >> 8;
    fprintf(saida, "%c", lixo); //print the first byte
    lixo = tree_size  & 255; //checkin which bits are set on tree size
    fprintf(saida, "%c", lixo); //printing second header byte
    return;
}

byte setBitAt(byte c_saida, short int pos) {
    return (c_saida | (1<<(7-pos)));
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
