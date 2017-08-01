#include <stdio.h>
#include <stdlib.h>

void aplyHuffmand(char* filePath) {
	printf("%s\n", filePath);
}

int main(int argc, char* argv[]) 
{
	if(argc >= 2) {
		aplyHuffmand(argv[1]);
		return 0;
	} else {
		printf("Missing args!\nFinished with error!\n");
		exit(1);
	}
}
