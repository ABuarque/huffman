#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include "utils.h"

typedef struct {
	byte trash;
	byte treeSize;
} Header;

/**
 * It gets trash and size of tree
 * and returns a struct with these values.
 * 
 * @param trash
 * @param tree size
 * @return Header object
 */
Header* newHeader(byte trash, byte treeSize);

/**
 * It gets a header object and destroys it.
 * 
 * @param header object
 */
void destroyHeader(Header* header);

#endif
