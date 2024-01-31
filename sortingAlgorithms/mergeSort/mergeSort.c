#include<stdio.h>
#include<stdlib.h>

void merge(int *arr, int l, int m, int h)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = h - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
#ifdef ASC_ORDER
            arr[k] = L[i];
			i++;
#elif DESC_ORDER
			arr[k] = R[j];
			j++;
#endif
        }
        else {
#ifdef ASC_ORDER
            arr[k] = R[j];
            j++;
#elif DESC_ORDER
			arr[k] = L[i];
			i++;
#endif
        }
        k++;
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int *a, int low, int high)
{
	if(low<high)
	{
		int mid = (low + (high-1))/2;

		mergeSort(a, low, mid);
		mergeSort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}

int main()
{
	int a[8] = {200,41,52,26,38,57,9,49};
	int idx = 0;
	
	printf("Input array:\n");
	for(; idx < 8; idx++)
		printf("%d\t",a[idx]);
	printf("\n");

	mergeSort(a,0,7);

	printf("Output array:\n");
	for(idx = 0; idx < 8; idx++)
		printf("%d\t",a[idx]);
	printf("\n");

	return 0;
}
