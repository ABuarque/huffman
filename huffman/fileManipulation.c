#include "fileManipulation.h"
#include "utils.h"
#include <stdlib.h>
#include <ctype.h>

#define DEBUG if(0)

/****************************************************
				Auxiliar functions
	Client programmer doesn't need to take care
about them, due to that, they've been separated from
the interface.
*****************************************************/


/**********************************************************
			Contract's functions implementation
***********************************************************/

 
void bytesFrequency(FILE *file, int *bytesFrequency) {

	byte byteIndex;

	while(fread(&byteIndex, 1, 1, file) > 0) {
		bytesFrequency[(byte) byteIndex]++;
	}

	rewind(file);
}

/**********************************************************
			Auxiliar functions implementation
**********************************************************/

