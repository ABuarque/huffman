#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include "utils.h"

typedef struct {
	byte scrap;
	byte treeSize;
} Header;

Header* newHeader(byte scrap, byte treeSize);

void destroyHeader(Header* header);

#endif
