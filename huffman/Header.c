#include "Header.h"
#include <stdlib.h>

Header* newHeader(byte scrap, byte treeSize) {
	Header* header = (Header*) malloc(sizeof(Header));
	header->scrap = scrap;
	header->treeSize = treeSize;
	return header;
}

void destroyHeader(Header* header) {
	free(header);
}
