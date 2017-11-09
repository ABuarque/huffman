#include <stdio.h>
#include <stdlib.h>
#include "HeapedPriorityQueue.h"
#include "PriorityQueue.h"
#include <time.h>

int main()
{
	const int TEST_MAX = 2000;
	int i;
	FILE *hpqFile;
	FILE *pqFile;
	srand(time(NULL));

	hpqFile = fopen("heap_priority_queue.csv","wb");
	pqFile = fopen("priority_queue.csv","wb");
	fprintf(pqFile, "quantity,comparison\n");
	fprintf(hpqFile, "quantity,comparison\n");

	HeapedPriorityQueue *hpq = newHeapedPriorityQueue(sizeof(int));
	PriorityQueue *pq = createPriorityQueue(sizeof(int));
	printf("Alimentando...\n");

	for(i = 0;i<TEST_MAX;i++)
	{
		int randValue = rand()%TEST_MAX;
		int hpqComparison = 0, pqComparison = 0;

		enqueueHPQ(hpq, &randValue, &hpqComparison);
		enqueue(pq,&randValue,randValue, &pqComparison);

		fprintf(pqFile, "%d,%d\n", i+1,pqComparison);
		fprintf(hpqFile, "%d,%d\n", i+1,hpqComparison);
	}

	printf("Arquivos gerados com sucesso!\n");

	fclose (pqFile);
	fclose(hpqFile);

	return 0;
}
