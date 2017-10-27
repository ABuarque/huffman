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
 * point and returns a string with the 
 * chars inside this range.
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
 * @return an array of bytes
 */
int* getBytesFrenquency(FILE* inputFile);

/**
 * It gets bytes frequency array to
 * build the tree and returns the tree.
 *
 * @param a bytes frequency array
 * @return a huffman tree
 */
HuffmanTree* buildHuffmanTree(int* bytesFrenquency);

/**
 * It gets a priority queue and helps
 * to build the huffman tree.
 *
 * @param a priority queue
 * @return a huffman tree
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
 * @param an integer
 */
void buildPathsHandler(byte** matrix, HuffmanTree* bt, byte *string, int position);

/**
 * It's a helpful function which handles the
 * process of writing bytes on file.
 *
 * @param a huffman tree
 * @param a file to write the tree in
 */
void setupTreeOnFileHandler(HuffmanTree *root, FILE *header);

/**
 * It starts the process writing the tree on file. It's 
 * done by getting the huffman tree and file to write.
 *
 * @param a huffman tree
 * @param a pointer to store size
 * @param a file to write
 */
void setupTreeOnFile(HuffmanTree *huffman, FILE *header);

/**
 * building....
 */
void writePaths(byte** tabela, FILE* arquivo, FILE* saida, int tree_size);

/**
 * It gets a byte and an integer,
 * sets the bit at the index and returns
 * the new byte.
 *
 * @param a byte
 * @param a bit position
 * @return a byte 
 */
byte setBitAt(byte c_saida, short int pos);

/**
 * It gets a Huffman tree and returns its size.
 *
 * @param a huffman tree
 * @return size
 */
int getTreeSize(HuffmanTree* tree);

/**
 * It helps to get the huffman tree.
 * 
 * @param a huffman tree
 * @param a poiter to store size
 */
void getSizeUtil(HuffmanTree* tree, int* sizePointer);


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

void writePaths(byte** tabela, FILE* arquivo, 
                            FILE* saida, int tree_size) {
    byte aux, character = 0;
    short int size = 0,position = 0;
    while((fscanf(arquivo,"%c",&aux)) != EOF) {
        position = 0;
        while(tabela[aux][position] != '\0') {
            if(size == 8){
                fprintf(saida,"%c",character);
                size = 0;
                character = 0;
            }
            if(tabela[aux][position] & 1)
                character = setBitAt(character,size);
            ++size;
            ++position;
        }
    }
    fprintf(saida,"%c",character); //bota ultimo char
    fseek(saida,0,SEEK_SET); //volta pro comeco
    byte lixo = (8 - size) << 5;
    //SETANDO O PRIMEIRO BYTE (BITS DO LIXO)
    lixo = lixo | tree_size >> 8;
    fprintf(saida, "%c", lixo);
    lixo = tree_size  & 255;
    fprintf(saida, "%c", lixo);
    return;
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
