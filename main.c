#include <stdio.h>
#include <stdlib.h>

void applyHuffmand(char* filePath) {
	printf("%s\n", filePath);
}

int main(int argc, char* argv[]) 
{
	if(argc >= 2) {
		applyHuffmand(argv[1]);
		return 0;
	} else {
		printf("Missing args!\nFinished with error!\n");
		exit(1);
	}
}
