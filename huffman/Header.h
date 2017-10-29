#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include "utils.h"

typedef struct {
	byte scrap;
	byte treeSize;
} Header;

/**
 * It gets scrap and size of tree
 * and returns a struct with these values.
 * 
 * @param scrap
 * @param tree size
 * @return Header object
 */
Header* newHeader(byte scrap, byte treeSize);

/**
 * It gets a header object and destroys it.
 * 
 * @param header object
 */
void destroyHeader(Header* header);

#endif
