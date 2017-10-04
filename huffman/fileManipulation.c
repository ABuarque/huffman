#include "fileManipulation.h"
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
			Contract's functions imeplementation
***********************************************************/

 
void charsFrequency(FILE *file, int *freq) {
	int chIndex;
	while((chIndex = fgetc(file)) != EOF) freq[chIndex]++;
}

void printFreq(int *freq) {
	int i;
	for(i = 0; i < ASCII_TABLE; i++) {
		if(freq[i] > 0) {
			if(!isprint(i) || isspace(i))
				printf("%d instances of character %x\n", freq[i], (unsigned) i); // This here is for nonPrintable Characters
			else 
				printf("%d instances of character '%c'\n", freq[i], i);
		}
	}
}




/**********************************************************
			Auxiliar functions imeplementation
**********************************************************/

