#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define PARENT(i)		(i/2)
#define LEFTCHILD(i)	(2*i)
#define RIGHTCHILD(i)	(2*i) + 1

typedef struct heap{
	int *heapArray;
	int height;
	int numElements;
} heap_t;

typedef enum{
	INSERT,
	DELETE
} heap_op_et;

void compareHeapElements(int idx, int *heapArr, heap_op_et opType)
{
	int temp = 0;
	int cmpValue = 0;
	bool swapped = false;
	int i = 1;
	int nextLeaf = 0;

	if(INSERT == opType)
	{
		do
		{
			if(heapArr[PARENT(idx) - 1] < heapArr[idx - 1])
			{
				temp = heapArr[PARENT(idx) - 1];
				heapArr[PARENT(idx) - 1] = heapArr[idx - 1];
				heapArr[idx - 1] = temp;

				idx = PARENT(idx);
				temp = 0;
				swapped = true;
			}
		}while((1 < idx) && (swapped));
	}
	else if(DELETE == opType)
	{
		do
		{
			if(heapArr[LEFTCHILD(i)-1] > heapArr[RIGHTCHILD(i)-1])
			{
				cmpValue = heapArr[LEFTCHILD(i)-1];
				nextLeaf = i++;
			}
			else
			{
				cmpValue = heapArr[RIGHTCHILD(i)-1];
				nextLeaf = i + 2;
			}

			if(cmpValue > heapArr[i - 1])
			{
				temp = heapArr[i-1];
				heapArr[i-1] = cmpValue;
				heapArr[nextLeaf - 1] = temp;
				swapped = true;
				i = nextLeaf;
			}

		}while((i > idx) && (swapped));
		
	}
}

int deleteHeap(heap_t *heap_p)
{
	assert(NULL != heap_p);

	int temp = 0;
	int arrSize = 0;
	printf("deleteHeap1\n");
	int idx = heap_p->numElements - 1;
	
	printf("deleteHeap\n");
	for(;idx<= 0; idx--)
	{
	printf("deleteHeap\n");
		temp = heap_p->heapArray[0];
		heap_p->heapArray[0] = heap_p->heapArray[idx];
		heap_p->heapArray[idx] = temp;
		heap_p->numElements--;
		arrSize++;
		
		if(idx > 0)
		{
			compareHeapElements(heap_p->numElements, heap_p->heapArray, DELETE);
		}
	}

	return arrSize;;
}

void insertHeap(int *arr, int arrSize, heap_t *heap_p)
{
	int idx = 0;

	for(; idx < arrSize; idx++)
	{
		heap_p->heapArray[idx] = arr[idx];

		if(0 < idx)
		{
			compareHeapElements(idx + 1, heap_p->heapArray, INSERT);
		}

		heap_p->numElements++;
	}

	//compute heap height
}

void createHeap(int *arr, int arrSize, heap_t *heap_p)
{
	heap_p = (heap_t*)malloc(sizeof(heap_t));
	assert(NULL != heap_p);
printf("heap_p addr: 0x%x\n",heap_p);
	heap_p->heapArray = (int*)malloc(sizeof(int)*(arrSize));
	assert(NULL != heap_p->heapArray);

	heap_p->numElements = 0;

	insertHeap(arr, arrSize, heap_p);

	assert(heap_p->numElements == arrSize);

	for(int idx = 0; idx < arrSize; idx++)
		printf("%d\t",heap_p->heapArray[idx]);
	printf("\nheap elements = %d\n",heap_p->numElements);
printf("heap_p addr: 0x%x\n",heap_p);
}

int main()
{
	int arr[5] = {10,20,15,30,40};
	int arrSize = 0;

	heap_t *heap_p = NULL;
	createHeap(arr, 5, heap_p);
printf("heap_p addr: 0x%x\n",heap_p);
	arrSize = deleteHeap(heap_p);

	for(int idx = 0; idx < arrSize; idx++)
		printf("%d\t",heap_p->heapArray[idx]);
	printf("\n non heap elements = %d\n",heap_p->numElements);

	return 0;
}
