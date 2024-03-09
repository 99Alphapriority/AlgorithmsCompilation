#include<stdio.h>

void sort(int *a, int length)
{
	int i= 0, j= 0, key= 0;

	for(j=1; j<length; j++)
	{
		key = a[j];
		i = j-1;

		while((i>=0) && 
#ifdef ASC_ORDER
		(a[i] > key)
#elif DESC_ORDER
		(a[i] < key)
#endif
		)
		{
			a[i+1] = a[i];
			i--;
		}

		a[i+1] = key;
	}
}

int main()
{
	int a[6] = {5,2,4,6,3,1};
	int i = 0;

	fprintf(stderr,"Input array:\n");
	for(i = 0; i<6; i++)
		printf("%d\t",a[i]);
	printf("\n");

	sort(a, 6);

	fprintf(stderr,"Output array:\n");
	for(i = 0; i<6; i++)
		printf("%d\t",a[i]);
	printf("\n");

	return 0;
}
