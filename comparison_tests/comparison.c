#include <stdio.h>
#include <stdlib.h>
#include "HeapedPriorityQueue.h"
#include "PriorityQueue.h"
#include <time.h>

int main()
{
	int i;
	FILE *hpqFile;
	FILE *pqFile;
	srand(time(NULL));

	hpqFile = fopen("heap_priority_queue.csv","wb");
	pqFile = fopen("priority_queue.csv","wb");

	HeapedPriorityQueue *hpq = newHeapedPriorityQueue(sizeof(int));
	PriorityQueue *pq = createPriorityQueue(sizeof(int));
	printf("Alimentando...\n");

	for(i = 0;i<MAX;i++)
	{
		int randValue = rand()%MAX;
		int hpqComparison = 0, pqComparison = 0;

		clock_t beginHeap, endHeap, begin, end;
		
		beginHeap = clock();
		enqueueHPQ(hpq, &randValue, &hpqComparison);
		endHeap = clock();

		double timeSpentHeap = (double)(endHeap - beginHeap) / CLOCKS_PER_SEC;

		begin = clock();
		enqueue(pq,&randValue,randValue, &pqComparison);
		end = clock();

		double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;

		//stop time
		if(!(i%10000)){
			printf("Testando sem heap... Número %d\n",randValue);
			printf("Tempo gasto na inserção: %lf\n", timeSpent);
			printf("Comparações realizadas: %d\n", pqComparison);
			fprintf(pqFile, "%lf,%d\n", timeSpent,pqComparison);

			printf("Testando com heap... Número %d\n",randValue);
			printf("Tempo gasto na inserção: %lf\n", timeSpentHeap);
			printf("Comparações realizadas: %d\n\n", hpqComparison);
			fprintf(hpqFile, "%lf,%d\n", timeSpentHeap,hpqComparison);
		}
		
	}

	fclose (pqFile);
	fclose(hpqFile);
	
	destroyHeapedPriorityQueue(hpq);
	destroyPriorityQueue(pq);
	return 0;
}
