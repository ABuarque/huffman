#include "HuffmanApplication.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void huffmanApplication(int argumentsCounter, char* argmentsVector[]) {
	if(argumentsCounter == 4) {

	} else {
		printf("%s %s", LOG_ERROR, BAD_ARGUMENTS);
		exit(1);
	}
}

