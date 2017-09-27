#include <stdio.h>
#include <stdlib.h>
#include "HeapedPriorityQueue.h"
#include "PriorityQueue.h"
#include <time.h>

int main()
{
	srand(time(NULL));
	HeapedPriorityQueue *hpq = newHeapedPriorityQueue(sizeof(int));
	PriorityQueue *pq = createPriorityQueue(sizeof(int));
	printf("Alimentando...\n");
	int i;
	for(i = 0;i<MAX;i++)
	{
		int randValue = rand()%MAX;
		int hpqComparison = 0, pqComparison = 0;
		clock_t begin = clock();
		//enqueueHPQ(hpq, &randValue, &hpqComparison);
		clock_t end = clock();
		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		begin = clock();
		enqueue(pq,&randValue,randValue, &pqComparison);
		end = clock();
		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		//stop time
		if(!(i%1000)){
			printf("Testando sem heap... Número %d\n",i);
			
		}
		
	}
	
	
	destroyHeapedPriorityQueue(hpq);
	destroyPriorityQueue(pq);
	return 0;
}
