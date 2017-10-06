#include "HuffmanApplication.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG if(1)

void huffmanApplication(int argumentsCounter, char* argmentsVector[]) {
	if(argumentsCounter == 4) {
		if(!strcmp(argmentsVector[1], DO_COMPRESS)) { //if flag is -comp
			DEBUG printf("dado -comp\n");
		} else if(!strcmp(argmentsVector[1], DO_DECOMPRESS)) { //if is -decomp
			DEBUG printf("dado -decomp\n");
		} else { //anything else
			printf("%s %s", LOG_ERROR, UNKNOW_ACTION_FLAG);
			exit(1);
		}
	} else {
		printf("%s %s", LOG_ERROR, BAD_ARGUMENTS);
		exit(1);
	}
}

