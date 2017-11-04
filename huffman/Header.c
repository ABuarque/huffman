#include "Header.h"
#include <stdlib.h>

Header* newHeader(byte trash, byte treeSize) {
	Header* header = (Header*) malloc(sizeof(Header));
	header->trash = trash;
	header->treeSize = treeSize;
	return header;
}

void destroyHeader(Header* header) {
	free(header);
}
